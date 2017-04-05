LINKAGE = -c
WARNINGS = -std=c++11 -Wall -Wextra
CC = g++


all: IntMatrix tar

tar:
	tar cvf ex1.tar IntMatrixDriver.cpp IntMatrix.h IntMatrix.cpp Makefile

IntMatrix: IntMatrixDriver.o IntMatrix.o
	$(CC) $(WARNINGS) IntMatrixDriver.o IntMatrix.o -o  IntMatrixMainDriver

IntMatrixDriver.o: IntMatrixDriver.cpp IntMatrix.h
	$(CC) $(LINKAGE) $(WARNINGS) IntMatrixDriver.cpp

IntMatrix.o: IntMatrix.cpp IntMatrix.h
	$(CC) $(LINKAGE) $(WARNINGS) IntMatrix.cpp

clean:
	rm -f IntMatrixDriver *.o ex1.tar

.PHONY: all clean tar