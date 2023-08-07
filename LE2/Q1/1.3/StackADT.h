#ifndef STACKADT_
#define STACKADT_

#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <stdbool.h>


typedef struct node stack_node;
typedef struct head stack_head;

stack_head* createStack(void);
bool pushStack(stack_head* stack, void* dataInPtr);
void* popstack(stack_head* stack);
void* stackTop(stack_head* stack);
bool emptystack(stack_head* stack);
bool fullstack(stack_head* stack);
int stackcount(stack_head* stack);
stack_head* destroyStack(stack_head* stack);

#endif
