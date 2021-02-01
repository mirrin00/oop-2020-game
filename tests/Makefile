include ../Header.mk
OFLAGS = -I../include -L../lib -lobjects -ltypes -llogic -lboost_unit_test_framework
TMP = tmp
OBJ = $(TMP)/suite1.o \
	  $(TMP)/suite2.o \
	  $(TMP)/suite3.o \
	  $(TMP)/suite5.o \
	  $(TMP)/suite6.o \
	  $(TMP)/main_test.o # $(TMP)/suite4.o
TESTS = tests
COLOR = \033[0;32m
NORMAL = \033[0m

.PHONY: all clean

all: $(TESTS)
	@echo "$(COLOR)Running tests...$(NORMAL)"
	-./$(TESTS) 
	rm -rf *.testing *.save

clean:
	@echo "$(COLOR)Cleanning...$(NORMAL)"
	rm -rf $(TMP) rm $(TESTS)

$(TMP)/%.d: %.cc | $(TMP)
	@echo "$(COLOR)Create $@ dependency...$(NORMAL)"
	rm -rf $@
	$(CC) -MM -MT $@ $(CFLAGS) $(OFLAGS) $< > $@

$(TMP)/%.o: %.cc $(TMP)/%.d | $(TMP)
	@echo "$(COLOR)Compile $@...$(NORMAL)"
	$(CC) -c $(CFLAGS) $(OFLAGS) $< -o $@


$(TESTS): $(OBJ)
	@echo "$(COLOR)Link $@...$(NORMAL)"
	$(CC) $(OBJ)  -Wl,-rpath=$(PWD)/lib $(CFLAGS) $(OFLAGS) -o $@

$(TMP):
	@mkdir -p $(TMP)

include $(OBJ:.o=.d)