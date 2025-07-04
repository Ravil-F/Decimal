#include "s21_basic.h"

int s21_get_sign(s21_decimal *value) {
  int sign;
  sign = value->bits[3] >> MAX_BITS;
  return sign;
}

void s21_set_sign(s21_decimal *value, int sign_value) {
  int sign = DIVIDER * 4 - 1;
  s21_set_bit(value, sign, sign_value);
}

int s21_get_scale(s21_decimal *value) {
  int scale;
  scale = (value->bits[3] & (MASK_SCALE << 16)) >> 16;
  return scale;
}

void s21_set_scale(s21_decimal *value, int scale_value) {
  value->bits[3] &= ~(MASK_SCALE << 16);
  value->bits[3] |= scale_value << 16;
}

int s21_get_bit(s21_decimal *value, int num) {
  int res;
  unsigned ind = 1;
  int number_bits = num / DIVIDER;
  int number_index = num % DIVIDER;
  int mask_tmp = ind << number_index;
  res = (value->bits[number_bits] & mask_tmp) >> number_index;
  return res;
}

void s21_set_bit(s21_decimal *value, int num, unsigned bit) {
  unsigned ind = 1;
  int number_bits = num / DIVIDER;
  int number_index = num % DIVIDER;
  int mask_tmp = ind << number_index;
  if (bit == 1) {
    value->bits[number_bits] = value->bits[number_bits] | mask_tmp;
  } else {
    value->bits[number_bits] = value->bits[number_bits] & ~mask_tmp;
  }
}

int s21_big_get_bit(s21_big_decimal *big_value, int num) {
  int res;
  unsigned ind = 1;
  int number_bits = num / DIVIDER;
  int number_index = num % DIVIDER;
  int mask_tmp = ind << number_index;
  res = (big_value->bits[number_bits] & mask_tmp) >> number_index;
  return res;
}

void s21_big_set_bit(s21_big_decimal *big_value, int num, unsigned bit) {
  unsigned ind = 1;
  int number_bits = num / DIVIDER;
  int number_index = num % DIVIDER;
  int mask_tmp = ind << number_index;
  if (bit == 1) {
    big_value->bits[number_bits] = big_value->bits[number_bits] | mask_tmp;
  } else {
    big_value->bits[number_bits] = big_value->bits[number_bits] & ~mask_tmp;
  }
}

int s21_big_get_scale(s21_big_decimal *big_value) {
  int scale;
  scale = (big_value->bits[7] & (MASK_SCALE << 16)) >> 16;
  return scale;
}

void s21_big_set_scale(s21_big_decimal *big_value, int scale_value) {
  big_value->bits[7] &= ~(MASK_SCALE << 16);
  big_value->bits[7] |= scale_value << 16;
}

int s21_big_get_sign(s21_big_decimal *big_value) {
  int sign;
  sign = big_value->bits[7] >> MAX_BITS;
  return sign;
}

void s21_big_set_sign(s21_big_decimal *big_value, int sign_value) {
  int sign = DIVIDER * 8 - 1;
  s21_big_set_bit(big_value, sign, sign_value);
}

void s21_decimal_to_big_decimal(s21_big_decimal *big_value,
                                s21_decimal *value) {
  int k = 0;
  for (int i = 0; i < 8; i++) {
    if (i == 3 || i == 4 || i == 5 || i == 6) {
      big_value->bits[i] = 0;
    } else {
      big_value->bits[i] = value->bits[k];
      k++;
    }
  }
}

int s21_big_decimal_to_decimal(s21_big_decimal *big_value, s21_decimal *value) {
  if (s21_big_zero(big_value) == 1) return 0;
  int res = 0;
  int flag_scale = 0;

  int scale = s21_big_get_scale(big_value);
  int status = s21_bank_rounding(big_value, &flag_scale);
  if (status == 0) {
    res = s21_big_decimal_overflow(big_value, 2);
    if (((res > 0 || res < 0) && (scale != 0)) || scale > 28) {
      s21_big_decimal_to_decimal(big_value, value);
    } else if (res == 0 && (scale <= 28)) {
      for (int i = 0; i < 3; i++) {
        value->bits[i] = big_value->bits[i];
      }
      value->bits[3] = big_value->bits[7];
    }
  }
  return status;
}

void s21_big_shift_left(s21_big_decimal *big_value, int shift_value) {
  int tmp_divider = DIVIDER;
  int max_bits[6] = {0};

  for (int j = 0; j < shift_value; j++) {
    for (int k = 0; k < 6; k++) {
      max_bits[k] = s21_big_get_bit(big_value, (tmp_divider * (k + 1)) - 1);
    }

    for (int i = 0; i < 7; i++) {
      big_value->bits[i] = big_value->bits[i] << 1;
    }

    for (int k = 0; k < 6; k++) {
      s21_big_set_bit(big_value, (tmp_divider * (k + 1)), max_bits[k]);
    }
  }
}

void s21_set_null_decimal(s21_decimal *decimal) {
  for (int i = 0; i < 4; i++) {
    decimal->bits[i] = 0;
  }
}

void s21_set_null_big_decimal(s21_big_decimal *decimal) {
  for (int i = 0; i < 8; i++) {
    decimal->bits[i] = 0;
  }
}

int s21_temp_shift_l(s21_decimal *result) {
  int flag = s21_check_overflow(result->bits[2]);
  if (flag == 0) {
    flag = s21_help_shift_l(result, 0, 0);
  }
  return flag;
}

int s21_help_shift_l(s21_decimal *res, int bit, int f) {
  int flag = 0;
  if (bit == 2) {
    if (s21_check_overflow(res->bits[bit])) {
      flag = 1;
    }
  } else {
    flag = s21_help_shift_l(res, bit + 1, s21_check_overflow(res->bits[bit]));
  }
  if (flag == 0) {
    res->bits[bit] <<= 1;
    res->bits[bit] |= f;
  }
  return flag;
}

void s21_big_set_7_bit_to_null(s21_big_decimal *value_1,
                               s21_big_decimal *value_2) {
  value_1->bits[7] = 0;
  value_2->bits[7] = 0;
}

void s21_body_div_by_ten_big_decimal(s21_big_decimal *value) {
  s21_big_decimal rem = {{0, 0, 0, 0, 0, 0, 0, 0}},
                  ten_div = {{10, 0, 0, 0, 0, 0, 0, 0}},
                  quot = {{0, 0, 0, 0, 0, 0, 0, 0}};
  for (int i = 7 * 32; i >= 0; i--) {
    int b = i / 32, shift = i % 32;
    s21_big_shift_left(&rem, 1);
    rem.bits[0] |= (value->bits[b] >> shift) & 1;
    if (s21_compare_decimal_for_div_by_ten_big(&rem, &ten_div) > 0) {
      rem.bits[0] -= ten_div.bits[0];
      quot.bits[b] |= 1 << shift;
    }
  }
  *value = quot;
}

int s21_set_status(s21_big_decimal *value, int scale) {
  int big_bits_is_full = 0, status = 0, greater_max_scale = 0;
  for (int i = 6; i >= 3 && big_bits_is_full != 1; i--) {
    if (value->bits[i] != 0) {
      big_bits_is_full = 1;
    }
  }
  if (scale > 28) {
    if (value->bits[0] == 0 && value->bits[1] == 0 && value->bits[2] == 0) {
      greater_max_scale = 1;
    }
  }
  int is_negative = (value->bits[7] & 0b10000000000000000000000000000000) != 0;
  if (big_bits_is_full && !is_negative) {
    status = 1;
  } else if (big_bits_is_full && is_negative) {
    status = 2;
  } else if (big_bits_is_full && !is_negative && greater_max_scale) {
    status = 1;
  } else if (big_bits_is_full && is_negative && greater_max_scale) {
    status = 2;
  }
  return status;
}

void s21_big_result_normalize(s21_big_decimal *value, int *scale) {
  while (value->bits[3] != 0 && *scale > 0) {
    s21_body_div_by_ten_big_decimal(value);
    (*scale)--;
  }
}