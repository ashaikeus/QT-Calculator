FLAGS = -Wall -Werror -Wextra -std=c11
LIB_FLAGS = -lcheck -lgcov
CODE_FILES = s21_*.c
TEST_FILES = test.c

all:
	gcc $(TEST_FILES) $(CODE_FILES) -o test -lcheck
	./test

style:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n *.c *.cpp *.h
	clang-format -i *.c *.cpp *.h
	rm .clang-format

checks: style
	gcc $(FLAGS) $(CODE_FILES) $(TEST_FILES) $(LIB_FLAGS)
	cppcheck *.c *.h

clean:
	rm -rf report *.a *.o *.gcda *.gcno *.gcov *.info test ./a.out *.dSYM
	rm -rf doxy* ./html ./latex

test: clean
	gcc $(TEST_FILES) $(CODE_FILES) -o test -lcheck
	./test
	rm ./test

main:
	gcc $(CODE_FILES)
	./a.out
	rm ./a.out

gcov_report:
	gcc --coverage $(CODE_FILES) $(TEST_FILES) $(LIB_FLAGS) -o test
	./test
	lcov -o test.info -c -d .
	genhtml -o report test.info
	open ./report/index.html

install: 
	mkdir kylebrea_SmartCalc
	cd kylebrea_SmartCalc && qmake ../C7-SmartCalc.pro && make

uninstall:
	rm -rf kylebrea_SmartCalc

dvi:
	doxygen -g doxyconfig
	doxygen doxyconfig
	open ./html/index.html

dist:
	tar -cf kylebrea_C7_SmartCalc_v1.0.tar *.cpp *.c *.h *.ui *.pro Makefile