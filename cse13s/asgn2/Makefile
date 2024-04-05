CC = clang
CFLAGS = -Wall -Werror -Wextra -Wpedantic
LFLAGS = -lm

all: mathlib-test e.o newton.o madhava.o euler.o bbp.o viete.o

mathlib-test: mathlib-test.o e.o newton.o madhava.o euler.o bbp.o viete.o
	$(CC) $(CFLAGS) -o mathlib-test mathlib-test.o e.o newton.o madhava.o euler.o bbp.o viete.o $(LFLAGS) 

mathlib-test.o: mathlib-test.c mathlib.h
	$(CC) $(CFLAGS) -c mathlib-test.c

e.o: e.c mathlib.h
	$(CC) $(CFLAGS) -c e.c

newton.o: newton.c mathlib.h
	$(CC) $(CFLAGS) -c newton.c

madhava.o: madhava.c mathlib.h
	$(CC) $(CFLAGS) -c madhava.c

euler.o: euler.c mathlib.h
	$(CC) $(CFLAGS) -c euler.c

bbp.o: bbp.c mathlib.h
	 $(CC) $(CFLAGS) -c bbp.c
  
viete.o: viete.c mathlib.h
	$(CC) $(CFLAGS) -c viete.c

clean:
	rm -f e_test mathlib-test *.o *.exe

format:
	clang-format -i -style=file *.c *.h

scan-build: clean  
	scan -build make
  

