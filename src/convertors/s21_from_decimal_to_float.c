#include "s21_convertors.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int status = 0;
  if (dst != NULL && s21_check_decimal_nubmer(&src)) {
    float result = 0;
    status = s21_help_convert_decimal_to_float(&src, &result);
    if (status == 0) {
      *dst = result;
    }
  } else
    status = 1;
  return status;
}