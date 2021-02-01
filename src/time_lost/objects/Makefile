include ../../../Header.mk
OFLAGS = -fPIC -I../../../include
TMP = tmp
OBJ = $(TMP)/cell.o \
      $(TMP)/field.o \
      $(TMP)/field_iterator.o \
      $(TMP)/essence.o \
      $(TMP)/item.o \
      $(TMP)/hands.o \
      $(TMP)/sword.o \
      $(TMP)/first_aid_kit.o \
      $(TMP)/bullets.o \
      $(TMP)/player.o \
      $(TMP)/object.o \
      $(TMP)/weapon.o \
	  $(TMP)/location.o
LIB = $(TMP)/libobjects.so
COLOR = \033[0;32m
NORMAL = \033[0m

.PHONY: all clean

all: $(LIB)

clean:
	@echo "$(COLOR)Cleanning...$(NORMAL)"
	rm -rf $(TMP)

$(TMP)/%.d: %.cc | $(TMP)
	@echo "$(COLOR)Create $< dependency...$(NORMAL)"
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


include $(OBJ:.o=.d)