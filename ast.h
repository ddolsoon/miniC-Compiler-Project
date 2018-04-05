/**
* Copyright (C) 2017 ARCS lab - All Rights Reserved
* You may use, distribute and modify this code under the
* terms of the ARCS license
*
* You should have received a copy of the ARCS license with
* this file. If not, please write to: jhpark@arcs.skku.edu
*
* Freely use this source code, but not allowed for any
* commercial uses.
*/

#ifndef AST_H
#define AST_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

FILE * fout;

typedef char bool;
#define true 1
#define false 0



/**
* Before you started..
*
* This file is a header file to implement the Abstract Syntax Tree(AST).
* You have to use the following structs as the nodes of the tree.
* This file will be included in bison implementation and tree walker.
* There are some informations that helps you using this header easly.
* So we recommend you to read carefully not olny this comment,
* but also those written in each line.
*
* First of all, all nodes are designed to target the visitor model.
* There are two models of tree walkers; visitor and listener.
* In visitor model, the developer controls the order of tree walks one by one.
* You are developer in this case.
* For example, when the tree walker program meets "Expr - Expr",
* you have to make the program visit the right-hand side first at this time.
*
* The next information is how to implement "List" structs.
* All structs of List is implemented in linked list.
* The variable named "prev" connect between node.
* The reason not using "next" variable is related to the execution model of Bison.
* Bison tool is designed for visiting leaf node first.
* It means that the parser will stack the nodes up while generating AST.
*/

typedef enum
{
	eInt, eFloat, eClass
} Type_e;
typedef enum
{
	eExpr, eAssign, eRet, eWhile, eDo, eFor, eIf, eCompound, eSemi, eCondition_w, eCondition_f, eCondition_i
} Stmt_e;
typedef enum
{
	eOper, eRef, eIntnum, eFloatnum
} Expr_e;
typedef enum
{
	eUn, eAddi, eMult, eRela, eEqlt, eBracket
} Oper_e;
typedef enum
{
	eVar, eCall
} Ref_e;
typedef enum
{
	eNegative
} Unop_e;
typedef enum
{
	ePlus, eMinus
} Addi_e;
typedef enum
{
	eMul, eDiv
} Mult_e;
typedef enum
{
	eLT, eGT, eLE, eGE
} Rela_e;
typedef enum
{
	eEQ, eNE
} Eqlt_e;



// Program := (ClassList)? (ClassMethodList)? MainFunc
struct Program {
	struct Class *_class;
	struct ClassMethodDef *classMethodDef;
	struct MainFunc *mainFunc;
};

// ClassList := (Class)+
// Class := class id { (previate : Member)? (public : Member)? }
struct Class {
	char *id;
	struct Member *priMember;
	struct Member *pubMember;
	struct Class *prev;
};

// Member := (VarDeclList)? (MethodDeclList)? (MethodDefList)?
struct Member {
	struct VarDecl *varDecl;
	struct MethodDecl *methodDecl;
	struct MethodDef *methodDef;
};

// VarDeclList := (VarDecl)+
// VarDecl := Type Ident (= (int|float))? ;
struct VarDecl {
	struct Type *type;
	struct Ident *ident;
	struct Expr *expr;
	struct VarDecl *prev;
};

// MethodDeclList := (MethodDecl)+
// MethodDecl := Type id ( (ParamList)? ) ;
struct MethodDecl {
	char *id;
	struct Type *type;
	struct Param *param;
	struct MethodDecl *prev;
};

// MethodDefList := (MethodDef)+
// MethodDef := Type id ( (ParamList)? ) CompoundStmt
struct MethodDef {
	char *id;
	struct Type *type;
	struct Param *param;
	struct CompoundStmt *compoundStmt;
	struct MethodDef *prev;
};

// ClassMethodList := (ClassMethodDef)+
// ClassMethodDef := Type id :: id ( (ParamList)? ) CompoundStmt
struct ClassMethodDef {
	struct Type * type;
	char *className;
	char *methodName;
	struct Param *param;
	struct CompoundStmt *compoundStmt;
	struct ClassMethodDef *prev;
};

// MainFunc := int main ( ) CompoundStmt
struct MainFunc {
	struct CompoundStmt *compoundStmt;
};

// ParamList := Param (, Param)*
// Param := Type Ident
struct Param {
	struct Type *type;
	struct Ident *ident;
	struct Param *prev;
};

// Ident := id
//        | id [ intnum ]
struct Ident {
	char *id;
	int len; // 0 if scalar
};

// Type := int
//       | float
//       | id
struct Type {
	char *id; // NULL unless class type
	Type_e e;
};

// CompoundStmt := { (VarDeclList)? (StmtList)? }
struct CompoundStmt {
	struct VarDecl *varDecl;
	struct Stmt *stmt;
};

// StmtList := (Stmt)+
// Stmt := ExprStmt
//       | AssignStmt
//       | RetStmt
//       | WhileStmt
//       | DoStmt
//       | ForStmt
//       | IfStmt
//       | CompoundStmt
//       | ;
struct Stmt {
	Stmt_e e;
	union {
		struct ExprStmt *exprStmt;
		struct AssignStmt *assignStmt;
		struct RetStmt *retStmt;
		struct WhileStmt *whileStmt;
		struct DoStmt *doStmt;
		struct ForStmt *forStmt;
		struct IfStmt *ifStmt;
		struct CompoundStmt *compoundStmt;
	} type;
	struct Stmt *prev;
};

// ExprStmt := Expr ;
struct ExprStmt {
	struct Expr *expr;
};

// AssignStmt := RefVarExpr = Expr ;
struct AssignStmt {
	struct RefVarExpr *refVarExpr;
	struct Expr *expr;
};

// RetStmt := return (Expr)? ;
struct RetStmt {
	struct Expr *expr;
};

// WhileStmt := while ( Expr ) Stmt
struct WhileStmt {
	struct Expr *cond;
	struct Stmt *body;
};

// DoStmt := do Stmt while ( Expr ) ;
struct DoStmt {
	struct Expr *cond;
	struct Stmt *body;
};

// ForStmt := for ( Expr ; Expr ; Expr ) Stmt
struct ForStmt {
	struct Expr *init, *cond, *incr;
	struct Stmt *body;
};

// IfStmt := if ( Expr ) Stmt (else Stmt)?
struct IfStmt {
	struct Expr *cond;
	struct Stmt *ifBody;
	struct Stmt *elseBody;
};

// Expr := OperExpr
//       | RefExpr
//       | intnum
//       | floatnum
struct Expr {
	Expr_e e;
	union {
		struct OperExpr *operExpr;
		struct RefExpr *refExpr;
		int intnum;
		float floatnum;
	} type;
};

// OperExpr := unop Expr
//           | Expr addiop Expr
//           | Expr multop Expr
//           | Expr relaop Expr
//           | Expr eqltop Expr
//           | ( Expr )
struct OperExpr {
	Oper_e e;
	union {
		struct UnOp *un;
		struct AddiOp *addi;
		struct MultOp *mult;
		struct RelaOp *rela;
		struct EqltOp *eqlt;
		struct Expr *bracket;
	} type;
};

// RefExpr := RefVarExpr
//          | RefCallExpr
struct RefExpr {
	Ref_e e;
	union {
		struct RefVarExpr *refVarExpr;
		struct RefCallExpr *refCallExpr;
	} type;
};

// RefVarExpr := (RefExpr .)? IdentExpr
struct RefVarExpr {
	struct RefExpr *refExpr;
	struct IdentExpr *identExpr;
};

// RefCallExpr := (RefExpr .)? CallExpr
struct RefCallExpr {
	struct RefExpr *refExpr;
	struct CallExpr *callExpr;
};

// IdentExpr := id [ Expr ]
//            | id
struct IdentExpr {
	char *id;
	struct Expr *expr; // NULL if scalar
};

// CallExpr := id ( (ArgList)? )
struct CallExpr {
	char *id;
	struct Arg *arg;
};

// ArgList := Expr (, Expr)*
struct Arg {
	struct Expr *expr;
	struct Arg *prev;
};

/** Following definitions are additional structs for OperExpr. **/
struct UnOp {
	Unop_e e;
	struct Expr *expr;
};

struct AddiOp {
	Addi_e e;
	struct Expr *lhs;
	struct Expr *rhs;
};

struct MultOp {
	Mult_e e;
	struct Expr *lhs;
	struct Expr *rhs;
};

struct RelaOp {
	Rela_e e;
	struct Expr *lhs;
	struct Expr *rhs;
};

struct EqltOp {
	Eqlt_e e;
	struct Expr *lhs;
	struct Expr *rhs;
};

struct Program* alloc_ast_program(struct Class *_class, struct ClassMethodDef *classMethodDef, struct MainFunc *mainFunc);
struct Class* alloc_ast_class(char * id, struct Member * priMember, struct Member * pubMember);
struct Member* alloc_ast_member(struct VarDecl * varDecl, struct MethodDecl * methodDecl, struct MethodDef * methodDef);
struct VarDecl* alloc_ast_vardecl(struct Type * type, struct Ident * ident, struct Expr * expr);
struct MethodDecl* alloc_ast_methoddecl(char * id, struct Type * type, struct Param * param);
struct MethodDef* alloc_ast_methoddef(char * id, struct Type * type, struct Param * param, struct CompoundStmt * compoundStmt);
struct ClassMethodDef* alloc_ast_classmethoddef(struct Type * type, char * className, char * methodName, struct Param * param, struct CompoundStmt * compoundStmt);
struct MainFunc* alloc_ast_mainfunc(struct CompoundStmt * compoundStmt);
struct Param* alloc_ast_Param(struct Type * type, struct Ident * ident);
struct Ident* alloc_ast_ident(char * id, int len);
struct Type* alloc_ast_type(char * id, Type_e e);
struct CompoundStmt* alloc_ast_compoundstmt(struct VarDecl * varDecl, struct Stmt * stmt);
struct Stmt* alloc_ast_stmt(Stmt_e e, void * type);
struct ExprStmt* alloc_ast_exprstmt(struct Expr * expr);
struct AssignStmt* alloc_ast_assignstmt(struct RefVarExpr * refVarExpr, struct Expr * expr);
struct RetStmt* alloc_ast_retstmt(struct Expr * expr);
struct WhileStmt* alloc_ast_whilestmt(struct Expr * cond, struct Stmt * body);
struct DoStmt* alloc_ast_dostmt(struct Expr * cond, struct Stmt * body);
struct ForStmt* alloc_ast_forstmt(struct Expr *init, struct Expr * cond, struct Expr * incr, struct Stmt * body);
struct IfStmt* alloc_ast_ifstmt(struct Expr * cond, struct Stmt * ifBody, struct Stmt * elseBody);
struct Expr* alloc_ast_expr(Expr_e e, void * type, int intnum, float floatnum); // special
struct OperExpr* alloc_ast_operexpr(Oper_e e, void * type);
struct RefExpr* alloc_ast_refexpr(Ref_e e, void * type);
struct RefVarExpr* alloc_ast_refvarexpr(struct RefExpr * refExpr, struct IdentExpr * identExpr);
struct RefCallExpr* alloc_ast_refcallexpr(struct RefExpr * refExpr, struct CallExpr * callExpr);
struct IdentExpr* alloc_ast_identexpr(char * id, struct Expr * expr);
struct CallExpr* alloc_ast_callexpr(char * id, struct Arg * arg);
struct UnOp* alloc_ast_unop(Unop_e e, struct Expr * expr);
struct AddiOp* alloc_ast_AddiOp(Addi_e e, struct Expr * lhs, struct Expr * rhs);
struct MultOp* alloc_ast_MultOp(Mult_e e, struct Expr * lhs, struct Expr * rhs);
struct RelaOp* alloc_ast_RelaOp(Rela_e e, struct Expr * lhs, struct Expr * rhs);
struct EqltOp* alloc_ast_EqltOp(Eqlt_e e, struct Expr * lhs, struct Expr * rhs);

struct Class* alloc_ast_Class_List(struct Class * ClassList, struct Class * _class);
struct VarDecl* alloc_ast_VarDecl_List(struct VarDecl * VarDeclList, struct VarDecl * varDecl);
struct MethodDecl* alloc_ast_MethodDecl_List(struct MethodDecl * MethodDeclList, struct MethodDecl * methodDecl);
struct MethodDef* alloc_ast_MethodDef_List(struct MethodDef * MethodDefList, struct MethodDef * methodDef);
struct ClassMethodDef* alloc_ast_ClassMethodDef_List(struct ClassMethodDef * ClassMethodDefList, struct ClassMethodDef * classMethodDef);
struct Param* alloc_ast_Param_List(struct Param * ParamList, struct Param * param);
struct Stmt* alloc_ast_Stmt_List(struct Stmt * StmtList, struct Stmt * stmt);
struct Arg* alloc_ast_Arg_List(struct Arg * ArgList, struct Expr * expr);

void printHEAD(struct Program * head);
void printClassList(struct Class * _class);
void printClassMethodList(struct ClassMethodDef * classMethodDef);
void printMainFunc(struct MainFunc * mainFunc);
void printCompoundStmt(struct CompoundStmt * compoundStmt);
void printMember(struct Member * member);


void printVarDeclList(struct VarDecl * vardecl);
void printMethodDeclList(struct MethodDecl * methoddecl);
void printMethodDefList(struct MethodDef * methoddef);
void printType(struct Type * type);
void printIdent(struct Ident * ident);

void printExpr(struct Expr * expr);
void printOperExpr(struct OperExpr * operExpr);
void printUnOp(struct UnOp * unOp);
void printAddiOp(struct AddiOp * addiOp);
void printMultOp(struct MultOp * multOp);
void printRelaOp(struct RelaOp * relaOp);
void printEqltOp(struct EqltOp * eqltOp);


void printParamList(struct Param * param);
void printStmtList(struct Stmt * stmt);
void printExprStmt(struct ExprStmt * exprStmt);
void printAssignStmt(struct AssignStmt * assignStmt);
void printRetStmt(struct RetStmt * retStmt);
void printWhileStmt(struct WhileStmt * whileStmt);
void printDoStmt(struct DoStmt * doStmt);
void printForStmt(struct ForStmt * forStmt);
void printIfStmt(struct IfStmt * ifStmt);


void printRefExpr(struct RefExpr * refExpr);
void printRefVarExpr(struct RefVarExpr * refVarExpr);

void printRefCallExpr(struct RefCallExpr * refCallExpr);
void printIdentExpr(struct IdentExpr * identExpr);
void printCallExpr(struct CallExpr * callExpr);
void printArgList(struct Arg * arg);

//심볼테이블

void printSymbolTable(struct Program * head);
void printMainFuncSymbolTable(struct MainFunc * mainFunc, int * levels);
void printVarDeclListSymbolTable(struct VarDecl * varDecl, int level, char * location);

void printIfStmtSymbolTable(struct IfStmt * ifStmt, int * levels, char * location);
void printForStmtSymbolTable(struct ForStmt * forStmt, int  * levels, char * location);
void printDoStmtSymbolTable(struct DoStmt * doStmt, int * levels, char * location);
void printWhileStmtSymbolTable(struct WhileStmt * whileStmt, int * levels, char * location);
void printStmtListSymbolTable(struct Stmt * stmt, int * levels, char * location);
void printCompoundStmtSymbolTable(struct CompoundStmt * compoundStmt, int * levels, char * location);
void store_preLevels(int * levels, int * pre_levels);
void load_preLevels(int * levels, int * pre_levels);


#endif


