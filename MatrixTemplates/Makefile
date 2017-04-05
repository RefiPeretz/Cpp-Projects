CPPFLAGS=-std=c++11 -pthread -Wall -Wextra -Wvla -O
CC = g++


.SUFFIXES:

Matrix: Matrix.hpp.gch

Matrix.hpp.gch: Matrix.hpp
	$(CC) $(CPPFLAGS) -x c++-header Matrix.hpp

tar:
	tar cvf ex3.tar Matrix.hpp Makefile README

clean:
	rm -rf *.gch ex3.tar

.PHONY: clean
	
.DEFAULT_GOAL := Matrix.hpp.gch