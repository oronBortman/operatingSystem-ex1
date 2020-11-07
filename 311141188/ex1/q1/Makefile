# Makefile for ex1-q1 winter 2020A
CFLAGS = -g -Wall
LDFLAGS = -lm # not really needed for this exercise
CC = gcc -std=c99
ECHO = echo "going to compile for target $@"
PROG = ex1_q1

all: $(PROG) test

$(PROG): ex1_q1.o LinkedList.o 
	$(CC) $(CFLAGS) LinkedList.o ex1_q1.o  -o $(PROG)

test:
	# make sure you have input file in.txt.
	# so the following command works
	./$(PROG) < in.txt > out.log

ex1_q1.o:  ex1_q1.h ex1_q1.c
	$(CC) $(CFLAGS) -c ex1_q1.c

LinkedList.o:  LinkedList.h LinkedList.c 
	$(CC) $(CFLAGS) -c LinkedList.c

clean: 
	$(RM) *.o *~ $(PROG)