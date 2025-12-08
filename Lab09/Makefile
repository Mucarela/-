CC      = clang
CFLAGS  = -std=c11 -Wall -Wextra -pedantic -I./src
ARCH    =
DIST_DIR = ./dist

SRC     = ./src/lib.c ./src/main.c

all: main.bin test.bin

main.bin: $(SRC)
	$(CC) $(CFLAGS) $^ $(ARCH) -o $(DIST_DIR)/$@

test.bin: ./test/test.c ./src/lib.c ./src/lib.h
	$(CC) $(CFLAGS) $< ./src/lib.c $(ARCH) -o $(DIST_DIR)/$@ -lcheck -lm -lsubunit

test: test.bin
	./dist/test.bin

clean:
	rm -rf $(DIST_DIR)/*.bin
