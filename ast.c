#include "ast.h"

struct Program* alloc_ast_program(struct Class *_classList, struct ClassMethodDef *classMethodDefList, struct MainFunc *mainFunc)
{
	struct Program * node = (struct Program*)malloc(sizeof(struct Program));
	node->_class = _classList;
	node->classMethodDef = classMethodDefList;
	node->mainFunc = mainFunc;

	return node;
}

struct Class* alloc_ast_class(char * id, struct Member * priMember, struct Member * pubMember)
{
	struct Class * node = (struct Class*)malloc(sizeof(struct Class));

	node->id = malloc(sizeof(id));
	strcpy(node->id, id);

	node->priMember = priMember;
	node->pubMember = pubMember;

	return node;

}
struct Member* alloc_ast_member(struct VarDecl * varDecl, struct MethodDecl * methodDecl, struct MethodDef * methodDef)
{
	//printf("member debugging");
	struct Member * node = (struct Member*)malloc(sizeof(struct Member));

	node->varDecl = varDecl;
	node->methodDecl = methodDecl;
	node->methodDef = methodDef;

	return node;
}
struct VarDecl* alloc_ast_vardecl(struct Type * type, struct Ident * ident, struct Expr * expr)
{
	//printf("VarDecl debugging");
	struct VarDecl * node = (struct VarDecl*)malloc(sizeof(struct VarDecl));

	node->type = type;
	node->ident = ident;
	node->expr = expr;


	return node;

}
struct MethodDecl* alloc_ast_methoddecl(char * id, struct Type * type, struct Param * param)
{
	struct MethodDecl * node = (struct MethodDecl*)malloc(sizeof(struct MethodDecl));

	node->id = malloc(sizeof(id));
	strcpy(node->id, id);
	node->type = type;
	node->param = param;


	return node;

}
struct MethodDef* alloc_ast_methoddef(char * id, struct Type * type, struct Param * param, struct CompoundStmt * compoundStmt)
{
	struct MethodDef * node = (struct MethodDef*)malloc(sizeof(struct MethodDef));

	node->id = malloc(sizeof(id));
	strcpy(node->id, id);
	node->type = type;
	node->param = param;
	node->compoundStmt = compoundStmt;

	return node;
}
struct ClassMethodDef* alloc_ast_classmethoddef(struct Type * type, char * className, char * methodName, struct Param * param, struct CompoundStmt * compoundStmt)
{
	struct ClassMethodDef * node = (struct ClassMethodDef*)malloc(sizeof(struct ClassMethodDef));
	node->type = type;
	node->className = malloc(sizeof(className));
	strcpy(node->className, className);
	node->methodName = malloc(sizeof(methodName));
	strcpy(node->methodName, methodName);
	node->param = param;
	node->compoundStmt = compoundStmt;

	return node;

}
struct MainFunc* alloc_ast_mainfunc(struct CompoundStmt * compoundStmt)
{
	struct MainFunc * node = (struct MainFunc*)malloc(sizeof(struct MainFunc));
	node->compoundStmt = compoundStmt;

	return node;

}

struct Param* alloc_ast_Param(struct Type * type, struct Ident * ident)
{
	struct Param * node = (struct Param*)malloc(sizeof(struct Param));
	node->type = type;
	node->ident = ident;

	return node;
}

struct Ident* alloc_ast_ident(char * id, int len)
{
	struct Ident * node = (struct Ident*)malloc(sizeof(struct Ident));
	node->id = malloc(sizeof(id));
	strcpy(node->id, id);
	node->len = len;

	return node;

}
struct Type* alloc_ast_type(char * id, Type_e e)
{
	struct Type * node = (struct Type*)malloc(sizeof(struct Type));
	node->e = e;
	if (node->e == eClass) {
		node->id = malloc(sizeof(id));
		strcpy(node->id, id);
	}
	else {
		node->id = NULL;
	}

	return node;
}
struct CompoundStmt* alloc_ast_compoundstmt(struct VarDecl * varDecl, struct Stmt * stmt)
{
	struct CompoundStmt * node = (struct CompoundStmt*)malloc(sizeof(struct CompoundStmt));
	node->varDecl = varDecl;
	node->stmt = stmt;

	return node;
}
struct Stmt* alloc_ast_stmt(Stmt_e e, void * type)
{
	struct Stmt * node = (struct Stmt*)malloc(sizeof(struct Stmt));

	node->e = e;

	switch (node->e)
	{
	case eExpr:
		node->type.exprStmt = type;
		break;
	case eAssign:
		node->type.assignStmt = type;
		break;
	case eRet:
		node->type.retStmt = type;
		break;
	case eWhile:
		node->type.whileStmt = type;
		break;
	case eDo:
		node->type.doStmt = type;
		break;
	case eFor:
		node->type.forStmt = type;
		break;
	case eIf:
		node->type.ifStmt = type;
		break;
	case eCompound:
		node->type.compoundStmt = type;
		break;
	case eSemi:
		node->type.assignStmt = NULL;
		break;
	}



	return node;
}
struct ExprStmt* alloc_ast_exprstmt(struct Expr * expr)
{
	struct ExprStmt * node = (struct ExprStmt*)malloc(sizeof(struct ExprStmt));
	node->expr = expr;

	return node;
}
struct AssignStmt* alloc_ast_assignstmt(struct RefVarExpr * refVarExpr, struct Expr * expr)
{
	struct AssignStmt * node = (struct AssignStmt*)malloc(sizeof(struct AssignStmt));
	node->refVarExpr = refVarExpr;
	node->expr = expr;

	return node;
}
struct RetStmt* alloc_ast_retstmt(struct Expr * expr)
{
	struct RetStmt * node = (struct RetStmt*)malloc(sizeof(struct RetStmt));
	node->expr = expr;

	return node;
}
struct WhileStmt* alloc_ast_whilestmt(struct Expr * cond, struct Stmt * body)
{
	struct WhileStmt * node = (struct WhileStmt*)malloc(sizeof(struct WhileStmt));
	node->cond = cond;
	node->body = body;

	return node;
}
struct DoStmt* alloc_ast_dostmt(struct Expr * cond, struct Stmt * body)
{
	struct DoStmt * node = (struct DoStmt*)malloc(sizeof(struct DoStmt));
	node->cond = cond;
	node->body = body;

	return node;
}
struct ForStmt* alloc_ast_forstmt(struct Expr *init, struct Expr * cond, struct Expr * incr, struct Stmt * body)
{
	struct ForStmt * node = (struct ForStmt*)malloc(sizeof(struct ForStmt));
	node->init = init;
	node->cond = cond;
	node->incr = incr;
	node->body = body;

	return node;
}
struct IfStmt* alloc_ast_ifstmt(struct Expr * cond, struct Stmt * ifBody, struct Stmt * elseBody)
{
	struct IfStmt * node = (struct IfStmt*)malloc(sizeof(struct IfStmt));
	node->cond = cond;
	node->ifBody = ifBody;
	node->elseBody = elseBody;

	return node;
}
struct Expr* alloc_ast_expr(Expr_e e, void * type, int intnum, float floatnum)
{
	struct Expr * node = (struct Expr*)malloc(sizeof(struct Expr));
	node->e = e;
	switch (node->e)
	{
	case eOper:
		node->type.operExpr = type;
		break;
	case eRef:
		node->type.refExpr = type;
		break;
	case eIntnum:
		node->type.intnum = intnum;
		break;
	case eFloatnum:
		node->type.floatnum = floatnum;
		break;
	}

	return node;

}

struct OperExpr* alloc_ast_operexpr(Oper_e e, void * type)
{
	struct OperExpr * node = (struct OperExpr*)malloc(sizeof(struct OperExpr));
	node->e = e;
	switch (node->e)
	{
	case eUn:
		node->type.un = type;
		break;
	case eAddi:
		node->type.addi = type;
		break;
	case eMult:
		node->type.mult = type;
		break;
	case eRela:
		node->type.rela = type;
		break;
	case eEqlt:
		node->type.eqlt = type;
		break;
	case eBracket:
		node->type.bracket = type;
		break;
	}

	return node;
}
struct RefExpr* alloc_ast_refexpr(Ref_e e, void * type)
{
	struct RefExpr * node = (struct RefExpr*)malloc(sizeof(struct RefExpr));
	node->e = e;
	switch (node->e)
	{
	case eVar:
		node->type.refVarExpr = type;
		break;
	case eCall:
		node->type.refCallExpr = type;
		break;
	}

	return node;
}
struct RefVarExpr* alloc_ast_refvarexpr(struct RefExpr * refExpr, struct IdentExpr * identExpr)
{
	struct RefVarExpr * node = (struct RefVarExpr*)malloc(sizeof(struct RefVarExpr));

	node->refExpr = refExpr;
	node->identExpr = identExpr;

	return node;
}
struct RefCallExpr* alloc_ast_refcallexpr(struct RefExpr * refExpr, struct CallExpr * callExpr)
{
	struct RefCallExpr * node = (struct RefCallExpr*)malloc(sizeof(struct RefCallExpr));
	node->refExpr = refExpr;
	node->callExpr = callExpr;


	return node;
}
struct IdentExpr* alloc_ast_identexpr(char * id, struct Expr * expr)
{
	struct IdentExpr * node = (struct IdentExpr*)malloc(sizeof(struct IdentExpr));
	node->id = malloc(sizeof(id));
	strcpy(node->id, id);
	node->expr = expr;

	return node;
}
struct CallExpr* alloc_ast_callexpr(char * id, struct Arg * arg)
{
	struct CallExpr * node = (struct CallExpr*)malloc(sizeof(struct CallExpr));
	node->id = malloc(sizeof(id));
	strcpy(node->id, id);

	node->arg = arg;

	return node;
}


struct UnOp* alloc_ast_unop(Unop_e e, struct Expr * expr)
{
	struct UnOp * node = (struct UnOp*)malloc(sizeof(struct UnOp));
	node->e = e;
	node->expr = expr;

	return node;
}
struct AddiOp* alloc_ast_AddiOp(Addi_e e, struct Expr * lhs, struct Expr * rhs)
{
	struct AddiOp * node = (struct AddiOp*)malloc(sizeof(struct AddiOp));
	node->e = e;
	node->lhs = lhs;
	node->rhs = rhs;

	return node;
}
struct MultOp* alloc_ast_MultOp(Mult_e e, struct Expr * lhs, struct Expr * rhs)
{
	struct MultOp * node = (struct MultOp*)malloc(sizeof(struct MultOp));
	node->e = e;
	node->lhs = lhs;
	node->rhs = rhs;

	return node;
}
struct RelaOp* alloc_ast_RelaOp(Rela_e e, struct Expr * lhs, struct Expr * rhs)
{
	struct RelaOp * node = (struct RelaOp*)malloc(sizeof(struct RelaOp));
	node->e = e;
	node->lhs = lhs;
	node->rhs = rhs;

	return node;
}
struct EqltOp* alloc_ast_EqltOp(Eqlt_e e, struct Expr * lhs, struct Expr * rhs)
{
	struct EqltOp * node = (struct EqltOp*)malloc(sizeof(struct EqltOp));
	node->e = e;
	node->lhs = lhs;
	node->rhs = rhs;

	return node;
}


struct Class* alloc_ast_Class_List(struct Class * ClassList, struct Class * _class)
{
	_class->prev = ClassList;

	return _class;
}
struct VarDecl* alloc_ast_VarDecl_List(struct VarDecl * VarDeclList, struct VarDecl * varDecl)
{
	varDecl->prev = VarDeclList;

	return varDecl;
}
struct MethodDecl* alloc_ast_MethodDecl_List(struct MethodDecl * MethodDeclList, struct MethodDecl * methodDecl)
{
	methodDecl->prev = MethodDeclList;

	return methodDecl;
}
struct MethodDef* alloc_ast_MethodDef_List(struct MethodDef * MethodDefList, struct MethodDef * methodDef)
{
	methodDef->prev = MethodDefList;

	return methodDef;
}
struct ClassMethodDef* alloc_ast_ClassMethodDef_List(struct ClassMethodDef * ClassMethodDefList, struct ClassMethodDef * classMethodDef)
{
	classMethodDef->prev = ClassMethodDefList;

	return classMethodDef;
}

struct Stmt* alloc_ast_Stmt_List(struct Stmt * StmtList, struct Stmt * stmt)
{
	stmt->prev = StmtList;

	return stmt;
}

struct Param* alloc_ast_Param_List(struct Param * ParamList, struct Param * param)
{
	param->prev = ParamList;

	return param;
}

struct Arg* alloc_ast_Arg_List(struct Arg * ArgList, struct Expr * expr)
{
	struct Arg * node = (struct Arg*)malloc(sizeof(struct Arg));
	node->prev = ArgList;
	node->expr = expr;

	return node;
}

void printHEAD(struct Program * head)
{
	if (head != NULL)
	{
		printClassList(head->_class);
		printClassMethodList(head->classMethodDef);
		printMainFunc(head->mainFunc);

	}
	return;
}

void printClassList(struct Class * _class)
{

	if (_class != NULL)
	{
		if (_class->prev != NULL)
		{
			printClassList(_class->prev);
		}

		fprintf(fout, "class ");
		fprintf(fout, "%s", _class->id);
		fprintf(fout, "\n{\n");

		if (_class->priMember != NULL)
		{
			fprintf(fout, "private:\n");
			printMember(_class->priMember);
		}

		if (_class->pubMember != NULL)
		{
			fprintf(fout, "public:\n");
			printMember(_class->pubMember);
		}

		fprintf(fout, "\n}\n\n");

	}

	return;
}


void printClassMethodList(struct ClassMethodDef * classMethodDef)
{
	if (classMethodDef != NULL)
	{
		if (classMethodDef->prev != NULL)
		{
			printClassMethodList(classMethodDef->prev);
		}

		fprintf(fout, "\n\n");
		printType(classMethodDef->type);
		fprintf(fout, " ");
		fprintf(fout, "%s", classMethodDef->className);
		fprintf(fout, "::");
		fprintf(fout, "%s", classMethodDef->methodName);
		fprintf(fout, "(");
		printParamList(classMethodDef->param);
		fprintf(fout, ")\n");
		printCompoundStmt(classMethodDef->compoundStmt);
		fprintf(fout, "\n\n");

	}

	return;
}

void printMainFunc(struct MainFunc * mainFunc)
{
	if (mainFunc != NULL)
	{
		fprintf(fout, "int main () \n");
		printCompoundStmt(mainFunc->compoundStmt);
	}

	return;
}

void printCompoundStmt(struct CompoundStmt * compoundStmt)
{
	if (compoundStmt != NULL)
	{
		fprintf(fout, "{\n");
		printVarDeclList(compoundStmt->varDecl);
		printStmtList(compoundStmt->stmt);
		fprintf(fout, "}\n");
	}

	return;
}

void printMember(struct Member * member)
{
	if (member != NULL)
	{
		if (member->varDecl != NULL)
		{
			printVarDeclList(member->varDecl);
		}

		if (member->methodDecl != NULL)
		{
			printMethodDeclList(member->methodDecl);
		}

		if (member->methodDef != NULL)
		{
			printMethodDefList(member->methodDef);
		}
	}

	return;
}

void printVarDeclList(struct VarDecl * vardecl)
{
	//printf("debugging");
	if (vardecl != NULL)
	{
		if (vardecl->prev != NULL)
		{
			printVarDeclList(vardecl->prev);
		}
		//fprintf(fout,"\t");
		printType(vardecl->type);
		fprintf(fout, " ");
		printIdent(vardecl->ident);
		if (vardecl->expr != NULL)
		{
			fprintf(fout, " = ");
			printExpr(vardecl->expr);
		}
		fprintf(fout, ";\n");

	}


	return;
}

void printMethodDeclList(struct MethodDecl * methoddecl)
{
	if (methoddecl != NULL)
	{
		if (methoddecl->prev != NULL)
		{
			printMethodDeclList(methoddecl->prev);
		}
		//fprintf(fout,"\t");
		printType(methoddecl->type);
		fprintf(fout, " ");
		fprintf(fout, "%s", methoddecl->id);
		fprintf(fout, "(");
		printParamList(methoddecl->param);
		fprintf(fout, ")");
		fprintf(fout, ";\n");

	}

	return;
}

void printMethodDefList(struct MethodDef * methoddef)
{
	if (methoddef != NULL)
	{
		if (methoddef->prev != NULL)
		{
			printMethodDefList(methoddef->prev);
		}
		//fprintf(fout,"\t");
		printType(methoddef->type);
		fprintf(fout, " ");
		fprintf(fout, "%s", methoddef->id);
		fprintf(fout, "(");
		printParamList(methoddef->param);
		fprintf(fout, ")\n");
		printCompoundStmt(methoddef->compoundStmt);


	}

	return;
}

void printType(struct Type * type)
{
	if (type != NULL)
	{
		switch (type->e)
		{
		case eInt:
			fprintf(fout, "int");
			break;
		case eFloat:
			fprintf(fout, "float");
			break;
		case eClass:
			fprintf(fout, "%s", type->id);
			break;
		}
	}
	return;
}

void printIdent(struct Ident * ident)
{
	if (ident != NULL)
	{
		if (ident->len == 0)
		{
			fprintf(fout, "%s", ident->id);
		}
		else
		{
			fprintf(fout, "%s[%d]", ident->id, ident->len);
		}
	}

	return;
}

void printExpr(struct Expr * expr)
{
	if (expr != NULL)
	{
		switch (expr->e)
		{
		case eOper:
			printOperExpr(expr->type.operExpr);
			break;
		case eRef:
			printRefExpr(expr->type.refExpr);
			break;
		case eIntnum:
			fprintf(fout, "%d", expr->type.intnum);
			break;
		case eFloatnum:
			fprintf(fout, "%d", expr->type.floatnum);
			break;
		}
	}

	return;
}

void printOperExpr(struct OperExpr * operExpr)
{
	if (operExpr != NULL)
	{
		switch (operExpr->e)
		{
		case eUn:
			printUnOp(operExpr->type.un);
			break;
		case eAddi:
			printAddiOp(operExpr->type.addi);
			break;
		case eMult:
			break;
			printMultOp(operExpr->type.mult);
		case eRela:
			printRelaOp(operExpr->type.rela);
			break;
		case eEqlt:
			printEqltOp(operExpr->type.eqlt);
			break;

		case eBracket:
			fprintf(fout, "( ");
			printExpr(operExpr->type.bracket);
			fprintf(fout, " )");
			break;
		}
	}
}

void printUnOp(struct UnOp * unOp)
{
	if (unOp != NULL)
	{
		fprintf(fout, "-");
		printExpr(unOp->expr);
	}

	return;
}

void printAddiOp(struct AddiOp * addiOp)
{
	if (addiOp != NULL)
	{
		switch (addiOp->e)
		{
		case ePlus:
			printExpr(addiOp->lhs);
			fprintf(fout, "+");
			printExpr(addiOp->rhs);
			break;
		case eMinus:
			printExpr(addiOp->lhs);
			fprintf(fout, "-");
			printExpr(addiOp->rhs);
			break;
		}
	}

	return;
}

void printMultOp(struct MultOp * multOp)
{
	if (multOp != NULL)
	{
		switch (multOp->e)
		{
		case eMul:
			printExpr(multOp->lhs);
			fprintf(fout, "*");
			printExpr(multOp->rhs);
			break;
		case eDiv:
			printExpr(multOp->lhs);
			fprintf(fout, "/");
			printExpr(multOp->rhs);
			break;
		}
	}

	return;
}

void printRelaOp(struct RelaOp * relaOp)
{
	if (relaOp != NULL)
	{
		switch (relaOp->e)
		{
		case eLT:
			printExpr(relaOp->lhs);
			fprintf(fout, "<");
			printExpr(relaOp->rhs);
			break;
		case eGT:
			printExpr(relaOp->lhs);
			fprintf(fout, ">");
			printExpr(relaOp->rhs);
			break;

		case eLE:
			printExpr(relaOp->lhs);
			fprintf(fout, "<=");
			printExpr(relaOp->rhs);
			break;
		case eGE:
			printExpr(relaOp->lhs);
			fprintf(fout, ">=");
			printExpr(relaOp->rhs);
			break;

		}
	}

	return;
}

void printEqltOp(struct EqltOp * eqltOp)
{
	if (eqltOp != NULL)
	{
		switch (eqltOp->e)
		{
		case eEQ:
			printExpr(eqltOp->lhs);
			fprintf(fout, "==");
			printExpr(eqltOp->rhs);
			break;
		case eNE:
			printExpr(eqltOp->lhs);
			fprintf(fout, "!=");
			printExpr(eqltOp->rhs);
			break;
		}
	}

	return;
}



//////////////////////////////////////////////////

void printParamList(struct Param * param)
{
	if (param != NULL)
	{
		if (param->prev != NULL)
		{
			printParamList(param->prev);
			fprintf(fout, ", ");
		}

		printType(param->type);
		fprintf(fout, " ");
		printIdent(param->ident);

	}

	return;
}

////////////////////////////////////////////////

void printStmtList(struct Stmt * stmt)
{
	if (stmt != NULL)
	{
		if (stmt->prev != NULL)
		{
			printStmtList(stmt->prev);
		}

		switch (stmt->e)
		{
		case eExpr:
			printExprStmt(stmt->type.exprStmt);
			break;
		case eAssign:
			printAssignStmt(stmt->type.assignStmt);
			break;
		case eRet:
			printRetStmt(stmt->type.retStmt);
			break;
		case eWhile:
			printWhileStmt(stmt->type.whileStmt);
			break;
		case eDo:
			printDoStmt(stmt->type.doStmt);
			break;
		case eFor:
			printForStmt(stmt->type.forStmt);
			break;
		case eIf:
			printIfStmt(stmt->type.ifStmt);
			break;
		case eCompound:
			printCompoundStmt(stmt->type.compoundStmt);
			break;
		case eSemi:
			fprintf(fout, ";\n");
			break;
		}
	}

	return;
}

void printExprStmt(struct ExprStmt * exprStmt)
{
	if (exprStmt != NULL)
	{
		printExpr(exprStmt->expr);
		fprintf(fout, ";\n");
	}

	return;
}

void printAssignStmt(struct AssignStmt * assignStmt)
{
	if (assignStmt != NULL)
	{
		printRefVarExpr(assignStmt->refVarExpr);
		fprintf(fout, " = ");
		printExpr(assignStmt->expr);
		fprintf(fout, ";\n");
	}

	return;
}

void printRetStmt(struct RetStmt * retStmt)
{
	if (retStmt != NULL)
	{
		fprintf(fout, "return ");
		printExpr(retStmt->expr);
		fprintf(fout, ";\n");
	}

	return;
}

void printWhileStmt(struct WhileStmt * whileStmt)
{
	if (whileStmt != NULL)
	{
		fprintf(fout, "while(");
		printExpr(whileStmt->cond);
		fprintf(fout, ")");
		printStmtList(whileStmt->body);
	}

	return;
}

void printDoStmt(struct DoStmt * doStmt)
{
	if (doStmt != NULL)
	{
		fprintf(fout, "do");
		printStmtList(doStmt->body);
		fprintf(fout, "while(");
		printExpr(doStmt->cond);
		fprintf(fout, ")");
		fprintf(fout, ";\n");

	}

	return;
}

void printForStmt(struct ForStmt * forStmt)
{
	if (forStmt != NULL)
	{

		fprintf(fout, "for(");
		printExpr(forStmt->init);
		fprintf(fout, ";");
		printExpr(forStmt->cond);
		fprintf(fout, ";");
		printExpr(forStmt->incr);
		fprintf(fout, ")\n");
		printStmtList(forStmt->body);
	}

	return;
}

void printIfStmt(struct IfStmt * ifStmt)
{
	if (ifStmt != NULL)
	{
		if (ifStmt->elseBody == NULL) {
			fprintf(fout, "if(");
			printExpr(ifStmt->cond);
			fprintf(fout, ")\n");
			printStmtList(ifStmt->ifBody);
		}
		else if (ifStmt->elseBody != NULL) {
			fprintf(fout, "if(");
			printExpr(ifStmt->cond);
			fprintf(fout, ")\n");
			printStmtList(ifStmt->ifBody);
			fprintf(fout, "else\n");
			printStmtList(ifStmt->elseBody);
		}
	}

	return;
}

///////////////////////////////////////////////////////


void printRefExpr(struct RefExpr * refExpr)
{
	if (refExpr != NULL)
	{
		switch (refExpr->e)
		{
		case eVar:
			printRefVarExpr(refExpr->type.refVarExpr);
			break;
		case eCall:
			printRefCallExpr(refExpr->type.refCallExpr);
			break;
		}
	}

	return;
}

void printRefVarExpr(struct RefVarExpr * refVarExpr)
{
	if (refVarExpr != NULL)
	{
		if (refVarExpr->refExpr != NULL) {
			printRefExpr(refVarExpr->refExpr);
			fprintf(fout, ".");
		}

		printIdentExpr(refVarExpr->identExpr);
	}



	return;
}

void printRefCallExpr(struct RefCallExpr * refCallExpr)
{
	//printf("printRefCallExpr()호출됨.\n");
	if (refCallExpr != NULL)
	{
		if (refCallExpr->refExpr != NULL) {
			printRefExpr(refCallExpr->refExpr);
			fprintf(fout, ".");
		}

		printCallExpr(refCallExpr->callExpr);
	}


	return;
}

void printIdentExpr(struct IdentExpr * identExpr)
{
	if (identExpr != NULL)
	{
		if (identExpr->expr == NULL)
		{
			fprintf(fout, "%s", identExpr->id);
		}
		else if (identExpr->expr != NULL)
		{
			fprintf(fout, "%s", identExpr->id);
			fprintf(fout, "[");
			printExpr(identExpr->expr);
			fprintf(fout, "]");
		}
	}


	return;
}

void printCallExpr(struct CallExpr * callExpr)
{
	//printf("printCallExpr()호출됨.\n");
	if (callExpr != NULL)
	{
		fprintf(fout, "%s", callExpr->id);
		fprintf(fout, "(");
		printArgList(callExpr->arg);
		fprintf(fout, ")");
	}

	return;
}

void printArgList(struct Arg * arg)
{
	if (arg != NULL)
	{
		if (arg->prev != NULL)
		{
			printArgList(arg->prev);
			fprintf(fout, ", ");
		}

		printExpr(arg->expr);
	}

	return;
}

/////////////////////////심볼 테이블 함수 //////////////////////////

int count = 1;


void printSymbolTable(struct Program * head)
{
	if (head != NULL) {


		int levels[4];
		for (int i = 0; i < 4; i++)
			levels[i] = 0;

		
		printMainFuncSymbolTable(head->mainFunc, levels);
	}

}

void printMainFuncSymbolTable(struct MainFunc * mainFunc, int * levels)
{

	char * location = malloc(sizeof(char) * 1000);
	for (int i = 0; i < 1000; i++)
		location[i] = '\0';
	strcat(location, "Location : main");


	printCompoundStmtSymbolTable(mainFunc->compoundStmt, levels, location);

}

void printCompoundStmtSymbolTable(struct CompoundStmt * compoundStmt, int * levels, char * location)
{
	if (compoundStmt != NULL) {

		fprintf(fout, location);
		fprintf(fout, "\n");

		fprintf(fout, "%-6s%-10s%-20s%-6s%-20s\n",
			"Count", "Type", "Name", "Array", "Role");
		printVarDeclListSymbolTable(compoundStmt->varDecl, 1, location);
		fprintf(fout, "\n\n");

		count = 1;
		char pre_location[1000];
		int pre_levels[4];

		store_preLevels(levels, pre_levels);
		strcpy(pre_location, location);	//이전 위치 임시 저장
		printStmtListSymbolTable(compoundStmt->stmt, levels, location);

		strcpy(location, pre_location);	//이전 위치 다시 불러오기
		load_preLevels(levels, pre_levels);
		fprintf(fout, "\n\n");


	}
}

void store_preLevels(int * levels,int * pre_levels) {
	for (int i = 0; i < 4; i++)
		pre_levels[i] = levels[i];
}

void load_preLevels(int * levels, int * pre_levels) {
	for (int i = 0; i < 4; i++)
		levels[i] = pre_levels[i];
}

void printStmtListSymbolTable(struct Stmt * stmt, int * levels, char * location) {
	if (stmt != NULL) {
		if (stmt->prev != NULL) {
			printStmtListSymbolTable(stmt->prev, levels, location);
		}

		switch (stmt->e)
		{
		case eWhile:
			printWhileStmtSymbolTable(stmt->type.whileStmt, levels, location);
			break;
		case eDo:
			printDoStmtSymbolTable(stmt->type.doStmt, levels, location);
			break;
		case eFor:
			printForStmtSymbolTable(stmt->type.forStmt, levels, location);
			break;
		case eIf:
			printIfStmtSymbolTable(stmt->type.ifStmt, levels, location);
			break;
		case eCompound:
			printCompoundStmtSymbolTable(stmt->type.compoundStmt, levels, location);

			break;
		}

	}
}

void printWhileStmtSymbolTable(struct WhileStmt * whileStmt, int * levels, char * location) {

	if (whileStmt != NULL) {

		char str[100];
		char pre_location[1000];
		int pre_levels[4];

		strcpy(pre_location, location);	//이전 위치 임시 저장


		levels[0]++;
		sprintf(str, " - while(%d)", levels[0]);
		strcat(location, str);
		printStmtListSymbolTable(whileStmt->body, levels, location);



		strcpy(location, pre_location);	//이전 위치 다시 불러오기




	}
}

void printDoStmtSymbolTable(struct DoStmt * doStmt, int * levels, char * location) {
	if (doStmt != NULL) {

		//sprintf(str, " - while(%d)");
		char str[100];
		char pre_location[1000];
		int pre_levels[4];

		strcpy(pre_location, location);	//이전 위치 임시 저장


		levels[1]++;
		sprintf(str, " - do(%d)", levels[1]);
		strcat(location, str);
		printStmtListSymbolTable(doStmt->body, levels, location);


		strcpy(location, pre_location);	//이전 위치 다시 불러오기



	}
}

void printForStmtSymbolTable(struct ForStmt * forStmt, int * levels, char * location) {

	if (forStmt != NULL) {

		char str[100];
		char pre_location[1000];


		strcpy(pre_location, location);	//이전 위치 임시 저장


		levels[2]++;
		sprintf(str, " - for(%d)", levels[2]);
		strcat(location, str);
		printStmtListSymbolTable(forStmt->body, levels, location);

		strcpy(location, pre_location);	//이전 위치 다시 불러오기

	}
}

void printIfStmtSymbolTable(struct IfStmt * ifStmt, int * levels, char * location) {
	if (ifStmt != NULL) {


		char str[100];
		char pre_location[1000];

		strcpy(pre_location, location);	//이전 위치 임시 저장

		levels[3]++;
		sprintf(str, " - if(%d)", levels[3]);
		strcat(location, str);
		printStmtListSymbolTable(ifStmt->ifBody, levels, location);


		strcpy(location, pre_location);	//이전 위치 다시 불러오기

	}
}

void printVarDeclListSymbolTable(struct VarDecl * varDecl, int level, char * location)
{
	count++;
	if (varDecl != NULL) {
		if (varDecl->prev != NULL)
		{

			printVarDeclListSymbolTable(varDecl->prev, level + 1, location);

		}

		if (varDecl->type->e == eInt) {

			if (varDecl->ident->len != 0) {

				fprintf(fout, "%-6d%-10s%-20s%-6d%-20s\n",
					count - level, "int", varDecl->ident->id, varDecl->ident->len, "variable");
			}
			else {

				fprintf(fout, "%-6d%-10s%-20s%-6s%-20s\n",
					count - level, "int", varDecl->ident->id, "-", "variable");
			}

		}
		else if (varDecl->type->e == eFloat) {

			if (varDecl->ident->len != 0) {

				fprintf(fout, "%-6d%-10s%-20s%-6d%-20s\n",
					count - level, "float", varDecl->ident->id, varDecl->ident->len, "variable");
			}
			else {

				fprintf(fout, "%-6d%-10s%-20s%-6s%-20s\n",
					count - level, "float", varDecl->ident->id, "-", "variable");
			}
		}
		else if (varDecl->type->e == eClass) {

			if (varDecl->ident->len != 0) {

				fprintf(fout, "%-6d%-10s%-20s%-6d%-20s\n",
					count - level, varDecl->type->id, varDecl->ident->id, varDecl->ident->len, "variable");
			}
			else {

				fprintf(fout, "%-6d%-10s%-20s%-6s%-20s\n",
					count - level, varDecl->type->id, varDecl->ident->id, "-", "variable");


			}
		}


	}

	return;

}













