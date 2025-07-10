CC = gcc

CFLAGS_DEBUG = -Wall -Wextra -Werror -Wpointer-arith -Wcast-align \
         -Wstrict-prototypes -Wwrite-strings -Waggregate-return \
         -Wswitch-default -Wswitch-enum -Wunreachable-code \
	 -Wunused-parameter -Wuninitialized -Winit-self -Wpedantic \
	 -O0 -std=c99 -g \
	 -fsanitize=address \
	 
CFLAGS = -Wall -Wextra -Werror \
	 -O2 -std=c99\

MAHC_LIB_PATH = ./mahc/target/debug/

LINKS = -L$(MAHC_LIB_PATH) -lmahc -lSDL3 -lSDL3_ttf

MAIN_TARGET = main.out
TEST_TARGET = test.out
MAIN_SRC = src/*.c
TEST_SRC = test/test.c src/*.c

.PHONY: all build run clean test format bear debug build-mahc-header build-mahc

all: whodoyouthinkyouareiam

whodoyouthinkyouareiam:  build-mahc-header build-mahc build run

build:
	$(CC) $(CFLAGS) -o $(MAIN_TARGET) $(MAIN_SRC) $(LINKS)

run:
	./$(MAIN_TARGET)

test:
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(TEST_SRC) && ./$(TEST_TARGET)

clean:
	-rm -f $(MAIN_TARGET) $(TEST_TARGET) && rm -rf $(MAHC_LIB_PATH)

format: 
	find ./ -name '*.h' -o -iname '*.c' | xargs clang-format -i --verbose

bear: # this is for creating the compile_commands.json file
	rm -f compile_commands.json && bear -- make build

debug: build-mahc-header build-mahc
	$(CC) $(CFLAGS_DEBUG) -o $(MAIN_TARGET) $(MAIN_SRC) $(LINKS)

build-mahc:
	cargo build --manifest-path ./mahc/Cargo.toml

build-mahc-header:
	cbindgen ./mahc --config cbindgen.toml --output ./src/mahc.h
