CC = gcc

CFLAGS = -Wall -Wextra -Werror -std=c11
TEST_FLAGS = -lcheck -lpthread -lm

OS:=$(shell uname -s)
ifeq ($(OS), Linux)
 TEST_FLAGS += -lrt -lsubunit
endif

MATRIX= ./functions/*.c
TEST= ./unit_tests/test*.c ./unit_tests/test_lib_matrix.h
OBJECTS= *.o

CLANG= clang-format

.PHONY: all clean test lib_matrix.a gcov_report

all: lib_matrix.a test gcov_report

lib_matrix.a:
	$(CC) $(CFLAGS) -c $(MATRIX)
	ar rcs lib_matrix.a $(OBJECTS)
	ranlib lib_matrix.a

test: lib_matrix.a
	$(CC) $(CFLAGS) $(MATRIX) $(TEST) lib_matrix.a $(TEST_FLAGS) -o lib_matrix_test
	./lib_matrix_test

gcov_report: lib_matrix.a
	$(CC) $(CFLAGS) --coverage $(MATRIX) $(TEST) $(TEST_FLAGS) -o lib_matrix_test
	./lib_matrix_test
	lcov -t "lib_matrix_test" -o lib_matrix_test_report.info -c -d .
	genhtml -o report lib_matrix_test_report.info
	open report/index.html
	rm -rf *.o *.a *.gch *.gcno *.gcda *.info lib_matrix_test

clean:
	rm -rf *.o *.a *.gcda *.gcno *.info report lib_matrix_test

rebuild:
	make clean
	make all

clang_n:
	$(CLANG) -style=Google -n *.[ch] */*.[ch]

clang_i:
	$(CLANG) -style=Google -i *.[ch] */*.[ch]

