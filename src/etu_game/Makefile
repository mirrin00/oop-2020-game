COLOR = \033[0;32m
NORMAL = \033[0m

all:
	@echo "$(COLOR)Compiling module objects...$(NORMAL)"
	$(MAKE) -C objects
	@echo "$(COLOR)Compiling module types...$(NORMAL)"
	$(MAKE) -C types

clean:
	@echo "$(COLOR)Clean module objects...$(NORMAL)"
	$(MAKE) -C objects clean
	@echo "$(COLOR)Clean module types...$(NORMAL)"
	$(MAKE) -C types clean