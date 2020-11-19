CC = g++
ifneq ($(DEBUG), )
	CFLAGS = -std=c++17
else
	CFLAGS = -g -std=c++17
endif
