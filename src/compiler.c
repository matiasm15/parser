/* Analizador sintactico descendente con retroceso */

#include "../include/compiler.h"
#include "../include/parser.h"
#include "flex/lex.yy.c"

FILE *yyin;
bool error = false;
tablaSimbolos_t tablaSimbolos;

void main(int argc, char *argv[]) {
	gram gramatica;
	definirGramatica(&gramatica);

	lista *listaToken;
	inicializarLista(&listaToken);

	arbol *miArbol;
	inicializarArbol(gramatica.simboloDistiguido, &miArbol);

	inicializarTS();

	if (argc == 1) {
		printf("\n[Error] No se ha especificado ningun archivo.\n");
		exit(1);
	}

	yyin = fopen(argv[1], "r");
	if (yyin == NULL) {
		printf("\n[Error] No se encuentra el archivo \"%s\".\n", argv[1]);
		exit(1);
	}

	listarCadena(&listaToken, &gramatica);
	pSubN(gramatica.simboloDistiguido, &gramatica, &listaToken, &miArbol);

	if ((error == false) && esFinDeCadena(listaToken)) {
		printf("\nLa cadena pertenece al lenguaje.\n");
	} else {
		printf("\nLa cadena no pertenece al lenguaje.\n");
	}
}
