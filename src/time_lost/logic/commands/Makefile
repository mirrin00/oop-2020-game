include ../../../../Header.mk
OFLAGS = -std=c++17 -fPIC -I../../../../include
TMP = ../tmp
OBJ = $(TMP)/player_move_down_command.o \
	  $(TMP)/player_move_up_command.o \
	  $(TMP)/player_move_left_command.o \
	  $(TMP)/player_move_right_command.o \
	  $(TMP)/player_interact_command.o \
	  $(TMP)/player_attack_command.o \
	  $(TMP)/pause_command.o \
	  $(TMP)/empty_command.o \
	  $(TMP)/save_command.o \
	  $(TMP)/direction_up_command.o \
	  $(TMP)/direction_down_command.o \
	  $(TMP)/direction_left_command.o \
	  $(TMP)/direction_right_command.o \
	  $(TMP)/player_rifle_weapon_command.o \
	  $(TMP)/player_pistol_weapon_command.o \
	  $(TMP)/player_knife_weapon_command.o \
	  $(TMP)/player_reload_command.o
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