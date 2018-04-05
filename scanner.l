/* declarations */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"
extern void yyerror(const char *s);
%}


/* patterns & actions */
%option yylineno 

%%


"/*"([^\*]|\*[^/])*"*/"    	{ } // multiline comments
"//".*[\n]+            		{ } // oneline comments
[ \t\n\r]+            		{ } //whitespace

"int"	{return TK_INT; }
"float" {return TK_FLOAT; }

"+"	{return TK_PLUS; }
"-"	{return TK_MINUS; }
"*"	{return TK_MULT; }
"/"	{return TK_DIV; }
"="	{return TK_ASSIGN; }

"=="	{return TK_EQUAL; }
"!="	{return TK_NOTEQUAL; }
"<"	{return TK_LESS; }
">"	{return TK_GREATER; }
"<="	{return TK_LESS_EQ; }
">="	{return TK_GREATER_EQ; }

":"	{return TK_COLON; }
";"	{return TK_SEMICOLON; }
"::"	{return TK_RANGE_RES; }
"."	{return TK_PERIOD; }
","	{return TK_COMMA; }

"("	{return TK_OPEN_PAR; }
")"	{return TK_CLOSE_PAR; }
"{"	{return TK_OPEN_BRACE; }
"}"	{return TK_CLOSE_BRACE; }
"["	{return TK_OPEN_BRACKET; }
"]"	{return TK_CLOSE_BRACKET; }

"class"		{return TK_CLASS; }
"private"	{return TK_PRIVATE; }
"public"	{return TK_PUBLIC; }
"main"		{return TK_MAIN; }
"return"	{return TK_RETURN; }
"while"		{return TK_WHILE; }
"do"		{return TK_DO;	}
"for"		{return TK_FOR; }
"if"		{return TK_IF; }
"else"		{return TK_ELSE; }

[A-Za-z_][A-Za-z0-9_]*	{ strcpy(yylval.varid,yytext); 
				return TK_ID; }
[0-9]+			{ yylval.intnum = atoi(yytext);
				return TK_INTNUM; }
[0-9]+.[0-9]+		{ yylval.floatnum = atoi(yytext);
				return TK_FLOATNUM; }

%%

void yyerror(const char *s){
	printf("%d : %s at %s \n", yylineno, s, yytext);
	return ;
}


