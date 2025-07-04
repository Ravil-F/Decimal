#include "s21_convertors.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int flag = (dst == NULL);
  if (flag == 0) {
    s21_set_null_decimal(dst);
    if (s21_chek_float_number_zero(&src) && s21_check_float_nubmer(&src)) {
      flag = 1;
    } else if (s21_chek_float_number_zero(&src)) {
      s21_decimal result = {0};
      s21_set_null_decimal(&result);
      if ((flag = s21_def_exp_and_number((src < 0 ? (src * -1) : src),
                                         &result)) == 0) {
        if (src < 0) {
          result.bits[3] |= 1 << (MAX_BITS);
        }
        *dst = result;
      }
    } else {
      s21_float_zero_in_decimal(dst, &src);
    }
  }
  return flag;
}