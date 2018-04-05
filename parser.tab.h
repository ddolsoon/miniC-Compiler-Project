/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_INTNUM = 258,
    TK_FLOATNUM = 259,
    TK_ID = 260,
    TK_INT = 261,
    TK_FLOAT = 262,
    TK_PLUS = 263,
    TK_MINUS = 264,
    TK_MULT = 265,
    TK_DIV = 266,
    TK_ASSIGN = 267,
    TK_EQUAL = 268,
    TK_NOTEQUAL = 269,
    TK_LESS = 270,
    TK_GREATER = 271,
    TK_LESS_EQ = 272,
    TK_GREATER_EQ = 273,
    TK_COLON = 274,
    TK_SEMICOLON = 275,
    TK_RANGE_RES = 276,
    TK_PERIOD = 277,
    TK_COMMA = 278,
    TK_OPEN_PAR = 279,
    TK_CLOSE_PAR = 280,
    TK_OPEN_BRACE = 281,
    TK_CLOSE_BRACE = 282,
    TK_OPEN_BRACKET = 283,
    TK_CLOSE_BRACKET = 284,
    TK_CLASS = 285,
    TK_PRIVATE = 286,
    TK_PUBLIC = 287,
    TK_MAIN = 288,
    TK_RETURN = 289,
    TK_WHILE = 290,
    TK_DO = 291,
    TK_FOR = 292,
    TK_IF = 293,
    TK_ELSE = 294,
    SIGN_MINUS = 295
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 13 "parser.y" /* yacc.c:1909  */

	int intnum;
	int floatnum;
	char varid[255];
	struct Program * ptr_Program;
	struct Class * ptr_class;
	struct Member * ptr_Member;     
	struct VarDecl * ptr_VarDecl;
	struct MethodDecl * ptr_MethodDecl;
	struct MethodDef * ptr_MethodDef;
	struct ClassMethodDef * ptr_ClassMethodDef;
	struct MainFunc * ptr_MainFunc;
	struct Param * ptr_Param;
	struct Ident * ptr_Ident;
	struct Type * ptr_Type;
	struct CompoundStmt * ptr_CompoundStmt;
	struct Stmt * ptr_Stmt;
	struct ExprStmt * ptr_ExprStmt;
	struct AssignStmt * ptr_AssignStmt;
	struct RetStmt * ptr_RetStmt;
	struct WhileStmt * ptr_WhileStmt;
	struct DoStmt * ptr_DoStmt;
	struct ForStmt * ptr_ForStmt;
	struct IfStmt * ptr_IfStmt;
	struct Expr * ptr_Expr;
	struct OperExpr * ptr_OperExpr;
	struct RefExpr * ptr_RefExpr;
	struct RefVarExpr * ptr_RefVarExpr;
	struct RefCallExpr * ptr_RefCallExpr;
	struct IdentExpr * ptr_IdentExpr;
	struct CallExpr * ptr_CallExpr;
	struct Arg * ptr_Arg;
	struct UnOp * ptr_UnOp;
	struct AddiOp * ptr_AddiOp;
	struct MultOp * ptr_MultOp;
	struct RelaOp * ptr_RelaOp;
	struct EqltOp * ptr_EqltOp;

#line 134 "parser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
