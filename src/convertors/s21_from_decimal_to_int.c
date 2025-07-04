#include "s21_convertors.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int sign = 0;
  int flag = s21_help_convert_decimal_to_int(&src, &dst, &sign);
  if (flag == 0 && s21_check_decimal_nubmer(&src)) {
    *dst = src.bits[0];
    if (sign != 0) {
      *dst *= -1;
    }
  }
  return flag;
}