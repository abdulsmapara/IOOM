#ifndef STDBST_H_INCLUDED
#define STDBST_H_INCLUDED
#include "util.h"
bstNode* initializeBST(bstNode* root);
bstNode* makeNode(itemType data);
bstNode* insertNode(bstNode* root,bstNode* element);
bstNode* deleteNode(bstNode* root,itemType key);
void printCousins(bstNode* root,itemType node);
void traverse(bstNode* root);
int sum_at_max_level(bstNode* root);
#endif