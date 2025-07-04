#include "../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int flag = 0;
  int scale = s21_get_scale(&value);
  if (s21_error(&value) == 1 || result == NULL || scale < 0) {
    flag = 1;
  } else {
    s21_set_null_decimal(result);
    *result = value;
    int sign = s21_get_sign(&value);
    if (sign == 0) {
      s21_set_sign(result, 1);
    } else {
      s21_set_sign(result, 0);
    }
  }
  return flag;
}