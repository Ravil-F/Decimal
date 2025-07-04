#ifndef S21_BASIC
#define S21_BASIC

#include "../s21_decimal.h"
#include "check/s21_check.h"
#include "common_denominator/s21_com_denom.h"

int s21_get_sign(s21_decimal *value);
void s21_set_sign(s21_decimal *value, int sign_value);
int s21_get_scale(s21_decimal *value);
void s21_set_scale(s21_decimal *value, int scale_value);
int s21_get_bit(s21_decimal *value, int num);
void s21_set_bit(s21_decimal *value, int num, unsigned bit);
int s21_big_get_bit(s21_big_decimal *big_value, int num);
void s21_big_set_bit(s21_big_decimal *big_value, int num, unsigned bit);
int s21_big_get_scale(s21_big_decimal *big_value);
void s21_big_set_scale(s21_big_decimal *big_value, int scale_value);
int s21_big_get_sign(s21_big_decimal *big_value);
void s21_big_set_sign(s21_big_decimal *big_value, int sign_value);
void s21_decimal_to_big_decimal(s21_big_decimal *big_value, s21_decimal *value);
int s21_big_decimal_to_decimal(s21_big_decimal *big_value, s21_decimal *value);
void s21_big_shift_left(s21_big_decimal *bs21_is_decimal_not_emptyig_value,
                        int shift_value);
void s21_set_null_big_decimal(s21_big_decimal *decimal);
void s21_set_null_decimal(s21_decimal *decimal);
void s21_shift_big_dec_right(s21_big_decimal *value, int num);
int s21_temp_shift_l(s21_decimal *result);
int s21_help_shift_l(s21_decimal *res, int bit, int f);
void s21_big_set_7_bit_to_null(s21_big_decimal *value_1,
                               s21_big_decimal *value_2);
void s21_body_div_by_ten_big_decimal(s21_big_decimal *value);
int s21_set_status(s21_big_decimal *value, int scale);
void s21_big_result_normalize(s21_big_decimal *value, int *scale);

#endif