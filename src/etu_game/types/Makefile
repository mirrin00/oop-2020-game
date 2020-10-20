CC = g++
CFLAGS = -std=c++17 -fPIC -I../../../include
OBJ = tmp/etu_game_exception.o
LIB = tmp/libtypes.so
COLOR = \033[0;32m
NORMAL = \033[0m

.PHONY: all
all: $(LIB)

tmp/%.d: %.cc | tmp
	@echo "$(COLOR)Create $@ dependency...$(NORMAL)"
	rm -rf $@
	$(CC) -MM -MT $@ $(CFLAGS) $< > $@

tmp/%.o: %.cc tmp/%.d | tmp
	@echo "$(COLOR)Compile $@...$(NORMAL)"
	$(CC) -c $(CFLAGS) $< -o $@


$(LIB): $(OBJ)
	@echo "$(COLOR)Compile lib $(LIB)...$(NORMAL)"
	g++ -shared -o $(LIB) $(OBJ)
	cp $(LIB) ../../../lib

tmp:
	@mkdir -p tmp

.PHONY: clean
clean:
	@echo "$(COLOR)Cleanning...$(NORMAL)"
	rm -rf tmp

include $(OBJ:.o=.d)