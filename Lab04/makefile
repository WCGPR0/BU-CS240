PROJECT=vwu4_04_TextProcB.tar.gz
COMPILIER=g++
CFLAGS=-c -Wall -std=c++0x
LDFLAGS=-g
SOURCES=Word.cpp Main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=submission

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(COMPILIER) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(COMPILIER) $(CFLAGS) $< -o $@

$(PROJECT).tar.gz \
dist:	$(SOURCES)
	tar -czvf $(PROJECT).tar $(SOURCES) Word.h makefile
	gzip $(PROJECT).tar

clean:
	rm -f *.o $(EXEC1) $(EXEC2)
