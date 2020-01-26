CC=gcc
AR=ar -rcs
OBJECTS_MAIN=main.o
OBJECTS_LIB=mylib.o
FLAGS= -Wall -g
all: frequency
frequency:main.o Node.o
	$(CC) $(FLAGS) -o frequency $(OBJECTS_MAIN) Node.o 
Node.o:Node.c 
	$(CC) $(FLAGS) -c Node.c
main.o:main.c Node.h
	$(CC) $(FLAGS) -c main.c 
.PHONY: clean all

clean:
	rm -f *.o *.a *.so  frequency
