CC=gcc
SRC := $(shell find src -name '*.c')
TARGET=ecs_shooter
CFLAGS=-Wall -Wextra -Wconversion -Wdouble-promotion -Wno-unused-parameter -Wno-unused-function -Wno-sign-conversion
CPPFLAGS=-I/opt/homebrew/opt/raylib/include -Iinclude -Isrc -I/opt/homebrew/opt/cjson/include
LDFLAGS=-L/opt/homebrew/opt/raylib/lib -L/opt/homebrew/opt/cjson/lib
LDLIBS=-lraylib -lcjson

all:
	${CC} ${SRC} ${CPPFLAGS} ${CFLAGS} ${LDFLAGS} ${LDLIBS} -o ${TARGET}
