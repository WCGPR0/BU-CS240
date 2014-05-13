PROJECT=vwu4_lab06_a.tar.gz
COMPILIER=g++
CFLAGS=-c -Wall -std=c++0x
LDFLAGS=-g
SOURCES=Node.cpp LinkedList.cpp Driver.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=linkedList

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(COMPILIER) $(LDFLAGS) $(OBJECTS) -o $@
.cpp.o:
	$(COMPILIER) $(LDFLAGS)  $(CFLAGS) $< -o $@

$(PROJECT).tar.gz \
dist:	$(SOURCES)
	tar -czvf $(PROJECT).tar $(SOURCES) LinkedList.h Node.h makefile
	gzip $(PROJECT).tar

clean:
	rm -f *.o $(EXECUTABLE)
