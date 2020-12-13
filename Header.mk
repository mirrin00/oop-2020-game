CC = g++
ifeq ($(COMPILE_TYPE), Release)
	CFLAGS = -std=c++17 -O2
else
	CFLAGS = -g -std=c++17
endif
