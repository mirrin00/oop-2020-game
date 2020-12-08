CC = g++
ifeq ($(COMPILE_TYPE), Release)
	CFLAGS = -std=c++17
else
	CFLAGS = -g -std=c++17
endif
