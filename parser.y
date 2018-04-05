/* declarations */            
%{  
#include <stdio.h> 
#include <stdlib.h> 
#include "ast.h"    
#include "CFG.h"   
            
struct Program *head = NULL;		//Head for abstract syntax tree

%}
   
//NON-TERMINAL
%union {
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
}

%type <intnum>	TK_INTNUM
%type <floatnum> TK_FLOATNUM
%type <varid>	TK_ID

%type <ptr_Program> PROGRAM 
%type <ptr_class> CLASS_LIST CLASS
%type <ptr_Member> MEMBER
%type <ptr_VarDecl> VAR_DECL_LIST VAR_DECL
%type <ptr_MethodDecl> METHOD_DECL_LIST FUNC_DECL
%type <ptr_MethodDef> METHOD_DEF_LIST FUNC_DEF
%type <ptr_ClassMethodDef> CLASS_METHOD_LIST CLASS_METHOD_DEF
%type <ptr_MainFunc> MAINFUNC
%type <ptr_Param> PARAM_LIST PARAM
%type <ptr_Ident> IDENT
%type <ptr_Type> TYPE
%type <ptr_CompoundStmt> COMPOUND_STMT
%type <ptr_Stmt> STMT_LIST STMT
%type <ptr_ExprStmt> EXPR_STMT
%type <ptr_AssignStmt> ASSIGN_STMT
%type <ptr_RetStmt> RET_STMT
%type <ptr_WhileStmt> WHILE_STMT
%type <ptr_DoStmt> DO_STMT
%type <ptr_ForStmt> FOR_STMT
%type <ptr_IfStmt> IF_STMT
%type <ptr_OperExpr> OPER_EXPR
%type <ptr_RefExpr> REF_EXPR
%type <ptr_RefVarExpr> REF_VAR_EXPR
%type <ptr_RefCallExpr> REF_CALL_EXPR
%type <ptr_IdentExpr> IDENT_EXPR
%type <ptr_CallExpr> CALL_EXPR
%type <ptr_Arg> ARG_LIST
%type <ptr_Expr> EXPR
%type <ptr_UnOp> UNOP
%type <ptr_AddiOp> ADDIOP
%type <ptr_MultOp> MULTOP
%type <ptr_RelaOp> RELAOP
%type <ptr_EqltOp> EQLTOP


//TERMINAL 

%token TK_INTNUM TK_FLOATNUM TK_ID

%token TK_INT TK_FLOAT // int float

%token TK_PLUS TK_MINUS TK_MULT TK_DIV // + - * /

%token TK_ASSIGN	// =

%token TK_EQUAL TK_NOTEQUAL TK_LESS TK_GREATER TK_LESS_EQ TK_GREATER_EQ // == != < > <= >=

%token TK_COLON TK_SEMICOLON TK_RANGE_RES TK_PERIOD TK_COMMA // : ; :: . ,

%token TK_OPEN_PAR TK_CLOSE_PAR TK_OPEN_BRACE TK_CLOSE_BRACE TK_OPEN_BRACKET TK_CLOSE_BRACKET // ( ) { } [ ]

// class private public main return while do for if else
%token TK_CLASS TK_PRIVATE TK_PUBLIC TK_MAIN TK_RETURN TK_WHILE TK_DO TK_FOR TK_IF TK_ELSE 


%right TK_ASSIGN
%right SIGN_MINUS

%start PROGRAM

/* rules & actions */
%%
  
// Program := (ClassList)? (ClassMethodList)? MainFunc
PROGRAM : CLASS_LIST CLASS_METHOD_LIST MAINFUNC 	{ head = alloc_ast_program($1,$2,$3); }
	| CLASS_LIST MAINFUNC 				{ head = alloc_ast_program($1,NULL,$2); }
	| CLASS_METHOD_LIST MAINFUNC 			{ head = alloc_ast_program(NULL,$1,$2); }
	| MAINFUNC					{ head = alloc_ast_program(NULL,NULL,$1); }
	|						{ head = NULL; }
;

// ClassList := (Class)+
CLASS_LIST : CLASS_LIST CLASS				{ $$ = alloc_ast_Class_List($1,$2); }
	| CLASS						{ $$ = alloc_ast_Class_List(NULL,$1); }
;
 
// Class := class id { ( private : Member )? ( public : Member )? }
CLASS : TK_CLASS TK_ID TK_OPEN_BRACE TK_PRIVATE TK_COLON MEMBER TK_PUBLIC TK_COLON MEMBER TK_CLOSE_BRACE	{ $$ = alloc_ast_class($2,$6,$9); }
	| TK_CLASS TK_ID TK_OPEN_BRACE TK_PRIVATE TK_COLON MEMBER TK_CLOSE_BRACE				{ $$ = alloc_ast_class($2,$6,NULL);}
	| TK_CLASS TK_ID TK_OPEN_BRACE TK_PUBLIC TK_COLON MEMBER TK_CLOSE_BRACE					{ $$ = alloc_ast_class($2,NULL,$6);}
	| TK_CLASS TK_ID TK_OPEN_BRACE TK_CLOSE_BRACE								{ $$ = alloc_ast_class($2,NULL,NULL);}
;

// (VarDeclList)? (MethodDeclList)? (MethodDefList)?
MEMBER : VAR_DECL_LIST METHOD_DECL_LIST METHOD_DEF_LIST		{ $$ = alloc_ast_member($1,$2,$3); }
	| VAR_DECL_LIST METHOD_DECL_LIST			{ $$ = alloc_ast_member($1,$2,NULL); }
	| VAR_DECL_LIST METHOD_DEF_LIST				{ $$ = alloc_ast_member($1,NULL,$2); }
	| METHOD_DECL_LIST METHOD_DEF_LIST			{ $$ = alloc_ast_member(NULL,$1,$2); }
	| METHOD_DEF_LIST					{ $$ = alloc_ast_member(NULL,NULL,$1); }
	| METHOD_DECL_LIST					{ $$ = alloc_ast_member(NULL,$1,NULL); }
	| VAR_DECL_LIST						{ $$ = alloc_ast_member($1,NULL,NULL); }
	|							{ $$ = alloc_ast_member(NULL,NULL,NULL); }
; 
 
// VarDeclList := (VarDecl)+
VAR_DECL_LIST : VAR_DECL_LIST VAR_DECL				{ $$ = alloc_ast_VarDecl_List($1,$2);}
	| VAR_DECL						{ $$ = alloc_ast_VarDecl_List(NULL,$1); }
;
// MethodDeclList := (FuncDecl)+
METHOD_DECL_LIST : METHOD_DECL_LIST FUNC_DECL			{ $$ = alloc_ast_MethodDecl_List($1,$2); }
	| FUNC_DECL						{ $$ = alloc_ast_MethodDecl_List(NULL,$1); }
;
 
// MethodDefList := (FuncDef)+
METHOD_DEF_LIST : METHOD_DEF_LIST FUNC_DEF			{ $$ = alloc_ast_MethodDef_List($1,$2); }
	| FUNC_DEF						{ $$ = alloc_ast_MethodDef_List(NULL,$1); }
;
 
// VarDecl := Type Ident ( = Expr )? ;
VAR_DECL : TYPE IDENT TK_ASSIGN EXPR TK_SEMICOLON	{ $$ = alloc_ast_vardecl($1,$2,$4);}
	 | TYPE IDENT TK_SEMICOLON	{ $$ = alloc_ast_vardecl($1,$2,NULL); }
;
// FuncDecl := Type id ( (ParamList)? ) ;
FUNC_DECL : TYPE TK_ID TK_OPEN_PAR PARAM_LIST TK_CLOSE_PAR TK_SEMICOLON { $$ = alloc_ast_methoddecl($2,$1,$4); }
	  | TYPE TK_ID TK_OPEN_PAR TK_CLOSE_PAR TK_SEMICOLON { $$ = alloc_ast_methoddecl($2,$1,NULL); }
;
// FuncDef := Type id ( (ParamList)? ) CompoundStmt
FUNC_DEF : TYPE TK_ID TK_OPEN_PAR PARAM_LIST TK_CLOSE_PAR COMPOUND_STMT { $$ = alloc_ast_methoddef($2,$1,$4,$6); }
	 | TYPE TK_ID TK_OPEN_PAR TK_CLOSE_PAR COMPOUND_STMT		{ $$ = alloc_ast_methoddef($2,$1,NULL,$5); }
;

// ClassMethodList := (ClassMethodDef)+
CLASS_METHOD_LIST : CLASS_METHOD_LIST CLASS_METHOD_DEF			{ $$ = alloc_ast_ClassMethodDef_List($1,$2); }
		  | CLASS_METHOD_DEF					{ $$ = alloc_ast_ClassMethodDef_List(NULL,$1); }
;
// ClassMethodDef := Type id :: id ( (ParamList)? ) CompoundStmt 질문한 부분
CLASS_METHOD_DEF : TYPE TK_ID TK_RANGE_RES TK_ID TK_OPEN_PAR PARAM_LIST TK_CLOSE_PAR COMPOUND_STMT { $$ = alloc_ast_classmethoddef($1,$2,$4,$6,$8);}
		 | TYPE TK_ID TK_RANGE_RES TK_ID TK_OPEN_PAR TK_CLOSE_PAR COMPOUND_STMT { $$ = alloc_ast_classmethoddef($1,$2,$4,NULL,$7); }
;
 
// MainFunc := int main ( ) CompoundStmt
MAINFUNC :TK_INT TK_MAIN TK_OPEN_PAR TK_CLOSE_PAR COMPOUND_STMT { $$ = alloc_ast_mainfunc($5); }
;
 
// ParamList := Param ( , Param )*
PARAM_LIST : PARAM_LIST TK_COMMA PARAM				{ $$ = alloc_ast_Param_List($1,$3); }
	   | PARAM						{ $$ = alloc_ast_Param_List(NULL,$1); }
;
// Param := Type Ident
PARAM : TYPE IDENT						{ $$ = alloc_ast_Param($1,$2); }
;
// Ident := id | id [ intnum ]
IDENT : TK_ID							{ $$ = alloc_ast_ident($1,0); }
	| TK_ID TK_OPEN_BRACKET TK_INTNUM TK_CLOSE_BRACKET	{ $$ = alloc_ast_ident($1,$3); }
;
// Type := int | float | id
TYPE : TK_INT							{ $$ = alloc_ast_type(NULL,eInt); }
	| TK_FLOAT						{ $$ = alloc_ast_type(NULL,eFloat); }
	| TK_ID							{ $$ = alloc_ast_type($1,eClass); }
;
 
// CompoundStmt := { (VarDeclList)? (StmtList)? }
COMPOUND_STMT : TK_OPEN_BRACE VAR_DECL_LIST STMT_LIST TK_CLOSE_BRACE		{ $$ = alloc_ast_compoundstmt($2,$3); }
	| TK_OPEN_BRACE VAR_DECL_LIST TK_CLOSE_BRACE				{ $$ = alloc_ast_compoundstmt($2,NULL); }
	| TK_OPEN_BRACE STMT_LIST TK_CLOSE_BRACE				{ $$ = alloc_ast_compoundstmt(NULL,$2); }
	| TK_OPEN_BRACE	TK_CLOSE_BRACE						{ $$ = alloc_ast_compoundstmt(NULL,NULL); }
;
 
// StmtList := (Stmt)+
STMT_LIST : STMT_LIST STMT					{ $$ = alloc_ast_Stmt_List($1,$2); }
	| STMT							{ $$ = alloc_ast_Stmt_List(NULL,$1); }
; 
// Stmt := ExprStmt
//	| AssignStmt
//	| RetStmt
//	| WhileStmt
//	| DoStmt
//	| ForStmt
//	| IfStmt
//	| CompoundStmt
//	| ;
STMT : EXPR_STMT						{ $$ = alloc_ast_stmt(eExpr,$1); }
	| ASSIGN_STMT						{ $$ = alloc_ast_stmt(eAssign,$1); }
	| RET_STMT						{ $$ = alloc_ast_stmt(eRet,$1); }
	| WHILE_STMT						{ $$ = alloc_ast_stmt(eWhile,$1); }
	| DO_STMT						{ $$ = alloc_ast_stmt(eDo,$1); }
	| FOR_STMT						{ $$ = alloc_ast_stmt(eFor,$1); }
	| IF_STMT						{ $$ = alloc_ast_stmt(eIf,$1); }
	| COMPOUND_STMT						{ $$ = alloc_ast_stmt(eCompound,$1); }
	| TK_SEMICOLON						{ $$ = alloc_ast_stmt(eSemi,NULL); }
;
 
// ExprStmt := Expr ;
EXPR_STMT : EXPR TK_SEMICOLON					{ $$ = alloc_ast_exprstmt($1); }
;
 
// ASsignStmt := RefVarExpr = Expr ;
ASSIGN_STMT : REF_VAR_EXPR TK_ASSIGN EXPR TK_SEMICOLON		{ $$ = alloc_ast_assignstmt($1,$3); }
;

// RetStmt := return (Expr)? ;
RET_STMT : TK_RETURN EXPR TK_SEMICOLON				{ $$ = alloc_ast_retstmt($2); }
	| TK_RETURN TK_SEMICOLON				{ $$ = alloc_ast_retstmt(NULL); }
;

// WhileStmt := while ( Expr ) Stmt
WHILE_STMT : TK_WHILE TK_OPEN_PAR EXPR TK_CLOSE_PAR STMT	{ $$ = alloc_ast_whilestmt($3,$5); }
;
 
// DoStmt := do Stmt while ( Expr ) ;
DO_STMT : TK_DO STMT TK_WHILE TK_OPEN_PAR EXPR TK_CLOSE_PAR TK_SEMICOLON { $$ = alloc_ast_dostmt($5,$2); }
;

// ForStmt := for ( Expr ; Expr ; Expr ) Stmt
FOR_STMT : TK_FOR TK_OPEN_PAR EXPR TK_SEMICOLON EXPR TK_SEMICOLON EXPR TK_CLOSE_PAR STMT { $$ = alloc_ast_forstmt($3,$5,$7,$9); }
;

// IfStmt := if ( Expr ) Stmt (else Stmt)?
IF_STMT : TK_IF TK_OPEN_PAR EXPR TK_CLOSE_PAR STMT TK_ELSE STMT 			 { $$ = alloc_ast_ifstmt($3,$5,$7); }
	| TK_IF TK_OPEN_PAR EXPR TK_CLOSE_PAR STMT 					 { $$ = alloc_ast_ifstmt($3,$5,NULL); }
;

// Expr := OperExpr
//	| RefExpr
//	| intnum
//	| floatnum
EXPR : OPER_EXPR					{ $$ = alloc_ast_expr(eOper,$1,0,0); }
	| REF_EXPR					{ $$ = alloc_ast_expr(eRef,$1,0,0); }
	| TK_INTNUM					{ $$ = alloc_ast_expr(eIntnum,NULL,$1,0); }
	| TK_FLOATNUM					{ $$ = alloc_ast_expr(eFloatnum,NULL,0,$1); }
;

// OperExpr := unop Expr
//	    | Expr addiop Expr
//	    | Expr multop Expr
//	    | Expr relaop Expr
//	    | Expr eqltop Expr
//	    | ( Expr )
OPER_EXPR : UNOP %prec SIGN_MINUS					{ $$ = alloc_ast_operexpr(eUn,$1); }
	| ADDIOP						{ $$ = alloc_ast_operexpr(eAddi,$1); }
	| MULTOP						{ $$ = alloc_ast_operexpr(eMult,$1); }
	| RELAOP						{ $$ = alloc_ast_operexpr(eRela,$1);}
	| EQLTOP						{ $$ = alloc_ast_operexpr(eEqlt,$1); }
	| TK_OPEN_PAR EXPR TK_CLOSE_PAR				{ $$ = alloc_ast_operexpr(eBracket,$2); }
;
 
UNOP : TK_MINUS EXPR						{ $$ = alloc_ast_unop(eNegative,$2); }
;

ADDIOP : EXPR TK_PLUS EXPR					{ $$ = alloc_ast_AddiOp(ePlus,$1,$3); }
	| EXPR TK_MINUS EXPR					{ $$ = alloc_ast_AddiOp(eMinus,$1,$3); }
;
 
MULTOP : EXPR TK_MULT EXPR					{ $$ = alloc_ast_MultOp(eMul,$1,$3); }
	| EXPR TK_DIV EXPR					{ $$ = alloc_ast_MultOp(eDiv,$1,$3); }
;
 
RELAOP : EXPR TK_LESS EXPR					{ $$ = alloc_ast_RelaOp(eLT,$1,$3); }
	| EXPR TK_GREATER EXPR					{ $$ = alloc_ast_RelaOp(eGT,$1,$3); } 
	| EXPR TK_LESS_EQ EXPR					{ $$ = alloc_ast_RelaOp(eLE,$1,$3); }
	| EXPR TK_GREATER_EQ EXPR				{ $$ = alloc_ast_RelaOp(eGE,$1,$3); }
;

EQLTOP : EXPR TK_EQUAL EXPR					{ $$ = alloc_ast_EqltOp(eEQ,$1,$3); }
	| EXPR TK_NOTEQUAL EXPR					{ $$ = alloc_ast_EqltOp(eNE,$1,$3); }
;
 
// RefExpr := RefVarExpr | RefCallExpr
REF_EXPR : REF_VAR_EXPR						{ $$ = alloc_ast_refexpr(eVar,$1); }
	| REF_CALL_EXPR						{ $$ = alloc_ast_refexpr(eCall,$1); }
;
// RefVarExpr := (RefExpr .)? IdentExpr
REF_VAR_EXPR : REF_EXPR TK_PERIOD IDENT_EXPR			{ $$ = alloc_ast_refvarexpr($1,$3); }
	| IDENT_EXPR						{ $$ = alloc_ast_refvarexpr(NULL,$1); }
;
// RefCallExpr := (RefExpr .)? CallExpr
REF_CALL_EXPR : REF_EXPR TK_PERIOD CALL_EXPR			{ $$ = alloc_ast_refcallexpr($1,$3); }
	| CALL_EXPR						{ $$ = alloc_ast_refcallexpr(NULL,$1); }
;        
// IdentExpr := id [ Expr ]
//	     | id
IDENT_EXPR : TK_ID TK_OPEN_BRACKET EXPR TK_CLOSE_BRACKET	{ $$ = alloc_ast_identexpr($1,$3); }
	| TK_ID							{ $$ = alloc_ast_identexpr($1,NULL); }
;
          
// CallExpr := id ( (ArgList)? )
CALL_EXPR : TK_ID TK_OPEN_PAR ARG_LIST TK_CLOSE_PAR		{ $$ = alloc_ast_callexpr($1,$3); }
	| TK_ID TK_OPEN_PAR TK_CLOSE_PAR			{ $$ = alloc_ast_callexpr($1,NULL); }
;
    
// ArgList := Expr (, Expr)*
ARG_LIST : ARG_LIST TK_COMMA EXPR		{ $$ = alloc_ast_Arg_List($1,$3); }
	| EXPR					{ $$ = alloc_ast_Arg_List(NULL,$1); }
;
   
        
%%   
 
int main(int argc, char* argv[])
{
	extern FILE *yyin;
  
	char filename[256];
	char filename2[256];

	yyin = fopen(argv[1], "r");
	printf("AST 를 생성 중입니다....................\n");
	yyparse(); //parsing
	fclose(yyin);
  
	printf("AST 생성완료!\n");
	strcpy(filename, "AST_restore_code.cpp");
	
	fout = fopen(filename, "w");
	printHEAD(head);
	fclose(fout);
	printf("AST 바탕으로 소스코드 복원파일 생성! \n");

	strcpy(filename2,"AST_Symbol_Table.txt");
	fout = fopen(filename2, "w");
	printSymbolTable(head);
	fclose(fout);
	printf("AST 바탕으로 심볼테이블 생성! \n");
  
	strcpy(filename2,"CFG.out");
	fout = fopen(filename2, "w");
	printCFG(head);
	fclose(fout);
	printf("AST 바탕으로 Control Flow Graph 생성! \n");
 	
	strcpy(filename2,"Liveness.out");
	fout = fopen(filename2, "w");
	fclose(fout);
	printf("Liveness는 구현하지 못했습니다... \n");
 
 
   
	return 0;
}

 



