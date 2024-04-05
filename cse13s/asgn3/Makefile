CC = clang
CFLAGS = -Wall -Werror -Wextra -Wpedantic -g
LFLAGS = -lm 


all: sorting

sorting: insert.o heap.o quick.o stats.o shell.o sorting.o
	$(CC) $(CFLAGS) -o sorting insert.o heap.o quick.o stats.o shell.o sorting.o $(LFLAGS)

sorting.o: sorting.c set.h
	$(CC) $(CFLAGS) -c sorting.c

insert.o: insert.c insert.h
	$(CC) $(CFLAGS) -c insert.c

heap.o: heap.c heap.h
	$(CC) $(CFLAGS) -c heap.c

quick.o: quick.c quick.h
	$(CC) $(CFLAGS) -c quick.c

stats.o: stats.c stats.h
	$(CC) $(CFLAGS) -c stats.c

shell.c: shell.c shell.h
	$(CC) $(CFLAGS) -c shell.c

clean:
	rm -f sorting *.o

format:
	clang-format -i -style=file *.c *.h

scan-build: clean
	scan-build make
