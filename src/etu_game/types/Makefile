COMPILER = g++
CFLAGS = -std=c++17 -I../../../include
OBJ = etu_game_exception.o
OUTPUT = libtypes.a

all: $(OUTPUT)
	cp $(OUTPUT) ../../../lib

%.o: %.cc
	@echo "Compile $@..."
	$(COMPILER) -c $(CFLAGS) $< -o $@

$(OUTPUT): $(OBJ)
	@echo "Compile lib $(OUTPUT)..."
	ar rvs $(OUTPUT) $(OBJ)

clean:
	@echo "Cleanning..."
	rm *.o *.a