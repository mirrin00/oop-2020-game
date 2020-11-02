CC = g++
CFLAGS = -std=c++17 -I../include -L../lib -lobjects -ltypes -llogic -lsfml-system -lsfml-graphics  -lsfml-window
OBJ = tmp/game.o
GAME = game
COLOR = \033[0;32m
NORMAL = \033[0m

.PHONY: all clean

all: $(GAME)

clean:
	@echo "$(COLOR)Cleanning...$(NORMAL)"
	rm -rf tmp $(GAME) *.log

tmp/%.d: %.cc | tmp
	@echo "$(COLOR)Create $@ dependency...$(NORMAL)"
	rm -rf $@
	$(CC) -MM -MT $@ $(CFLAGS) $< > $@

tmp/%.o: %.cc tmp/%.d | tmp
	@echo "$(COLOR)Compile $@...$(NORMAL)"
	$(CC) -c $(CFLAGS) $< -o $@


$(GAME): $(OBJ)
	@echo "$(COLOR)Compile $@...$(NORMAL)"
	$(CC) $(OBJ)  -Wl,-rpath=$(PWD)/lib  $(CFLAGS) -o $@

tmp:
	@mkdir -p tmp

include $(OBJ:.o=.d)