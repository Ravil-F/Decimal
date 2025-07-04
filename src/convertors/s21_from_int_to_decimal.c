#include "s21_convertors.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int flag = 0;
  if (dst == NULL)
    flag = 1;
  else {
    int sign = 0;
    if (s21_neg_check(&src, dst)) {
      src *= -1;
      sign = 1;
    }
    s21_set_null_decimal(dst);
    for (int i = 0, j = MAX_BITS, mask = 1; j >= 0 && flag == 0; j--) {
      dst->bits[i] |= src & (mask << j);
    }
    s21_set_sign(dst, sign);
  }
  return flag;
}
