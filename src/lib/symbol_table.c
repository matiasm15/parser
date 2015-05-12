#include "../../include/symbol_table.h"

void inicializarTS() {
	int i;

	for (i = 0; CANT_SIMBOLOS > i; ++i) {
		strcpy(tablaSimbolos[i].lexema, "");
	}
}

void agregarTokenTS(token_t *token, char *lexema) {
	int i;

	for (i = 0; CANT_SIMBOLOS > i; ++i) {
		if (strcmp(tablaSimbolos[i].lexema, "") == 0) {
			elemTS_t nuevoElem;
			nuevoElem.indToken = token->indToken;
			strcpy(nuevoElem.lexema, lexema);

			token->indTS = i;
			return;
		}
	}
	
	token->indTS = -1;
}

int darIndiceTS(char *lexema) {
	int i;

	for (i = 0; CANT_SIMBOLOS > i; ++i) {
		if (strcmp(tablaSimbolos[i].lexema, lexema) == 0) {
			return i;
		}
	}
	
	return -1;
}
