#ifndef S21_COMPARISON
#define S21_COMPARISON

#include "../s21_decimal.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);
int s21_big_is_less(s21_big_decimal *big_value_1, s21_big_decimal *big_value_2);
int s21_big_is_equal(s21_big_decimal *big_value_1,
                     s21_big_decimal *big_value_2);
int s21_is_greater_or_equal_big_decimal(s21_big_decimal value_1,
                                        s21_big_decimal value_2);
int s21_is_greater_big_decimal(s21_big_decimal value_1,
                               s21_big_decimal value_2);
int s21_big_is_greater(s21_big_decimal *value_1, s21_big_decimal *value_2);
int s21_compare_decimal_for_div_by_ten_big(s21_big_decimal *a,
                                           s21_big_decimal *b);

#endif