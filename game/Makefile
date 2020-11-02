include ../Header.mk
OFLAGS = -I../include -L../lib -lobjects -ltypes -llogic -lsfml-system -lsfml-graphics  -lsfml-window
TMP = tmp
OBJ = $(TMP)/game.o
GAME = game
COLOR = \033[0;32m
NORMAL = \033[0m

.PHONY: all clean

all: $(GAME)

clean:
	@echo "$(COLOR)Cleanning...$(NORMAL)"
	rm -rf $(TMP) $(GAME) *.log

$(TMP)/%.d: %.cc | $(TMP)
	@echo "$(COLOR)Create $@ dependency...$(NORMAL)"
	rm -rf $@
	$(CC) -MM -MT $@ $(CFLAGS) $(OFLAGS) $< > $@

$(TMP)/%.o: %.cc $(TMP)/%.d | $(TMP)
	@echo "$(COLOR)Compile $@...$(NORMAL)"
	$(CC) -c $(CFLAGS) $(OFLAGS) $< -o $@


$(GAME): $(OBJ)
	@echo "$(COLOR)Compile $@...$(NORMAL)"
	$(CC) $(OBJ)  -Wl,-rpath=$(PWD)/lib  $(CFLAGS) $(OFLAGS) -o $@

$(TMP):
	@mkdir -p $(TMP)

include $(OBJ:.o=.d)