CC = gcc
CFLAGS = -Wall -Werror -Og -g

all: matrix_main matrix_mul_main

matrix_main: matrix_main.c matrix_funcs.o matrix_funcs_student.o
	$(CC) $(CFLAGS) -o $@ $^

matrix_mul_main: matrix_mul_main.c matrix_funcs.o matrix_funcs_student.o \
	matmul.o matmul_student.o
	$(CC) $(CFLAGS) -o $@ $^

matrix_funcs.o: matrix_funcs.c matrix.h
	$(CC) $(CFLAGS) -c matrix_funcs.c

matrix_funcs_student.o: matrix_funcs_student.c matrix.h
	$(CC) $(CFLAGS) -c matrix_funcs_student.c

matmul.o: matmul.c matrix.h
	$(CC) $(CFLAGS) -c matmul.c

matmul_student.o: matmul_student.c
	$(MAKE) -f Makefile_matmul $@

test: matrix_main
	@echo "------Running speed test with nicely sized matrix------"
	@./matrix_main --even | tee evenResults.txt
	@echo "------Running speed test with oddly-sized matrix------"
	@./matrix_main --odd | tee nonEvenResults.txt
	@cat evenResults.txt nonEvenResults.txt | grep '^Ratio' > ratios.txt

testmul: matrix_mul_main
	@./matrix_mul_main 2357 3001 1693 | tee matmul.txt

clean:
	rm -f *.o *.gch matrix_main matrix_mul_main

clean-results:
	rm -f ratios.txt evenResults.txt nonEvenResults.txt matmul.txt
