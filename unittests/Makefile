COMPILER = g++
LIBS = -lobjects -ltypes
CFLAGS = -std=c++17 -I../include -L../lib
UNITTESTS = unittest1

all: $(UNITTESTS)
	@echo "Running UnitTest 1..."
	./unittest1
	@echo "All UnitTests done."

%: %.cc ../lib/*
	$(COMPILER) $< unittest.cc $(CFLAGS) $(LIBS) -o $@

clean:
	rm $(UNITTESTS)