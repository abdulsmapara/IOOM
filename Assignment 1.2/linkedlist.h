#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED
#include "util.h"

typedef struct NodeTag Node;

Node* MakeNode(nodeData data);
void push_back(Node** head,Node** tail,Node* element);
nodeData pop_front(Node** head,Node** tail);
#endif