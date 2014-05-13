PROJECT=vwu4_03_BagB
COMPILIER=g++
CFLAGS=-c -Wall -std=c++0x
LDFLAGS=-g
SOURCES=Bag.cpp BagTest.cpp Simple.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=submission

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(COMPILIER) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(COMPILIER) $(CFLAGS) $< -o $@

$(PROJECT).tar.gz \
dist:	$(SOURCES)
	tar -cvf $(PROJECT).tar $(SOURCES)
	gzip $(PROJECT).tar

clean:
	rm -f *.o $(EXEC1) $(EXEC2)
