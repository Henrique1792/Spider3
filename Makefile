#Using gcc compiler
CC = gcc

# Output path and filename
BINARY = ./build/output

# Includes directory
INCLUDE = ./include

SRC = ./src/*.c
OBJS= $(subst src/,build/, $(SRC:%.c=%.o))
LOCAL= $(subst src/,,$(SRC:%.c=%.o))
# Libraries 

LIBS = -lGL -lGLU -lglut -lm
# Flags
FLAGS = -Wall -O0 -g -Wextra -pthread

#.PHONY: Execute the method, even if the files compiled exist -
#        phoning compile obliges it to compile everything every compilation =)
.PHONY: compile

all: compile 
	$(CC) -o $(BINARY) -I$(INCLUDE) $(OBJS) $(LIBS) $(FLAGS)
	ctags -R *

compile:
	$(CC) -c $(SRC) 
	mv $(LOCAL) -t ./build

get_tags:
	ctags -R *
run:
	$(BINARY)

debug:
	valgrind $(BINARY)

clean:
	rm $(BINARY) tags $(OBJS)
