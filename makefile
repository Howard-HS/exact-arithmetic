CC = g++
FLAGS = --std=c++11
INCLUDES = -I ./headers
SOURCE = ./src/gcd.cpp ./src/rational.cpp

make: interactive

interactive:
	$(CC) ./src/rational-interactive.cpp $(SOURCE) $(INCLUDES) -o rationalInteractive.out

cmdline:
	$(CC) ./src/rational-cmdline.cpp $(SOURCE) $(INCLUDES) -o rationalCmdline.out

test:
	$(CC) ./tests/test_rational.cpp $(SOURCE) $(INCLUDES) -lboost_unit_test_framework -o testRational.out  

clean:
	rm -rf *.out