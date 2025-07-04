#ifndef S21_COMMON_DENOMINATION
#define S21_COMMON_DENOMINATION

#include "../s21_basic.h"

int s21_common_denominator(s21_big_decimal *big_value_1,
                           s21_big_decimal *big_value_2);
void s21_big_mult_10(s21_big_decimal *big_value, int difference_scale);
int s21_bank_rounding(s21_big_decimal *big_value, int *flag_scale);
int s21_remainder(s21_big_decimal *big_value, int *flag_scale,
                  unsigned long long *remainder, int *scale);
int s21_big_div_10(s21_big_decimal *big_value, int scale);
s21_big_decimal s21_big_dec_div_ten_degre(s21_big_decimal *big_value,
                                          s21_big_decimal *big_remainder,
                                          int *scale);
void s21_big_body_div_by_ten(s21_big_decimal *big_value, s21_big_decimal *rem);
int s21_big_compare_decimal_for_div_by_ten(s21_big_decimal *a,
                                           s21_big_decimal *b);
int s21_big_decimal_overflow(s21_big_decimal *big_value, int ind);
int s21_big_decimal_overflow_for_decimal(s21_big_decimal *big_value, int ind);
int s21_res_dec(s21_big_decimal *big_value, int *res, int *scale);
void s21_check_remainder(s21_big_decimal *big_value, s21_big_decimal *tmp_value,
                         unsigned long long *remainder, int *flag_scale,
                         int *scale, int *res);

#endif