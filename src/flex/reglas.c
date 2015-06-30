
%option noyywrap

%{
	#include "../../include/compiler.h"

	void listarCadena(lista **listaToken, gram *gramatica) {
		token_t token;

		while ((token.indToken = yylex()) != -1) {
			if (CONST_ENTERA >= token.indToken) {
				if ((token.indTS = darIndiceTS(yytext)) == -1) {
					agregarTokenTS(&token, yytext);
					if (token.indTS == -1) {
						printf("\n[Error] No se puedo asignar memoria para el identificador \"%s\" en la tabla de simbolos.\n", yytext);
						exit(1);
					}
				}
			} else if (token.indToken == ERROR) {
				printf("\n[Error] Simbolo desconocido \"%s\".\n", yytext);
				exit(1);
			} else {
				token.indTS = 0;
			}

			agregarAlFinal(token, listaToken);
		}


		// Marca de fin de la cadena.
		token.indToken = -1;
		token.indTS = 0;
		agregarAlFinal(token, listaToken);
	}
%}

DIGITO				[0-9]
MINUSCULA			[a-z]
MAYUSCULA			[A-Z]

%%

[ \n\t]+								|
"/*"[^}\n]*"*/"  						{ }

"("										{ return ABRIR_PAR; }
")"										{ return CERRAR_PAR; }
"{"										{ return ABRIR_LL; }
"}"										{ return CERRAR_LL; }
"+"										{ return SUMA; }
"*"										{ return MULT; }
"-"										{ return MENOS; }
O										{ return OR; }
Y										{ return AND; }
NO										{ return NO; }
VERDADERO								{ return VERDADERO; }
FALSO									{ return FALSO; }
Para									{ return PARA; }
desde									{ return DESDE; }
hasta									{ return HASTA; }
Si										{ return SI; }
entonces								{ return ENTONCES; }
"="										{ return ASIGN; }
"=="									{ return IGUAL; }
"<"										{ return MENOR; }
">"										{ return MAYOR; }
"<="									{ return MENOR_IGUAL; }
">="									{ return MAYOR_IGUAL; }
","										{ return COMA; }
";"										{ return PUNTO_COMA; }
entero									{ return ENTERO; }
logico									{ return LOGICO; }
regresar								{ return REGRESAR; }

{DIGITO}+								{ return CONST_ENTERA; }
{MINUSCULA}+							{ return ID_VARIABLE; }
{MAYUSCULA}{MINUSCULA}*					{ return ID_FUNCION; }    

<<EOF>>									{ return -1; }

.										{ return ERROR; }
