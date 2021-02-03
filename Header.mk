CC = g++
ifeq ($(COMPILE_TYPE), Release)
	CFLAGS = -std=c++17 -O2
else
	CFLAGS = -ggdb3 -std=c++17
endif
