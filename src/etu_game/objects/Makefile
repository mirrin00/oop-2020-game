CC = g++
CFLAGS = -std=c++17 -I../../../include
OBJ = tmp/cell.o \
      tmp/field.o \
	  tmp/field_iterator.o
LIB = tmp/libobjects.a

.PHONY: all

all: $(LIB)

tmp/%.d: %.cc | tmp
	@echo "Create $@ dependency..."
	rm -rf $@
	$(CC) -MM -MT $@ $(CFLAGS) $< > $@

tmp/%.o: %.cc tmp/%.d | tmp
	@echo "Compile $@..."
	$(CC) -c $(CFLAGS) $< -o $@


$(LIB): $(OBJ)
	@echo "Compile lib $(LIB)..."
	ar rvs $(LIB) $(OBJ)
	cp $(LIB) ../../../lib

tmp:
	@mkdir -p tmp

.PHONY: clean

clean:
	@echo "Cleanning..."
	rm -rf tmp

include $(OBJ:.o=.d)