COMPILER = g++
FLAGS = -g -Wall -std=c++0x
EXEC1 = prelab_a
EXEC2 = prelab_b

all: $(EXEC1) $(EXEC2)

$(EXEC1): Tester.o ClassB.o
	$(COMPILER) $(FLAGS) -o $(EXEC1) Tester.o ClassB.o

$(EXEC2): Driver.o ClassB.o
	$(COMPILER) $(FLAGS) -o $(EXEC2) Driver.o ClassB.o

Driver.o: Driver.cpp
	$(COMPILER) $(FLAGS) -c Driver.cpp

Tester.o: Tester.cpp
	$(COMPILER) $(FLAGS) -c Tester.cpp

ClassB.o: ClassB.cpp
	$(COMPILER) $(FLAGS) -c ClassB.cpp

clean:
	rm -f *.o $(EXEC1) $(EXEC2)
