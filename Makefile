CC=gcc
SRC := $(shell find src -name '*.c')
TARGET=top_down_shooter
CFLAGS=-Wall -Wextra -Wconversion -Wdouble-promotion -Wno-unused-parameter -Wno-unused-function -Wno-sign-conversion
CPPFLAGS=-I/opt/homebrew/opt/raylib/include -Iinclude -Isrc
LDFLAGS=-L/opt/homebrew/opt/raylib/lib
LDLIBS=-lraylib 

all:
	${CC} ${SRC} -o ${TARGET} ${CPPFLAGS} ${LDFLAGS} ${LDLIBS} ${CFLAGS}