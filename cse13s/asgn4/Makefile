CC = clang
CFLAGS = -Wall -Werror -Wextra -Wpedantic -g
LFLAGS = -lm

all: tsp

tsp: graph.o path.o stack.o tsp.o
	$(CC) $(CFLAGS) -o tsp tsp.o graph.o path.o stack.o $(LFLAGS)

tsp.o: tsp.c 
	$(CC) $(CFLAGS) -c tsp.c

graph.o: graph.c graph.h
	$(CC) $(CFLAGS) -c graph.c

path.o: path.c path.h
	$(CC) $(CFLAGS) -c path.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c


clean:
	rm -f tsp *.o

format:
	clang-format -i -style=file *.c *.h

scan-build: clean
	scan-build make
