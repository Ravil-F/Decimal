#include "s21_check.h"

int s21_zero(s21_decimal *value) {
  int res = 0;
  for (int i = (DIVIDER * 3) - 1; i >= 0 && res == 0; i = i - 1) {
    if (s21_get_bit(value, i) != 0) {
      res = 1;
    }
  }
  return res == 0 ? 1 : 0;
}

int s21_error_scale(s21_decimal *value) { return (s21_get_scale(value) > 28); }

int s21_check_zero(s21_decimal *value_1, s21_decimal *value_2) {
  int res = 0;
  if ((s21_zero(value_1) == 1) && (s21_zero(value_2) == 1)) {
    res = 1;
  }
  return res;
}

int s21_big_check_scale(s21_big_decimal *big_value_1,
                        s21_big_decimal *big_value_2) {
  int scale_1 = s21_big_get_scale(big_value_1);
  int scale_2 = s21_big_get_scale(big_value_2);
  int res;
  if (scale_1 > scale_2) {
    res = 0;
  } else if (scale_1 < scale_2) {
    res = 1;
  } else {
    res = 2;
  }
  return res;
}

int s21_big_check_mantisa(s21_big_decimal *big_value_1,
                          s21_big_decimal *big_value_2) {
  int res = 2;
  for (int i = (DIVIDER * 7) - 1; i >= 0 && res == 2; i--) {
    if (s21_big_get_bit(big_value_1, i) < s21_big_get_bit(big_value_2, i)) {
      res = 0;
    }
    if (s21_big_get_bit(big_value_1, i) > s21_big_get_bit(big_value_2, i)) {
      res = 1;
    }
  }
  return res;
}

int s21_big_check_sign(s21_big_decimal *big_value_1,
                       s21_big_decimal *big_value_2) {
  return s21_big_get_sign(big_value_1) == s21_big_get_sign(big_value_2) ? 1 : 0;
}

int s21_big_check_zero(s21_big_decimal *big_value_1,
                       s21_big_decimal *big_value_2) {
  int res = 0;
  if ((s21_big_zero(big_value_1) == 1) && (s21_big_zero(big_value_2) == 1)) {
    res = 1;
  }
  return res;
}

int s21_big_zero(s21_big_decimal *big_value) {
  int res = 0;
  for (int i = (DIVIDER * 6) - 1; i >= 0 && res == 0; i--) {
    if (s21_big_get_bit(big_value, i) != 0) {
      res = 1;
    }
  }
  return res == 0 ? 1 : 0;
}

int s21_3rd_bit_error(s21_decimal *value) {
  int res = 0;
  for (int i = 0; i < 16 && res == 0; i++) {
    if ((value->bits[3] >> i) & 1) {
      res = 1;
    }
  }
  for (int i = 24; i < 31 && res == 0; i++) {
    if ((value->bits[3] >> i) & 1) {
      res = 1;
    }
  }
  return res;
}

int s21_error(s21_decimal *value) {
  return s21_3rd_bit_error(value) || s21_error_scale(value);
}