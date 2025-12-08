CC      = clang
C_OPTS  = -std=gnu11 -g -Wall -Wextra -Werror -Wformat-security \
          -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses \
          -Wnull-dereference -Wno-unused-variable -Wno-implicit-int-float-conversion \
          -Werror=vla -I./src

clean:
	rm -rf dist

prep:
	mkdir -p dist

compile: main.bin

main.bin: src/main.c
	$(CC) $(C_OPTS) $< -o ./dist/main.bin -lm

run: clean prep compile
	./dist/main.bin

all: clean prep compile check

check:
	clang-format --verbose -dry-run --Werror src/*
	clang-tidy src/*.c \
		-checks=-readability-uppercase-literal-suffix,-readability-magic-numbers,\
-clang-analyzer-deadcode.DeadStores,-clang-analyzer-security.insecureAPI.rand
	rm -rf src/*.dump
