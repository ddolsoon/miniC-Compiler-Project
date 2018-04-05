#ifndef CFG
#define CFG 
#include "ast.h"

typedef enum
{
	CFG_eAssign = 1, CFG_eCondition_i, CFG_eCondition_w, CFG_eCondition_f, CFG_eWhile, CFG_eIf
} CFG_Block;

struct BasicBlock
{
	CFG_Block type;

	int Number;
	int start;
	int end;
	int visited;

	struct Stmt *Stmt;

	struct BasicBlockList *Preds;
	struct BasicBlockList *Succs;

	struct BasicBlock *prev;
	struct BasicBlock *next;
};


struct BasicBlockList
{
	struct BasicBlock *node;
	struct BasicBlockList *next;
};


void printCFG(struct Program *head);
struct BasicBlock* makeBasicBlock(struct MainFunc * mainFunc);
struct BasicBlock* CFGCompoundStmt(struct CompoundStmt *CompoundStmt);
struct BasicBlock* CFGStmtList(struct Stmt * Stmt, struct BasicBlock *PrevNode);

void addBasicBlock(struct BasicBlock *CFGStmt, struct Stmt *Stmt);
void connectBasicBlock(struct BasicBlock *Parent, struct BasicBlock *Child);
void printBasicBlock(struct BasicBlock *CFG);
void adjustReturn(struct BasicBlock *Block, struct BasicBlock *last);


#endif


