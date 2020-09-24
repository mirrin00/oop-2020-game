COMPILER = g++
CFLAGS = -std=c++17 -I../../../include
OBJ = tmp/cell.o \
      tmp/field.o \
	  tmp/field_iterator.o
INCLUDE_OBJECTS = ../../../include/etu_game/objects/
INCLUDE_TYPES = ../../../include/etu_game/types/
OUTPUT = tmp/libobjects.a

all: $(OUTPUT)
#	cp $(OUTPUT) ../../../lib

tmp/cell.o: cell.cc $(INCLUDE_OBJECTS)cell.h $(INCLUDE_TYPES)cell_type.h
	@echo "Compile $@..."
	$(COMPILER) -c $(CFLAGS) $< -o $@

tmp/field.o: field.cc $(INCLUDE_OBJECTS)field.h $(INCLUDE_TYPES)etu_game_exception.h
	@echo "Compile $@..."
	$(COMPILER) -c $(CFLAGS) $< -o $@

tmp/field_iterator.o: field_iterator.cc $(INCLUDE_OBJECTS)field_iterator.h $(INCLUDE_OBJECTS)field.h $(INCLUDE_TYPES)etu_game_exception.h
	@echo "Compile $@..."
	$(COMPILER) -c $(CFLAGS) $< -o $@

$(OUTPUT): tmp $(OBJ)
	@echo "Compile lib $(OUTPUT)..."
	ar rvs $(OUTPUT) $(OBJ)
	cp $(OUTPUT) ../../../lib

tmp:
	mkdir tmp

clean:
	@echo "Cleanning..."
	rm -r tmp
