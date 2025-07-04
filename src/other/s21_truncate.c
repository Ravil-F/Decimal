#include "../s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
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
      s21_decimal remainder;
      *result = s21_dec_div_ten_degre(&value, &remainder);
      if (sign == 1) {
        s21_set_sign(result, 1);
      }
    }
  }
  return flag;
}