.PHONY: program debug

program: main.c functions.c functions.h
	clang main.c functions.c -o main

debug: main.c functions.c functions.h
	clang -g -fsanitize=address main.c functions.c -o main

