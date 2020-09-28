COMPILER = g++
LIBS = -lobjects
CFLAGS = -std=c++17 -I./include -L./lib -o main


libs:
	@echo "Compiling libs..."
	$(MAKE) -C src/etu_game

run_unittests: libs
	@echo "Compiling and run unittests..."
	$(MAKE) -C tests

clean:
	@echo "Clean..."
	$(MAKE) -C src/etu_game clean
	@echo "Clean tests..."
	$(MAKE) -C tests clean
clean_libs:
	@echo "Clean libs..."
	rm lib/*