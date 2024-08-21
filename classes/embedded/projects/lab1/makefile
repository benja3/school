# Makefile for Linux only

CC = gcc
FLAGS = -fPIC -g -Wall

libimgdisp.a:
	$(CC) $(FLAGS) -c imgdisp.c -o imgdisp.o 
	ar rcs libimgdisp.a imgdisp.o

test: libimgdisp.a 
	$(CC) $(FLAGS) test-driver.c libimgdisp.a -o test

lab1: libimgdisp.a
	$(CC) $(FLAGS) lab1-X-handout.c libimgdisp.a -o lab1

clean:
	rm -f imgdisp.o libimgdisp.a lab1 test

