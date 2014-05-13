PROJECT=vwu4_05_nodeB.tar.gz
COMPILIER=g++
CFLAGS=-c -Wall -std=c++0x
LDFLAGS=-g
SOURCES=Node.cpp Main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=node_b

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(COMPILIER) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(COMPILIER) $(CFLAGS) $< -o $@

$(PROJECT).tar.gz \
dist:	$(SOURCES)
	tar -czvf $(PROJECT).tar $(SOURCES) Node.h makefile
	gzip $(PROJECT).tar

clean:
	rm -f *.o $(EXEC1) $(EXEC2)
