CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
FILES = s21_memchr.c s21_memcmp.c s21_memcpy.c s21_memset.c \
		s21_strchr.c s21_strcspn.c s21_strlen.c s21_strncat.c \
		s21_strncmp.c s21_strncpy.c s21_strrchr.c s21_strstr.c \
		s21_strtok.c s21_strerror.c s21_strpbrk.c s21_insert.c \
		s21_trim.c s21_to_lower.c s21_to_upper.c s21_strcpy.c \
		s21_sprintf.c
FILE_TESTS = ./suites/suite_insert.c ./suites/suite_memchr.c ./suites/suite_memcpy.c ./suites/suite_memset.c \
				./suites/suite_strchr.c ./suites/suite_strcspn.c ./suites/suite_strerror.c ./suites/suite_strlen.c ./suites/suite_strncat.c \
				./suites/suite_strncmp.c ./suites/suite_strncpy.c ./suites/suite_strpbrk.c ./suites/suite_strrchr.c ./suites/suite_strstr.c \
				./suites/suite_strtok.c ./suites/suite_to_lower.c ./suites/suite_to_upper.c ./suites/suite_trim.c \
				./suites/suite_sprintf.c ./suites/suite_memcmp.c 
TARGET=s21_string.a
TEST_FLAGS = -lcheck #-lm #-lsubunit

all: gcov_report

$(TARGET): 
	$(CC) ${CFLAGS} -c ${FILES}
	ar rc libs21_string.a s21*.o
	ranlib libs21_string.a
	cp libs21_string.a s21_string.a

test: $(TARGET)
	$(CC) test.c ${CFLAGS} ${FILES} ${FILE_TESTS} s21_string.h ${TEST_FLAGS} -o s21_string --coverage
	@echo "---------------------------TESTS--------------------------------------" 
	./s21_string
	@echo "----------------------------------------------------------------------"

gcov_report: test 
	lcov -t "gcov_report" -o Coverage_Report.info -c -d .
	genhtml -o ./report Coverage_Report.info
	open ./report/src/index.html

clean:
	rm -rf s21_math
	rm -rf *.out
	rm -rf *.o
	rm -rf *.a
	rm -rf *.gcno
	rm -rf *.gch
	rm -rf *.gcda
	rm -rf *.gcov
	rm -rf *.info
	rm -rf *.html
	rm -rf *.css
	rm -rf test
	rm -rf gcov_test
	rm -rf test report