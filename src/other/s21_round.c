#include "../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int flag = 0;
  int scale = s21_get_scale(&value);
  if (s21_error(&value) == 1 || result == NULL || scale < 0) {
    flag = 1;
  } else {
    s21_set_null_decimal(result);
    int sign = s21_get_sign(&value);
    if (scale == 0) {
      *result = value;
    } else {
      s21_decimal tmp_res;
      s21_decimal tail;
      s21_truncate(value, &tmp_res);
      s21_sub(value, tmp_res, &tail);
      s21_set_sign(&tail, 0);
      s21_side(tmp_res, tail, result, sign);
      if (sign == 1) {
        s21_set_sign(result, 1);
      }
    }
  }
  return flag;
}

s21_decimal s21_side(s21_decimal value, s21_decimal tail, s21_decimal *result,
                     int sign) {
  if (s21_is_greater_or_equal(tail, s21_half()) == 1) {
    if (sign == 1) {
      s21_sub(value, s21_one(), result);
    } else {
      s21_add(value, s21_one(), result);
    }
  } else {
    *result = value;
  }
  return *result;
}