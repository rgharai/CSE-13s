CC = clang 
CFLAGS = -Wall -Wextra -Werror -Wpedantic
LFLAGS = -lm
OBJECTS = code.o huffman.o io.o node.o pq.o stack.o 

all: encode decode

encode: $(OBJECTS) encode.o 
	$(CC) $(LFLAGS) -o encode $(OBJECTS) encode.o 

decode: $(OBJECTS) decode.o 
	$(CC) $(LFLAGS) -o decode $(OBJECTS) decode.o 



%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.h
	$(CC) $(CFLAGS) -h $< -o $@
	
clean:
	rm -f encode decode $(OBJECTS) encode.o decode.o

scan-build: clean
	scan-build make   
	
format: 
	clang-format -i -style=file *.[c,h]
