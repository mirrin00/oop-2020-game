COMPILER = g++
LIBS = -lobjects
CFLAGS = -std=c++17 -I./include -L./lib -o main
COLOR = \033[0;32m
NORMAL = \033[0m


libs:
	@echo "$(COLOR)Compiling libs...$(NORMAL)"
	$(MAKE) -C src/etu_game

run_unittests: libs
	@echo "$(COLOR)Compiling and run unittests...$(NORMAL)"
	$(MAKE) -C tests

game: libs
	@echo "$(COLOR)Compiling game...$(NORMAL)"
	$(MAKE) -C game

clean:
	@echo "$(COLOR)Clean...$(NORMAL)"
	$(MAKE) -C src/etu_game clean
	@echo "$(COLOR)Clean tests...$(NORMAL)"
	$(MAKE) -C tests clean
	@echo "$(COLOR)Clean game...$(NORMAL)"
	$(MAKE) -C game clean
clean_libs:
	@echo "$(COLOR)Clean libs...$(NORMAL)"
	rm lib/*