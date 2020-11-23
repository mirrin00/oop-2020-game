CC = g++
ifeq ($(COMPILE_TYPE), Debug)
	CFLAGS = -g -std=c++17
else
	CFLAGS = -std=c++17
endif
