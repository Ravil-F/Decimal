#include "../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int flag = 0;
  int scale = s21_get_scale(&value);
  if (s21_error(&value) == 1 || result == NULL || scale < 0) {
    flag = 1;
  } else {
    s21_set_null_decimal(result);
    if (scale == 0) {
      *result = value;
    } else {
      int sign = s21_get_sign(&value);
      s21_decimal tmp_res;
      s21_decimal tail;
      s21_decimal empty = {0};
      s21_truncate(value, &tmp_res);
      s21_sub(value, tmp_res, &tail);
      if (sign == 0 || s21_is_equal(tail, empty) == 1) {
        *result = tmp_res;
      } else {
        s21_sub(tmp_res, s21_one(), result);
        s21_set_sign(result, 1);
      }
    }
  }
  return flag;
}