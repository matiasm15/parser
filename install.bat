mkdir lib
mkdir obj
gcc -Wall -g -c src/lib/tree.c
move /Y tree.o obj
ar rcs lib/libtree.a obj/tree.o
gcc -Wall -g -c src/lib/list.c
move /Y list.o obj
ar rcs lib/liblist.a obj/list.o
gcc -Wall -g -c src/lib/grammar.c
move /Y grammar.o obj
ar rcs lib/libgrammar.a obj/grammar.o
gcc -Wall -g -c src/lib/symbol_table.c
move /Y symbol_table.o obj
ar rcs lib/libsymbol_table.a obj/symbol_table.o
gcc -Wall -g -c src/lib/parser.c
move /Y parser.o obj
ar rcs lib/libparser.a obj/parser.o
gcc -g src/compiler.c -o compiler -Llib -ltree -llist -lsymbol_table -lparser -lgrammar