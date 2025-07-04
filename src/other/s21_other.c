#include "../s21_decimal.h"

int s21_neg_check(int *i, s21_decimal *dst) {
  int is_neg = 0;
  if (*i < 0) {
    is_neg = 1;
    dst->bits[3] = dst->bits[3] | (is_neg << MAX_BITS);
  }
  return is_neg;
}

int s21_check_overflow(uint32_t value) { return value & (1 << 31) ? 1 : 0; }

// ARITHMETIC

int s21_dec_mull_ten(s21_decimal *result, int scale) {
  int flag = 0;
  for (int i = 0; i < scale && flag == 0; i++) {
    s21_decimal tmp = *result, tmp_num = *result;
    for (int j = 0; j < 3; j++) {
      flag = s21_temp_shift_l(&tmp);
    }
    if (flag == 0) {
      flag = s21_temp_shift_l(&tmp_num);
    }
    if (flag == 0) {
      flag = s21_add(tmp, tmp_num, result);
    }
  }
  return flag;
}

// divided by ten degree

s21_decimal s21_dec_div_ten_degre(s21_decimal *value, s21_decimal *remainder) {
  int scale = s21_get_scale(value);
  s21_decimal result = *value;
  s21_decimal temp_reminder;

  s21_set_null_decimal(remainder);
  for (int i = 0; i < scale; i++) {
    s21_set_null_decimal(&temp_reminder);
    s21_body_div_by_ten(&result, &temp_reminder);
    s21_dec_mull_ten(&temp_reminder, i);
    s21_add(*remainder, temp_reminder, remainder);
  }

  return result;
}

void s21_body_div_by_ten(s21_decimal *value, s21_decimal *rem) {
  s21_decimal ten_div = {{10, 0, 0, 0}}, quot = {0};
  for (int i = 95; i >= 0; i--) {
    int b = i / 32, shift = i % 32;
    s21_temp_shift_l(rem);
    rem->bits[0] |= (value->bits[b] >> shift) & 1;
    if (s21_compare_decimal_for_div_by_ten(rem, &ten_div) > 0) {
      rem->bits[0] -= ten_div.bits[0];
      quot.bits[b] |= 1 << shift;
    }
  }
  *value = quot;
}

// HELP FOR ROUND & FLOOR
// единица для вычитания и сложения в округлении
s21_decimal s21_one() {
  s21_decimal one;
  s21_set_null_decimal(&one);
  one.bits[0] = 1;
  return one;
}
// 0.5 для round (определение, в какую сторону
// округлять)
s21_decimal s21_half() {
  int h = 5;
  s21_decimal half;
  s21_from_int_to_decimal(h, &half);
  s21_set_scale(&half, 1);
  return half;
}