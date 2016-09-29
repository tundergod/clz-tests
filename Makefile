CC = gcc
CFLAGS = -O0 -std=gnu99
EXECUTABLE = \
	clz_recursive clz_iteration clz_binary clz_byte clz_harley \
	time_test benchmark_clock_gettime 
	
default: clz.o
	$(CC) $(CFLAGS)  clz.o time_test.c -DCLZ1 -o clz_recursive
	$(CC) $(CFLAGS)  clz.o time_test.c -DCLZ2 -o clz_iteration
	$(CC) $(CFLAGS)  clz.o time_test.c -DCLZ3 -o clz_binary
	$(CC) $(CFLAGS)  clz.o time_test.c -DCLZ4 -o clz_byte
	$(CC) $(CFLAGS)  clz.o time_test.c -DCLZ5 -o clz_harley
	$(CC) $(CFLAGS)  clz.o benchmark_clock_gettime.c -o benchmark_clock_gettime

.PHONY: clean default

check: default
	time ./clz_recursive
	time ./clz_iteration
	time ./clz_binary
	time ./clz_byte
	time ./clz_harley

gensv: default
	./benchmark_clock_gettime 10000\
	done > result.csv 

plot: result.csv
	gnuplot clz_runtime.gp

clean:
	rm -f $(EXECUTABLE) *.o *.s result.csv runtime.gp
