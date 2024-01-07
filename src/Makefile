CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
FILES = s21_memchr.c s21_memcmp.c s21_memcpy.c s21_memset.c \
		s21_strchr.c s21_strcspn.c s21_strlen.c s21_strncat.c \
		s21_strncmp.c s21_strncpy.c s21_strrchr.c s21_strstr.c \
		s21_strtok.c s21_strerror.c s21_strpbrk.c s21_insert.c \
		s21_trim.c s21_to_lower.c s21_to_upper.c s21_strcpy.c \
		s21_sprintf.c
FILE_TESTS =./tests/test_me.c ./tests/test_memchr.c ./tests/test_memcmp.c ./tests/test_memcpy.c \
		./tests/test_memset.c ./tests/test_strncat.c ./tests/test_strchr.c ./tests/test_strncmp.c \
		./tests/test_strncpy.c ./tests/test_strlen.c ./tests/test_strrchr.c ./tests/test_strtok.c \
		./tests/test_strstr.c ./tests/test_strcspn.c ./tests/test_strerror.c ./tests/test_strpbrk.c \
		./tests/test_strcpy.c ./tests/test_insert.c ./tests/test_to_lower.c \
		./tests/test_to_upper.c ./tests/test_trim.c ./tests/test_sprintf_pointer.c \
		./tests/test_sprintf_percent.c ./tests/test_sprintf_n.c ./tests/test_sprintf_i.c ./tests/test_sprintf_d.c \
		./tests/test_sprintf_string.c ./tests/test_sprintf_f.c ./tests/test_sprintf_unsigned.c \
		./tests/test_sprintf_e.c ./tests/test_sprintf_g.c ./tests/test_sprintf_octal.c ./tests/test_sprintf_hex1.c \
		./tests/test_sprintf_hex2.c 
		

TARGET=s21_string.a
TEST_FLAGS = -lcheck -lm -lsubunit

all: gcov_report

$(TARGET): 
	$(CC) ${CFLAGS} -c ${FILES}
	ar rc libs21_string.a s21*.o
	ranlib libs21_string.a
	cp libs21_string.a s21_string.as

test: $(TARGET)
	$(CC) ${CFLAGS} ${FILES} ${FILE_TESTS} s21_string.h s21_sprintf.h ${TEST_FLAGS} -o s21_string --coverage
	@echo "---------------------------TESTS--------------------------------------" 
	./s21_string
	@echo "----------------------------------------------------------------------"

run:
#	gcc -g -Wall -Wextra -Werror -std=c11 -lm s21_sprintf.c s21_memcpy.c s21_strlen.c s21_strncpy.c s21_strchr.c
	gcc -g -Wall -Wextra -Werror -std=c11 -lm test_main0.c s21_memcpy.c s21_strlen.c s21_strncpy.c s21_strchr.c

gcov_report: test 
	lcov -t "test" -o test.info -c -d .	
	genhtml -o report test.info
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
	rm -rf test repor