# Makefile for ex1-q1 winter 2020A
CFLAGS = -g -Wall
LDFLAGS = -lm # not really needed for this exercise
CC = gcc -std=c99
ECHO = echo "going to compile for target $@"
PROG = ex1_q1

all: $(PROG) test
#all: main.o ex1_q1_given.o LinkedList.o 
#	$(CC) $(CFLAGS) main LinkedList ex1_q1  -o prog

$(PROG): main.o ex1_q1_given.o LinkedList.o 
	$(CC) $(CFLAGS) main.o LinkedList.o ex1_q1_given.o  -o $(PROG)

test:
	# make sure you have input file in.txt.
	# so the following command works
	./$(PROG) < in.txt > out.log

main:  main.c
	$(CC) $(CFLAGS) -c main.c

ex1_q1_prog:  ex1_q1.h ex1_q1_given.c
	$(CC) $(CFLAGS) -c ex1_q1_given.c

LinkedList:  LinkedList.h LinkedList.c 
	$(CC) $(CFLAGS) -c LinkedList.c

clean: 
	$(RM) *.o *~ $(PROG)