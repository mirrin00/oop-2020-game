include ../../../Header.mk
OFLAGS = -std=c++17 -fPIC -I../../../include
TMP = tmp
OBJ = $(TMP)/logger.o \
      $(TMP)/publisher.o \
      $(TMP)/time_lost.o \
	  $(TMP)/logging_interface.o \
	  $(TMP)/menu_item_interface.o \
	  $(TMP)/menu.o \
	  $(TMP)/save_writer.o \
	  $(TMP)/save_reader.o
COMMANDS = $(TMP)/player_move_down_command.o \
           $(TMP)/player_move_up_command.o \
           $(TMP)/player_move_left_command.o \
           $(TMP)/player_move_right_command.o \
           $(TMP)/player_interact_command.o \
		   $(TMP)/player_attack_command.o \
		   $(TMP)/pause_command.o \
		   $(TMP)/empty_command.o \
		   $(TMP)/save_command.o
TURNS = $(TMP)/player_turn.o \
        $(TMP)/pause_turn.o \
	    $(TMP)/enemy_turn.o \
		$(TMP)/exit_turn.o \
		$(TMP)/start_menu_turn.o \
		$(TMP)/win_turn.o \
		$(TMP)/lose_turn.o 
MENUS = $(TMP)/menu_item_exit.o \
		$(TMP)/menu_item_load.o \
		$(TMP)/menu_item_save.o \
		$(TMP)/menu_item_start.o 
SAVES = $(TMP)/coin_save.o \
		$(TMP)/enemy_save_interface.o \
		$(TMP)/field_save.o \
		$(TMP)/hands_save.o \
		$(TMP)/health_potion_save.o \
		$(TMP)/player_save.o \
		$(TMP)/sword_save.o \
		$(TMP)/time_lost_save.o
LIB = $(TMP)/liblogic.so
COLOR = \033[0;32m
NORMAL = \033[0m

.PHONY: all commands turns menus saves

all: $(LIB)

$(TMP)/%.d: %.cc | $(TMP)
	@echo "$(COLOR)Create $< dependency...$(NORMAL)"
	rm -rf $@
	$(CC) -MM -MT $@ $(CFLAGS) $(OFLAGS) $< > $@

$(TMP)/%.o: %.cc $(TMP)/%.d | $(TMP)
	@echo "$(COLOR)Compile $@...$(NORMAL)"
	$(CC) -c $(CFLAGS) $(OFLAGS) $< -o $@


$(LIB): $(OBJ) commands turns menus saves
	@echo "$(COLOR)Link library $(LIB)...$(NORMAL)"
	g++ -shared -o $(LIB) $(OBJ) $(COMMANDS) $(TURNS) $(MENUS) $(SAVES)
	cp $(LIB) ../../../lib

commands: $(TMP)
	$(MAKE) -C commands

turns: $(TMP)
	$(MAKE) -C turns

menus: $(TMP)
	$(MAKE) -C menu_items

saves: $(TMP)
	$(MAKE) -C saves

$(TMP):
	@mkdir -p $(TMP)

.PHONY: clean

clean:
	@echo "$(COLOR)Cleanning...$(NORMAL)"
	rm -rf $(TMP)

include $(OBJ:.o=.d)