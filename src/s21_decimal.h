#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BITS 31
#define DIVIDER 32
#define MIN_INT -2147483648  //-2147483648
#define MAX_INT 2147483647   // 2147483647
#define MAX_DEC 79228162514264337593543950335.0f
#define MAX_FLOAT 3.4E+38
#define MIN_FLOAT 3.4E-38
#define BREAK_EXP 9999
#define MASK_SCALE 255  // 00000000 11111111 00000000 00000000
#define MASK_ZERO 0     // 00000000 00000000 00000000 00000000

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[8];
} s21_big_decimal;

#include "arithmetic/s21_arithmetic.h"
#include "basic/s21_basic.h"
#include "comparison/s21_comparison.h"
#include "convertors/s21_convertors.h"
#include "other/s21_other.h"

#endif
