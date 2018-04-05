#include "CFG.h"

int BBNum = 0;	//Basic Blcok 번호

void printCFG(struct Program * head)
{
	struct BasicBlock * Graph;
	Graph = makeBasicBlock(head->mainFunc);
	printBasicBlock(Graph);
}

struct BasicBlock* makeBasicBlock(struct MainFunc * mainFunc)
{
	struct BasicBlock * graph;
	if (mainFunc != NULL) {
		graph = CFGCompoundStmt(mainFunc->compoundStmt);
	}

	return graph;
}

struct BasicBlock* CFGCompoundStmt(struct CompoundStmt *CompoundStmt)
{
	struct BasicBlock * Graph;	//CFG Head
	struct BasicBlock * ptr;    //순회를 위한 포인터
	struct BasicBlock * last;	//마지막 노드 address

	if (CompoundStmt != NULL) {
		Graph = CFGStmtList(CompoundStmt->stmt, NULL);
		ptr = Graph;

		while ((ptr->next) != NULL) {
			ptr = ptr->next;
		}

		ptr->end = 1;
		last = ptr;

		while ((ptr->prev) != NULL) {
			ptr = ptr->prev;
		}

		ptr->start = 1;

		adjustReturn(ptr, last);
	}
	return ptr;

}

struct BasicBlock *CFGStmtList(struct Stmt *stmt, struct BasicBlock *PrevNode)
{

	struct BasicBlock* CFGNodeAssign = NULL;
	struct BasicBlock* CFGNodeCondition = NULL;
	struct BasicBlock* CFGNodeWhile_s = NULL;
	struct BasicBlock* CFGNodeFor_s = NULL;
	struct BasicBlock* CFGNodeIf_s = NULL;
	struct BasicBlock* CFGNodeIf_s_end = NULL;
	struct BasicBlock* CFGNodeElse_s_end = NULL;
	struct BasicBlock* CFGNodeWhile_s_end = NULL;
	struct BasicBlock* CFGNodeElse_s = NULL;

	struct BasicBlock *Blockptr = NULL,
		*CurrentNode = NULL;

	struct Stmt *Stmtptr = NULL, *tempStmt = NULL;

	if (PrevNode == NULL) {
		CurrentNode = (struct BasicBlock *)malloc(sizeof(struct BasicBlock));
		memset(CurrentNode, 0, sizeof(struct BasicBlock));
		CurrentNode->type = CFG_eAssign;
		CurrentNode->Number = BBNum++;
	}
	else {
		CurrentNode = PrevNode;
	}

	//printf("에러2\n");
	if (stmt != NULL) {
		if (stmt->e == eAssign) {
			Stmtptr = stmt->prev;
			if (CurrentNode->type == CFG_eCondition_w ||
				CurrentNode->type == CFG_eCondition_f) {

				CFGNodeAssign = (struct BasicBlock *)malloc(sizeof(struct BasicBlock));
				memset(CFGNodeAssign, 0, sizeof(struct BasicBlock));
				CFGNodeAssign->type = CFG_eAssign;
				CFGNodeAssign->Number = BBNum++;


				addBasicBlock(CFGNodeAssign, stmt);

				connectBasicBlock(CFGNodeAssign, CurrentNode);

				CurrentNode->prev = CFGNodeAssign;
				CFGNodeAssign->next = CurrentNode;
				CurrentNode = CFGNodeAssign;
			}
			else {

				addBasicBlock(CurrentNode, stmt);
			}
			if (Stmtptr != NULL) {
				//printf("Stmtptr != NULL error  112 line \n");
				CurrentNode = CFGStmtList(Stmtptr, CurrentNode);
			}
			return CurrentNode;
		}
		else if (stmt->e == eCompound) {

			//printf("CFGStmtList eCompound\n");
			Stmtptr = stmt->prev;

			//printf("error  122 line \n");
			CurrentNode = CFGStmtList(stmt->type.compoundStmt->stmt, CurrentNode);
			if (Stmtptr != NULL) {
				CFGStmtList(stmt->prev, CurrentNode);
			}
			return CurrentNode;
		}
		else if (stmt->e == eIf) {
			//printf("error  129 line \n");
			Stmtptr = stmt->prev;

			CFGNodeCondition = (struct BasicBlock *)malloc(sizeof(struct BasicBlock));
			memset(CFGNodeCondition, 0, sizeof(struct BasicBlock));
			CFGNodeCondition->type = CFG_eCondition_i;
			CFGNodeCondition->Number = BBNum++;
			tempStmt = (struct Stmt *)malloc(sizeof(struct Stmt));
			tempStmt->e = eCondition_i;
			tempStmt->type.exprStmt = (struct ExprStmt *)malloc(sizeof(struct ExprStmt));
			tempStmt->type.exprStmt->expr = stmt->type.ifStmt->cond;
			addBasicBlock(CFGNodeCondition, tempStmt);

			CFGNodeIf_s = (struct BasicBlock *)malloc(sizeof(struct BasicBlock));
			memset(CFGNodeIf_s, 0, sizeof(struct BasicBlock));
			CFGNodeIf_s->Number = BBNum++;
			CFGNodeIf_s = CFGStmtList(stmt->type.ifStmt->ifBody, CFGNodeIf_s);
			CFGNodeIf_s_end = CFGNodeIf_s;
			while ((CFGNodeIf_s_end->next) != NULL) {
				CFGNodeIf_s_end = (CFGNodeIf_s_end->next);
			}

			if (stmt->type.ifStmt->elseBody != NULL) {
				CFGNodeElse_s = (struct BasicBlock *)malloc(sizeof(struct BasicBlock));
				memset(CFGNodeElse_s, 0, sizeof(struct BasicBlock));
				CFGNodeElse_s->Number = BBNum++;
				CFGNodeElse_s = CFGStmtList(stmt->type.ifStmt->elseBody, CFGNodeElse_s);
				CFGNodeElse_s_end = CFGNodeElse_s;
				while ((CFGNodeElse_s_end->next) != NULL) {
					CFGNodeElse_s_end = (CFGNodeElse_s_end->next);
				}
			}

			if (stmt->type.ifStmt->elseBody != NULL) {
				connectBasicBlock(CFGNodeCondition, CFGNodeIf_s);
				connectBasicBlock(CFGNodeCondition, CFGNodeElse_s);
				connectBasicBlock(CFGNodeIf_s_end, CurrentNode);
				connectBasicBlock(CFGNodeElse_s_end, CurrentNode);
			}
			else {
				connectBasicBlock(CFGNodeCondition, CFGNodeIf_s);
				connectBasicBlock(CFGNodeCondition, CurrentNode);
				connectBasicBlock(CFGNodeIf_s_end, CurrentNode);
			}

			CurrentNode->prev = CFGNodeCondition;
			CFGNodeCondition->next = CurrentNode;
			CurrentNode = CFGNodeCondition;

			if (Stmtptr != NULL) {
				CurrentNode = CFGStmtList(Stmtptr, CurrentNode);
			}

			return CurrentNode;
		}
		else if (stmt->e == eWhile || stmt->e == eDo) {
			//printf("error  203 line \n");
			Stmtptr = stmt->prev;

			CFGNodeCondition = (struct BasicBlock *)malloc(sizeof(struct BasicBlock));
			memset(CFGNodeCondition, 0, sizeof(struct BasicBlock));
			CFGNodeCondition->type = CFG_eCondition_w;
			CFGNodeCondition->Number = BBNum++;
			tempStmt = (struct Stmt *)malloc(sizeof(struct Stmt));
			memset(tempStmt, 0, sizeof(struct Stmt));
			tempStmt->e = eCondition_w;
			tempStmt->type.exprStmt = (struct ExprStmt *)malloc(sizeof(struct ExprStmt));
			tempStmt->type.exprStmt->expr = stmt->type.whileStmt->cond;
			addBasicBlock(CFGNodeCondition, tempStmt);


			CFGNodeWhile_s = (struct BasicBlock *)malloc(sizeof(struct BasicBlock));
			memset(CFGNodeWhile_s, 0, sizeof(struct BasicBlock));
			CFGNodeWhile_s->Number = BBNum++;
			CFGNodeWhile_s = CFGStmtList(stmt->type.whileStmt->body, CFGNodeWhile_s);
			CFGNodeWhile_s_end = CFGNodeWhile_s;
			while ((CFGNodeWhile_s_end->next) != NULL) {
				CFGNodeWhile_s_end = (CFGNodeWhile_s_end->next);
			}

			connectBasicBlock(CFGNodeCondition, CFGNodeWhile_s);
			connectBasicBlock(CFGNodeWhile_s_end, CFGNodeCondition);
			connectBasicBlock(CFGNodeCondition, CurrentNode);

			CurrentNode->prev = CFGNodeCondition;
			CFGNodeCondition->next = CurrentNode;
			CurrentNode = CFGNodeCondition;

			if (Stmtptr != NULL) {
				CurrentNode = CFGStmtList(Stmtptr, CurrentNode);
			}

			return CurrentNode;
		}
		else if (stmt->e == eFor) {
			//printf("error  253 line \n");
			Stmtptr = stmt->prev;

			CFGNodeAssign = (struct BasicBlock *)malloc(sizeof(struct BasicBlock));
			memset(CFGNodeAssign, 0, sizeof(struct BasicBlock));
			CFGNodeAssign->type = CFG_eAssign;
			CFGNodeAssign->Number = BBNum++;
			//printf("error  262 line \n");
			//copy statment to the block
			tempStmt = (struct Stmt *)malloc(sizeof(struct Stmt));
			memset(tempStmt, 0, sizeof(struct Stmt));
			tempStmt->e = eExpr;
			//printf("error  266 line \n");
			tempStmt->type.exprStmt = (struct ExprStmt *)malloc(sizeof(struct ExprStmt));
			tempStmt->type.exprStmt->expr = stmt->type.forStmt->init;
			//printf("error  269 line \n");
			addBasicBlock(CFGNodeAssign, tempStmt);


			//printf("error  273 line \n");
			CFGNodeCondition = (struct BasicBlock *)malloc(sizeof(struct BasicBlock));
			memset(CFGNodeCondition, 0, sizeof(struct BasicBlock));
			CFGNodeCondition->type = CFG_eCondition_f;
			CFGNodeCondition->Number = BBNum++;

			tempStmt = (struct Stmt *)malloc(sizeof(struct Stmt));
			memset(tempStmt, 0, sizeof(struct Stmt));

			tempStmt->e = eCondition_f;
			tempStmt->type.exprStmt = (struct ExprStmt *)malloc(sizeof(struct ExprStmt));
			tempStmt->type.exprStmt->expr = stmt->type.forStmt->cond;
			addBasicBlock(CFGNodeCondition, tempStmt);


			CFGNodeWhile_s = (struct BasicBlock *)malloc(sizeof(struct BasicBlock));
			memset(CFGNodeWhile_s, 0, sizeof(struct BasicBlock));
			CFGNodeWhile_s->type = CFG_eWhile;
			CFGNodeWhile_s->Number = BBNum++;

			tempStmt = (struct Stmt *)malloc(sizeof(struct Stmt));
			memset(tempStmt, 0, sizeof(struct Stmt));
			tempStmt->e = eExpr;
			//printf("error  296 line \n");
			tempStmt->type.exprStmt = (struct ExprStmt *)malloc(sizeof(struct ExprStmt));
			tempStmt->type.exprStmt->expr = stmt->type.forStmt->incr;
			addBasicBlock(CFGNodeWhile_s, tempStmt);

			CFGNodeWhile_s = CFGStmtList(stmt->type.forStmt->body->type.compoundStmt->stmt, CFGNodeWhile_s);
			CFGNodeWhile_s_end = CFGNodeWhile_s;
			while ((CFGNodeWhile_s_end->next) != NULL) {
				CFGNodeWhile_s_end = (CFGNodeWhile_s_end->next);
			}

			connectBasicBlock(CFGNodeAssign, CFGNodeCondition);
			connectBasicBlock(CFGNodeCondition, CFGNodeWhile_s);
			connectBasicBlock(CFGNodeWhile_s_end, CFGNodeCondition);
			connectBasicBlock(CFGNodeCondition, CurrentNode);

			CurrentNode->prev = CFGNodeAssign;
			CFGNodeAssign->next = CurrentNode;
			CurrentNode = CFGNodeAssign;

			if (Stmtptr != NULL) {
				CurrentNode = CFGStmtList(Stmtptr, CurrentNode);
			}

			return CurrentNode;
		}
		else if (stmt->e == eRet) {

			Stmtptr = stmt->prev;
			addBasicBlock(CurrentNode, stmt);

			if (Stmtptr != NULL) {
				CurrentNode = CFGStmtList(Stmtptr, CurrentNode);
			}

			return CurrentNode;
		}
	}
}



void addBasicBlock(struct BasicBlock *CFGNode, struct Stmt *Stmt) {


	struct Stmt *ptr1, *ptr2, *ptr3;

	ptr1 = Stmt->prev;
	ptr2 = Stmt;
	ptr2->prev = NULL;

	if (CFGNode->Stmt == NULL) {
		CFGNode->Stmt = ptr2;
	}
	else {
		ptr3 = CFGNode->Stmt;
		while (ptr3->prev != NULL) {
			ptr3 = ptr3->prev;
		}
		ptr3->prev = ptr2;
	}

	return;
}



void connectBasicBlock(struct BasicBlock *Parent, struct BasicBlock *Child) {

	struct BasicBlockList *ptr;

	if (Parent->Succs == NULL) {
		Parent->Succs = (struct BasicBlockList*)malloc(sizeof(struct BasicBlockList));
		memset(Parent->Succs, 0, sizeof(struct BasicBlockList));
		Parent->Succs->node = Child;
	}
	else {
		ptr = Parent->Succs;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = (struct BasicBlockList*)malloc(sizeof(struct BasicBlockList));
		memset(ptr->next, 0, sizeof(struct BasicBlockList));
		ptr = ptr->next;
		ptr->node = Child;
	}




	if (Child->Preds == NULL) {
		Child->Preds = (struct BasicBlockList*)malloc(sizeof(struct BasicBlockList*));
		memset(Child->Preds, 0, sizeof(struct BasicBlockList));
		Child->Preds->node = Parent;
	}
	else {
		ptr = Child->Preds;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = (struct BasicBlockList*)malloc(sizeof(struct BasicBlockList*));
		memset(ptr->next, 0, sizeof(struct BasicBlockList));
		ptr = ptr->next;
		ptr->node = Parent;
	}

	return;
}


void printBasicBlock(struct BasicBlock *Block) {

	struct BasicBlockList *ptr = NULL;

	fprintf(fout, "B%d\n{\n", Block->Number);
	printStmtList(Block->Stmt);
	fprintf(fout, "}\n");

	fprintf(fout, "Predecessor : ");
	if (Block->start == 1) {
		fprintf(fout, "start\n");
	}
	else {
		ptr = Block->Preds;
		while (ptr != NULL) {
			fprintf(fout, "B%d", ptr->node->Number);
			if (ptr->next != NULL)
				fprintf(fout, ", ");
			ptr = ptr->next;
		}
		fprintf(fout, "\n");
	}

	fprintf(fout, "Successor : ");
	if (Block->end == 1) {
		fprintf(fout, "end\n");
	}
	else {
		ptr = Block->Succs;
		while (ptr != NULL) {
			fprintf(fout, "B%d", ptr->node->Number);
			if (ptr->next != NULL)
				fprintf(fout, ", ");
			ptr = ptr->next;
		}
		fprintf(fout, "\n");
	}
	fprintf(fout, "\n");




	Block->visited = 2;
	if (Block->Succs) {
		ptr = Block->Succs;
		while (ptr != NULL) {
			if (ptr->node->visited == 1) {
				printBasicBlock(ptr->node);
			}
			ptr = ptr->next;
		}
	}

	return;
}


void adjustReturn(struct BasicBlock *Block, struct BasicBlock *last) {
	struct Stmt *Stmtptr;
	struct BasicBlockList *Listptr;

	if (Block != NULL) {
		Stmtptr = Block->Stmt;
		while (Stmtptr != NULL) {
			if ((Stmtptr->e) == eRet) {
				Listptr = Block->Succs;

				while (Listptr != NULL) {
					if ((Listptr->node) == last) {
						Block->visited = 1;
						return;
					}
					Listptr = Listptr->next;
				}

				Listptr = Block->Succs;
				if (Listptr != NULL) {
					while (Listptr->next != NULL) {
						Listptr = Listptr->next;
					}
				}
				if (last != Block) {
					Listptr->next = (struct BasicBlockList*)malloc(sizeof(struct BasicBlockList));
					Listptr = Listptr->next;
					Listptr->node = last;
				}

			}
			Stmtptr = Stmtptr->prev;
		}


		Block->visited = 1;
		if (Block->Succs) {
			Listptr = Block->Succs;
			while (Listptr != NULL) {
				if (Listptr->node->visited == 0) {
					adjustReturn(Listptr->node, last);
				}
				Listptr = Listptr->next;
			}
		}

	}
}

