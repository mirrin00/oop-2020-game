include ../../../Header.mk
OFLAGS = -std=c++17 -fPIC -I../../../include
TMP = tmp
OBJ = $(TMP)/logger.o \
      $(TMP)/publisher.o \
      $(TMP)/time_lost.o \
	  $(TMP)/logging_interface.o \
	  $(TMP)/commands/player_move_down_command.o \
	  $(TMP)/commands/player_move_up_command.o \
	  $(TMP)/commands/player_move_left_command.o \
	  $(TMP)/commands/player_move_right_command.o \
	  $(TMP)/commands/player_interact_command.o 
#LIB = $(TMP)/liblogic.a
LIB = $(TMP)/liblogic.so
COLOR = \033[0;32m
NORMAL = \033[0m

.PHONY: all

all: $(LIB)

$(TMP)/%.d: %.cc | $(TMP)
	@echo "$(COLOR)Create $< dependency...$(NORMAL)"
	rm -rf $@
	$(CC) -MM -MT $@ $(CFLAGS) $(OFLAGS) $< > $@

$(TMP)/%.o: %.cc $(TMP)/%.d | $(TMP)
	@echo "$(COLOR)Compile $@...$(NORMAL)"
	$(CC) -c $(CFLAGS) $(OFLAGS) $< -o $@


$(LIB): $(OBJ)
	@echo "$(COLOR)Compile lib $(LIB)...$(NORMAL)"
	g++ -shared -o $(LIB) $(OBJ)
	cp $(LIB) ../../../lib

$(TMP):
	@mkdir -p $(TMP)/commands

.PHONY: clean

clean:
	@echo "$(COLOR)Cleanning...$(NORMAL)"
	rm -rf $(TMP)

include $(OBJ:.o=.d)