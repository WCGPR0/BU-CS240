COMPILER = g++
FLAGS = -g -Wall -std=c++0x
EXEC1 = a
PROJECT = vwu4_lab09

all: $(EXEC1)

$(EXEC1): DataProcessor.o Driver.o
	$(COMPILER) $(FLAGS) -o $(EXEC1) $^

Driver.o: Driver.cpp
	$(COMPILER) $(FLAGS) -c $<	

DataProcessor.o: DataProcessor.cpp
	$(COMPILER) $(FLAGS) -c $<

clean:
	rm -f *.o $(EXEC1) $(PROJECT).tar.gz 

$(PROJECT).tar.gz \
dist:	Driver.cpp 
	tar -czvf $(PROJECT).tar DataProcessor.cpp DataProcessor.h  Driver.cpp makefile output_to_graph 
	gzip $(PROJECT).tar 
