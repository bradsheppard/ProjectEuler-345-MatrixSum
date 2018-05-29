CC = gcc

HEADERS = matrix.h
OBJECTS = matrix.o main.o

default: maxsum

%.o: %.c $(HEADERS)
	$(CC) -c $< -o $@

maxsum: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

clean:
	-rm -f $(OBJECTS)
	-rm -f maxsum
