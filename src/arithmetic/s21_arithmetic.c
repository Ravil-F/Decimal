#include "s21_arithmetic.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int status = 0, sign = 0;
  s21_set_null_decimal(result);
  if ((s21_get_sign(&value_1) == s21_get_sign(&value_2))) {
    sign = s21_get_sign(&value_1);
    status = s21_add_helper(value_1, value_2, result);
  } else if (s21_get_sign(&value_1) != s21_get_sign(&value_2)) {
    s21_decimal tmp_value_1 = value_1, tmp_value_2 = value_2;
    s21_set_sign(&tmp_value_1, 0);
    s21_set_sign(&tmp_value_2, 0);
    if (s21_is_greater(tmp_value_1, tmp_value_2)) {
      sign = s21_get_sign(&value_1);
      status = s21_sub_helper(tmp_value_1, tmp_value_2, result);
    } else if (s21_is_equal(tmp_value_1, tmp_value_2)) {
      sign = 0;
      status = s21_sub_helper(tmp_value_1, tmp_value_2, result);
    } else {
      sign = s21_get_sign(&value_2);
      status = s21_sub_helper(tmp_value_2, tmp_value_1, result);
    }
  }
  if (status == 0) {
    s21_set_sign(result, sign);
  } else {
    s21_set_null_decimal(result);
  }
  return status;
}

int s21_add_helper(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *result) {
  s21_big_decimal big_decimal_value_1, big_decimal_value_2,
      big_decimal_result = {0};
  int scale = 0, status = 0;
  s21_decimal_to_big_decimal(&big_decimal_value_1, &value_1);
  s21_decimal_to_big_decimal(&big_decimal_value_2, &value_2);
  if ((s21_get_scale(&value_1) - s21_get_scale(&value_2)) > 0) {
    scale = s21_get_scale(&value_1);
  } else {
    scale = s21_get_scale(&value_2);
  }
  int sign = s21_big_get_sign(&big_decimal_value_1);
  s21_common_denominator(&big_decimal_value_1, &big_decimal_value_2);
  s21_add_big_decimal(big_decimal_value_1, big_decimal_value_2,
                      &big_decimal_result);
  s21_big_result_normalize(&big_decimal_result, &scale);
  s21_big_set_sign(&big_decimal_result, sign);
  status = s21_set_status(&big_decimal_result, scale);
  if (status == 0) {
    status = s21_big_decimal_to_decimal(&big_decimal_result, result);
    s21_set_scale(result, scale);
  } else {
    s21_set_null_big_decimal(&big_decimal_result);
  }
  return status;
}

void s21_add_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2,
                         s21_big_decimal *result) {
  int res = 0, overflow = 0;
  for (int i = 0; i < 224; i++) {
    res =
        s21_big_get_bit(&value_1, i) + s21_big_get_bit(&value_2, i) + overflow;
    overflow = res / 2;
    s21_big_set_bit(result, i, res % 2);
  }
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int status = 0, sign = 0;
  s21_set_null_decimal(result);
  s21_decimal tmp_value_1 = value_1, tmp_value_2 = value_2;
  if (s21_get_sign(&value_1) != s21_get_sign(&value_2)) {
    sign = s21_get_sign(&value_1);
    status = s21_add_helper(tmp_value_1, tmp_value_2, result);
  } else if (s21_get_sign(&value_1) == s21_get_sign(&value_2)) {
    s21_set_sign(&tmp_value_1, 0);
    s21_set_sign(&tmp_value_2, 0);
    if (s21_is_less_or_equal(value_2, value_1)) {
      sign = 0;
      if (s21_is_greater_or_equal(tmp_value_1, tmp_value_2)) {
        status = s21_sub_helper(value_1, value_2, result);
      } else {
        status = s21_sub_helper(value_2, value_1, result);
      }
    } else {
      sign = 1;
      if (s21_is_greater_or_equal(tmp_value_1, tmp_value_2)) {
        status = s21_sub_helper(value_1, value_2, result);
      } else {
        status = s21_sub_helper(value_2, value_1, result);
      }
    }
  }
  if (status == 0) {
    s21_set_sign(result, sign);
  } else {
    s21_set_null_decimal(result);
  }
  return status;
}

int s21_sub_helper(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *result) {
  s21_big_decimal big_decimal_value_1, big_decimal_value_2,
      big_decimal_result = {0};
  int scale = 0, status = 0;
  s21_decimal_to_big_decimal(&big_decimal_value_1, &value_1);
  s21_decimal_to_big_decimal(&big_decimal_value_2, &value_2);
  if ((s21_get_scale(&value_1) - s21_get_scale(&value_2)) > 0) {
    scale = s21_get_scale(&value_1);
  } else {
    scale = s21_get_scale(&value_2);
  }
  int sign = s21_big_get_sign(&big_decimal_value_1);
  s21_common_denominator(&big_decimal_value_1, &big_decimal_value_2);
  s21_sub_big_decimal(big_decimal_value_1, big_decimal_value_2,
                      &big_decimal_result);
  s21_big_result_normalize(&big_decimal_result, &scale);
  s21_big_set_sign(&big_decimal_result, sign);
  status = s21_set_status(&big_decimal_result, scale);
  if (status == 0) {
    status = s21_big_decimal_to_decimal(&big_decimal_result, result);
    s21_set_scale(result, scale);
  } else {
    s21_set_null_big_decimal(&big_decimal_result);
  }
  return status;
}

void s21_sub_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2,
                         s21_big_decimal *result) {
  int tmp = 0, res = 0;
  for (int i = 0; i < 224; i++) {
    res = s21_big_get_bit(&value_1, i) - s21_big_get_bit(&value_2, i) - tmp;
    tmp = res < 0;
    res = abs(res);
    s21_big_set_bit(result, i, res % 2);
  }
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int status = 0, sign = 0;
  s21_set_null_decimal(result);
  if (s21_get_sign(&value_1) == s21_get_sign(&value_2)) {
    sign = 0;
  } else if (s21_get_sign(&value_1) != s21_get_sign(&value_2)) {
    sign = 1;
  }
  status = s21_mul_helper(value_1, value_2, result);
  if (status == 0) {
    s21_set_sign(result, sign);
  } else {
    s21_set_null_decimal(result);
  }
  return status;
}

int s21_mul_helper(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *result) {
  s21_big_decimal big_decimal_value_1, big_decimal_value_2,
      big_decimal_result = {0};
  int scale = 0, status = 0, sign = 0;
  s21_decimal_to_big_decimal(&big_decimal_value_1, &value_1);
  s21_decimal_to_big_decimal(&big_decimal_value_2, &value_2);
  scale = s21_big_get_scale(&big_decimal_value_1) +
          s21_big_get_scale(&big_decimal_value_2);
  if (s21_big_get_sign(&big_decimal_value_1) ==
      s21_big_get_sign(&big_decimal_value_2)) {
    sign = 0;
  } else {
    sign = 1;
  }
  s21_big_set_7_bit_to_null(&big_decimal_value_1, &big_decimal_value_2);
  s21_mul_big_decimal(big_decimal_value_1, big_decimal_value_2,
                      &big_decimal_result);
  s21_big_result_normalize(&big_decimal_result, &scale);
  s21_big_set_sign(&big_decimal_result, sign);
  status = s21_set_status(&big_decimal_result, scale);
  if (status == 0) {
    status = s21_big_decimal_to_decimal(&big_decimal_result, result);
    s21_set_scale(result, scale);
  } else {
    s21_set_null_big_decimal(&big_decimal_result);
  }
  return status;
}

int s21_mul_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2,
                        s21_big_decimal *result) {
  int status = 0, count = 0;
  for (int i = 0; i < 224 && !status; i++) {
    if (s21_big_get_bit(&value_2, i)) {
      if (s21_big_get_sign(&value_1))
        status = 1;
      else {
        s21_big_shift_left(&value_1, i - count);
        s21_add_big_decimal(value_1, *result, result);
        count = i;
      }
    }
  }
  return status;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int status = 0, sign = 0;
  s21_decimal null_decimal = {0};
  if (s21_check_zero(&value_2, &null_decimal)) {
    status = 3;
  } else {
    if ((s21_get_sign(&value_1) && !s21_get_sign(&value_2)) ||
        (!s21_get_sign(&value_1) && s21_get_sign(&value_2))) {
      sign = 1;
    } else {
      sign = 0;
    }
    s21_big_decimal big_value_1, big_value_2, big_result = {{0}};
    s21_decimal_to_big_decimal(&big_value_1, &value_1);
    s21_decimal_to_big_decimal(&big_value_2, &value_2);
    status = s21_div_big_decimal(big_value_1, big_value_2, &big_result);
    s21_set_null_decimal(result);
    status = s21_set_status(&big_result, s21_big_get_scale(&big_result));
    if (status == 0) {
      status = s21_big_decimal_to_decimal(&big_result, result);
      s21_set_sign(result, sign);
    } else {
      s21_set_null_decimal(result);
    }
  }
  return status;
}

int s21_div_helper(s21_big_decimal value_1, s21_big_decimal value_2,
                   s21_big_decimal *result, s21_big_decimal *big_remainder) {
  int status = 0;
  s21_big_decimal tmp = {0};
  s21_set_null_big_decimal(result);
  s21_set_null_big_decimal(big_remainder);
  for (int i = 224; i >= 0; i--) {
    s21_set_null_big_decimal(&tmp);
    s21_big_shift_left(big_remainder, 1);
    if (s21_big_get_bit(&value_1, i)) {
      s21_big_set_bit(big_remainder, 0, 1);
    }
    if (s21_is_greater_or_equal_big_decimal(*big_remainder, value_2)) {
      s21_sub_big_decimal(*big_remainder, value_2, &tmp);
      *big_remainder = tmp;
      s21_big_set_bit(result, i, 1);
      status = 0;
    }
  }
  return status;
}

int s21_handle_remainder(s21_big_decimal big_remainder,
                         s21_big_decimal big_value_2, int *scale,
                         s21_big_decimal *result) {
  int status = 0;
  s21_big_decimal big_result = *result;
  int tmp_scale = 0;
  while (!s21_big_zero(&big_remainder) && tmp_scale < 40) {
    s21_big_decimal tmp = {0};
    s21_big_decimal tmp_result = {0};
    s21_big_decimal tmp_remainder = {0};
    s21_big_mult_10(&big_remainder, 1);
    s21_div_helper(big_remainder, big_value_2, &tmp_result, &tmp_remainder);
    s21_big_mult_10(&big_result, 1);
    s21_add_big_decimal(big_result, tmp_result, &tmp);
    big_remainder = tmp_remainder;
    if (s21_is_greater_big_decimal(big_remainder, big_value_2)) {
      s21_sub_big_decimal(big_remainder, big_value_2, &tmp);
      big_remainder = tmp;
    }
    big_result = tmp;
    tmp_scale++;
  }
  *scale = tmp_scale;
  status = s21_set_status(&big_result, *scale);
  if (status == 0) {
    *result = big_result;
  } else {
    s21_set_null_big_decimal(&big_result);
  }
  return status;
}

int s21_div_big_decimal(s21_big_decimal big_value_1,
                        s21_big_decimal big_value_2,
                        s21_big_decimal *big_result) {
  int status = 0, scale = 0;
  s21_big_decimal big_remainder = {0};
  scale = s21_big_get_scale(&big_value_1) - s21_big_get_scale(&big_value_2);
  s21_common_denominator(&big_value_1, &big_value_2);
  big_value_1.bits[7] = 0;
  big_value_2.bits[7] = 0;
  status = s21_div_helper(big_value_1, big_value_2, big_result, &big_remainder);
  if (!s21_big_zero(&big_remainder)) {
    status =
        s21_handle_remainder(big_remainder, big_value_2, &scale, big_result);
    s21_big_result_normalize(big_result, &scale);
    s21_big_set_scale(big_result, scale);
  } else {
    s21_big_set_scale(big_result, 0);
  }
  return status;
}
