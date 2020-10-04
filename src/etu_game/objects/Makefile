CC = g++
CFLAGS = -std=c++17 -I../../../include
OBJ = tmp/cell.o \
      tmp/field.o \
	  tmp/field_iterator.o \
	  tmp/essence.o \
	  tmp/item.o \
	  tmp/hands.o \
	  tmp/sword.o \
	  tmp/health_potion.o \
	  tmp/coin.o \
	  tmp/player.o 
LIB = tmp/libobjects.a
COLOR = \033[0;32m
NORMAL = \033[0m

.PHONY: all

all: $(LIB)

tmp/%.d: %.cc | tmp
	@echo "$(COLOR)Create $< dependency...$(NORMAL)"
	rm -rf $@
	$(CC) -MM -MT $@ $(CFLAGS) $< > $@

tmp/%.o: %.cc tmp/%.d | tmp
	@echo "$(COLOR)Compile $@...$(NORMAL)"
	$(CC) -c $(CFLAGS) $< -o $@


$(LIB): $(OBJ)
	@echo "$(COLOR)Compile lib $(LIB)...$(NORMAL)"
	ar rvs $(LIB) $(OBJ)
	cp $(LIB) ../../../lib

tmp:
	@mkdir -p tmp

.PHONY: clean

clean:
	@echo "$(COLOR)Cleanning...$(NORMAL)"
	rm -rf tmp

include $(OBJ:.o=.d)