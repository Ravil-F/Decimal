#ifndef S21_ARITHMETIC_H
#define S21_ARITHMETIC_H

#include "../s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_add_helper(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *result);
void s21_add_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2,
                         s21_big_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub_helper(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *result);
void s21_sub_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2,
                         s21_big_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul_helper(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *result);
int s21_mul_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2,
                        s21_big_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div_helper(s21_big_decimal value_1, s21_big_decimal value_2,
                   s21_big_decimal *result, s21_big_decimal *big_remainder);
int s21_handle_remainder(s21_big_decimal big_remainder,
                         s21_big_decimal big_value_2, int *scale,
                         s21_big_decimal *result);
int s21_div_big_decimal(s21_big_decimal big_value_1,
                        s21_big_decimal big_value_2,
                        s21_big_decimal *big_result);

#endif  // S21_ARITHMETIC_H