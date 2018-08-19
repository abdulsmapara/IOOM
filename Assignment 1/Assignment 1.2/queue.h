#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include "util.h"
#include "linkedlist.h"
typedef struct queueds QueueDS;

QueueDS* InitializeQueue(QueueDS* qptr);
boolean emptyQueue(QueueDS* qptr);
boolean fullQueue(QueueDS* qptr);
status push(QueueDS* qptr,nodeData element);
status pop(QueueDS* qptr,nodeData* ret);
int num_nodes(QueueDS* qptr);
#endif