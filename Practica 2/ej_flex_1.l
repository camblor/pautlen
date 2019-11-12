%{
    #include <stdio.h> /*para poder utilizar funiones de C (printf)*/
    #include "tokens.h" /*donde estan almacenadas las claves*/
%}

%option noyywrap

%%
main { return TOK_MAIN; }
array { return TOK_ARRAY; }
int { return TOK_INT; }
if { return TOK_IF; }
else { return TOK_ELSE; }
while { return TOK_WHILE; }
";" { return TOK_PUNTOYCOMA; }
"(" { return TOK_PARENTESISIZQUIERDO; }
")" { return TOK_PARENTESISDERECHO; }
"*" { return TOK_ASTERISCO; }
"+" { return TOK_MAS; }
"<=" { return TOK_MENORIGUAL; }
%%
