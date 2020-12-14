COMPILER = g++
LIBS = -lobjects
CFLAGS = -std=c++17 -I./include -L./lib -o main
COLOR = \033[0;32m
NORMAL = \033[0m

.PHONY: all libs run_tests game clean clean_libs

all: libs

libs:
	@echo "$(COLOR)Compiling libs...$(NORMAL)"
	$(MAKE) -C src/time_lost

run_tests: libs
	@echo "$(COLOR)Compiling and run tests...$(NORMAL)"
	$(MAKE) -C tests

game: libs
	@echo "$(COLOR)Compiling game...$(NORMAL)"
	$(MAKE) -C game

clean:
	@echo "$(COLOR)Clean...$(NORMAL)"
	$(MAKE) -C src/time_lost clean
	@echo "$(COLOR)Clean tests...$(NORMAL)"
	$(MAKE) -C tests clean
	@echo "$(COLOR)Clean game...$(NORMAL)"
	$(MAKE) -C game clean
clean_libs:
	@echo "$(COLOR)Clean libs...$(NORMAL)"
	rm lib/*