#include "s21_com_denom.h"

int s21_common_denominator(s21_big_decimal *big_value_1,
                           s21_big_decimal *big_value_2) {
  int status = 0;
  int sign_1 = s21_big_get_sign(big_value_1);
  int sign_2 = s21_big_get_sign(big_value_2);
  int scale_1 = s21_big_get_scale(big_value_1);
  int scale_2 = s21_big_get_scale(big_value_2);
  int difference_scale = 0;

  if (scale_1 > 28) {
    status = s21_big_div_10(big_value_1, scale_1);
    s21_big_set_scale(big_value_1, 28);
  }
  if (scale_2 > 28) {
    status = s21_big_div_10(big_value_2, scale_2);
    s21_big_set_scale(big_value_2, 28);
  }
  if (s21_big_check_scale(big_value_1, big_value_2) == 0) {
    status = 0;
    difference_scale = scale_1 - scale_2;
    s21_big_mult_10(big_value_2, difference_scale);
    s21_big_set_scale(big_value_2, scale_1);
  } else if (s21_big_check_scale(big_value_1, big_value_2) == 1) {
    status = 0;
    difference_scale = scale_2 - scale_1;
    s21_big_mult_10(big_value_1, difference_scale);
    s21_big_set_scale(big_value_1, scale_2);
  }
  s21_big_set_sign(big_value_1, sign_1);
  s21_big_set_sign(big_value_2, sign_2);
  return status;
}

void s21_big_mult_10(s21_big_decimal *big_value, int difference_scale) {
  for (int i = 0; i < difference_scale; i++) {
    s21_big_decimal tmp_big_value_1 = *big_value;
    s21_big_decimal tmp_big_value_2 = *big_value;
    s21_big_shift_left(&tmp_big_value_1, 3);
    s21_big_shift_left(&tmp_big_value_2, 1);
    s21_add_big_decimal(tmp_big_value_1, tmp_big_value_2, big_value);
  }
}

int s21_big_div_10(s21_big_decimal *big_value, int scale) {
  int minus_scale = scale - 28;
  int status = 0;
  for (int i = scale; i > 28; i--) {
    status = s21_bank_rounding(big_value, &minus_scale);
  }
  return status;
}

s21_big_decimal s21_big_dec_div_ten_degre(s21_big_decimal *big_value,
                                          s21_big_decimal *big_remainder,
                                          int *scale) {
  s21_big_decimal temp_big_reminder;
  for (int i = 0; i < *scale; i++) {
    s21_set_null_big_decimal(&temp_big_reminder);
    s21_big_body_div_by_ten(big_value, &temp_big_reminder);
    s21_big_mult_10(&temp_big_reminder, i);
    s21_add_big_decimal(*big_remainder, temp_big_reminder, big_remainder);
  }
  *scale = 0;
  return *big_value;
}

void s21_big_body_div_by_ten(s21_big_decimal *big_value, s21_big_decimal *rem) {
  s21_big_decimal ten_div = {{10, 0, 0, 0, 0, 0, 0, 0}},
                  quot = {{0, 0, 0, 0, 0, 0, 0, 0}};

  for (int i = (DIVIDER * 7) - 1; i >= 0; i--) {
    int b = i / DIVIDER, shift = i % DIVIDER;
    s21_big_shift_left(rem, 1);
    rem->bits[0] |= (big_value->bits[b] >> shift) & 1;
    if (s21_big_compare_decimal_for_div_by_ten(rem, &ten_div) > 0) {
      rem->bits[0] -= ten_div.bits[0];
      quot.bits[b] |= 1 << shift;
    }
  }
  *big_value = quot;
}

int s21_big_compare_decimal_for_div_by_ten(s21_big_decimal *a,
                                           s21_big_decimal *b) {
  int result = s21_big_is_equal(a, b);
  if (result == 1) {
    result = 1;
  } else if ((result = s21_big_is_less(b, a)) == 1) {
    result = 2;
  } else {
    result = 0;
  }
  return result;
}

int s21_bank_rounding(s21_big_decimal *big_value, int *flag_scale) {
  int status = 0;
  int res = 0;
  unsigned long long remainder = 0;
  s21_big_decimal big_result;
  int sign = s21_big_get_sign(big_value);
  int scale = s21_big_get_scale(big_value);
  res = s21_remainder(big_value, flag_scale, &remainder, &scale);
  if ((res > 0 || res < 0) && (*flag_scale == 0)) {
    status = 1;
  } else if ((((res == 0) && (scale > 28) && (*flag_scale == 0)) ||
              (s21_big_decimal_overflow_for_decimal(big_value, 0) == 0 &&
               remainder < 5))) {
    status = 2;
  } else {
    if (((big_value->bits[0] & 1) && (remainder >= 5)) || (remainder > 5)) {
      s21_big_decimal big_one = {{1, 0, 0, 0, 0, 0, 0, 0}};
      big_result = *big_value;
      s21_add_big_decimal(big_result, big_one, big_value);
    }
  }
  s21_big_set_scale(big_value, scale);
  s21_big_set_sign(big_value, sign);
  return status;
}

int s21_remainder(s21_big_decimal *big_value, int *flag_scale,
                  unsigned long long *remainder, int *scale) {
  s21_big_decimal tmp_value = *big_value;
  int fl_wl = 0;
  int res = 0;
  res = s21_big_decimal_overflow(big_value, 2);
  res = s21_res_dec(big_value, &res, scale);
  if (*flag_scale > 28) {
    res = 1;
  }
  while ((((res > 0) || (res < 0)) && (*scale != 0)) || fl_wl != 0) {
    s21_check_remainder(big_value, &tmp_value, remainder, flag_scale, scale,
                        &res);
    if (scale == 0 || *flag_scale > 0) {
      fl_wl = 1;
    }
  }
  res = s21_res_dec(big_value, &res, scale);
  return res;
}

int s21_big_decimal_overflow(s21_big_decimal *big_value, int ind) {
  int res = 0;
  for (int i = 6; (i > ind) && res == 0; i--) {
    res = big_value->bits[i] | 0;
  }
  return res;
}

int s21_big_decimal_overflow_for_decimal(s21_big_decimal *big_value, int ind) {
  int res = 0;
  for (int i = 6; (((i >= ind) && (res == 0)) ||
                   ((res == 0) && (s21_big_get_scale(big_value) > 28)));
       i--) {
    res = big_value->bits[i] | 0;
  }
  return res;
}

int s21_res_dec(s21_big_decimal *big_value, int *res, int *scale) {
  int res_dec = *res;
  if (res_dec == 0 && *scale > 28) {
    res_dec = s21_big_decimal_overflow_for_decimal(big_value, 0);
  }
  return res_dec;
}

void s21_check_remainder(s21_big_decimal *big_value, s21_big_decimal *tmp_value,
                         unsigned long long *remainder, int *flag_scale,
                         int *scale, int *res) {
  s21_big_decimal rem = {0};
  unsigned long long tmp_rem;
  int fl = 0;
  for (int i = 6; i >= 0 && (fl == 0 || s21_big_get_scale(big_value) > 28);
       i--) {
    *res = s21_big_decimal_overflow(big_value, 2);
    *res = s21_res_dec(big_value, res, scale);
    if (((*res < 0 || *res > 0) || (*flag_scale > 0)) &&
        ((fl == 0) || s21_big_get_scale(big_value) > 28)) {
      s21_set_null_big_decimal(&rem);
      for (int i = 6; i >= 0; i--) {
        *remainder = 0;
        tmp_rem = (*remainder << 32) | tmp_value->bits[i];
        *remainder = tmp_rem % 10;
        tmp_value->bits[i] = tmp_rem / 10;
        if (((big_value->bits[0] & 1) && (*remainder >= 5)) ||
            (*remainder > 5)) {
          s21_big_decimal big_one = {{1, 0, 0, 0, 0, 0, 0, 0}};
          s21_add_big_decimal(*tmp_value, big_one, tmp_value);
        }
      }
      if (*flag_scale > 0) {
        *big_value = s21_big_dec_div_ten_degre(big_value, &rem, flag_scale);
      } else {
        int tmp_scale = 1;
        *big_value = s21_big_dec_div_ten_degre(big_value, &rem, &tmp_scale);
      }
      (*scale)--;
      fl = 1;
    }
  }
}
