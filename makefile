# gcc -o compiler src/compiler.c src/lib/tree.c src/lib/list.c src/lib/grammar.c src/lib/symbol_table.c src/lib/parser.c

CC = gcc

LDIR = src/lib

_LFILE = tree.c list.c grammar.c symbol_table.c parser.c
LFILE = $(patsubst %, $(LDIR)/%, $(_LFILE))

compiler:
	$(CC) -o compiler -g src/compiler.c $(LFILE)
