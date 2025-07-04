#define _GNU_SOURSE
#include "s21_decimal.h"

#include <check.h>

#define F_BIG 22
#define F_SMAL 13
#define ERROR 1
#define SUCCSES 0

int s21_check_decimal(s21_decimal *v_first, s21_decimal *v_seconde) {
  int flag = 0;
  for (int i = 0; i < 4; i++) {
    if (v_first->bits[i] != v_seconde->bits[i]) {
      flag = 1;
      break;
    }
  }
  return flag;
}
int s21_random_int_number(int iteration) {
  int i = 0;
  do {
    s21_decimal test;
    int j = (rand() + 1) % INT32_MAX;
    if (rand() % 2 == 1) {
      j *= -1;
    }
    ck_assert_int_eq(s21_from_int_to_decimal(j, &test), 0);
  } while ((i++) < iteration);
  return 0;
}
START_TEST(s21_int_to_decimal) {
  {
    s21_decimal test = {0};
    s21_decimal check = {.bits = {[0] = 0b00000000000000000000000000000000,
                                  [1] = 0b00000000000000000000000000000000,
                                  [2] = 0b00000000000000000000000000000000,
                                  [3] = 0b00000000000000000000000000000000}};
    int i = 0;
    int res = s21_from_int_to_decimal(i, &test);
    ck_assert_int_eq(res, 0);
    if (res == 0) {
      ck_assert_int_eq(s21_check_decimal(&test, &check), 0);
    }
  }
  {
    s21_decimal test = {0};
    s21_decimal check = {.bits = {[0] = 0b00000000000000000000000000000001,
                                  [1] = 0b00000000000000000000000000000000,
                                  [2] = 0b00000000000000000000000000000000,
                                  [3] = 0b00000000000000000000000000000000}};
    int i = 1;
    int res = s21_from_int_to_decimal(i, &test);
    ck_assert_int_eq(res, 0);
    if (res == 0) {
      ck_assert_int_eq(s21_check_decimal(&test, &check), 0);
    }
  }
  {
    s21_decimal test = {0};
    s21_decimal check = {.bits = {[0] = 0b00000000000000000001000011000110,
                                  [1] = 0b00000000000000000000000000000000,
                                  [2] = 0b00000000000000000000000000000000,
                                  [3] = 0b00000000000000000000000000000000}};
    int i = 4294;
    int res = s21_from_int_to_decimal(i, &test);
    ck_assert_int_eq(res, 0);
    if (res == 0) {
      ck_assert_int_eq(s21_check_decimal(&test, &check), 0);
    }
  }
  {
    s21_decimal test = {0};
    s21_decimal check = {.bits = {[0] = 0b1001001100101100000001011011010,
                                  [1] = 0b00000000000000000000000000000000,
                                  [2] = 0b00000000000000000000000000000000,
                                  [3] = 0b00000000000000000000000000000000}};
    int i = 1234567898;
    int res = s21_from_int_to_decimal(i, &test);
    ck_assert_int_eq(res, 0);
    if (res == 0) {
      ck_assert_int_eq(s21_check_decimal(&test, &check), 0);
    }
  }
  {
    s21_decimal test = {0};
    s21_decimal check = {.bits = {[0] = 0b01111111111111111111111111111111,
                                  [1] = 0b00000000000000000000000000000000,
                                  [2] = 0b00000000000000000000000000000000,
                                  [3] = 0b00000000000000000000000000000000}};
    int i = MAX_INT;
    int res = s21_from_int_to_decimal(i, &test);
    ck_assert_int_eq(res, 0);
    if (res == 0) {
      ck_assert_int_eq(s21_check_decimal(&test, &check), 0);
    }
  }

  {
    s21_decimal test = {0};
    s21_decimal check = {.bits = {[0] = 0b00000000000000000000000000000000,
                                  [1] = 0b00000000000000000000000000000000,
                                  [2] = 0b00000000000000000000000000000000,
                                  [3] = 0b00000000000000000000000000000000}};
    int i = 0;
    int res = s21_from_int_to_decimal(i, &test);
    ck_assert_int_eq(res, 0);
    if (res == 0) {
      ck_assert_int_eq(s21_check_decimal(&test, &check), 0);
    }
  }
  { s21_random_int_number(10); }
}
END_TEST
START_TEST(s21_int_to_decimal_negative) {
  {
    s21_decimal test = {0};
    s21_decimal check = {.bits = {[0] = 0b00000000000000000000000000000000,
                                  [1] = 0b00000000000000000000000000000000,
                                  [2] = 0b00000000000000000000000000000000,
                                  [3] = 0b00000000000000000000000000000000}};
    int i = -0;
    int res = s21_from_int_to_decimal(i, &test);
    ck_assert_int_eq(res, 0);
    if (res == 0) {
      ck_assert_int_eq(s21_check_decimal(&test, &check), 0);
    }
  }
  {
    s21_decimal test = {0};
    s21_decimal check = {.bits = {[0] = 0b00000000000000000000000000000001,
                                  [1] = 0b00000000000000000000000000000000,
                                  [2] = 0b00000000000000000000000000000000,
                                  [3] = 0b10000000000000000000000000000000}};
    int i = -1;
    int res = s21_from_int_to_decimal(i, &test);
    ck_assert_int_eq(res, 0);
    if (res == 0) {
      ck_assert_int_eq(s21_check_decimal(&test, &check), 0);
    }
  }
  {
    s21_decimal test = {0};
    s21_decimal check = {.bits = {[0] = 0b1001001100101100000001011011010,
                                  [1] = 0b00000000000000000000000000000000,
                                  [2] = 0b00000000000000000000000000000000,
                                  [3] = 0b10000000000000000000000000000000}};
    int i = -1234567898;
    int res = s21_from_int_to_decimal(i, &test);
    ck_assert_int_eq(res, 0);
    if (res == 0) {
      ck_assert_int_eq(s21_check_decimal(&test, &check), 0);
    }
  }
  {
    s21_decimal test = {0};
    s21_decimal check = {.bits = {[0] = 0b00000000000000000001000011000110,
                                  [1] = 0b00000000000000000000000000000000,
                                  [2] = 0b00000000000000000000000000000000,
                                  [3] = 0b10000000000000000000000000000000}};
    int i = -4294;
    int res = s21_from_int_to_decimal(i, &test);
    ck_assert_int_eq(res, 0);
    if (res == 0) {
      ck_assert_int_eq(s21_check_decimal(&test, &check), 0);
    }
  }
  {
    s21_decimal test = {0};
    s21_decimal check = {.bits = {[0] = 0b10000000000000000000000000000000,
                                  [1] = 0b00000000000000000000000000000000,
                                  [2] = 0b00000000000000000000000000000000,
                                  [3] = 0b10000000000000000000000000000000}};
    int i = MIN_INT;
    int res = s21_from_int_to_decimal(i, &test);
    ck_assert_int_eq(res, 0);
    if (res == 0) {
      ck_assert_int_eq(s21_check_decimal(&test, &check), 0);
    }
  }
}
END_TEST
START_TEST(s21_float_to_decimal) {
  {
    s21_decimal test = {.bits = {[0] = 0b00000000000000000000000000000000,
                                 [1] = 0b00000000000000000000000000000000,
                                 [2] = 0b00000000000000000000000000000000,
                                 [3] = 0b00000000000000000000000000000000}};
    s21_decimal check = {.bits = {[0] = 0b00000000000100101101011010001000,
                                  [1] = 0b00000000000000000000000000000000,
                                  [2] = 0b00000000000000000000000000000000,
                                  [3] = 0b00000000000001100000000000000000}};
    float i = 1.2345678001;
    int res = s21_from_float_to_decimal(i, &test);
    ck_assert_int_eq(res, 0);
    if (res == 0) {
      ck_assert_int_eq(s21_check_decimal(&test, &check), 0);
    }
  }
  {
    s21_decimal test = {.bits = {[0] = 0b00000000000000000000000000000000,
                                 [1] = 0b00000000000000000000000000000000,
                                 [2] = 0b00000000000000000000000000000000,
                                 [3] = 0b00000000000000000000000000000000}};

    s21_decimal check = {.bits = {[0] = 0b00000000100101111100010011101001,
                                  [1] = 0b00000000000000000000000000000000,
                                  [2] = 0b00000000000000000000000000000000,
                                  [3] = 0b00000000000010100000000000000000}};
    float i = 0.00099463450000;
    int res = s21_from_float_to_decimal(i, &test);
    ck_assert_int_eq(res, 0);
    if (res == 0) {
      ck_assert_int_eq(s21_check_decimal(&test, &check), 0);
    }
  }
  {
    s21_decimal test = {.bits = {[0] = 0b00000000000000000000000000000000,
                                 [1] = 0b00000000000000000000000000000000,
                                 [2] = 0b00000000000000000000000000000000,
                                 [3] = 0b00000000000000000000000000000000}};

    s21_decimal check = {.bits = {[0] = 0b00000000100100000101000011010000,
                                  [1] = 0b00000000000000000000000000000000,
                                  [2] = 0b00000000000000000000000000000000,
                                  [3] = 0b00000000000000000000000000000000}};
    s21_set_scale(&check, 14);
    float i = 0.0000000945787212;
    int res = s21_from_float_to_decimal(i, &test);
    ck_assert_int_eq(res, 0);
    if (res == 0) {
      ck_assert_int_eq(s21_check_decimal(&test, &check), 0);
    }
  }
}
END_TEST
START_TEST(s21_dec_to_float) {
  {
    s21_decimal value = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x190000}};
    float res = 2099.5463;
    float dst = 0;
    s21_from_decimal_to_float(value, &dst);
    ck_assert_int_eq(s21_from_decimal_to_float(value, &dst), 0);
    ck_assert_float_eq(dst, res);
  }

  {
    s21_decimal value = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x1A0000}};
    float res = 209.95463;
    float dst = 0;
    s21_from_decimal_to_float(value, &dst);
    ck_assert_int_eq(s21_from_decimal_to_float(value, &dst), 0);
    ck_assert_float_eq(dst, res);
  }

  {
    s21_decimal value = {{1289, 0, 0, 0}};
    float res = 1289.0;
    float dst = 0;
    ck_assert_int_eq(s21_from_decimal_to_float(value, &dst), 0);
    ck_assert_float_eq(dst, res);
  }
  {
    s21_decimal value = {{1289, 0, 0, 0}};
    s21_set_scale(&value, 1);
    float res = 128.9;
    float dst = 0;
    ck_assert_int_eq(s21_from_decimal_to_float(value, &dst), 0);
    ck_assert_float_eq(dst, res);
  }
  {
    s21_decimal value = {{1289, 0, 0, 0}};
    s21_set_scale(&value, 2);
    float res = 12.89;
    float dst = 0;
    ck_assert_int_eq(s21_from_decimal_to_float(value, &dst), 0);
    ck_assert_float_eq(dst, res);
  }
  {
    s21_decimal value = {{1289, 0, 0, 0}};
    s21_set_scale(&value, 3);
    float res = 1.289;
    float dst = 0;
    ck_assert_int_eq(s21_from_decimal_to_float(value, &dst), 0);
    ck_assert_float_eq(dst, res);
  }
  {
    s21_decimal value = {{1289, 0, 0, 0}};
    s21_set_scale(&value, 4);
    float res = 0.1289;
    float dst = 0;
    ck_assert_int_eq(s21_from_decimal_to_float(value, &dst), 0);
    ck_assert_float_eq(dst, res);
  }
  {
    s21_decimal value = {{1289, 0, 0, 0}};
    s21_set_scale(&value, 5);
    float res = 0.01289;
    float dst = 0;
    ck_assert_int_eq(s21_from_decimal_to_float(value, &dst), 0);
    ck_assert_float_eq(dst, res);
  }
  {
    s21_decimal value = {{1289, 0, 0, 0}};
    s21_set_scale(&value, 6);
    float res = 0.001289;
    float dst = 0;
    ck_assert_int_eq(s21_from_decimal_to_float(value, &dst), 0);
    ck_assert_float_eq(dst, res);
  }
  {
    s21_decimal value = {{1289, 0, 0, 0}};
    s21_set_scale(&value, 7);
    float res = 0.0001289;
    float dst = 0;
    ck_assert_int_eq(s21_from_decimal_to_float(value, &dst), 0);
    ck_assert_float_eq(dst, res);
  }
  {
    s21_decimal value = {{1289, 0, 0, 0}};
    s21_set_scale(&value, 15);
    float res = 0.000000000001289;
    float dst = 0;
    ck_assert_int_eq(s21_from_decimal_to_float(value, &dst), 0);
    ck_assert_float_eq(dst, res);
  }
  {
    s21_decimal value = {{1289, 0, 0, 0}};
    s21_set_scale(&value, 28);
    float res = 0.0000000000000000000000001289;
    float dst = 0;
    ck_assert_int_eq(s21_from_decimal_to_float(value, &dst), 0);
    ck_assert_float_eq(dst, res);
  }
}
END_TEST
START_TEST(s21_dec_to_float_negative) {}
END_TEST
START_TEST(s21_failed_tests) {
  // INT
  { ck_assert_int_eq(s21_from_int_to_decimal(1, NULL), 1); }
  // END INT

  // FLOAT
  {
    static const float fails_big[F_BIG] = {
        340282346638528859811704183484516925440.f,
        340282326356119256160033759537265639424.f,
        340282306073709652508363335590014353408.f,
        170141173319264429905852091742258462720.f,
        226854897759019239874469455656344616960.f,
        283568632339978851668922031544056414208.f,
        85070586659632214952926045871129231360.f,
        85070591730234615865843651857942052864.f,
        5316911666227013434557877866945576960.f,
        2658455991569831745807614120560689152.f,
        20769186196199271228741710417756160.f,
        10384593717069655257060992658440192.f,
        158456325028528675187087900672.0f,
        158456315583795709447797473280.0f,
        158456306139062743708507045888.0f,
        316912631167591418895594946560.f,
        158456325028528675187087900672.f,
        79228190848463234811415232512.f,
        79228181403730269072124805120.f,
        79228171958997303332834377728.f,
        79228162514264337593543950336.f,
        79228162514264337593543950335.f,
    };
    for (int i = 0; i < F_BIG; i++) {
      s21_decimal test;
      float j = fails_big[i];

      ck_assert_int_eq(s21_from_float_to_decimal(j, &test), 1);
    }
  }

  {  // SMALL FLOAT
    static const float fails_small[F_SMAL] = {
        0.00000000000000000000000000009999999429857660888699309391359540480357727713304344f,
        0.00000000000000000000000000009999998828004553267688105311366433422567940670147579f,
        0.00000000000000000000000000009999998226151445646676901231373326364778153626990814f,
        0.00000000000000000000000000009000000028539691658739462124217382784332763280814999f,
        0.00000000000000000000000000005000000015855384254855256735676323769073757378230555f,
        0.00000000000000000000000000004999999714928830444349654695679770240178863856652172f,
        4.999999414002276633844052655683216711283970335073789659219301029224880039691925048828125E-29f,
        1.2621774483536188886587657044524579674771302961744368076324462890625E-29f,
        1.0000000031710768509710513471352647538147514756461109453056224083411507308483123779296875E-29f,
        7.7037193183714626222678539700519994217126886949453196668630670929101000865557580254971981E-34f,
        4.8148245739821641389174087312824996385704304343408247917894169330688125540973487659357488E-35f,
        1.1754943508222875079687365372222456778186655567720875215087517062784172594547271728515625E-38f,
        1.4012984643248170709237295832899161312802619418765157717570682838897910826858606014866381E-45f,
    };
    for (int i = 0; i < F_SMAL; i++) {
      s21_decimal test;
      float j = fails_small[i];
      // printf("i is %d !%lf!\n",i,j);
      ck_assert_int_eq(s21_from_float_to_decimal(j, &test), 1);
    }
  }
  {
    s21_decimal test;
    float i = MAX_FLOAT - 1;
    ck_assert_int_eq(s21_from_float_to_decimal(i, &test), 1);
  }
  { ck_assert_int_eq(s21_from_float_to_decimal(1, NULL), 1); }
  {
    float f = -NAN;
    s21_decimal result;

    int code = s21_from_float_to_decimal(f, &result);
    ck_assert_int_eq(code, ERROR);
  }
  {
    s21_decimal test;
    float i = NAN;
    ck_assert_int_eq(s21_from_float_to_decimal(i, &test), 1);
  }
  {
    s21_decimal test;
    float i = INFINITY;
    ck_assert_int_eq(s21_from_float_to_decimal(i, &test), 1);
  }
  {
    s21_decimal test;
    float i = -INFINITY;
    ck_assert_int_eq(s21_from_float_to_decimal(i, &test), 1);
  }
  {
    s21_decimal test;
    float i = 0.000000000000000000000000000000000123566;
    ck_assert_int_eq(s21_from_float_to_decimal(i, &test), 1);
  }
  {
    s21_decimal test;
    float i = 89228162514264337593543950335.9f;
    ck_assert_int_eq(s21_from_float_to_decimal(i, &test), 1);
  }
  {
    s21_decimal test;
    float i = 792281625142643375935439503358.9f;
    ck_assert_int_eq(s21_from_float_to_decimal(i, &test), 1);
  }
  {
    s21_decimal test;
    float i = 1e-29;
    ck_assert_int_eq(s21_from_float_to_decimal(i, &test), 1);
  }
  {
    float f = 0.0;
    s21_decimal result;
    s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};

    int code = s21_from_float_to_decimal(f, &result);

    ck_assert_int_eq(code, SUCCSES);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
  }
  {
    float f = -0.0;
    s21_decimal result;
    s21_decimal check = {{0x0, 0x0, 0x0, 0x80000000}};

    int code = s21_from_float_to_decimal(f, &result);

    ck_assert_int_eq(code, SUCCSES);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
  }
  // END FLOAT

  // DECIMAL TO IN

  {
    s21_decimal test = {.bits = {[0] = 0b1111111111111111111111111111111,
                                 [1] = 0b00000000000000000000000000000001,
                                 [2] = 0b00000000000000000000000000000000,
                                 [3] = 0b00000000000000000000000000000000}};
    int check = 0, res_test = 0;
    ck_assert_int_eq(s21_from_decimal_to_int(test, &res_test), 1);
    ck_assert_int_eq(check, res_test);
  }
  {
    s21_decimal test = {.bits = {[0] = 0b1111111111111111111111111111111,
                                 [1] = 0b00000000000000000000000000000000,
                                 [2] = 0b10000000000000000000000000000000,
                                 [3] = 0b00000000000000000000000000000000}};
    int res_test = 0;
    ck_assert_int_eq(s21_from_decimal_to_int(test, &res_test), 1);
  }
  {
    s21_decimal test = {.bits = {[0] = 0b1111111111111111111111111111111,
                                 [1] = 0b00000000000000000000000000000000,
                                 [2] = 0b10000000000000000000000000000000,
                                 [3] = 0b00000000000000000000000000000000}};
    ck_assert_int_eq(s21_from_decimal_to_int(test, NULL), 1);
  }
  {
    s21_decimal test = {.bits = {[0] = 0b11000000000000000000000000000000,
                                 [1] = 0b00000000000000000000000000000000,
                                 [2] = 0b00000000000000000000000000000000,
                                 [3] = 0b10000000000000000000000000000000}};
    int res_test;
    ck_assert_int_eq(s21_from_decimal_to_int(test, &res_test), 1);
  }
  {
    s21_decimal test = {.bits = {[0] = 0b10000000000000000000000000000001,
                                 [1] = 0b00000000000000000000000000000000,
                                 [2] = 0b00000000000000000000000000000000,
                                 [3] = 0b10000000000000000000000000000000}};
    int res_test = 0;
    ck_assert_int_eq(s21_from_decimal_to_int(test, &res_test), 1);
  }
  {
    s21_decimal test;
    ck_assert_int_eq(s21_from_decimal_to_int(test, NULL), 1);
  }
  {
    s21_decimal value = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
    int dst = 0;
    ck_assert_int_eq(s21_from_decimal_to_int(value, &dst), 1);
  }
  {
    s21_decimal value = {{-1, 0, 0, 0x11C0000}};
    int dst = 0;
    ck_assert_int_eq(s21_from_decimal_to_int(value, &dst), 1);
  }
  {
    s21_decimal value = {{-1, 0, 0, 0x1C8000}};
    int dst = 0;
    ck_assert_int_eq(s21_from_decimal_to_int(value, &dst), 1);
  }
  {
    s21_decimal value = {{0, 0, 0, 0x1D0000}};
    int dst = 0;
    ck_assert_int_eq(s21_from_decimal_to_int(value, &dst), 1);
  }
  {
    s21_decimal value = {{0, 0, 0, 1000000000}};
    int dst = 0;
    ck_assert_int_eq(s21_from_decimal_to_int(value, &dst), 1);
  }
  {
    s21_decimal value = {{9794567, 867540, 0, 0}};
    int dst = 0;
    ck_assert_int_eq(s21_from_decimal_to_int(value, &dst), 1);
  }
  // END DECIMAL TO INT

  {
    s21_decimal value = {{-1, 0, 0, 0x11C0000}};
    float dst = 0;
    ck_assert_int_eq(s21_from_decimal_to_float(value, &dst), 1);
  }
  {
    s21_decimal value = {{-1, 0, 0, 0x1C8000}};
    float dst = 0;
    ck_assert_int_eq(s21_from_decimal_to_float(value, &dst), 1);
  }
  {
    s21_decimal value = {{0, 0, 0, 0x1D0000}};
    float dst = 0;
    ck_assert_int_eq(s21_from_decimal_to_float(value, &dst), 1);
  }
  {
    s21_decimal value = {{0, 0, 0, 1000000000}};
    float dst = 0;
    ck_assert_int_eq(s21_from_decimal_to_float(value, &dst), 1);
  }
}
END_TEST

START_TEST(s21_decimal_to_int) {
  {
    s21_decimal test = {{0x226e073f, 0x88000592, 0x4c9, 0x140000}};
    int check = 226, res_test = 0;
    ck_assert_int_eq(s21_from_decimal_to_int(test, &res_test), 0);
    ck_assert_int_eq(check, res_test);
  }
  {
    s21_decimal test = {.bits = {[0] = 0b0000000000000000000000000000001,
                                 [1] = 0b00000000000000000000000000000000,
                                 [2] = 0b00000000000000000000000000000000,
                                 [3] = 0b00000000000000000000000000000000}};
    int check = 1, res_test = 0;
    ck_assert_int_eq(s21_from_decimal_to_int(test, &res_test), 0);
    ck_assert_int_eq(check, res_test);
  }
  {
    s21_decimal test = {.bits = {[0] = 0b0000000100000000000000000000001,
                                 [1] = 0b00000000000000000000000000000000,
                                 [2] = 0b00000000000000000000000000000000,
                                 [3] = 0b10000000000000000000000000000000}};
    int check = -8388609, res_test = 0;
    ck_assert_int_eq(s21_from_decimal_to_int(test, &res_test), 0);
    ck_assert_int_eq(check, res_test);
  }
  {
    s21_decimal test = {.bits = {[0] = 0b0000000000000000000000000000101,
                                 [1] = 0b00000000000000000000000000000000,
                                 [2] = 0b00000000000000000000000000000000,
                                 [3] = 0b00000000000000000000000000000000}};
    int check = 5, res_test = 0;
    ck_assert_int_eq(s21_from_decimal_to_int(test, &res_test), 0);
    ck_assert_int_eq(check, res_test);
  }
  {
    s21_decimal test = {.bits = {[0] = 0b00000000010000000000000101,
                                 [1] = 0b00000000000000000000000000000000,
                                 [2] = 0b00000000000000000000000000000000,
                                 [3] = 0b00000000000000000000000000000000}};
    int check = 65541, res_test = 0;
    ck_assert_int_eq(s21_from_decimal_to_int(test, &res_test), 0);
    ck_assert_int_eq(check, res_test);
  }
  {
    s21_decimal test = {.bits = {[0] = 0b1000000000000010000000000000101,
                                 [1] = 0b00000000000000000000000000000000,
                                 [2] = 0b00000000000000000000000000000000,
                                 [3] = 0b00000000000000000000000000000000}};
    int check = 1073807365, res_test = 0;
    ck_assert_int_eq(s21_from_decimal_to_int(test, &res_test), 0);
    ck_assert_int_eq(check, res_test);
  }
  {
    s21_decimal test = {.bits = {[0] = 0b1000000000000010000000000000101,
                                 [1] = 0b00000000000000000000000000000000,
                                 [2] = 0b00000000000000000000000000000000,
                                 [3] = 0b10000000000000000000000000000000}};
    int check = -1073807365, res_test = 0;
    ck_assert_int_eq(s21_from_decimal_to_int(test, &res_test), 0);
    ck_assert_int_eq(check, res_test);
  }
  {
    s21_decimal test = {.bits = {[0] = 0b1111111111111111111111111111111,
                                 [1] = 0b00000000000000000000000000000000,
                                 [2] = 0b00000000000000000000000000000000,
                                 [3] = 0b00000000000000000000000000000000}};
    int check = 2147483647, res_test = 0;
    ck_assert_int_eq(s21_from_decimal_to_int(test, &res_test), 0);
    ck_assert_int_eq(check, res_test);
  }
  {
    s21_decimal test = {.bits = {[0] = 0b1111111111111111111111111111111,
                                 [1] = 0b00000000000000000000000000000000,
                                 [2] = 0b00000000000000000000000000000000,
                                 [3] = 0b10000000000000000000000000000000}};
    int check = -2147483647, res_test = 0;
    ck_assert_int_eq(s21_from_decimal_to_int(test, &res_test), 0);
    ck_assert_int_eq(check, res_test);
  }
  {
    s21_decimal test = {.bits = {[0] = 0b10000000000000000000000000000000,
                                 [1] = 0b00000000000000000000000000000000,
                                 [2] = 0b00000000000000000000000000000000,
                                 [3] = 0b10000000000000000000000000000000}};
    int check = -2147483648, res_test = 0;
    ck_assert_int_eq(s21_from_decimal_to_int(test, &res_test), 0);
    ck_assert_int_eq(check, res_test);
  }
  {
    s21_decimal test = {.bits = {[0] = 0b10000000000000000000000000000000,
                                 [1] = 0b00000000000000000000000000000000,
                                 [2] = 0b00000000000000000000000000000000,
                                 [3] = 0b00000000000000000000000000000000}};
    int check = 21474, res_test = 0;
    s21_set_scale(&test, 5);
    ck_assert_int_eq(s21_from_decimal_to_int(test, &res_test), 0);
    ck_assert_int_eq(check, res_test);
  }
  {
    s21_decimal test = {.bits = {[0] = 0b00000000000000000000000110100000,
                                 [1] = 0b00000000000000000000000000000000,
                                 [2] = 0b00000000000000000000000000000000,
                                 [3] = 0b00000000000000100000000000000000}};
    int check = 4, res_test = 0;
    ck_assert_int_eq(s21_from_decimal_to_int(test, &res_test), 0);
    ck_assert_int_eq(check, res_test);
  }
  {
    s21_decimal test = {.bits = {[0] = 0b00000000000000000000000110100000,
                                 [1] = 0b00000000000000000000000000000000,
                                 [2] = 0b00000000000000001100000000000000,
                                 [3] = 0b00000000000101110000000000000000}};
    int check = 9, res_test = 0;
    ck_assert_int_eq(s21_from_decimal_to_int(test, &res_test), 0);
    // printf("res is %d\n",res_test);
    ck_assert_int_eq(check, res_test);
  }
  {
    s21_decimal test = {.bits = {[0] = 0b00000000000000000000000110100000,
                                 [1] = 0b00000000000000000000000000000000,
                                 [2] = 0b00000000000000001100000000000000,
                                 [3] = 0b00000000000110000000000000000000}};
    int check = 0, res_test = 0;
    ck_assert_int_eq(s21_from_decimal_to_int(test, &res_test), 0);
    // "res is %d\n",res_test);
    ck_assert_int_eq(check, res_test);
  }
  {
    s21_decimal test = {.bits = {[0] = 0b00000000000000000000000110100000,
                                 [1] = 0b00000000000000000000000000000000,
                                 [2] = 0b00000000000000001100000000000000,
                                 [3] = 0b10000000000101110000000000000000}};
    int check = -9, res_test = 0;
    ck_assert_int_eq(s21_from_decimal_to_int(test, &res_test), 0);
    ck_assert_int_eq(check, res_test);
  }
  {
    s21_decimal test = {.bits = {[0] = 0b00000000000000000000000110000000,
                                 [1] = 0b00000000000100000010000000000000,
                                 [2] = 0b10000000011000001100000000000000,
                                 [3] = 0b10000000000110010000000000000000}};
    int check = -3973, res_test = 0;
    ck_assert_int_eq(s21_from_decimal_to_int(test, &res_test), 0);
    ck_assert_int_eq(check, res_test);
  }
}
END_TEST
START_TEST(s21_decimal_to_int_negative) {
  {
    s21_decimal test = {{0x36f9f0ed, 0x0, 0x0, 0x80000000}};
    int check = -922349805, res_test = 0;
    ck_assert_int_eq(s21_from_decimal_to_int(test, &res_test), 0);
    ck_assert_int_eq(check, res_test);
  }
  {
    s21_decimal test = {{0x862, 0x0, 0x0, 0x80000000}};
    int check = -2146, res_test = 0;
    ck_assert_int_eq(s21_from_decimal_to_int(test, &res_test), 0);
    ck_assert_int_eq(check, res_test);
  }
  {
    s21_decimal test = {
        {0x2772f5e, 0x0, 0x0, [3] = 0b10000000000001000000000000000000}};
    int check = -4136, res_test = 0;
    ck_assert_int_eq(s21_from_decimal_to_int(test, &res_test), 0);
    // s21_print_bits(&test);
    ck_assert_int_eq(check, res_test);
  }
  {
    s21_decimal test = {{0x56, 0x0, 0x0, 0x80000000}};
    int check = -86, res_test = 0;
    ck_assert_int_eq(s21_from_decimal_to_int(test, &res_test), 0);
    // s21_print_bits(&test);
    ck_assert_int_eq(check, res_test);
  }
}
END_TEST

// comparison
START_TEST(s21_is_less_test_1) {
  {  // 0<0
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_less = s21_is_less(a, b);
    ck_assert_uint_eq(0, res_less);
  }

  {  // 10<10
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000010101010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000010101010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_less = s21_is_less(a, b);
    ck_assert_uint_eq(0, res_less);
  }
  {  //-10<10
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000010101010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000010101010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_less = s21_is_less(a, b);
    ck_assert_uint_eq(1, res_less);
  }
  {  // 10<-10
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000010101010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000010101010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};
    int res_less = s21_is_less(a, b);
    ck_assert_uint_eq(0, res_less);
  }
  {  // 0<0
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_less = s21_is_less(a, b);
    ck_assert_uint_eq(0, res_less);
  }
  {  //-0<0
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_less = s21_is_less(a, b);
    ck_assert_uint_eq(0, res_less);
  }
  {  // 2147483648<1073741824
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_less = s21_is_less(a, b);
    ck_assert_uint_eq(0, res_less);
  }
  {  //-63<-65
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000111111,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000001000001,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};
    int res_less = s21_is_less(a, b);
    ck_assert_uint_eq(0, res_less);
  }
  {  // 63<65
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000111111,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000001000001,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_less = s21_is_less(a, b);
    ck_assert_uint_eq(1, res_less);
  }
  {  //-65<-63
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000001000001,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000111111,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};
    int res_less = s21_is_less(a, b);
    ck_assert_uint_eq(1, res_less);
  }
  {  //-63<-63
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000111111,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000111111,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};
    int res_less = s21_is_less(a, b);
    ck_assert_uint_eq(0, res_less);
  }
  {  //-107374<-2147483648
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b01000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b01000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};
    int res_less = s21_is_less(a, b);
    ck_assert_uint_eq(0, res_less);
  }
  {  //
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000001000000000000000,
                              [3] = 0b00000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_less = s21_is_less(a, b);
    ck_assert_uint_eq(0, res_less);
  }
  {  //
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000001000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_less = s21_is_less(a, b);
    ck_assert_uint_eq(1, res_less);
  }

  {  // scale 28
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000111000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000111000000000000000000}};
    int res_less = s21_is_less(a, b);
    ck_assert_uint_eq(0, res_less);
  }
  {  // scale 28 sign 1
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000111000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000111000000000000000000}};
    int res_less = s21_is_less(a, b);
    ck_assert_uint_eq(1, res_less);
  }
  {  // scale 2
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b10000000000000000000000000000000,
                              [3] = 0b10000000000001000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b10000000000000000000000000000000,
                              [3] = 0b10000000000001000000000000000000}};
    int res_less = s21_is_less(a, b);
    ck_assert_uint_eq(0, res_less);
  }
  {  // scale 2 sign 1
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b10000000000000000000000000000000,
                              [3] = 0b00000000000001000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b10000000000000000000000000000000,
                              [3] = 0b10000000000001000000000000000000}};
    int res_less = s21_is_less(a, b);
    ck_assert_uint_eq(0, res_less);
  }
  {  // scale 26/28 sign 1/1
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000110100000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000111000000000000000000}};
    int res_less = s21_is_less(a, b);
    ck_assert_uint_eq(1, res_less);
  }
  {  // scale 28/28 sign 1/1
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000111000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000111000000000000000000}};
    int res_less = s21_is_less(a, b);
    ck_assert_uint_eq(0, res_less);
  }
  {  // scale 28/28 sign 1/0
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000111000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000111000000000000000000}};
    int res_less = s21_is_less(a, b);
    ck_assert_uint_eq(1, res_less);
  }
  {  // 0.02360<0.0236
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000100100111000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000001010000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000011101100,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000001000000000000000000}};
    int res_less = s21_is_less(a, b);
    ck_assert_uint_eq(0, res_less);
  }

  {  //  -1342177280, 0, -0.0236 < -1342177280, 0, -0.02360    scale 4-5
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000011101100,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b01010000000000000000000000000000,
                              [3] = 0b10000000000001000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000100100111000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b01010000000000000000000000000000,
                              [3] = 0b10000000000001010000000000000000}};
    int res_less = s21_is_less(a, b);
    ck_assert_uint_eq(1, res_less);
  }

  {  //  1342177280, 0, 0.0236 < 1342177280, 0, 0.02360    scale 4-5
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000011101100,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b01010000000000000000000000000000,
                              [3] = 0b00000000000001000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000100100111000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b01010000000000000000000000000000,
                              [3] = 0b00000000000001010000000000000000}};
    int res_less = s21_is_less(a, b);
    ck_assert_uint_eq(0, res_less);
  }
}
END_TEST

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

START_TEST(s21_is_greater_test_1) {
  {  // 0>0
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_greater = s21_is_greater(a, b);
    ck_assert_uint_eq(0, res_greater);
  }

  {  // 10>10
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000010101010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000010101010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_greater = s21_is_greater(a, b);
    ck_assert_uint_eq(0, res_greater);
  }
  {  //-10>10
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000010101010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000010101010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_greater = s21_is_greater(a, b);
    ck_assert_uint_eq(0, res_greater);
  }
  {  // 10>-10
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000010101010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000010101010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};
    int res_greater = s21_is_greater(a, b);
    ck_assert_uint_eq(1, res_greater);
  }
  {  // 0>0
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_greater = s21_is_greater(a, b);
    ck_assert_uint_eq(0, res_greater);
  }
  {  //-0<0
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_greater = s21_is_greater(a, b);
    ck_assert_uint_eq(0, res_greater);
  }
  {  // 2147483648>1073741824
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b10000000000000000000000000000000,
                              [3] = 0b0000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b01000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_greater = s21_is_greater(a, b);
    ck_assert_uint_eq(1, res_greater);
  }
  {  //-63>-65
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000111111,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000001000001,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};
    int res_greater = s21_is_greater(a, b);
    ck_assert_uint_eq(1, res_greater);
  }
  {  // 63>65
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000111111,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000001000001,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_greater = s21_is_greater(a, b);
    ck_assert_uint_eq(0, res_greater);
  }
  {  //-65>-63
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000001000001,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000111111,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};
    int res_greater = s21_is_greater(a, b);
    ck_assert_uint_eq(0, res_greater);
  }
  {  //-63>-63
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000111111,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000111111,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};
    int res_greater = s21_is_greater(a, b);
    ck_assert_uint_eq(0, res_greater);
  }
  {  //-107374>-2147483648
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b01000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b10000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};
    int res_greater = s21_is_greater(a, b);
    ck_assert_uint_eq(1, res_greater);
  }
  {  //
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000001000000000000000,
                              [3] = 0b00000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_greater = s21_is_greater(a, b);
    ck_assert_uint_eq(1, res_greater);
  }
  {  //
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000001000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_greater = s21_is_greater(a, b);
    ck_assert_uint_eq(0, res_greater);
  }
  {  // scale 28
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000111000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000111000000000000000000}};
    int res_greater = s21_is_greater(a, b);
    ck_assert_uint_eq(0, res_greater);
  }
  {  // scale 28 sign 1
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000111000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000111000000000000000000}};
    int res_greater = s21_is_greater(a, b);
    ck_assert_uint_eq(0, res_greater);
  }
  {  // scale 2
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b10000000000000000000000000000000,
                              [3] = 0b10000000000001000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b10000000000000000000000000000000,
                              [3] = 0b10000000000001000000000000000000}};
    int res_greater = s21_is_greater(a, b);
    ck_assert_uint_eq(0, res_greater);
  }
  {  // scale 2 sign 1
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b10000000000000000000000000000000,
                              [3] = 0b00000000000001000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b10000000000000000000000000000000,
                              [3] = 0b10000000000001000000000000000000}};
    int res_greater = s21_is_greater(a, b);
    ck_assert_uint_eq(1, res_greater);
  }
  {  // scale 26/28 sign 1/1
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000001101000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000111000000000000000000}};
    int res_greater = s21_is_greater(a, b);
    ck_assert_uint_eq(0, res_greater);
  }
  {  // scale 28/28 sign 1/1
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000111000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000111000000000000000000}};
    int res_greater = s21_is_greater(a, b);
    ck_assert_uint_eq(0, res_greater);
  }
  {  // scale 28/28 sign 1/0
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000111000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000111000000000000000000}};
    int res_greater = s21_is_greater(a, b);
    ck_assert_uint_eq(0, res_greater);
  }
  {  // 0.02360>0.0236
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000100100111000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000001010000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000011101100,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000001000000000000000000}};
    int res_greater = s21_is_greater(a, b);
    ck_assert_uint_eq(0, res_greater);
  }

  {  //  -1342177280, 0, -0.0236 > -1342177280, 0, -0.02360    scale 4-5
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000011101100,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b01010000000000000000000000000000,
                              [3] = 0b10000000000001000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000100100111000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b01010000000000000000000000000000,
                              [3] = 0b10000000000001010000000000000000}};
    int res_greater = s21_is_greater(a, b);
    ck_assert_uint_eq(0, res_greater);
  }

  {  //  1342177280, 0, 0.0236 > 1342177280, 0, 0.02360    scale 4-5
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000011101100,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b01010000000000000000000000000000,
                              [3] = 0b00000000000001000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000100100111000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b01010000000000000000000000000000,
                              [3] = 0b00000000000001010000000000000000}};
    int res_greater = s21_is_greater(a, b);
    ck_assert_uint_eq(1, res_greater);
  }
}
END_TEST

//============================================================================================================

START_TEST(s21_is_equal_test_1) {
  {  // 0=0
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_equal = s21_is_equal(a, b);
    ck_assert_uint_eq(1, res_equal);
  }

  {  // 10=10
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000010101010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000010101010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_equal = s21_is_equal(a, b);
    ck_assert_uint_eq(1, res_equal);
  }
  {  //-10=10
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000010101010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000010101010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_equal = s21_is_equal(a, b);
    ck_assert_uint_eq(0, res_equal);
  }
  {  // 10=-10
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000010101010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000010101010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};
    int res_equal = s21_is_equal(a, b);
    ck_assert_uint_eq(0, res_equal);
  }
  {  // 0=0
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_equal = s21_is_equal(a, b);
    ck_assert_uint_eq(1, res_equal);
  }
  {  //-0=0
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_equal = s21_is_equal(a, b);
    ck_assert_uint_eq(1, res_equal);
  }
  {  // 2147483648=1073741824
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b10000000000000000000000000000000,
                              [3] = 0b0000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b01000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_equal = s21_is_equal(a, b);
    ck_assert_uint_eq(0, res_equal);
  }
  {  //-63=-65
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000111111,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000001000001,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};
    int res_equal = s21_is_equal(a, b);
    ck_assert_uint_eq(0, res_equal);
  }
  {  // 63=65
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000111111,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000001000001,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_equal = s21_is_equal(a, b);
    ck_assert_uint_eq(0, res_equal);
  }
  {  //-65=-63
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000001000001,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000111111,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};
    int res_equal = s21_is_equal(a, b);
    ck_assert_uint_eq(0, res_equal);
  }
  {  //-63=-63
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000111111,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000111111,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};
    int res_equal = s21_is_equal(a, b);
    ck_assert_uint_eq(1, res_equal);
  }
  {  //-107374=-2147483648
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b01000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b10000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};
    int res_equal = s21_is_equal(a, b);
    ck_assert_uint_eq(0, res_equal);
  }
  {  //
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000001000000000000000,
                              [3] = 0b00000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_equal = s21_is_equal(a, b);
    ck_assert_uint_eq(0, res_equal);
  }
  {  //
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000001000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_equal = s21_is_equal(a, b);
    ck_assert_uint_eq(0, res_equal);
  }

  {  // scale 28
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000111000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000111000000000000000000}};
    int res_equal = s21_is_equal(a, b);
    ck_assert_uint_eq(1, res_equal);
  }
  {  // scale 28 sign 1
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000111000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000111000000000000000000}};
    int res_equal = s21_is_equal(a, b);
    ck_assert_uint_eq(0, res_equal);
  }
  {  // scale 2
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b10000000000000000000000000000000,
                              [3] = 0b10000000000001000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b10000000000000000000000000000000,
                              [3] = 0b10000000000001000000000000000000}};
    int res_equal = s21_is_equal(a, b);
    ck_assert_uint_eq(1, res_equal);
  }
  {  // scale 2 sign 1
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b10000000000000000000000000000000,
                              [3] = 0b00000000000001000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b10000000000000000000000000000000,
                              [3] = 0b10000000000001000000000000000000}};
    int res_equal = s21_is_equal(a, b);
    ck_assert_uint_eq(0, res_equal);
  }
  {  // scale 26/28 sign 1/1
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000110100000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000111000000000000000000}};
    int res_equal = s21_is_equal(a, b);
    ck_assert_uint_eq(0, res_equal);
  }
  {  // 0.02360=0.0236
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000100100111000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000001010000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000011101100,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000001000000000000000000}};
    int res_eqaul = s21_is_equal(a, b);
    ck_assert_uint_eq(1, res_eqaul);
  }
  {  // 0.0236=0.02360
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000011101100,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000001000000000000000000}};
    s21_decimal b = {.bits = {[0] = 0b00000000000000000000100100111000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000001010000000000000000}};
    int res_eqaul = s21_is_equal(a, b);
    ck_assert_uint_eq(1, res_eqaul);
  }

  {  //  -1342177280, 0, -0.0236 == -1342177280, 0, -0.02360    scale 4-5
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000011101100,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b01010000000000000000000000000000,
                              [3] = 0b10000000000001000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000100100111000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b01010000000000000000000000000000,
                              [3] = 0b10000000000001010000000000000000}};
    int res = s21_is_equal(a, b);
    ck_assert_uint_eq(0, res);
  }

  {  //  1342177280, 0, 0.0236 == 1342177280, 0, 0.02360    scale 4-5
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000011101100,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b01010000000000000000000000000000,
                              [3] = 0b00000000000001000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000100100111000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b01010000000000000000000000000000,
                              [3] = 0b00000000000001010000000000000000}};
    int res = s21_is_equal(a, b);
    ck_assert_uint_eq(0, res);
  }
}
END_TEST

//!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!

// >< 1
// == 0
START_TEST(s21_is_not_equal_test_1) {
  {  // 0!=0
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res = s21_is_not_equal(a, b);
    ck_assert_uint_eq(0, res);
  }

  {  // 10!=10
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000010101010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000010101010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_not_equal = s21_is_not_equal(a, b);
    ck_assert_uint_eq(0, res_not_equal);
  }
  {  //-10!=10
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000010101010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000010101010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_not_equal = s21_is_not_equal(a, b);
    ck_assert_uint_eq(1, res_not_equal);
  }
  {  // 10!=-10
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000010101010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000010101010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};
    int res_not_equal = s21_is_not_equal(a, b);
    ck_assert_uint_eq(1, res_not_equal);
  }
  {  // 0!=0
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_not_equal = s21_is_not_equal(a, b);
    ck_assert_uint_eq(0, res_not_equal);
  }
  {  //-0!=0
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_not_equal = s21_is_not_equal(a, b);
    ck_assert_uint_eq(0, res_not_equal);
  }
  {  // 2147483648!=1073741824
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b10000000000000000000000000000000,
                              [3] = 0b0000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b01000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_not_equal = s21_is_not_equal(a, b);
    ck_assert_uint_eq(1, res_not_equal);
  }
  {  //-63!=-65
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000111111,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000001000001,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};
    int res_not_equal = s21_is_not_equal(a, b);
    ck_assert_uint_eq(1, res_not_equal);
  }
  {  // 63!=65
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000111111,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000001000001,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_not_equal = s21_is_not_equal(a, b);
    ck_assert_uint_eq(1, res_not_equal);
  }
  {  //-65!=-63
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000001000001,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000111111,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};
    int res_not_equal = s21_is_not_equal(a, b);
    ck_assert_uint_eq(1, res_not_equal);
  }
  {  //-63!=-63
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000111111,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000111111,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};
    int res_not_equal = s21_is_not_equal(a, b);
    ck_assert_uint_eq(0, res_not_equal);
  }
  {  //-107374!=-2147483648
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b01000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b10000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};
    int res_not_equal = s21_is_not_equal(a, b);
    ck_assert_uint_eq(1, res_not_equal);
  }
  {  //
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000001000000000000000,
                              [3] = 0b00000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_not_equal = s21_is_not_equal(a, b);
    ck_assert_uint_eq(1, res_not_equal);
  }
  {  //
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000001000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_not_equal = s21_is_not_equal(a, b);
    ck_assert_uint_eq(1, res_not_equal);
  }

  {  // scale 28
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000111000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000111000000000000000000}};
    int res_not_equal = s21_is_not_equal(a, b);
    ck_assert_uint_eq(0, res_not_equal);
  }
  {  // scale 28 sign 1
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000111000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000111000000000000000000}};
    int res_not_equal = s21_is_not_equal(a, b);
    ck_assert_uint_eq(1, res_not_equal);
  }
  {  // scale 2
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b10000000000000000000000000000000,
                              [3] = 0b10000000000001000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b10000000000000000000000000000000,
                              [3] = 0b10000000000001000000000000000000}};
    int res_not_equal = s21_is_not_equal(a, b);
    ck_assert_uint_eq(0, res_not_equal);
  }
  {  // scale 2 sign 1
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b10000000000000000000000000000000,
                              [3] = 0b00000000000001000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b10000000000000000000000000000000,
                              [3] = 0b10000000000001000000000000000000}};
    int res_not_equal = s21_is_not_equal(a, b);
    ck_assert_uint_eq(1, res_not_equal);
  }
  {  // scale 26/28 sign 1/1
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000110100000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000111000000000000000000}};
    int res_not_equal = s21_is_not_equal(a, b);
    ck_assert_uint_eq(1, res_not_equal);
  }
  {  // 0.02360!=0.0236
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000100100111000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000001010000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000011101100,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000001000000000000000000}};
    int res_not_equal = s21_is_not_equal(a, b);
    ck_assert_uint_eq(0, res_not_equal);
  }
  {  // 0.0236!=0.02360
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000011101100,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000001000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000100100111000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000001010000000000000000}};
    int res_not_equal = s21_is_not_equal(a, b);
    ck_assert_uint_eq(0, res_not_equal);
  }

  {  //  -1342177280, 0, -0.0236 != -1342177280, 0, -0.02360    scale 4-5
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000011101100,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b01010000000000000000000000000000,
                              [3] = 0b10000000000001000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000100100111000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b01010000000000000000000000000000,
                              [3] = 0b10000000000001010000000000000000}};
    int res = s21_is_not_equal(a, b);
    ck_assert_uint_eq(1, res);
  }

  {  //  1342177280, 0, 0.0236 != 1342177280, 0, 0.02360    scale 4-5
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000011101100,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b01010000000000000000000000000000,
                              [3] = 0b00000000000001000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000100100111000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b01010000000000000000000000000000,
                              [3] = 0b00000000000001010000000000000000}};
    int res = s21_is_not_equal(a, b);
    ck_assert_uint_eq(1, res);
  }
}
END_TEST

//<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=

START_TEST(s21_is_less_or_equal_test_1) {
  {  // 10<=10
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_less_or_equal = s21_is_less_or_equal(a, b);
    ck_assert_uint_eq(1, res_less_or_equal);
  }

  {  // 10<=10
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000010101010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000010101010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_less_or_equal = s21_is_less_or_equal(a, b);
    ck_assert_uint_eq(1, res_less_or_equal);
  }
  {  //-10<=10
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000010101010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000010101010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_less_or_equal = s21_is_less_or_equal(a, b);
    ck_assert_uint_eq(1, res_less_or_equal);
  }
  {  // 10<=-10
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000010101010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000010101010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};
    int res_less_or_equal = s21_is_less_or_equal(a, b);
    ck_assert_uint_eq(0, res_less_or_equal);
  }
  {  // 0<=0
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_less_or_equal = s21_is_less_or_equal(a, b);
    ck_assert_uint_eq(1, res_less_or_equal);
  }
  {  //-0<=0
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_less_or_equal = s21_is_less_or_equal(a, b);
    ck_assert_uint_eq(1, res_less_or_equal);
  }
  {  // 2147483648<=1073741824
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b10000000000000000000000000000000,
                              [3] = 0b0000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b01000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_less_or_equal = s21_is_less_or_equal(a, b);
    ck_assert_uint_eq(0, res_less_or_equal);
  }
  {  //-63<=-65
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000111111,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000001000001,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};
    int res_less_or_equal = s21_is_less_or_equal(a, b);
    ck_assert_uint_eq(0, res_less_or_equal);
  }
  {  // 63<=65
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000111111,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000001000001,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_less_or_equal = s21_is_less_or_equal(a, b);
    ck_assert_uint_eq(1, res_less_or_equal);
  }
  {  //-65<=-63
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000001000001,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000111111,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};
    int res_less_or_equal = s21_is_less_or_equal(a, b);
    ck_assert_uint_eq(1, res_less_or_equal);
  }
  {  //-63<=-63
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000111111,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000111111,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};
    int res_less_or_equal = s21_is_less_or_equal(a, b);
    ck_assert_uint_eq(1, res_less_or_equal);
  }
  {  //-107374<=-2147483648
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b01000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b10000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};
    int res_less_or_equal = s21_is_less_or_equal(a, b);
    ck_assert_uint_eq(0, res_less_or_equal);
  }
  {  //
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000001000000000000000,
                              [3] = 0b00000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_less_or_equal = s21_is_less_or_equal(a, b);
    ck_assert_uint_eq(0, res_less_or_equal);
  }
  {  //
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000001000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_less_or_equal = s21_is_less_or_equal(a, b);
    ck_assert_uint_eq(1, res_less_or_equal);
  }

  {  // scale 28
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000111000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000111000000000000000000}};
    int res_less_or_equal = s21_is_less_or_equal(a, b);
    ck_assert_uint_eq(1, res_less_or_equal);
  }
  {  // scale 28 sign 1
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000111000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000111000000000000000000}};
    int res_less_or_equal = s21_is_less_or_equal(a, b);
    ck_assert_uint_eq(1, res_less_or_equal);
  }
  {  // scale 2
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b10000000000000000000000000000000,
                              [3] = 0b10000000000001000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b10000000000000000000000000000000,
                              [3] = 0b10000000000001000000000000000000}};
    int res_less_or_equal = s21_is_less_or_equal(a, b);
    ck_assert_uint_eq(1, res_less_or_equal);
  }
  {  // scale 2 sign 1
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b10000000000000000000000000000000,
                              [3] = 0b00000000000001000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b10000000000000000000000000000000,
                              [3] = 0b10000000000001000000000000000000}};
    int res_less_or_equal = s21_is_less_or_equal(a, b);
    ck_assert_uint_eq(0, res_less_or_equal);
  }
  {  // scale 26/28 sign 1/1
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000110100000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000111000000000000000000}};
    int res_less_or_equal = s21_is_less_or_equal(a, b);
    ck_assert_uint_eq(1, res_less_or_equal);
  }
  {  // 0.02360<=0.0236
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000100100111000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000001010000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000011101100,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000001000000000000000000}};
    int res_less_or_equal = s21_is_less_or_equal(a, b);
    ck_assert_uint_eq(1, res_less_or_equal);
  }
  {  // 0.0236<=0.02360
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000011101100,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000001000000000000000000}};
    s21_decimal b = {.bits = {[0] = 0b00000000000000000000100100111000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000001010000000000000000}};
    int res_less_or_equal = s21_is_less_or_equal(a, b);
    ck_assert_uint_eq(1, res_less_or_equal);
  }

  {  //  -1342177280, 0, -0.0236 <= -1342177280, 0, -0.02360    scale 4-5
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000011101100,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b01010000000000000000000000000000,
                              [3] = 0b10000000000001000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000100100111000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b01010000000000000000000000000000,
                              [3] = 0b10000000000001010000000000000000}};
    int res = s21_is_less_or_equal(a, b);
    ck_assert_uint_eq(1, res);
  }

  {  //  1342177280, 0, 0.0236 <= 1342177280, 0, 0.02360    scale 4-5
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000011101100,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b01010000000000000000000000000000,
                              [3] = 0b00000000000001000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000100100111000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b01010000000000000000000000000000,
                              [3] = 0b00000000000001010000000000000000}};
    int res = s21_is_less_or_equal(a, b);
    ck_assert_uint_eq(0, res);
  }
}
END_TEST

//>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=

START_TEST(s21_is_greater_or_equal_test_1) {
  {  // 56986>=56986
    s21_decimal a = {.bits = {[0] = 0b00000000000000001101111010011010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000001110000000000000000000}};  // 56

    s21_decimal b = {.bits = {[0] = 0b00000000000000001101111010011010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_greater_or_equal = s21_is_greater_or_equal(a, b);
    ck_assert_uint_eq(0, res_greater_or_equal);
  }

  {  // 10>=10
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};
    int res_greater_or_equal = s21_is_greater_or_equal(a, b);
    ck_assert_uint_eq(1, res_greater_or_equal);
  }

  {  // 10>=10
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000010101010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000010101010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_greater_or_equal = s21_is_greater_or_equal(a, b);
    ck_assert_uint_eq(1, res_greater_or_equal);
  }
  {  //-10>=10
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000010101010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000010101010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_greater_or_equal = s21_is_greater_or_equal(a, b);
    ck_assert_uint_eq(0, res_greater_or_equal);
  }
  {  // 10>=-10
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000010101010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000010101010,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};
    int res_greater_or_equal = s21_is_greater_or_equal(a, b);
    ck_assert_uint_eq(1, res_greater_or_equal);
  }
  {  // 0>=0
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_greater_or_equal = s21_is_greater_or_equal(a, b);
    ck_assert_uint_eq(1, res_greater_or_equal);
  }
  {  //-0>=0
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_greater_or_equal = s21_is_greater_or_equal(a, b);
    ck_assert_uint_eq(1, res_greater_or_equal);
  }
  {  // 2147483648>=1073741824
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b10000000000000000000000000000000,
                              [3] = 0b0000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b01000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_greater_or_equal = s21_is_greater_or_equal(a, b);
    ck_assert_uint_eq(1, res_greater_or_equal);
  }
  {  //-63>=-65
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000111111,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000001000001,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};
    int res_greater_or_equal = s21_is_greater_or_equal(a, b);
    ck_assert_uint_eq(1, res_greater_or_equal);
  }
  {  // 63>=65
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000111111,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000001000001,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_greater_or_equal = s21_is_greater_or_equal(a, b);
    ck_assert_uint_eq(0, res_greater_or_equal);
  }
  {  //-65>=-63
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000001000001,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000111111,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};
    int res_greater_or_equal = s21_is_greater_or_equal(a, b);
    ck_assert_uint_eq(0, res_greater_or_equal);
  }
  {  //-63>=-63
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000111111,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000111111,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};
    int res_greater_or_equal = s21_is_greater_or_equal(a, b);
    ck_assert_uint_eq(1, res_greater_or_equal);
  }
  {  //-107374>=-2147483648
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b01000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b10000000000000000000000000000000,
                              [3] = 0b10000000000000000000000000000000}};
    int res_greater_or_equal = s21_is_greater_or_equal(a, b);
    ck_assert_uint_eq(1, res_greater_or_equal);
  }
  {  //
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000001000000000000000,
                              [3] = 0b00000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_greater_or_equal = s21_is_greater_or_equal(a, b);
    ck_assert_uint_eq(1, res_greater_or_equal);
  }
  {  //
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000001000000000000000,
                              [3] = 0b10000000000000000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000000000000000000000000}};
    int res_greater_or_equal = s21_is_greater_or_equal(a, b);
    ck_assert_uint_eq(0, res_greater_or_equal);
  }

  {  // scale 28
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000111000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000111000000000000000000}};
    int res_greater_or_equal = s21_is_greater_or_equal(a, b);
    ck_assert_uint_eq(1, res_greater_or_equal);
  }
  {  // scale 28 sign 1
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000111000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000111000000000000000000}};
    int res_greater_or_equal = s21_is_greater_or_equal(a, b);
    ck_assert_uint_eq(0, res_greater_or_equal);
  }
  {  // scale 2
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b10000000000000000000000000000000,
                              [3] = 0b10000000000001000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b10000000000000000000000000000000,
                              [3] = 0b10000000000001000000000000000000}};
    int res_greater_or_equal = s21_is_greater_or_equal(a, b);
    ck_assert_uint_eq(1, res_greater_or_equal);
  }
  {  // scale 2 sign 1
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b10000000000000000000000000000000,
                              [3] = 0b00000000000001000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b10000000000000000000000000000000,
                              [3] = 0b10000000000001000000000000000000}};
    int res_greater_or_equal = s21_is_greater_or_equal(a, b);
    ck_assert_uint_eq(1, res_greater_or_equal);
  }
  {  // scale 26/28 sign 1/1
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000000110100000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000000000000,
                              [1] = 0b00000000000000000010001000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b10000000000111000000000000000000}};
    int res_greater_or_equal = s21_is_greater_or_equal(a, b);
    ck_assert_uint_eq(0, res_greater_or_equal);
  }
  {  // 0.02360!=0.0236
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000100100111000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000001010000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000000011101100,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000001000000000000000000}};
    int res_greater_or_equal = s21_is_greater_or_equal(a, b);
    ck_assert_uint_eq(1, res_greater_or_equal);
  }
  {  // 0.0236!=0.02360
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000011101100,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000001000000000000000000}};
    s21_decimal b = {.bits = {[0] = 0b00000000000000000000100100111000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b00000000000000000000000000000000,
                              [3] = 0b00000000000001010000000000000000}};
    int res_greater_or_equal = s21_is_greater_or_equal(a, b);
    ck_assert_uint_eq(1, res_greater_or_equal);
  }

  {  //  -1342177280, 0, -0.0236 >= -1342177280, 0, -0.02360    scale 4-5
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000011101100,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b01010000000000000000000000000000,
                              [3] = 0b10000000000001000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000100100111000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b01010000000000000000000000000000,
                              [3] = 0b10000000000001010000000000000000}};
    int res = s21_is_greater_or_equal(a, b);
    ck_assert_uint_eq(0, res);
  }

  {  //  1342177280, 0, 0.0236 >= 1342177280, 0, 0.02360    scale 4-5
    s21_decimal a = {.bits = {[0] = 0b00000000000000000000000011101100,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b01010000000000000000000000000000,
                              [3] = 0b00000000000001000000000000000000}};

    s21_decimal b = {.bits = {[0] = 0b00000000000000000000100100111000,
                              [1] = 0b00000000000000000000000000000000,
                              [2] = 0b01010000000000000000000000000000,
                              [3] = 0b00000000000001010000000000000000}};
    int res = s21_is_greater_or_equal(a, b);
    ck_assert_uint_eq(1, res);
  }
}
END_TEST

// arifmetics

START_TEST(add_0) {
  s21_decimal val1 = {{15, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_1) {
  s21_decimal val1 = {{15, 0, 0, 0}};
  s21_decimal val2 = {{15, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_2) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{1, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(1, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_3) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  int status = s21_add(val1, val2, &res);
  ck_assert_int_eq(2, status);
}
END_TEST

START_TEST(add_4) {
  s21_decimal val1 = {{8, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_5) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_6) {
  s21_decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_7) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_8) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_9) {
  s21_decimal val1 = {{4, 0, 0, 0}};
  s21_decimal val2 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_10) {
  s21_decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_11) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{4, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_12) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(2, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_13) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_14) {
  s21_decimal val1 = {{4, 0, 0, 0}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_15) {
  s21_decimal val1 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_16) {
  s21_decimal val1 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(2, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_17) {
  s21_decimal val1 = {{0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111, 0b0}};
  s21_decimal val2 = {{0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111, 0b0}};
  s21_set_scale(&val1, 5);
  s21_set_scale(&val2, 3);
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_18) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_set_scale(&val1, 5);
  s21_set_scale(&val2, 3);
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

// START_TEST(add_19) {
//   float a = s21_random_float_number(-10e8, 10e8);
//   float b = s21_random_float_number(-10e8, 10e8);
//   float c = 0;

//   s21_decimal _a = {{0, 0, 0, 0}};
//   s21_decimal _b = {{0, 0, 0, 0}};
//   s21_decimal res = {{0, 0, 0, 0}};

//   s21_from_float_to_decimal(a, &_a);
//   s21_from_float_to_decimal(b, &_b);
//   s21_add(_a, _b, &res);
//   s21_from_decimal_to_float(res, &c);

//   ck_assert_float_eq_tol(a + b, c, 10e2);
// }
// END_TEST

START_TEST(add_test_1) {
  int num1 = 42;
  int num2 = 30;
  int sum_int = 72;
  s21_decimal a = {{0}};
  s21_decimal b = {{0}};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
  ck_assert_int_eq(s21_add(a, b, &res_dec), 0);
}
END_TEST

START_TEST(add_test_2) {
  int num1 = 1000;
  int num2 = 2000;
  int sum_int = 3000;
  s21_decimal a = {{0}};
  s21_decimal b = {{0}};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(add_test_3) {
  int num1 = 0;
  int num2 = 0;
  int sum_int = 0;
  s21_decimal a = {{0}};
  s21_decimal b = {{0}};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(add_test_4) {
  int num1 = -15;
  int num2 = 5;
  int sum_int = -10;
  s21_decimal a = {{0}};
  s21_decimal b = {{0}};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(add_test_5) {
  int num1 = 11115;
  int num2 = 5;
  int sum_int = 11120;
  s21_decimal a = {{0}};
  s21_decimal b = {{0}};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(add_test_6) {
  int num1 = -1;
  int num2 = -10;
  int sum_int = -11;
  s21_decimal a = {{0}};
  s21_decimal b = {{0}};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(add_test_7) {
  s21_decimal src1, src2;
  int a = -1234;
  int b = 234;
  int res_origin = -1000;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(add_test_8) {
  s21_decimal src1, src2;
  int a = -9403;
  int b = 234;
  int res_origin = -9169;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(add_test_9) {
  s21_decimal src1, src2;
  int a = 9403;
  int b = 202;
  int res_origin = 9605;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(add_test_10) {
  s21_decimal src1, src2;
  int a = 450;
  int b = -50;
  int res_origin = 400;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(add_test_11) {
  s21_decimal src1, src2;
  float num1 = 7.25;
  float num2 = 9.5;
  float res_origin = 16.75;
  s21_from_float_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);

  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_12) {
  s21_decimal src1, src2;
  int num1 = -1234;
  float num2 = 1.234;
  float res_origin = -1232.766;
  s21_from_int_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_13) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
  int num1 = -1234;
  float num2 = -1.234;
  float res_origin = -1235.234;
  s21_from_int_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_14) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
  float num1 = -94;
  float num2 = 0.00234;
  float res_origin = 0;
  res_origin = num1 + num2;
  s21_from_float_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_15) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
  float num1 = -940.3;
  float num2 = 0.000234;
  float res_origin = -940.299766;
  s21_from_float_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_16) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
  float num1 = -0.9403;
  float num2 = 0.000234;
  float res_origin = -0.940066;
  s21_from_float_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_18) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
  float num1 = -0.9403;
  float num2 = -112.0234;
  float res_origin = -112.9637;
  s21_from_float_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_19) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
  float num1 = -0.94e03;
  float num2 = -112.0234;
  float res_origin = -1052.0234;
  s21_from_float_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_20) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
  float num1 = -0.94e03;
  float num2 = -112.0e2;
  float res_origin = -12140;
  s21_from_float_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_21) {
  s21_decimal dec1 = {{0}};
  s21_decimal dec2 = {{0}};
  int tmp1 = 100;
  int tmp2 = 99999;
  int res_s21 = 0;
  int res = 100099;
  s21_decimal res1 = {{0}};
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_add(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(add_test_22) {
  s21_decimal dec1 = {{0}};
  s21_decimal dec2 = {{0}};
  int tmp1 = -100;
  int tmp2 = -99999;
  int res_s21 = 0;
  int res = -100099;
  s21_decimal res1 = {{0}};
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_add(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(add_test_23) {
  s21_decimal dec1 = {{0}};
  s21_decimal dec2 = {{0}};
  int tmp1 = 2147483647;
  int tmp2 = -2147483647;
  int res_s21 = 0;
  int res = 0;
  s21_decimal res1 = {{0}};
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_add(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(add_test_24) {
  s21_decimal dec1 = {{0}};
  s21_decimal dec2 = {{0}};
  // 66167570159
  dec1.bits[3] = 0x300000;
  dec1.bits[2] = 0;
  dec1.bits[1] = 0xF;
  dec1.bits[0] = 0;
  // 1096959721471
  dec2.bits[3] = 0x300000;
  dec2.bits[2] = 0;
  dec2.bits[1] = 0xFF;
  dec2.bits[0] = 0;
  s21_set_scale(&dec1, 28);
  s21_set_scale(&dec2, 28);
  s21_decimal res1 = {{0}};
  int status = s21_add(dec1, dec2, &res1);
  ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(add_test_25) {
  s21_decimal dec1 = {{0}};
  s21_decimal dec2 = {{0}};
  int tmp1 = -2147483647;
  int tmp2 = 2147483647;
  int res_s21 = 0;
  int res = 0;
  s21_decimal res1 = {{0}};
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_add(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(add_test_26) {
  int tmp1 = 4294967295;
  s21_decimal dec1 = {{tmp1, tmp1, tmp1, 0}};
  s21_decimal dec2 = {{1, 0, 0, 0}};
  s21_decimal res1 = {{0}};
  int ret_s21 = s21_add(dec1, dec2, &res1);
  ck_assert_int_eq(1, ret_s21);
}
END_TEST

START_TEST(add_test_27) {
  int tmp1 = 4294967295;
  float tmp2 = pow(2, 31);
  s21_decimal dec1 = {{tmp1, tmp1, tmp1, tmp2}};
  s21_decimal dec2 = {{1, 0, 0, tmp2}};
  s21_decimal res1 = {{0}};
  int ret_s21 = s21_add(dec1, dec2, &res1);
  ck_assert_int_eq(2, ret_s21);
}
END_TEST

START_TEST(add_test_28) {
  float float_a = -1075857397.21875;
  float float_b = 6268947362.84375;

  float float_res = 0;
  float_res = float_a + float_b;

  s21_decimal expected = {0};
  s21_from_float_to_decimal(float_res, &expected);

  s21_decimal dec_a = {0};
  s21_from_float_to_decimal(float_a, &dec_a);
  s21_decimal dec_b = {0};
  s21_from_float_to_decimal(float_b, &dec_b);
  s21_decimal result = {0};
  int code = s21_add(dec_a, dec_b, &result);
  float got_float = 0;
  s21_from_decimal_to_float(result, &got_float);
  ck_assert_int_eq(code, 0);
  ck_assert_float_eq_tol(got_float, float_res, 1e-06);
}

START_TEST(add_test_29) {
  s21_decimal src1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal src2 = {0};
  float a = 0.01448;
  s21_from_float_to_decimal(a, &src2);
  s21_decimal res_dec = {0};
  s21_add(src1, src2, &res_dec);
  ck_assert_int_eq(s21_add(src1, src2, &res_dec), 0);
}
END_TEST

START_TEST(add_test_30) {
  s21_decimal src1 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b10000000000000000000000000000000}};
  s21_decimal src2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111110, 0b10000000000000000000000000000000}};

  s21_decimal res_dec = {0};
  s21_add(src1, src2, &res_dec);
  ck_assert_int_eq(s21_add(src1, src2, &res_dec), 2);
}
END_TEST

START_TEST(s21_test_decimal_add_0) {
  s21_decimal c = {{5, 0, 0, 0}};
  s21_decimal d = {{5, 0, 0, 0}};
  s21_decimal etalon = {{10, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(add, 0);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_1) {
  s21_decimal c = {{100, 0, 0, 0}};
  s21_decimal d = {{100, 0, 0, 0}};
  s21_decimal etalon = {{100, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(add, 0);
  ck_assert_int_eq(equal, 0);
}
END_TEST

START_TEST(s21_test_decimal_add_2) {
  s21_decimal c = {{2147483647, 0, 0, 0}};
  s21_decimal d = {{2147483647, 0, 0, 0}};
  s21_decimal etalon = {{4294967294, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal *p_result = &result;
  int add = s21_add(c, d, p_result);
  ck_assert_int_eq(add, 0);
  int equal = s21_is_equal(result, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_3) {
  s21_decimal c = {{1000, 0, 0, 0}};
  s21_decimal d = {{1000, 0, 0, 0}};
  s21_decimal etalon = {{2000, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal *p_result = &result;
  int add = s21_add(c, d, p_result);
  ck_assert_int_eq(add, 0);
  int equal = s21_is_equal(result, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_4) {
  s21_decimal c = {{1000, 0, 0, ~(INT_MAX)}};
  s21_decimal d = {{1000, 0, 0, 0}};
  s21_decimal etalon = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal *p_result = &result;
  int add = s21_add(c, d, p_result);
  ck_assert_int_eq(add, 0);
  int equal = s21_is_equal(result, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_5) {
  s21_decimal c = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal d = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal etalon = {{2, 0, 0, ~(INT_MAX)}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal *p_result = &result;
  int add = s21_add(c, d, p_result);
  ck_assert_int_eq(add, 0);
  int equal = s21_is_equal(*p_result, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_6) {
  s21_decimal c = {{0, 0, 0, 0}};
  s21_decimal d = {{0, 0, 0, 0}};
  s21_decimal etalon = {{0, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_7) {
  s21_decimal c = {{1, 0, 0, 0}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{2, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_8) {
  s21_decimal c = {{1000, 0, 0, 0}};
  s21_decimal d = {{1000, 0, 0, 0}};
  s21_decimal etalon = {{2000, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_8_1) {
  s21_decimal c = {{INT_MAX, 0, 0, 0}};
  s21_decimal d = {{INT_MAX, 0, 0, 0}};
  s21_decimal etalon = {{4294967294, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_9) {
  s21_decimal c = {{INT_MAX, 0, 0, 0}};
  s21_decimal d = {{INT_MAX, 0, 0, 0}};
  s21_decimal etalon = {{UINT32_MAX - 1, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_10) {
  s21_decimal c = {{UINT32_MAX, 0, 0, 0}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{0, 1, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[3], etalon.bits[3]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[0], etalon.bits[0]);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_11) {
  s21_decimal c = {{0, UINT_MAX - 1, 0, 0}};
  s21_decimal d = {{0, 1, 0, 0}};
  s21_decimal etalon = {{0, UINT_MAX, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_12) {
  s21_decimal c = {{0, 0, UINT_MAX - 1, 0}};
  s21_decimal d = {{0, 0, 1, 0}};
  s21_decimal etalon = {{0, 0, UINT_MAX, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_13) {
  s21_decimal c = {{0, 0, 0, ~(INT_MAX)}};
  s21_decimal d = {{0, 0, 0, ~(INT_MAX)}};
  s21_decimal etalon = {{0, 0, 0, ~(INT_MAX)}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_14) {
  s21_decimal c = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{0, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_15) {
  s21_decimal c = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal d = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal etalon = {{2, 0, 0, ~(INT_MAX)}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[3], etalon.bits[3]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[0], etalon.bits[0]);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_16) {
  s21_decimal c = {{11, 0, 0, 65536}};
  s21_decimal d = {{0, 0, 0, 0}};
  s21_decimal etalon = {{11, 0, 0, 65536}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_17) {
  s21_decimal c = {{11, 0, 0, 65536}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{21, 0, 0, 65536}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_18) {
  s21_decimal c = {{111, 0, 0, 65536}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{121, 0, 0, 65536}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_19) {
  s21_decimal c = {{111, 0, 0, 196608}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{1111, 0, 0, 196608}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_20) {
  s21_decimal c = {0};
  c.bits[0] = 0b11111111111111111111111111111110;
  c.bits[1] = 0b00000000000000000000000000000000;
  c.bits[2] = 0b00000000000000000000000000000000;
  c.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {0};
  etalon.bits[0] = 0b11111111111111111111111111111111;
  etalon.bits[1] = 0b00000000000000000000000000000000;
  etalon.bits[2] = 0b00000000000000000000000000000000;
  etalon.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;

  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_21) {
  s21_decimal c = {{UINT32_MAX - 1, UINT32_MAX, 0, 0}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{UINT32_MAX, UINT32_MAX, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_25) {
  s21_decimal c = {{0b00000000000000000001100101111001, 0, 0, 0}};
  s21_decimal d = {{0b00000000000000010010000110001001, 0, 0, 0}};
  s21_decimal etalon = {{0b00000000000000010011101100000010, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_26) {
  s21_decimal c = {{0b10001001111001111111111111111111,
                    0b10001010110001110010001100000100, 0, 0}};
  s21_decimal d = {{0b00000000000000000000000000000001, 0, 0, 0}};
  s21_decimal etalon = {{0b10001001111010000000000000000000,
                         0b10001010110001110010001100000100, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_27) {
  s21_decimal c = {{UINT_MAX, UINT_MAX, 0, 0}};
  s21_decimal d = {{0b00000000000000000000000000000001, 0, 0, 0}};
  s21_decimal etalon = {{0, 0, 1, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_28) {
  s21_decimal c = {
      {0b10000010111000100101101011101101, 0b11111001111010000010010110101101,
       0b10110000001111101111000010010100, 0b10000000000011100000000000000000}};
  s21_decimal d = {{0b00000011010000001001011100101110, 0, 0, 0}};
  s21_decimal etalon = {
      {0b01110001001010101101101011101101, 0b00101110001111001110000111111000,
       0b10110000001111101110111101101101, 0b10000000000011100000000000000000}};
  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_29) {
  s21_decimal c = {
      {0b10000010111000100101101011101101, 0b11111001111010000010010110101101,
       0b10110000001111101111000010010100, 0b10000000000011100000000000000000}};
  s21_decimal d = {
      {0b01001000000110110001111110011000, 0b11111011111111011000100101101101,
       0b00000000000001000110110101110111, 0b10000000000110000000000000000000}};
  s21_decimal etalon = {
      {0b10110110001010011011010111011010, 0b11111001111010100000110001111111,
       0b10110000001111101111000010010100, 0b10000000000011100000000000000000}};
  s21_decimal res = {{0, 0, 0, 0}};
  int add = s21_add(c, d, &res);
  ck_assert_int_eq(add, 0);
  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);
  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_30) {
  s21_decimal src1, src2, origin;
  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  origin.bits[0] = 0b01001110111001000011100101110110;
  origin.bits[1] = 0b01001011001101011010000111011001;
  origin.bits[2] = 0b00011001101110010111010010111111;
  origin.bits[3] = 0b00000000000011110000000000000000;

  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal *p_res = &result;
  int add = s21_add(src1, src2, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);

  int equal = s21_is_equal(result, origin);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_0) {
  s21_decimal c = {{0, 0, 0, 0}};
  s21_decimal d = {{0, 0, 0, 0}};
  s21_decimal etalon = {{0, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_1) {
  s21_decimal c = {{1, 0, 0, 0}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{2, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_2) {
  s21_decimal c = {{1000, 0, 0, 0}};
  s21_decimal d = {{1000, 0, 0, 0}};
  s21_decimal etalon = {{2000, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_3) {
  s21_decimal c = {{INT_MAX, 0, 0, 0}};
  s21_decimal d = {{INT_MAX, 0, 0, 0}};
  s21_decimal etalon = {{4294967294, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_4) {
  s21_decimal c = {{INT_MAX, 0, 0, 0}};
  s21_decimal d = {{INT_MAX, 0, 0, 0}};
  s21_decimal etalon = {{UINT32_MAX - 1, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_5) {
  s21_decimal c = {{UINT_MAX, 0, 0, 0}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{0, 1, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[3], etalon.bits[3]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[0], etalon.bits[0]);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_6) {
  s21_decimal c = {{0, UINT_MAX - 1, 0, 0}};
  s21_decimal d = {{0, 1, 0, 0}};
  s21_decimal etalon = {{0, UINT_MAX, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_7) {
  s21_decimal c = {{0, 0, UINT_MAX - 1, 0}};
  s21_decimal d = {{0, 0, 1, 0}};
  s21_decimal etalon = {{0, 0, UINT_MAX, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_8) {
  s21_decimal c = {{0, 0, 0, ~(INT_MAX)}};
  s21_decimal d = {{0, 0, 0, ~(INT_MAX)}};
  s21_decimal etalon = {{0, 0, 0, ~(INT_MAX)}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_9) {
  s21_decimal c = {{1, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{0, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_10) {
  s21_decimal c = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal d = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal etalon = {{2, 0, 0, ~(INT_MAX)}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);
  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_11) {
  s21_decimal c = {{11, 0, 0, 65536}};
  s21_decimal d = {{0, 0, 0, 0}};
  s21_decimal etalon = {{11, 0, 0, 65536}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_12) {
  s21_decimal c = {{11, 0, 0, 65536}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{21, 0, 0, 65536}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_13) {
  s21_decimal c = {{111, 0, 0, 65536}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{121, 0, 0, 65536}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_14) {
  s21_decimal c = {{111, 0, 0, 196608}};
  s21_decimal d = {{1, 0, 0, 0}};
  s21_decimal etalon = {{1111, 0, 0, 196608}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;

  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);
  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);
  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_20) {
  s21_decimal c = {{0b00000000000000000001100101111001, 0, 0, 0}};
  s21_decimal d = {{0b00000000000000010010000110001001, 0, 0, 0}};
  s21_decimal etalon = {{0b00000000000000010011101100000010, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_21) {
  s21_decimal c = {{0b10001001111001111111111111111111,
                    0b10001010110001110010001100000100, 0, 0}};
  s21_decimal d = {{0b00000000000000000000000000000001, 0, 0, 0}};
  s21_decimal etalon = {{0b10001001111010000000000000000000,
                         0b10001010110001110010001100000100, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_22) {
  s21_decimal c = {{UINT_MAX, UINT_MAX, 0, 0}};
  s21_decimal d = {{0b00000000000000000000000000000001, 0, 0, 0}};
  s21_decimal etalon = {{0, 0, 1, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_23) {
  s21_decimal c = {
      {0b10000010111000100101101011101101, 0b11111001111010000010010110101101,
       0b10110000001111101111000010010100, 0b10000000000011100000000000000000}};
  s21_decimal d = {{0b00000011010000001001011100101110, 0, 0, 0}};
  s21_decimal etalon = {
      {0b01110001001010101101101011101101, 0b00101110001111001110000111111000,
       0b10110000001111101110111101101101, 0b10000000000011100000000000000000}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;

  int add = s21_add(c, d, p_res);
  ck_assert_int_eq(add, 0);

  ck_assert_int_eq(res.bits[0], etalon.bits[0]);
  ck_assert_int_eq(res.bits[1], etalon.bits[1]);
  ck_assert_int_eq(res.bits[2], etalon.bits[2]);
  ck_assert_int_eq(res.bits[3], etalon.bits[3]);
  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_add_max_31) {
  s21_decimal src1 = {0};
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal src2 = {0};
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000110000000000000000;
  s21_decimal s21_res = {0};
  ck_assert_int_eq(s21_add(src1, src2, &s21_res), 0);
}
END_TEST

START_TEST(s21_add_max_32) {
  s21_decimal src1 = {0};
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal src2 = {0};
  src2.bits[0] = 0b00000000000000000000000000000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal s21_res = {0};
  ck_assert_int_eq(s21_add(src1, src2, &s21_res), 0);
}
END_TEST

START_TEST(s21_add_max_33) {
  s21_decimal src1 = {0};
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal src2 = {0};
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal s21_res = {0};
  ck_assert_int_eq(s21_add(src1, src2, &s21_res), 1);
}
END_TEST

START_TEST(s21_add_max_34) {
  s21_decimal src1 = {0};
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal src2 = {0};
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000110000000000000000;
  s21_decimal original_res = {0};
  original_res.bits[0] = 0b11111111111111111111111111111110;
  original_res.bits[1] = 0b11111111111111111111111111111111;
  original_res.bits[2] = 0b11111111111111111111111111111111;
  original_res.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal s21_res = {0};
  s21_add(src1, src2, &s21_res);
  ck_assert_int_eq(s21_add(src1, src2, &s21_res), 0);
  ck_assert_int_eq(original_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(original_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(original_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(original_res.bits[3], s21_res.bits[3]);
}
END_TEST

START_TEST(s21_add_max_35) {
  s21_decimal src1 = {0};
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal src2 = {0};
  src2.bits[0] = 0b00000000000000000000000000000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal original_res = {0};
  original_res.bits[0] = 0b11111111111111111111111111111110;
  original_res.bits[1] = 0b11111111111111111111111111111111;
  original_res.bits[2] = 0b11111111111111111111111111111111;
  original_res.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal s21_res = {0};
  s21_add(src1, src2, &s21_res);
  ck_assert_int_eq(s21_add(src1, src2, &s21_res), 0);
  ck_assert_int_eq(original_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(original_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(original_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(original_res.bits[3], s21_res.bits[3]);
}
END_TEST

START_TEST(s21_add_max_36) {
  s21_decimal src1 = {0};
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal src2 = {0};
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal original_res = {0};
  original_res.bits[0] = 0b11111111111111111111111111111110;
  original_res.bits[1] = 0b11111111111111111111111111111111;
  original_res.bits[2] = 0b11111111111111111111111111111111;
  original_res.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal s21_res = {0};
  s21_add(src1, src2, &s21_res);
  ck_assert_int_eq(s21_add(src1, src2, &s21_res), 0);
  ck_assert_int_eq(original_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(original_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(original_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(original_res.bits[3], s21_res.bits[3]);
}
END_TEST

START_TEST(add_test_37) {
  s21_decimal src1 = {0};
  src1.bits[0] = 0b00000000000000000000001111111111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal src2 = {0};
  src2.bits[0] = 0b00000000000000000000001111111111;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  s21_decimal original_res = {0};
  original_res.bits[0] = 0b00000000000000000010101111110101;
  original_res.bits[1] = 0b00000000000000000000000000000000;
  original_res.bits[2] = 0b00000000000000000000000000000000;
  original_res.bits[3] = 0b00000000000000100000000000000000;
  s21_decimal s21_res = {0};
  s21_add(src1, src2, &s21_res);
  ck_assert_int_eq(s21_add(src1, src2, &s21_res), 0);
  ck_assert_int_eq(original_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(original_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(original_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(original_res.bits[3], s21_res.bits[3]);
}
END_TEST

START_TEST(sub_0) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_1) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_2) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_3) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_4) {
  s21_decimal val1 = {{8, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_5) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_6) {
  s21_decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_7) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_8) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_9) {
  s21_decimal val1 = {{8, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_10) {
  s21_decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_11) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{4, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(2, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_12) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{4, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_13) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_14) {
  s21_decimal val1 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(2, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_15) {
  s21_decimal val1 = {{4, 0, 0, 0}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_16) {
  s21_decimal val1 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_17) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(1, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_18) {
  s21_decimal val1 = {{4, 0, 0, 0}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(1, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_19) {
  s21_decimal val1 = {{4, 0, 0, 0}};
  s21_decimal val2 = {{4, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_20) {
  s21_decimal dec1 = {{0}};
  s21_decimal dec2 = {{0}};
  int tmp1 = 100;
  int tmp2 = 99999;
  int res_s21 = 0;
  int res = -99899;
  s21_decimal res1 = {{0}};
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_sub(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(sub_21) {
  s21_decimal dec1 = {{0}};
  s21_decimal dec2 = {{0}};
  int tmp1 = -100;
  int tmp2 = -99999;
  int res_s21 = 0;
  s21_decimal res1 = {{0}};
  int res = 99899;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_sub(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(sub_22) {
  s21_decimal value_1 = {{13, 0, 0, 0}};
  s21_set_scale(&value_1, 1);
  s21_set_sign(&value_1, 1);
  s21_decimal value_2 = {{286, 0, 0, 0}};
  s21_set_scale(&value_2, 2);
  s21_set_sign(&value_2, 1);
  s21_decimal result = {0};
  s21_decimal check = {{156, 0, 0, 0}};
  s21_set_scale(&check, 2);
  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(sub_23) {
  s21_decimal value_1 = {{13, 0, 0, 0}};
  s21_set_scale(&value_1, 1);
  s21_set_sign(&value_1, 1);
  s21_decimal value_2 = {{286, 0, 0, 0}};
  s21_set_scale(&value_2, 2);
  s21_decimal result = {0};
  s21_decimal check = {{416, 0, 0, 0}};
  s21_set_scale(&check, 2);
  s21_set_sign(&check, 1);
  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(sub_24) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_1, 1);
  s21_decimal value_2 = {{2, 0, 0, 0}};
  s21_decimal result = {0};
  s21_decimal check = {{0, 0, 0, 0}};
  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

START_TEST(sub_25) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_1, 1);
  s21_decimal value_2 = {{2, 0, 0, 0}};
  s21_set_sign(&value_2, 1);
  s21_decimal result = {0};
  s21_decimal check = {{0, 0, 0, 0}};
  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

START_TEST(sub_26) {
  s21_decimal value_1 = {{64071, 0, 0, 0}};
  s21_set_scale(&value_1, 4);
  s21_decimal value_2 = {{5919, 0, 0, 0}};
  s21_set_scale(&value_2, 1);
  s21_decimal result = {0};
  s21_decimal check = {{5854929, 0, 0, 0}};
  s21_set_scale(&check, 4);
  s21_set_sign(&check, 1);
  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(sub_27) {
  s21_decimal src1 = {0}, src2 = {0};
  float a = -9403;
  float b = 202.098;
  float res_our_dec = 0.0;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  float res_origin = a - b;
  s21_decimal res_od = {0};
  s21_sub(src1, src2, &res_od);
  s21_from_decimal_to_float(res_od, &res_our_dec);
  ck_assert_float_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(sub_28) {
  s21_decimal src1 = {0}, src2 = {0};
  src1.bits[3] = 0b00000000000000010000000000000000;
  src1.bits[2] = 0;
  src1.bits[1] = 0;
  src1.bits[0] = 0b00000000000000000110011011110000;
  src2.bits[3] = 0b00000000000000110000000000000000;
  src2.bits[2] = 0;
  src2.bits[1] = 0;
  src2.bits[0] = 0b00000000000001000101000111010110;
  s21_decimal result_origin = {0};
  result_origin.bits[3] = 0b00000000000000110000000000000000;
  result_origin.bits[2] = 0;
  result_origin.bits[1] = 0;
  result_origin.bits[0] = 0b00000000001000111110001111101010;
  s21_decimal result_our = {0};
  s21_sub(src1, src2, &result_our);
  ck_assert_int_eq(result_origin.bits[3], result_our.bits[3]);
  ck_assert_int_eq(result_origin.bits[2], result_our.bits[2]);
  ck_assert_int_eq(result_origin.bits[1], result_our.bits[1]);
  ck_assert_int_eq(result_origin.bits[0], result_our.bits[0]);
}
END_TEST

START_TEST(s21_subTest1) {
  s21_decimal src1, src2, origin;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest2) {
  s21_decimal src1, src2, origin;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest3) {
  s21_decimal src1, src2, origin;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest4) {
  s21_decimal src1, src2, origin;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest5) {
  s21_decimal src1, src2, origin;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest6) {
  s21_decimal src1, src2, origin;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest7) {
  s21_decimal src1, src2, origin;
  src1.bits[0] = 0b00000000000000000001100101111001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000010010000110001001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000010000100000010000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest8) {
  s21_decimal src1, src2, origin;
  src1.bits[0] = 0b00000000000000000000000000000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000101110100011001110100011011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b00000101110100011001110100010111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest9) {
  s21_decimal src1, src2, origin;
  src1.bits[0] = 100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 95;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 5;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest10) {
  s21_decimal src1, src2, origin;
  src1.bits[0] = 0b00000000000001011001000011001100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b00000000000001011001000011001101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest11) {
  s21_decimal src1, src2, origin;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b11111101101100110001110000110001;
  src2.bits[1] = 0b00000000000000000000000000010110;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b11111101101100110001110000110000;
  origin.bits[1] = 0b00000000000000000000000000010110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest12) {
  s21_decimal src1, src2, origin;
  src1.bits[0] = 0b01001100110100101000000111000101;
  src1.bits[1] = 0b00000000000000000000000000000010;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b01001100110100101000000111000010;
  origin.bits[1] = 0b00000000000000000000000000000010;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest13) {
  s21_decimal src1, src2, origin;
  src1.bits[0] = 0b10001001111001111111111111111111;
  src1.bits[1] = 0b10001010110001110010001100000100;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b10001001111001111111111111111110;
  origin.bits[1] = 0b10001010110001110010001100000100;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest14) {
  s21_decimal src1, src2, origin;

  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b11111111111111111111111111111110;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest15) {
  s21_decimal src1, src2, origin;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;

  src2.bits[0] = 0b00111001100010111010010101100010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b11000000100010111000101000100010;
  origin.bits[1] = 0b11111111111111111111111111111101;
  origin.bits[2] = 0b00000000000000000000000000001001;
  origin.bits[3] = 0b00000000000000010000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest16) {
  s21_decimal src1, src2, origin;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;

  src2.bits[0] = 0b00000011010000001001011100101110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b10010100100110011101101011101101;
  origin.bits[1] = 0b11000101100100110110100101100010;
  origin.bits[2] = 0b10110000001111101111000110111100;
  origin.bits[3] = 0b10000000000011100000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest17) {
  s21_decimal src1, src2, origin;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b01001000000110110001111110011000;
  src2.bits[1] = 0b11111011111111011000100101101101;
  src2.bits[2] = 0b00000000000001000110110101110111;
  src2.bits[3] = 0b10000000000110000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);
  origin.bits[0] = 0b01001111100110101111111111111111;
  origin.bits[1] = 0b11111001111001100011111011011011;
  origin.bits[2] = 0b10110000001111101111000010010100;
  origin.bits[3] = 0b10000000000011100000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest18) {
  s21_decimal src1, src2, origin;
  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b01001110111001000011100101110110;
  origin.bits[1] = 0b01001011001101011010000111011001;
  origin.bits[2] = 0b00011001101110010111010010111111;
  origin.bits[3] = 0b00000000000011110000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest23) {
  s21_decimal src1, src2, origin;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest24) {
  s21_decimal src1, src2, origin;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest25) {
  s21_decimal src1, src2, origin;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest26) {
  s21_decimal src1, src2, origin;
  src1.bits[0] = 0b00101000111101011100001010001111;
  src1.bits[1] = 0b11110101110000101000111101011100;
  src1.bits[2] = 0b00000010100011110101110000101000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b00101000111101011100001010010000;
  origin.bits[1] = 0b11110101110000101000111101011100;
  origin.bits[2] = 0b00000010100011110101110000101000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest27) {
  s21_decimal src1, src2, origin;
  src1.bits[0] = 0b01011111000010000000010001011011;
  src1.bits[1] = 0b01101101111100110111111101100111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000011111010011010110001001110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b01011011000111100101100000001101;
  origin.bits[1] = 0b01101101111100110111111101100111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest28) {
  s21_decimal src1, src2, origin;
  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00010000010100101110011001011001;
  src2.bits[1] = 0b00000000000111110100000111110010;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b11101000101010001011011101111000;
  origin.bits[1] = 0b00000000000111110100000111110001;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest29) {
  s21_decimal src1, src2, origin;
  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;

  src2.bits[0] = 0b11010100101011100011110110001010;
  src2.bits[1] = 0b01110100000101000010011110100011;
  src2.bits[2] = 0b00000000000010000100000101000100;
  src2.bits[3] = 0b00000000000110000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b00001110111111111010100000101010;
  origin.bits[1] = 0b00101001110101100000001000110100;
  origin.bits[2] = 0b00000000000001011111000010100001;
  origin.bits[3] = 0b10000000000110000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest30) {
  s21_decimal src1, src2, origin;
  src1.bits[0] = 0b01010100010000000011110110001100;
  src1.bits[1] = 0b10001011010100100000010101011001;
  src1.bits[2] = 0b00011111101010011000000110101101;
  src1.bits[3] = 0b10000000000011000000000000000000;

  src2.bits[0] = 0b01100101111100100100110110101100;
  src2.bits[1] = 0b00000000000001111010100110101011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b11010010100100100111101010001100;
  origin.bits[1] = 0b10011110100111100111000100000100;
  origin.bits[2] = 0b00011111101010011000000100111000;
  origin.bits[3] = 0b10000000000011000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest31) {
  s21_decimal src1, src2, origin;
  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;

  src2.bits[0] = 0b00010111001001010100110000000010;
  src2.bits[1] = 0b00000000111101010001010110011011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b01011010101111100101111101110011;
  origin.bits[1] = 0b00101101001111010011000001101000;
  origin.bits[2] = 0b00000100101010001101010101010111;
  origin.bits[3] = 0b10000000000111000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST
START_TEST(s21_subTest33) {
  s21_decimal src1, src2, origin;
  src1.bits[0] = 0b10011001100110011001100110011001;
  src1.bits[1] = 0b10011001100110011001100110011001;
  src1.bits[2] = 0b00011001100110011001100110011001;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0b10011001100110011001100110011010;
  origin.bits[1] = 0b10011001100110011001100110011001;
  origin.bits[2] = 0b00011001100110011001100110011001;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_test_decimal_sub_simple_0) {
  s21_decimal c = {{10, 0, 0, 0}};
  s21_decimal d = {{5, 0, 0, 0}};
  s21_decimal etalon = {{5, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_sub(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_sub_simple_1) {
  s21_decimal c = {{100, 0, 0, 0}};
  s21_decimal d = {{5, 0, 0, 0}};
  s21_decimal etalon = {{5, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_sub(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 0);
}
END_TEST

START_TEST(s21_test_decimal_sub_simple_2) {
  s21_decimal c = {{INT_MAX, 0, 0, 0}};
  s21_decimal d = {{5, 0, 0, 0}};
  s21_decimal etalon = {{2147483642, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_sub(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_sub_simple_3) {
  s21_decimal c = {{INT_MAX, INT_MAX, 0, 0}};
  s21_decimal d = {{5, 0, 0, 0}};
  s21_decimal etalon = {{INT_MAX - 5, INT_MAX, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_sub(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}

START_TEST(s21_test_decimal_sub_simple_7) {
  s21_decimal c = {{1, 0, 0, 0}};
  s21_decimal d = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal etalon = {{2, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_sub(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_sub_simple_8) {
  s21_decimal c = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal d = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal etalon = {{0, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_sub(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_sub_simple_10) {
  s21_decimal c = {{100, 0, 0, 0}};
  s21_decimal d = {{100, 0, 0, ~(INT_MAX)}};
  s21_decimal etalon = {{200, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_sub(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_sub_simple_11) {
  s21_decimal c = {{100, 0, 0, ~(INT_MAX)}};
  s21_decimal d = {{100, 0, 0, ~(INT_MAX)}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal *p_res = &res;
  int add = s21_sub(c, d, p_res);
  ck_assert_int_eq(add, 0);
}
END_TEST

START_TEST(sub_test_11) {
  int num1 = 123;
  float num2 = 12.5;
  float origin_float = 110.5;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, origin_float);
}
END_TEST

START_TEST(sub_test_12) {
  int num1 = -123;
  float num2 = 12.5;
  float dif_float = num1 - num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, dif_float);
}
END_TEST

START_TEST(sub_test_14) {
  int num1 = 9403;
  float num2 = 202.098;
  float dif_float = 9200.902;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, dif_float);
}
END_TEST

START_TEST(sub_test_15) {
  int num1 = -9403;
  float num2 = 202.098;
  float dif_float = num1 - num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, dif_float);
}
END_TEST

START_TEST(sub_test_16) {
  float num1 = 9403.0;
  float num2 = 202.09e8;
  float dif_float = num1 - num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, dif_float);
}
END_TEST

START_TEST(sub_test_17) {
  float num1 = 9403.0e2;
  float num2 = 202.09e8;
  float dif_float = num1 - num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, dif_float);
}
END_TEST

START_TEST(sub_test_18) {
  float num1 = -9403.0e2;
  int num2 = -202;
  float dif_float = num1 - num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, dif_float);
}
END_TEST

START_TEST(sub_test_19) {
  float num1 = -94;
  float num2 = -202;
  float dif_float = num1 - num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, dif_float);
}
END_TEST

START_TEST(sub_test_20) {
  float num1 = -1.0 / 0.0;
  int num2 = 202;
  double dif_float = 0 - num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, dif_float);
}
END_TEST

START_TEST(sub_test_21) {
  float num1 = 1.0 / 0.0;
  int num2 = 20;
  double dif_float = 0 - num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, dif_float);
}
END_TEST

START_TEST(s21_sub_int_22) {
  s21_decimal dec1;
  s21_decimal dec2;
  int tmp1 = 100;
  int tmp2 = 99999;
  int res_s21 = 0;
  int res = -99899;
  s21_decimal res1 = {{0}};
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_sub(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_sub_int_23) {
  s21_decimal dec1;
  s21_decimal dec2;
  int tmp1 = -100;
  int tmp2 = -99999;
  int res_s21 = 0;
  int res = 99899;
  s21_decimal res1 = {{0}};
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_sub(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_sub_int_24) {
  s21_decimal dec1;
  s21_decimal dec2;
  int tmp1 = -2147483647;
  int tmp2 = -2147483647;
  int res_s21 = 0;
  int res = 0;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_decimal res1 = {{0}};
  s21_sub(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_sub_int_25) {
  s21_decimal dec1;
  s21_decimal dec2;
  int tmp1 = -214748347;
  int tmp2 = 217483647;
  int res_s21 = 0;
  int res = -214748347 - 217483647;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_decimal res1 = {{0}};
  s21_sub(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_sub_int_26) {
  s21_decimal dec1;
  s21_decimal dec2;
  int tmp1 = 214748347;
  int tmp2 = -217483647;
  int res_s21 = 0;
  int res = 214748347 - -217483647;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_decimal res1 = {{0}};
  s21_sub(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_sub_inf_27) {
  float tmp = pow(2, 31);
  s21_decimal dec1 = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal dec2 = {{1, 0, 0, tmp}};
  s21_decimal res1 = {{0}};
  int ret_s21 = s21_sub(dec1, dec2, &res1);
  ck_assert_int_eq(1, ret_s21);
}
END_TEST

START_TEST(s21_sub_neg_inf_28) {
  float tmp = pow(2, 31);
  s21_decimal dec1 = {{4294967295, 4294967295, 4294967295, tmp}};
  s21_decimal dec2 = {{1, 0, 0, 0}};
  s21_decimal res1 = {{0}};
  int ret_s21 = s21_sub(dec1, dec2, &res1);
  ck_assert_int_eq(2, ret_s21);
}
END_TEST

START_TEST(s21_sub_max_30) {
  s21_decimal src1 = {0};
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal src2 = {0};
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000110000000000000000;
  s21_decimal original_res = {0};
  original_res.bits[0] = 0b11111111111111111111111111111110;
  original_res.bits[1] = 0b11111111111111111111111111111111;
  original_res.bits[2] = 0b11111111111111111111111111111111;
  original_res.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal s21_res = {0};
  s21_sub(src1, src2, &s21_res);
  ck_assert_int_eq(s21_sub(src1, src2, &s21_res), 0);
  ck_assert_int_eq(original_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(original_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(original_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(original_res.bits[3], s21_res.bits[3]);
}
END_TEST

START_TEST(s21_sub_max_31) {
  s21_decimal src1 = {0};
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal src2 = {0};
  src2.bits[0] = 0b00000000000000000000000000000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal original_res = {0};
  original_res.bits[0] = 0b11111111111111111111111111111110;
  original_res.bits[1] = 0b11111111111111111111111111111111;
  original_res.bits[2] = 0b11111111111111111111111111111111;
  original_res.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal s21_res = {0};
  s21_sub(src1, src2, &s21_res);
  ck_assert_int_eq(s21_sub(src1, src2, &s21_res), 0);
  ck_assert_int_eq(original_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(original_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(original_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(original_res.bits[3], s21_res.bits[3]);
}
END_TEST

START_TEST(s21_sub_max_32) {
  s21_decimal src1 = {0};
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal src2 = {0};
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal original_res = {0};
  original_res.bits[0] = 0b11111111111111111111111111111110;
  original_res.bits[1] = 0b11111111111111111111111111111111;
  original_res.bits[2] = 0b11111111111111111111111111111111;
  original_res.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal s21_res = {0};
  s21_sub(src1, src2, &s21_res);
  ck_assert_int_eq(s21_sub(src1, src2, &s21_res), 0);
  ck_assert_int_eq(original_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(original_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(original_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(original_res.bits[3], s21_res.bits[3]);
}
END_TEST

START_TEST(s21_sub_max_35) {
  s21_decimal src1 = {0};
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal src2 = {0};
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal s21_res = {0};
  ck_assert_int_eq(s21_sub(src1, src2, &s21_res), 2);
}
END_TEST

START_TEST(mul_0) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_1) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_2) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_3) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_4) {
  s21_decimal val1 = {{8, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_5) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_6) {
  s21_decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_7) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_8) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(1, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_9) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(2, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_10) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(1, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_11) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{0, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_12) {
  s21_decimal value_1 = {{5, 0, 0, 0}};
  s21_decimal value_2 = {{7, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{35, 0, 0, 0}};
  int return_value = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(mul_13) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0, 0, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{1, 0xFFFFFFFE, 0, 0}};
  int return_value = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(mul_14) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{2, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{0, 0, 0, 0}};
  int return_value = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(mul_15) {
  s21_decimal value_1 = {{123456u, 123u, 0, 0}};
  s21_decimal value_2 = {{654321u, 654u, 0, 0}};
  s21_set_sign(&value_2, 1);
  s21_set_scale(&value_1, 2);
  s21_set_scale(&value_2, 3);
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{0xcedabe40, 0x99c0c5d, 0x13a3a, 0x80050000}};
  int return_value = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(mul_16) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{2, 0, 0, 0}};
  s21_set_sign(&value_2, 1);
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{0, 0, 0, 0}};
  int return_value = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

START_TEST(mul_17) {
  s21_decimal value_1 = {{17, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_decimal result = {0};
  s21_decimal check = {{0, 0, 0, 0}};
  int return_value = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(mul_18) {
  s21_decimal src1, src2;
  float a = 9403.0e2;
  float b = 9403.0e2;
  float res_our_dec = 0.0;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  float res_origin = 884164090000;
  s21_decimal res_od = {0};
  s21_mul(src1, src2, &res_od);
  s21_from_decimal_to_float(res_od, &res_our_dec);
  ck_assert_float_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(mul_19) {
  s21_decimal src1, src2;
  int a = -32768;
  int b = 32768;
  int res_our_dec = 0;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  int res_origin = -1073741824;
  s21_decimal res_od = {0};
  s21_mul(src1, src2, &res_od);
  s21_from_decimal_to_int(res_od, &res_our_dec);
  ck_assert_int_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(mul_test_1) {
  int num1 = -10;
  int num2 = -10;
  int prod_int = 100;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, prod_int);
}
END_TEST

START_TEST(mul_test_2) {
  int num1 = 10;
  int num2 = 20;
  int prod_int = 200;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, prod_int);
}
END_TEST

START_TEST(mul_test_3) {
  int num1 = -10;
  int num2 = 20;
  int prod_int = -200;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, prod_int);
}
END_TEST

START_TEST(mul_test_4) {
  int num1 = 9403;
  int num2 = 202;
  int res_origin = 1899406;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(mul_test_5) {
  int num1 = -32768;
  int num2 = 2;
  int res_origin = -65536;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(mul_test_6) {
  int num1 = -32768;
  int num2 = 32768;
  int res_origin = -1073741824;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(mul_test_7) {
  float num1 = 9403.0e2;
  int num2 = 202;
  float res_origin = 189940600;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(mul_test_8) {
  float num1 = 9403.0e2;
  float num2 = 9403.0e2;
  float res_origin = 884164090000;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(div_00) {
  s21_decimal val_1 = {{0b1, 0b0, 0b0, 0b00000000000111000000000000000000}};
  s21_decimal val_2 = {{0b1000000000, 0b0, 0b0, 0b0}};
  s21_decimal res = {{0}};
  // s21_decimal check = {{0b1, 0b0, 0b0, 0b0}};
  ck_assert_int_eq(2, s21_div(val_1, val_2, &res));
}
END_TEST

START_TEST(div_01) {
  s21_decimal val_1 = {{0b11111111111111111111111111111111,
                        0b11111111111111111111111111111111,
                        0b11111111111111111111111111111111, 0b0}};
  s21_decimal val_2 = {{0b1, 0b0, 0b0, 0b00000000000111000000000000000000}};
  s21_decimal res = {{0}};
  // s21_decimal check = {{0b1, 0b0, 0b0, 0b0}};
  ck_assert_int_eq(1, s21_div(val_1, val_2, &res));
}
END_TEST

START_TEST(div_0) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(div_1) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(div_2) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(div_3) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{0, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(3, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(div_4) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{0, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(3, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(div_5) {
  s21_decimal value_1 = {{35, 0, 0, 0}};
  s21_decimal value_2 = {{5, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{70, 0, 0, 0}};
  s21_set_scale(&value_1, 1);
  s21_set_scale(&value_2, 2);
  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(div_6) {
  s21_decimal value_1 = {{0x88888888, 0x88888888, 0x88888888, 0}};
  s21_decimal value_2 = {{0x2, 0, 0, 0}};
  // s21_set_sign(&value_2, 1);
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{0x44444444, 0x44444444, 0x44444444, 0}};
  // s21_set_sign(&check, 1);
  int return_value = s21_div(value_1, value_2, &result);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(result.bits[i], check.bits[i]);
  }

  // ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(div_7) {
  s21_decimal value_1 = {{10, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_decimal value_2 = {{8, 0, 0, 0}};
  s21_set_sign(&value_2, 1);
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{125, 0, 0, 0}};
  s21_set_scale(&check, 2);
  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(div_8) {
  s21_decimal value_1 = {{15, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{0, 0, 0, 0}};
  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 3);
}
END_TEST

START_TEST(div_9) {
  s21_decimal value_1 = {{10, 0, 0, 0}};
  s21_decimal value_2 = {{1, 0, 0, 0}};
  s21_set_scale(&value_2, 2);
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{1000u, 0, 0, 0}};
  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_negate_test) {
  {
    s21_decimal value_1 = {{10, 0, 0, 0b10000000000000000000000000000000}};
    s21_decimal value_2 = {{0, 0, 0, 0b00000000000000000000000000000000}};
    s21_decimal res = {{10, 0, 0, 0b00000000000000000000000000000000}};
    s21_negate(value_1, &value_2);
    ck_assert_int_eq(value_2.bits[0], res.bits[0]);
    ck_assert_int_eq(value_2.bits[1], res.bits[1]);
    ck_assert_int_eq(value_2.bits[2], res.bits[2]);
    ck_assert_int_eq(value_2.bits[3], res.bits[3]);

    s21_decimal value_3 = {{10, 0, 0, 0b00000000000000000000000000000000}};
    s21_decimal value_4 = {{0, 0, 0, 0b00000000000000000000000000000000}};
    s21_decimal res2 = {{10, 0, 0, 0b10000000000000000000000000000000}};
    s21_negate(value_3, &value_4);
    ck_assert_int_eq(value_4.bits[0], res2.bits[0]);
    ck_assert_int_eq(value_4.bits[1], res2.bits[1]);
    ck_assert_int_eq(value_4.bits[2], res2.bits[2]);
    ck_assert_int_eq(value_4.bits[3], res2.bits[3]);
  }
  {
    s21_decimal val = {{2, 0, 0, 0}};
    s21_decimal res = {0};
    int sign_before = s21_get_sign(&val);
    s21_negate(val, &res);
    int sign_after = s21_get_sign(&res);

    ck_assert_int_ne(sign_before, sign_after);
  }
  {
    s21_decimal decimal = {{0, 0, 0, 1000000000}};
    s21_decimal result;

    int code = s21_negate(decimal, &result);

    ck_assert_int_eq(code, 1);
  }
  {
    s21_decimal decimal = {{-1, 0, 0, 0x1C8000}};
    s21_decimal result;

    int code = s21_negate(decimal, &result);

    ck_assert_int_eq(code, 1);
  }
  {
    s21_decimal decimal = {{-1, 0, 0, 0x11C0000}};
    s21_decimal result;

    int code = s21_negate(decimal, &result);

    ck_assert_int_eq(code, 1);
  }
}
END_TEST

START_TEST(s21_truncate_test) {
  {
    s21_decimal value_1 = {
        {10000, 0, 0, 0b00000000000001000000000000000000}};  // 4
    s21_decimal value_2 = {{0, 0, 0, 0b00000000000000000000000000000000}};
    s21_decimal res = {{1, 0, 0, 0b00000000000000000000000000000000}};
    s21_truncate(value_1, &value_2);
    ck_assert_int_eq(value_2.bits[0], res.bits[0]);
    ck_assert_int_eq(value_2.bits[1], res.bits[1]);
    ck_assert_int_eq(value_2.bits[2], res.bits[2]);
    ck_assert_int_eq(value_2.bits[3], res.bits[3]);

    s21_decimal value_3 = {{1024, 0, 0, 0b10000000000000010000000000000000}};
    s21_decimal value_4 = {{0, 0, 0, 0b00000000000000000000000000000000}};
    s21_decimal res2 = {{102, 0, 0, 0b10000000000000000000000000000000}};
    s21_truncate(value_3, &value_4);
    ck_assert_int_eq(value_4.bits[0], res2.bits[0]);
    ck_assert_int_eq(value_4.bits[1], res2.bits[1]);
    ck_assert_int_eq(value_4.bits[2], res2.bits[2]);
    ck_assert_int_eq(value_4.bits[3], res2.bits[3]);
  }
  {
    s21_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
    s21_decimal res = {0};
    ck_assert_int_eq(0, s21_truncate(val, &res));
    float fres = 0;
    s21_from_decimal_to_float(res, &fres);
    float need = -2.0;
    ck_assert_float_eq(need, fres);
  }

  {
    s21_decimal val = {{7, 7, 7, 0}};
    s21_decimal res = {0};
    ck_assert_int_eq(0, s21_truncate(val, &res));
    float fres = 0;
    s21_from_decimal_to_float(res, &fres);
    float need = 129127208515966861312.0;
    ck_assert_float_eq(need, fres);
  }
  {
    s21_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
    s21_decimal res = {0};
    ck_assert_int_eq(0, s21_truncate(val, &res));
    float fres = 0;
    s21_from_decimal_to_float(res, &fres);
    float need = -2.0;
    ck_assert_float_eq(need, fres);
  }
  {
    s21_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
    s21_decimal res = {0};
    s21_set_scale(&val, 5);
    ck_assert_int_eq(0, s21_truncate(val, &res));
    float fres = 0;
    s21_from_decimal_to_float(res, &fres);
    float need = -0.0;
    ck_assert_float_eq(need, fres);
  }

  {
    s21_decimal val = {{128, 0, 0, 0}};
    s21_decimal res = {0};
    s21_set_scale(&val, 1);
    ck_assert_int_eq(0, s21_truncate(val, &res));
    float fres = 0;
    s21_from_decimal_to_float(res, &fres);
    float need = 12;
    ck_assert_float_eq(need, fres);
  }
  {
    s21_decimal decimal = {{0, 0, 0, 1000000000}};
    s21_decimal result;

    int code = s21_truncate(decimal, &result);

    ck_assert_int_eq(code, 1);
  }
  {
    s21_decimal decimal = {{-1, 0, 0, 0x1C8000}};
    s21_decimal result;

    int code = s21_negate(decimal, &result);

    ck_assert_int_eq(code, 1);
  }
  {
    s21_decimal decimal = {{-1, 0, 0, 0x11C0000}};
    s21_decimal result;

    int code = s21_negate(decimal, &result);

    ck_assert_int_eq(code, 1);
  }
}
END_TEST

START_TEST(s21_floor_test) {
  {
    s21_decimal value_1 = {
        {155, 0, 0, 0b00000000000000100000000000000000}};  // 2
    s21_decimal value_2 = {{0, 0, 0, 0b00000000000000000000000000000000}};
    s21_decimal res = {{1, 0, 0, 0b00000000000000000000000000000000}};
    s21_floor(value_1, &value_2);
    ck_assert_int_eq(value_2.bits[0], res.bits[0]);
    ck_assert_int_eq(value_2.bits[1], res.bits[1]);
    ck_assert_int_eq(value_2.bits[2], res.bits[2]);
    ck_assert_int_eq(value_2.bits[3], res.bits[3]);

    s21_decimal value_3 = {{1024, 0, 0, 0b00000000000000010000000000000000}};
    s21_decimal value_4 = {{0, 0, 0, 0b00000000000000000000000000000000}};
    s21_decimal res2 = {{102, 0, 0, 0b00000000000000000000000000000000}};
    s21_floor(value_3, &value_4);
    ck_assert_int_eq(value_4.bits[0], res2.bits[0]);
    ck_assert_int_eq(value_4.bits[1], res2.bits[1]);
    ck_assert_int_eq(value_4.bits[2], res2.bits[2]);
    ck_assert_int_eq(value_4.bits[3], res2.bits[3]);
  }
  {
    s21_decimal val = {{2, 0, 0, 0}};
    s21_decimal res = {0};
    ck_assert_int_eq(0, s21_floor(val, &res));
  }
  {
    s21_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
    s21_decimal res = {0};
    s21_floor(val, &res);
    float fres = 0;
    s21_from_decimal_to_float(res, &fres);
    ck_assert_float_eq(-2, fres);
  }
  {
    s21_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
    s21_decimal res = {0};
    s21_set_scale(&val, 5);
    s21_floor(val, &res);
    float fres = 0;
    s21_from_decimal_to_float(res, &fres);
    ck_assert_float_eq(-1, fres);
  }
  {
    s21_decimal val = {{2, 0, 0, 0}};
    s21_decimal res = {0};
    s21_set_scale(&val, 5);
    s21_floor(val, &res);
    float fres = 0;
    s21_from_decimal_to_float(res, &fres);
    ck_assert_float_eq(0, fres);
  }
  {
    s21_decimal decimal = {{0, 0, 0, 1000000000}};
    s21_decimal result;

    int code = s21_floor(decimal, &result);

    ck_assert_int_eq(code, 1);
  }
  {
    s21_decimal decimal = {{-1, 0, 0, 0x1C8000}};
    s21_decimal result;

    int code = s21_negate(decimal, &result);

    ck_assert_int_eq(code, 1);
  }
  {
    s21_decimal decimal = {{-1, 0, 0, 0x11C0000}};
    s21_decimal result;

    int code = s21_negate(decimal, &result);

    ck_assert_int_eq(code, 1);
  }
}
END_TEST

START_TEST(s21_round_test) {
  {
    s21_decimal value_1 = {
        {160, 0, 0, 0b00000000000000010000000000000000}};  // 1
    s21_decimal value_2 = {{0, 0, 0, 0b00000000000000000000000000000000}};
    s21_decimal res = {{16, 0, 0, 0b00000000000000000000000000000000}};
    s21_round(value_1, &value_2);
    ck_assert_int_eq(value_2.bits[0], res.bits[0]);
    ck_assert_int_eq(value_2.bits[1], res.bits[1]);
    ck_assert_int_eq(value_2.bits[2], res.bits[2]);
    ck_assert_int_eq(value_2.bits[3], res.bits[3]);

    s21_decimal value_3 = {{13, 0, 0, 0b00000000000000010000000000000000}};
    s21_decimal value_4 = {{0, 0, 0, 0b00000000000000000000000000000000}};
    s21_decimal res2 = {{1, 0, 0, 0b00000000000000000000000000000000}};
    s21_round(value_3, &value_4);
    ck_assert_int_eq(value_4.bits[0], res2.bits[0]);
    ck_assert_int_eq(value_4.bits[1], res2.bits[1]);
    ck_assert_int_eq(value_4.bits[2], res2.bits[2]);
    ck_assert_int_eq(value_4.bits[3], res2.bits[3]);

    s21_decimal value_5 = {{15, 0, 0, 0b00000000000000010000000000000000}};
    s21_decimal value_6 = {{0, 0, 0, 0b00000000000000000000000000000000}};
    s21_decimal res3 = {{2, 0, 0, 0b00000000000000000000000000000000}};
    s21_round(value_5, &value_6);
    ck_assert_int_eq(value_6.bits[0], res3.bits[0]);
    ck_assert_int_eq(value_6.bits[1], res3.bits[1]);
    ck_assert_int_eq(value_6.bits[2], res3.bits[2]);
    ck_assert_int_eq(value_6.bits[3], res3.bits[3]);
  }
  {
    s21_decimal val = {{7, 7, 7, 0}};
    s21_decimal res = {0};
    s21_round(val, &res);
    float fres = 0;
    s21_from_decimal_to_float(res, &fres);
    float need = 129127208515966861312.0;
    ck_assert_float_eq(need, fres);
  }
  {
    s21_decimal val = {{3, 3, 3, ~(UINT_MAX / 2)}};
    s21_decimal res = {0};
    ck_assert_int_eq(0, s21_round(val, &res));
  }
  {
    s21_decimal val = {{3, 3, 3, 0}};
    s21_decimal res = {0};
    s21_set_scale(&val, 5);
    ck_assert_int_eq(0, s21_round(val, &res));
  }
  {
    s21_decimal val = {{7, 7, 7, ~(UINT_MAX / 2)}};
    s21_decimal res = {0};
    s21_set_scale(&val, 5);
    ck_assert_int_eq(0, s21_round(val, &res));
  }
  {
    s21_decimal val = {{25, 0, 0, ~(UINT_MAX / 2)}};
    s21_decimal res = {0};
    s21_set_scale(&val, 1);
    ck_assert_int_eq(0, s21_round(val, &res));
  }
  {
    s21_decimal val = {{26, 0, 0, 0}};
    s21_decimal res = {0};
    s21_set_scale(&val, 1);
    ck_assert_int_eq(0, s21_round(val, &res));
  }
  {
    s21_decimal val = {{115, 0, 0, 0}};
    s21_decimal res = {0};
    s21_set_scale(&val, 1);
    ck_assert_int_eq(0, s21_round(val, &res));
  }
  {
    s21_decimal val = {{118, 0, 0, 0}};
    s21_decimal res = {0};
    s21_set_scale(&val, 1);
    ck_assert_int_eq(0, s21_round(val, &res));
  }
  {
    s21_decimal val = {{125, 0, 0, 0}};
    s21_decimal res = {0};
    s21_set_scale(&val, 1);
    ck_assert_int_eq(0, s21_round(val, &res));
  }
  {
    s21_decimal val = {{128, 0, 0, 0}};
    s21_decimal res = {0};
    s21_set_scale(&val, 1);
    s21_round(val, &res);
    float fres = 0;
    s21_from_decimal_to_float(res, &fres);
    float need = 13;
    ck_assert_float_eq(need, fres);
  }
  {
    s21_decimal decimal = {{0, 0, 0, 1000000000}};
    s21_decimal result;

    int code = s21_round(decimal, &result);

    ck_assert_int_eq(code, 1);
  }
  {
    s21_decimal decimal = {{-1, 0, 0, 0x1C8000}};
    s21_decimal result;

    int code = s21_negate(decimal, &result);

    ck_assert_int_eq(code, 1);
  }
  {
    s21_decimal decimal = {{-1, 0, 0, 0x11C0000}};
    s21_decimal result;

    int code = s21_negate(decimal, &result);

    ck_assert_int_eq(code, 1);
  }
}
END_TEST

Suite *test_suite() {
  srand(time(NULL));
  Suite *s = suite_create("s21_decimal_test");
  TCase *test = tcase_create("s21_decimal_test");
  tcase_add_test(test, s21_int_to_decimal);
  tcase_add_test(test, s21_int_to_decimal_negative);
  tcase_add_test(test, s21_float_to_decimal);
  tcase_add_test(test, s21_decimal_to_int);
  tcase_add_test(test, s21_dec_to_float);
  tcase_add_test(test, s21_dec_to_float_negative);
  tcase_add_test(test, s21_decimal_to_int_negative);
  tcase_add_test(test, s21_failed_tests);

  tcase_add_test(test, s21_is_less_test_1);
  tcase_add_test(test, s21_is_greater_test_1);
  tcase_add_test(test, s21_is_equal_test_1);
  tcase_add_test(test, s21_is_not_equal_test_1);
  tcase_add_test(test, s21_is_less_or_equal_test_1);
  tcase_add_test(test, s21_is_greater_or_equal_test_1);

  tcase_add_test(test, add_0);
  tcase_add_test(test, add_1);
  tcase_add_test(test, add_2);
  tcase_add_test(test, add_3);
  tcase_add_test(test, add_4);
  tcase_add_test(test, add_5);
  tcase_add_test(test, add_6);
  tcase_add_test(test, add_7);
  tcase_add_test(test, add_8);
  tcase_add_test(test, add_9);
  tcase_add_test(test, add_10);
  tcase_add_test(test, add_11);
  tcase_add_test(test, add_12);
  tcase_add_test(test, add_13);
  tcase_add_test(test, add_14);
  tcase_add_test(test, add_15);
  tcase_add_test(test, add_16);
  tcase_add_test(test, add_17);
  tcase_add_test(test, add_18);
  // tcase_add_loop_test(test, add_19, 0, 100);
  tcase_add_test(test, add_test_1);
  tcase_add_test(test, add_test_2);
  tcase_add_test(test, add_test_3);
  tcase_add_test(test, add_test_4);
  tcase_add_test(test, add_test_5);
  tcase_add_test(test, add_test_6);
  tcase_add_test(test, add_test_7);
  tcase_add_test(test, add_test_8);
  tcase_add_test(test, add_test_9);
  tcase_add_test(test, add_test_10);
  tcase_add_test(test, add_test_11);
  tcase_add_test(test, add_test_12);
  tcase_add_test(test, add_test_13);
  tcase_add_test(test, add_test_14);
  tcase_add_test(test, add_test_15);
  tcase_add_test(test, add_test_16);
  tcase_add_test(test, add_test_18);
  tcase_add_test(test, add_test_19);
  tcase_add_test(test, add_test_20);
  tcase_add_test(test, s21_test_decimal_add_0);
  tcase_add_test(test, s21_test_decimal_add_1);
  tcase_add_test(test, s21_test_decimal_add_2);
  tcase_add_test(test, s21_test_decimal_add_3);
  tcase_add_test(test, s21_test_decimal_add_4);
  tcase_add_test(test, s21_test_decimal_add_5);
  tcase_add_test(test, s21_test_decimal_add_6);
  tcase_add_test(test, s21_test_decimal_add_7);
  tcase_add_test(test, s21_test_decimal_add_8);
  tcase_add_test(test, s21_test_decimal_add_8_1);
  tcase_add_test(test, s21_test_decimal_add_9);
  tcase_add_test(test, s21_test_decimal_add_10);
  tcase_add_test(test, s21_test_decimal_add_11);
  tcase_add_test(test, s21_test_decimal_add_12);
  tcase_add_test(test, s21_test_decimal_add_13);
  tcase_add_test(test, s21_test_decimal_add_14);
  tcase_add_test(test, s21_test_decimal_add_15);
  tcase_add_test(test, s21_test_decimal_add_16);
  tcase_add_test(test, s21_test_decimal_add_17);
  tcase_add_test(test, s21_test_decimal_add_18);
  tcase_add_test(test, s21_test_decimal_add_19);
  tcase_add_test(test, s21_test_decimal_add_20);
  tcase_add_test(test, s21_test_decimal_add_21);
  tcase_add_test(test, s21_test_decimal_add_25);
  tcase_add_test(test, s21_test_decimal_add_26);
  tcase_add_test(test, s21_test_decimal_add_27);
  tcase_add_test(test, s21_test_decimal_add_28);
  tcase_add_test(test, s21_test_decimal_add_29);
  tcase_add_test(test, s21_test_decimal_add_30);
  tcase_add_test(test, s21_test_decimal_add_simple_0);
  tcase_add_test(test, s21_test_decimal_add_simple_1);
  tcase_add_test(test, s21_test_decimal_add_simple_2);
  tcase_add_test(test, s21_test_decimal_add_simple_3);
  tcase_add_test(test, s21_test_decimal_add_simple_4);
  tcase_add_test(test, s21_test_decimal_add_simple_5);
  tcase_add_test(test, s21_test_decimal_add_simple_6);
  tcase_add_test(test, s21_test_decimal_add_simple_7);
  tcase_add_test(test, s21_test_decimal_add_simple_8);
  tcase_add_test(test, s21_test_decimal_add_simple_9);
  tcase_add_test(test, s21_test_decimal_add_simple_10);
  tcase_add_test(test, s21_test_decimal_add_simple_11);
  tcase_add_test(test, s21_test_decimal_add_simple_12);
  tcase_add_test(test, s21_test_decimal_add_simple_13);
  tcase_add_test(test, s21_test_decimal_add_simple_14);
  tcase_add_test(test, s21_test_decimal_add_simple_20);
  tcase_add_test(test, s21_test_decimal_add_simple_21);
  tcase_add_test(test, s21_test_decimal_add_simple_22);
  tcase_add_test(test, s21_test_decimal_add_simple_23);
  tcase_add_test(test, add_test_21);
  tcase_add_test(test, add_test_22);
  tcase_add_test(test, add_test_23);
  tcase_add_test(test, add_test_24);
  tcase_add_test(test, add_test_25);
  tcase_add_test(test, add_test_26);
  tcase_add_test(test, add_test_27);
  tcase_add_test(test, add_test_28);
  tcase_add_test(test, add_test_29);
  tcase_add_test(test, add_test_30);
  tcase_add_test(test, s21_add_max_31);
  tcase_add_test(test, s21_add_max_32);
  tcase_add_test(test, s21_add_max_33);
  tcase_add_test(test, s21_add_max_34);
  tcase_add_test(test, s21_add_max_35);
  tcase_add_test(test, s21_add_max_36);
  tcase_add_test(test, add_test_37);

  tcase_add_test(test, sub_0);
  tcase_add_test(test, sub_1);
  tcase_add_test(test, sub_2);
  tcase_add_test(test, sub_3);
  tcase_add_test(test, sub_4);
  tcase_add_test(test, sub_5);
  tcase_add_test(test, sub_6);
  tcase_add_test(test, sub_7);
  tcase_add_test(test, sub_8);
  tcase_add_test(test, sub_9);
  tcase_add_test(test, sub_10);
  tcase_add_test(test, sub_11);
  tcase_add_test(test, sub_12);
  tcase_add_test(test, sub_13);
  tcase_add_test(test, sub_14);
  tcase_add_test(test, sub_15);
  tcase_add_test(test, sub_16);
  tcase_add_test(test, sub_17);
  tcase_add_test(test, sub_18);
  tcase_add_test(test, sub_19);
  tcase_add_test(test, sub_20);
  tcase_add_test(test, sub_21);
  tcase_add_test(test, sub_22);
  tcase_add_test(test, sub_23);
  tcase_add_test(test, sub_24);
  tcase_add_test(test, sub_25);
  tcase_add_test(test, sub_26);
  tcase_add_test(test, sub_27);
  tcase_add_test(test, sub_28);
  tcase_add_test(test, s21_subTest1);
  tcase_add_test(test, s21_subTest2);
  tcase_add_test(test, s21_subTest3);
  tcase_add_test(test, s21_subTest4);
  tcase_add_test(test, s21_subTest5);
  tcase_add_test(test, s21_subTest6);
  tcase_add_test(test, s21_subTest7);
  tcase_add_test(test, s21_subTest8);
  tcase_add_test(test, s21_subTest9);
  tcase_add_test(test, s21_subTest10);
  tcase_add_test(test, s21_subTest11);
  tcase_add_test(test, s21_subTest12);
  tcase_add_test(test, s21_subTest13);
  tcase_add_test(test, s21_subTest14);
  tcase_add_test(test, s21_subTest15);
  tcase_add_test(test, s21_subTest16);
  tcase_add_test(test, s21_subTest17);
  tcase_add_test(test, s21_subTest18);
  tcase_add_test(test, s21_subTest23);
  tcase_add_test(test, s21_subTest24);
  tcase_add_test(test, s21_subTest25);
  tcase_add_test(test, s21_subTest26);
  tcase_add_test(test, s21_subTest27);
  tcase_add_test(test, s21_subTest28);
  tcase_add_test(test, s21_subTest29);
  tcase_add_test(test, s21_subTest30);
  tcase_add_test(test, s21_subTest31);
  tcase_add_test(test, s21_subTest33);
  tcase_add_test(test, s21_test_decimal_sub_simple_0);
  tcase_add_test(test, s21_test_decimal_sub_simple_1);
  tcase_add_test(test, s21_test_decimal_sub_simple_2);
  tcase_add_test(test, s21_test_decimal_sub_simple_3);
  tcase_add_test(test, s21_test_decimal_sub_simple_7);
  tcase_add_test(test, s21_test_decimal_sub_simple_8);
  tcase_add_test(test, s21_test_decimal_sub_simple_10);
  tcase_add_test(test, s21_test_decimal_sub_simple_11);
  tcase_add_test(test, sub_test_11);
  tcase_add_test(test, sub_test_12);
  tcase_add_test(test, sub_test_14);
  tcase_add_test(test, sub_test_15);
  tcase_add_test(test, sub_test_16);
  tcase_add_test(test, sub_test_17);
  tcase_add_test(test, sub_test_18);
  tcase_add_test(test, sub_test_19);
  tcase_add_test(test, sub_test_20);
  tcase_add_test(test, sub_test_21);
  tcase_add_test(test, s21_sub_int_22);
  tcase_add_test(test, s21_sub_int_23);
  tcase_add_test(test, s21_sub_int_24);
  tcase_add_test(test, s21_sub_int_25);
  tcase_add_test(test, s21_sub_int_26);
  tcase_add_test(test, s21_sub_inf_27);
  tcase_add_test(test, s21_sub_neg_inf_28);
  tcase_add_test(test, s21_sub_max_30);
  tcase_add_test(test, s21_sub_max_31);
  tcase_add_test(test, s21_sub_max_32);
  tcase_add_test(test, s21_sub_max_35);

  tcase_add_test(test, mul_0);
  tcase_add_test(test, mul_1);
  tcase_add_test(test, mul_2);
  tcase_add_test(test, mul_3);
  tcase_add_test(test, mul_4);
  tcase_add_test(test, mul_5);
  tcase_add_test(test, mul_6);
  tcase_add_test(test, mul_7);
  tcase_add_test(test, mul_8);
  tcase_add_test(test, mul_9);
  tcase_add_test(test, mul_10);
  tcase_add_test(test, mul_11);
  tcase_add_test(test, mul_12);
  tcase_add_test(test, mul_13);
  tcase_add_test(test, mul_14);
  tcase_add_test(test, mul_15);
  tcase_add_test(test, mul_16);
  tcase_add_test(test, mul_17);
  tcase_add_test(test, mul_18);
  tcase_add_test(test, mul_19);
  tcase_add_test(test, mul_test_1);
  tcase_add_test(test, mul_test_2);
  tcase_add_test(test, mul_test_3);
  tcase_add_test(test, mul_test_4);
  tcase_add_test(test, mul_test_5);
  tcase_add_test(test, mul_test_6);
  tcase_add_test(test, mul_test_7);
  tcase_add_test(test, mul_test_8);

  tcase_add_test(test, div_00);
  tcase_add_test(test, div_01);
  tcase_add_test(test, div_0);
  tcase_add_test(test, div_1);
  tcase_add_test(test, div_2);
  tcase_add_test(test, div_3);
  tcase_add_test(test, div_4);
  tcase_add_test(test, div_5);
  tcase_add_test(test, div_6);
  tcase_add_test(test, div_7);
  tcase_add_test(test, div_8);
  tcase_add_test(test, div_9);

  // other
  tcase_add_test(test, s21_negate_test);
  tcase_add_test(test, s21_truncate_test);
  tcase_add_test(test, s21_floor_test);
  tcase_add_test(test, s21_round_test);
  suite_add_tcase(s, test);
  return s;
}
int main() {
  Suite *s;
  s = test_suite();
  SRunner *sr = srunner_create(s);
  int nf;
  srunner_run_all(sr, CK_NORMAL);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);
  return nf == 0 ? 0 : 1;
}
