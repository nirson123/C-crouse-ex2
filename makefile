CC = gcc
flags = -Wall -g

.PHONY: all clean

all: main

myBank.o : myBank.c myBank.h
	$(CC) $(flags) -c $< -o $@
	
main.o : main.c myBank.h
	$(CC) $(flags) -c $< -o $@
	
libmyBank.a: myBank.o
	ar rcs $@ $<
	
main : main.o libmyBank.a
	$(CC) $(flags) $^ -o $@
	
clean : 
	rm *.o *.a main 