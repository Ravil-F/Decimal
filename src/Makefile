OS = $(shell uname)
ifeq ($(OS),Darwin)
	FLAGS = -Wall -Werror -Wextra -std=c11
	LIBS = -lcheck
	M =
else ifeq ($(OS),Linux)
	FLAGS = -Wall -Werror -Wextra -std=c11
	LIBS =  -lcheck -lsubunit -pthread
	M = -lm
endif
S21 = s21_decimal
TEST = test
TEST_FOLDER = tests/*/*.c tests/*.c
FOLDER = basic/s21_*.c comparison/s21_*.c convertors/s21_*.c other/s21_*.c arithmetic/s21_*.c basic/*/s21_*.c
FOLDER_H = comparison/s21_*.h convertors/s21_*.h other/s21_*.h arithmetic/s21_*.h basic/*/s21_*.h basic/s21_*.h

all: clang-format $(S21).a

$(S21).a: $(FOLDER)
	gcc -c $(FLAGS) $(FOLDER)
	ar rc $(S21).a s21_*.o
	ranlib $(S21).a

test: clean $(S21).a
	gcc $(FLAGS) -o $(S21)_test $(S21)_test.c  $(S21).a $(LIBS) -g $(M) 
	./s21_decimal_test

gcov_report: clean
	gcc --coverage -o $(S21)_test $(FOLDER) $(S21)_test.c $(LIBS) $(M) 
	./$(S21)_test
	lcov -t "$(S21)_test" -o $(S21)_test.info -c -d .
	genhtml -o report $(S21)_test.info
	open ./report/index.html

clang-format:
	clang-format -i *.c *.h $(FOLDER) $(FOLDER_H)

clean:
	rm -rf *.o
	rm -rf *.out
	rm -rf *.a
	rm -rf *.info
	rm -rf $(S21)
	rm -rf $(S21)_test
	rm -rf test
	rm -rf s21_arithmetic_test
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf report
	rm -rf $(S21)_test.dSYM

rebuild: clean all
