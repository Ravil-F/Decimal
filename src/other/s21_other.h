#ifndef S21_OTHER_H
#define S21_OTHER_H

#include "../s21_decimal.h"

int s21_neg_check(int *i, s21_decimal *dst);
int s21_check_overflow(uint32_t value);
int s21_dec_mull_ten(s21_decimal *result, int scale);
s21_decimal s21_dec_div_ten_degre(s21_decimal *value, s21_decimal *remainder);
void s21_body_div_by_ten(s21_decimal *value, s21_decimal *rem);

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

int s21_big_floor(s21_big_decimal value, s21_big_decimal *result);
int s21_big_round(s21_big_decimal value, s21_big_decimal *result);
int s21_big_truncate(s21_big_decimal value, s21_big_decimal *result);
int s21_big_negate(s21_big_decimal value, s21_big_decimal *result);

s21_decimal s21_one();
s21_decimal s21_half();
s21_decimal s21_side(s21_decimal value, s21_decimal tail, s21_decimal *result,
                     int sign);
#endif
