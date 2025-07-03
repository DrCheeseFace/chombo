CC = gcc

CFLAGS_DEBUG = -Wall -Wextra -Werror -Wpointer-arith -Wcast-align \
         -Wstrict-prototypes -Wwrite-strings -Waggregate-return \
         -Wswitch-default -Wswitch-enum -Wunreachable-code \
	 -Wunused-parameter -Wuninitialized -Winit-self -Wpedantic \
	 -Og -std=c99 -g \
	 -fsanitize=address \
	 
CFLAGS = -Wall -Wextra -Werror \
	 -O2 -std=c99\


LINKS = -lSDL2 -lm


MAIN_TARGET = main.out
TEST_TARGET = test.out
MAIN_SRC = main.c lib/*.c
TEST_SRC = test/test.c lib/*.c

.PHONY: all build run clean test format bear debug

all: whodoyouthinkyouareiam

whodoyouthinkyouareiam: build run

build:
	$(CC) $(CFLAGS) -o $(MAIN_TARGET) $(MAIN_SRC) $(LINKS)

run:
	./$(MAIN_TARGET)

test:
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(TEST_SRC) && ./$(TEST_TARGET)

clean:
	-rm -f $(MAIN_TARGET) $(TEST_TARGET)

format: 
	find ./ -name '*.h' -o -iname '*.c' | xargs clang-format -i --verbose

bear: # this is for creating the compile_commands.json file
	rm -f compile_commands.json && bear -- make build

debug: 
	$(CC) $(CFLAGS_DEBUG) -o $(MAIN_TARGET) $(MAIN_SRC) $(LINKS)

