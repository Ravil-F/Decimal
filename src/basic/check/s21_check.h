#ifndef S21_CHECK
#define S21_CHECK

#include "../s21_basic.h"

int s21_check_zero(s21_decimal *value_1, s21_decimal *value_2);
int s21_big_check_scale(s21_big_decimal *big_value_1,
                        s21_big_decimal *big_value_2);
int s21_big_check_mantisa(s21_big_decimal *big_value_1,
                          s21_big_decimal *big_value_2);
int s21_big_check_sign(s21_big_decimal *big_value_1,
                       s21_big_decimal *big_value_2);
int s21_big_check_zero(s21_big_decimal *big_value_1,
                       s21_big_decimal *big_value_2);
int s21_zero(s21_decimal *value);
int s21_big_zero(s21_big_decimal *big_value);

int s21_error_scale(s21_decimal *value);
int s21_3rd_bit_error(s21_decimal *value);
int s21_error(s21_decimal *value);

#endif