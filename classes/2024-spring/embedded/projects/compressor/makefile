CC = gcc
FLAGS = -g -Wall

default:
	$(CC) $(FLAGS) driver.c rle.c lzw.c huffman2.c -o compressor -lm

test:
	$(CC) $(FLAGS) testing.c rle.c lzw.c huffman.c-o tester -lm


clean:
	rm compressor
