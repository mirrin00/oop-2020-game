CC = g++
CFLAGS = -std=c++17 -I../include -L../lib -lobjects -ltypes
SOURCES = test1.cc \
		  test2.cc \
		  test3.cc
MAIN = tmp/main_test.o
TESTS = tests

.PHONY: all clean

all: run_tests
	./$(TESTS)

clean:
	@echo "Cleanning..."
	rm -rf tmp rm $(TESTS)


run_tests: $(TESTS)

tmp/%.d: %.cc | tmp
	@echo "Create $@ dependency..."
	rm -rf $@
	$(CC) -MM -MT $@ $(CFLAGS) $< > $@

tmp/%.o: %.cc tmp/%.d | tmp
	@echo "Compile $@..."
	$(CC) -c $(CFLAGS) $< -o $@


$(TESTS): $(MAIN) $(SOURCES)
	@echo "Compile $@..."
	$(CC) $(OBJ) $(MAIN) $(SOURCES) $(CFLAGS) -o $@

tmp:
	@mkdir -p tmp

include $(OBJ:.o=.d)