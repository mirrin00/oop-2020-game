CC = g++
CFLAGS = -std=c++17 -I../include -L../lib -lobjects -ltypes -lboost_unit_test_framework
OBJ = tmp/suite1.o \
	  tmp/suite2.o \
	  tmp/suite3.o \
	  tmp/main_test.o
TESTS = tests

.PHONY: all clean

all: $(TESTS)
	@echo "Running tests..."
	./$(TESTS)

clean:
	@echo "Cleanning..."
	rm -rf tmp rm $(TESTS)

tmp/%.d: %.cc | tmp
	@echo "Create $@ dependency..."
	rm -rf $@
	$(CC) -MM -MT $@ $(CFLAGS) $< > $@

tmp/%.o: %.cc tmp/%.d | tmp
	@echo "Compile $@..."
	$(CC) -c $(CFLAGS) $< -o $@


$(TESTS): $(OBJ)
	@echo "Compile $@..."
	$(CC) $(OBJ) $(CFLAGS) -o $@

tmp:
	@mkdir -p tmp

include $(OBJ:.o=.d)