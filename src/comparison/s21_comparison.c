#include "s21_comparison.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  s21_big_decimal big_value_1;
  s21_big_decimal big_value_2;
  s21_decimal_to_big_decimal(&big_value_1, &value_1);
  s21_decimal_to_big_decimal(&big_value_2, &value_2);
  return s21_big_is_less(&big_value_1, &big_value_2);
}

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  int res = 0;
  if (s21_is_less(value_1, value_2) || s21_is_equal(value_1, value_2)) {
    res = 1;
  } else {
    res = 0;
  }
  return res;
}

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  int res = 0;
  int equal = s21_is_equal(value_1, value_2);
  if (equal == 1) {
    res = 0;
  } else if (s21_is_less(value_1, value_2)) {
    res = 0;
  } else {
    res = 1;
  }
  return res;
}

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  int res = 0;
  if (s21_is_greater(value_1, value_2) || s21_is_equal(value_1, value_2)) {
    res = 1;
  } else {
    res = 0;
  }
  return res;
}

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  s21_big_decimal big_value_1;
  s21_big_decimal big_value_2;
  s21_decimal_to_big_decimal(&big_value_1, &value_1);
  s21_decimal_to_big_decimal(&big_value_2, &value_2);
  return s21_big_is_equal(&big_value_1, &big_value_2);
}

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  return s21_is_equal(value_1, value_2) == 1 ? 0 : 1;
}

int s21_big_is_less(s21_big_decimal *big_value_1,
                    s21_big_decimal *big_value_2) {
  int res = 0;
  s21_common_denominator(big_value_1, big_value_2);
  int equal = s21_big_is_equal(big_value_1, big_value_2);
  int mantisa = s21_big_check_mantisa(big_value_1, big_value_2);
  if (equal == 1) {
    res = 0;
  } else if (((s21_big_get_sign(big_value_1) > s21_big_get_sign(big_value_2)) &&
              ((mantisa != 2))) ||
             (mantisa == 2 && (s21_big_get_sign(big_value_1) >
                               s21_big_get_sign(big_value_2))) ||
             (((s21_big_get_sign(big_value_1) == 0) &&
               (s21_big_get_sign(big_value_2) == 0)) &&
              mantisa == 0) ||
             (((s21_big_get_sign(big_value_1) == 1) &&
               (s21_big_get_sign(big_value_2) == 1)) &&
              mantisa == 1) ||
             ((s21_big_get_sign(big_value_1) > s21_big_get_sign(big_value_2)) &&
              mantisa == 1)) {
    res = 1;
  } else {
    res = 0;
  }
  return res;
}

int s21_big_is_equal(s21_big_decimal *big_value_1,
                     s21_big_decimal *big_value_2) {
  int res = 1;
  int sign = s21_big_check_sign(big_value_1, big_value_2);
  int zero = s21_big_check_zero(big_value_1, big_value_2);
  s21_common_denominator(big_value_1, big_value_2);
  int mantisa = s21_big_check_mantisa(big_value_1, big_value_2);
  if ((sign == 1 && (zero == 1 || mantisa == 2)) ||
      ((sign == 0) && zero == 1)) {
    res = 1;
  } else {
    res = 0;
  }
  return res;
}

int s21_is_greater_or_equal_big_decimal(s21_big_decimal value_1,
                                        s21_big_decimal value_2) {
  int result = 0;
  int flag = 0;
  for (int i = 7; i >= 0 && !flag && !result; i--) {
    if (value_1.bits[i] != 0 || value_2.bits[i] != 0) {
      if (value_1.bits[i] >= value_2.bits[i]) {
        result = 1;
      }
      flag = 1;
    }
  }
  return result;
}

int s21_is_greater_big_decimal(s21_big_decimal value_1,
                               s21_big_decimal value_2) {
  int result = 0;
  int flag = 0;
  for (int i = 7; i >= 0 && !result && !flag; i--) {
    if (value_1.bits[i] || value_2.bits[i]) {
      if (value_1.bits[i] > value_2.bits[i]) {
        result = 1;
      }
      if (value_1.bits[i] != value_2.bits[i]) {
        flag = 1;
      }
    }
  }
  return result;
}

int s21_big_is_greater(s21_big_decimal *value_1, s21_big_decimal *value_2) {
  int res = 0;
  int equal = s21_big_is_equal(value_1, value_2);
  if (equal == 1) {
    res = 0;
  } else if (s21_big_is_less(value_1, value_2)) {
    res = 0;
  } else {
    res = 1;
  }
  return res;
}

int s21_compare_decimal_for_div_by_ten_big(s21_big_decimal *a,
                                           s21_big_decimal *b) {
  int result = s21_big_is_equal(a, b);
  if (result == 1) {
    result = 1;
  } else if ((result = s21_big_is_greater(a, b)) == 1) {
    result = 2;
  } else {
    result = 0;
  }
  return result;
}