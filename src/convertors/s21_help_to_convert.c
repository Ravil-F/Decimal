#include "s21_convertors.h"

int s21_chek_float_number_zero(float *src) {
  return *src != 0.0 && *src != -0.0;
}

int s21_body_check_manage_bit(s21_decimal *number, int bit_s, int bit_f) {
  int status = 1, mask = 1;
  for (int i = bit_s; i <= bit_f && status != 0; i++) {
    if (number->bits[3] & (mask << i)) {
      status = 0;
    }
  }
  return status;
}

int s21_check_dec_scale(s21_decimal *number) {
  int status = 0, scale = s21_get_scale(number);
  if (scale >= 0 && scale <= 28) {
    status = 1;
  }
  return status;
}

int s21_check_decimal_nubmer(s21_decimal *number) {
  int status = 0;
  if (s21_body_check_manage_bit(number, 0, 15) &&
      s21_body_check_manage_bit(number, 24, 30) &&
      s21_check_dec_scale(number)) {
    status = 1;
  }
  return status;
}

int s21_check_float_nubmer(float *src) {
  float temp_src = fabs(*src);
  return isnan((*src)) || isinf((*src)) || temp_src >= MAX_DEC ||
         (temp_src > 0 && temp_src < 1e-28) || temp_src < MIN_FLOAT ||
         temp_src > MAX_FLOAT;
}

int s21_float_zero_in_decimal(s21_decimal *result, float *src) {
  int status = 0;
  char number[10];
  sprintf(number, "%+.6f", *src);
  s21_set_null_decimal(result);
  if (number[0] == '-') {
    s21_set_sign(result, 1);
  }
  return status;
}

int s21_help_convert_decimal_to_int(s21_decimal *value, int **dst, int *sign) {
  int flag = 0;
  if (((*dst) != NULL) && s21_check_decimal_nubmer(value)) {
    *sign = s21_get_sign(value);
    s21_decimal result, remainder;
    s21_set_null_decimal(&result);
    result = s21_dec_div_ten_degre(value, &remainder);
    flag = s21_comp_dec_with_maxint(&result, sign);
    if (flag == 0) {
      *value = result;
    }
  } else {
    flag = 1;
  }
  return flag;
}

int s21_fnd_pos_fisrt_bit(s21_decimal *value) {
  int pos = -1;
  for (int i = 96, mask = 1; i >= 0 && pos != i; i--) {
    int array = i / 32, elem = i % 32;
    if (value->bits[array] & (mask << elem)) {
      pos = i;
    }
  }
  return pos;
}

int s21_convert_dec_bits_to_fnumber(s21_decimal *value, float *dst) {
  double temp = 0;
  for (int i = 0, mask = 1; i <= 96; i++) {
    int array = i / 32, elem = i % 32;
    if (value->bits[array] & (mask << elem)) {
      temp += pow(2.0, i);
    }
  }
  temp /= pow(10.0, s21_get_scale(value));
  *dst = (float)temp;
  return 0;
}

int s21_help_convert_decimal_to_float(s21_decimal *value, float *dst) {
  int status = 0;
  int sign = s21_get_sign(value), pos = s21_fnd_pos_fisrt_bit(value);
  if (sign == 1) {
    sign = -1;
  } else {
    sign = 1;
  }
  s21_decimal tmp = *value;
  if ((pos >= 0 && pos <= 96)) {  // pos<=32 pos>32
    s21_convert_dec_bits_to_fnumber(&tmp, dst);
  } else if (pos == -1) {
    *dst = 0.0;
  } else {
    status = 1;
  }
  *dst *= sign;
  return status;
}

int s21_def_exp_and_number(float src, s21_decimal *result) {
  char number[100] = "";
  int accuracy = 6, flag = 0, true_scale = 0, scale = 0;
  sprintf(number, "%.*e", accuracy, src);
  s21_check_end_zero(number, &src, &accuracy);
  if (s21_fnd_scale(number, &accuracy, &scale, &true_scale) == 0) {
    int res = s21_convert_from_char_to_int(number, &accuracy);
    s21_from_int_to_decimal(res, result);
    if (scale > 0) {
      flag = s21_dec_mull_ten(result, scale);
    }
    if (flag == 0) {
      s21_enter_scale(&result->bits[3], true_scale);
    }
  }
  return flag;
}

int s21_convert_exp_string_for_int(char *number, int *e, int *sign) {
  int flag = 0;
  char *e_ptr = strchr(number, 'e');
  if (e_ptr != NULL) {
    (*e) = atoi(e_ptr + 2);
    (*sign) = *(e_ptr + 1) == '-' ? 1 : 0;
  } else {
    flag = 1;
  }
  return flag;
}

int s21_calc_scale(int *e, int *sign, int *scale, int *t_scale, int *acc) {
  int status = 0;
  if (*sign == 0) {
    *scale = *e - *acc;
    if (*scale <= 0) {
      *t_scale = *scale;
    }
  } else if (*sign) {
    *t_scale = *e + *acc;
  }
  *t_scale = abs(*t_scale);
  return status;
}

int s21_fnd_scale(char *number, int *acc, int *scale, int *t_scale) {
  int flag = 0, e = 0, sign = 0;
  if (s21_convert_exp_string_for_int(number, &e, &sign) == 0) {
    s21_calc_scale(&e, &sign, scale, t_scale, acc);
  } else {
    flag = 1;
  }
  return flag;
}

void s21_check_end_zero(char *num, float *src, int *acc) {
  char *e_ptr = strchr(num, 'e');
  if (e_ptr != NULL) {
    int i = 0;
    for (; *(e_ptr - (i + 1)) != '.' && isdigit(*(e_ptr - (i + 1))) &&
           *(e_ptr - (i + 1)) == '0';
         i++) {
      ;
    }
    int exp = (*acc) - i;
    if (exp >= 1) {
      sprintf(num, "%.*e", exp, *src);
    }
    *acc = exp;
  }
}

int s21_convert_from_char_to_int(char *num, int *accuracy) {
  int res = 0;
  char *e_ptr = strchr(num, 'e');
  if (e_ptr != NULL) {
    if ((*accuracy) == 0) {
      res = (*(e_ptr - 8) - 48);
    } else {
      for (int i = 0; i < *accuracy + 1; i++) {
        float tmp = pow(10.0, i);
        if (*(e_ptr - (i + 1)) != '.' && isdigit(*(e_ptr - (i + 1)))) {
          res += (*(e_ptr - (i + 1)) - 48) * tmp;
        } else if (*(e_ptr - (i + 1)) == '.') {
          res += (*(e_ptr - (i + 2)) - 48) * tmp;
        }
      }
    }
  }
  return res;
}

int s21_enter_scale(uint32_t *value, int t_scale) {
  int flag = 0;
  if (t_scale <= -1 || t_scale > 28)
    flag = 1;
  else {
    *value |= t_scale << 16;
  }
  return flag;
}

int s21_comp_dec_with_maxint(s21_decimal *value, int *sign) {
  int flag = 0;
  int mask = 1;
  for (int i = 2, j = 31; i >= 0 && flag != 1; j--) {
    int tmp = (value->bits[i] & (mask << j)) ? 1 : 0;
    if ((i > 0 && tmp == 1) || (*sign == 0 && i == 0 && j == 31 && tmp == 1)) {
      flag = 1;
    }
    if (j == 0) {
      j = 32;
      i--;
    }
  }
  if (flag == 0) {
    long int tmp = value->bits[0];
    int sign = s21_get_sign(value);
    if (sign) tmp *= -1;
    flag = !(tmp >= INT32_MIN && tmp <= INT32_MAX);
  }
  return flag;
}

int s21_compare_decimal_for_div_by_ten(s21_decimal *a, s21_decimal *b) {
  int result = s21_is_equal(*a, *b);
  if (result == 1) {
    result = 1;
  } else if ((result = s21_is_greater(*a, *b)) == 1) {
    result = 2;
  } else {
    result = 0;
  }
  return result;
}
