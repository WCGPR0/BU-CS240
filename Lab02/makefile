COMPILER = g++
FLAGS = -g -Wall -std=c++0x
EXEC1 = lab2_b

all: $(EXEC1)

$(EXEC1): Driver.o Circle.o Point.o
	$(COMPILER) $(FLAGS) -o $(EXEC1) Driver.o Circle.o Point.o	

Circle.o: Circle.cpp
	$(COMPILER) $(FLAGS) -c Circle.cpp

Tester.o: Driver.cpp
	$(COMPILER) $(FLAGS) -c Driver.cpp

Point.o: Point.cpp
	$(COMPILER) $(FLAGS) -c Point.cpp

clean:
	rm -f *.o $(EXEC1) $(EXEC2)
