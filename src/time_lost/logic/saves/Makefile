include ../../../../Header.mk
OFLAGS = -std=c++17 -fPIC -I../../../../include
TMP = ../tmp
OBJ = $(TMP)/coin_save.o \
	  $(TMP)/enemy_save_interface.o \
	  $(TMP)/field_save.o \
	  $(TMP)/hands_save.o \
	  $(TMP)/health_potion_save.o \
	  $(TMP)/player_save.o \
	  $(TMP)/sword_save.o \
	  $(TMP)/time_lost_save.o
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