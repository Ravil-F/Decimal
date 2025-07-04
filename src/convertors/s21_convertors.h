#ifndef S21_CONVERTORS_H
#define S21_CONVERTORS_H

#include "../s21_decimal.h"

int s21_neg_check(int *i, s21_decimal *dst);
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
int s21_check_float_nubmer(float *src);
int s21_chek_float_number_zero(float *src);
int s21_help_convert_decimal_to_int(s21_decimal *value, int **dst, int *sign);
int s21_help_convert_decimal_to_float(s21_decimal *value, float *dst);
int s21_check_decimal_nubmer(s21_decimal *number);
int s21_body_check_manage_bit(s21_decimal *number, int bit_s, int bit_f);
int s21_check_dec_scale(s21_decimal *number);
int s21_def_exp_and_number(float src, s21_decimal *result);
void s21_check_end_zero(char *num, float *src, int *acc);
int s21_convert_from_char_to_int(char *num, int *accuracy);
int s21_fnd_scale(char *number, int *acc, int *scale, int *t_scale);
int s21_convert_exp_string_for_int(char *number, int *e, int *sign);
int s21_enter_scale(uint32_t *value, int t_scale);
int s21_float_zero_in_decimal(s21_decimal *result, float *src);
int s21_comp_dec_with_maxint(s21_decimal *value, int *sign);
int s21_compare_decimal_for_div_by_ten(s21_decimal *a, s21_decimal *b);

#endif
