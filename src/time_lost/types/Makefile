include ../../../Header.mk
OFLAGS = -fPIC -I../../../include
TMP = tmp
OBJ = $(TMP)/time_lost_exception.o \
      $(TMP)/position.o \
	  $(TMP)/location_patterns.o \
	  $(TMP)/behavior_find.o \
	  $(TMP)/behavior_wait.o \
	  $(TMP)/behavior_fly.o \
	  $(TMP)/time_lost_file_exception.o \
	  $(TMP)/bullet_type.o \
	  $(TMP)/direction.o \
	  $(TMP)/weapon_type.o \
	  $(TMP)/last_action.o
LIB = $(TMP)/libtypes.so
COLOR = \033[0;32m
NORMAL = \033[0m

.PHONY: all
all: $(LIB)

$(TMP)/%.d: %.cc | $(TMP)
	@echo "$(COLOR)Create $@ dependency...$(NORMAL)"
	rm -rf $@
	$(CC) -MM -MT $@ $(CFLAGS) $(OFLAGS) $< > $@

$(TMP)/%.o: %.cc $(TMP)/%.d | $(TMP)
	@echo "$(COLOR)Compile $@...$(NORMAL)"
	$(CC) -c $(CFLAGS) $(OFLAGS) $< -o $@


$(LIB): $(OBJ)
	@echo "$(COLOR)Link library $(LIB)...$(NORMAL)"
	g++ -shared -o $(LIB) $(OBJ)
	cp $(LIB) ../../../lib

$(TMP):
	@mkdir -p $(TMP)

.PHONY: clean
clean:
	@echo "$(COLOR)Cleanning...$(NORMAL)"
	rm -rf $(TMP)

include $(OBJ:.o=.d)