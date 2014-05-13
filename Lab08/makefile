COMPILER = g++
FLAGS = -g -Wall -std=c++0x
EXEC1 = p1
PROJECT = vwu4_lab08

all: $(EXEC1)

$(EXEC1): Driver.o
	$(COMPILER) $(FLAGS) -o $(EXEC1) $<

Driver.o: Driver.cpp
	$(COMPILER) $(FLAGS) -c $<	

clean:
	rm -f *.o $(EXEC1) $(PROJECT).tar.gz STACK.CHKSUM QUEUE.CHKSUM

$(PROJECT).tar.gz \
dist:	Driver.cpp 
	tar -czvf $(PROJECT).tar Driver.cpp makefile 
	gzip $(PROJECT).tar 
