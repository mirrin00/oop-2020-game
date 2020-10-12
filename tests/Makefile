CC = g++
CFLAGS = -std=c++17 -I../include -L../lib -lobjects -ltypes -llogic -lboost_unit_test_framework
OBJ = tmp/suite1.o \
	  tmp/suite2.o \
	  tmp/suite3.o \
	  tmp/suite4.o \
	  tmp/main_test.o
TESTS = tests
COLOR = \033[0;32m
NORMAL = \033[0m

.PHONY: all clean

all: $(TESTS)
	@echo "$(COLOR)Running tests...$(NORMAL)"
	-./$(TESTS) 
	rm -rf *.testing

clean:
	@echo "$(COLOR)Cleanning...$(NORMAL)"
	rm -rf tmp rm $(TESTS)

tmp/%.d: %.cc | tmp
	@echo "$(COLOR)Create $@ dependency...$(NORMAL)"
	rm -rf $@
	$(CC) -MM -MT $@ $(CFLAGS) $< > $@

tmp/%.o: %.cc tmp/%.d | tmp
	@echo "$(COLOR)Compile $@...$(NORMAL)"
	$(CC) -c $(CFLAGS) $< -o $@


$(TESTS): $(OBJ)
	@echo "$(COLOR)Compile $@...$(NORMAL)"
	$(CC) $(OBJ) $(CFLAGS) -o $@

tmp:
	@mkdir -p tmp

include $(OBJ:.o=.d)