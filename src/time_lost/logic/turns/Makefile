include ../../../../Header.mk
OFLAGS = -std=c++17 -fPIC -I../../../../include
TMP = ../tmp
OBJ = $(TMP)/player_turn.o \
      $(TMP)/pause_turn.o \
	  $(TMP)/enemy_turn.o
COLOR = \033[0;32m
NORMAL = \033[0m

.PHONY: all

all: $(OBJ)

$(TMP)/%.d: %.cc | $(TMP)
	@echo "$(COLOR)Create $< dependency...$(NORMAL)"
	rm -rf $@
	$(CC) -MM -MT $@ $(CFLAGS) $(OFLAGS) $< > $@

$(TMP)/%.o: %.cc $(TMP)/%.d | $(TMP)
	@echo "$(COLOR)Compile $@...$(NORMAL)"
	$(CC) -c $(CFLAGS) $(OFLAGS) $< -o $@

$(TMP):
	@mkdir -p $(TMP)

.PHONY: clean

clean:
	@echo "$(COLOR)Cleanning...$(NORMAL)"
	rm -rf $(TMP)

include $(OBJ:.o=.d)