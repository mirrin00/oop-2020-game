include ../../../Header.mk
OFLAGS = -std=c++17 -fPIC -I../../../include
TMP = tmp
OBJ = $(TMP)/logger.o \
      $(TMP)/publisher.o \
      $(TMP)/time_lost.o \
	  $(TMP)/logging_interface.o 
COMMANDS = $(TMP)/player_move_down_command.o \
           $(TMP)/player_move_up_command.o \
           $(TMP)/player_move_left_command.o \
           $(TMP)/player_move_right_command.o \
           $(TMP)/player_interact_command.o \
		   $(TMP)/player_attack_command.o \
		   $(TMP)/pause_command.o \
		   $(TMP)/empty_command.o 
TURNS = $(TMP)/player_turn.o \
        $(TMP)/pause_turn.o \
	    $(TMP)/enemy_turn.o
LIB = $(TMP)/liblogic.so
COLOR = \033[0;32m
NORMAL = \033[0m

.PHONY: all commands turns

all: $(LIB)

$(TMP)/%.d: %.cc | $(TMP)
	@echo "$(COLOR)Create $< dependency...$(NORMAL)"
	rm -rf $@
	$(CC) -MM -MT $@ $(CFLAGS) $(OFLAGS) $< > $@

$(TMP)/%.o: %.cc $(TMP)/%.d | $(TMP)
	@echo "$(COLOR)Compile $@...$(NORMAL)"
	$(CC) -c $(CFLAGS) $(OFLAGS) $< -o $@


$(LIB): $(OBJ) commands turns
	@echo "$(COLOR)Link library $(LIB)...$(NORMAL)"
	g++ -shared -o $(LIB) $(OBJ) $(COMMANDS) $(TURNS)
	cp $(LIB) ../../../lib

commands: $(TMP)
	$(MAKE) -C commands

turns: $(TMP)
	$(MAKE) -C turns

$(TMP):
	@mkdir -p $(TMP)

.PHONY: clean

clean:
	@echo "$(COLOR)Cleanning...$(NORMAL)"
	rm -rf $(TMP)

include $(OBJ:.o=.d)