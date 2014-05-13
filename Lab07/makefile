COMPILER = g++
FLAGS = -g -Wall -std=c++0x
EXEC1 = lab07
PROJECT = vwu4_lab07

all: $(EXEC1)

$(EXEC1): Driver.o DLinkedList.o Node.o Stack.o Queue.o
	$(COMPILER) $(FLAGS) -o $(EXEC1) Driver.o DLinkedList.o Node.o Stack.o Queue.o

Driver.o: Driver.cpp
	$(COMPILER) $(FLAGS) -c Driver.cpp

DlinkedList.o: DLinkedList.cc
	$(COMPILER) $(FLAGS) -c DLinkedList.cc

Node.o: Node.cpp
	$(COMPILER) $(FLAGS) -c Node.cpp

Stack.o: Stack.h
	$(COMPILER) $(FLAGS) -c Node.h

Queue.o: Queue.h
	$(COMPILER) $(FLAGS) -c Queue.h

clean:
	rm -f *.o $(EXEC1) $(PROJECT).tar.gz STACK.CHKSUM QUEUE.CHKSUM

$(PROJECT).tar.gz \
dist:	Driver.cpp Node.cpp Stack.h Queue.h Stack.cc Queue.cc DLinkedList.h DLinkedList.cc makefile
	md5sum Stack.cc > STACK.CHKSUM
	md5sum Queue.cc > QUEUE.CHKSUM
	tar -czvf $(PROJECT).tar Driver.cpp Node.cpp Node.h Stack.h Queue.h Stack.cc Queue.cc DLinkedList.h DLinkedList.cc makefile \
	STACK.CHKSUM QUEUE.CHKSUM
	gzip $(PROJECT).tar 
