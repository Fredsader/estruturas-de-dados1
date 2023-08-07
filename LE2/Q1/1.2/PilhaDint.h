#ifndef PILHADINT_H
#define PILHADINT_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


typedef struct aluno{
		int* dataPtr;
		struct aluno *link;	
	}Aluno;

typedef	struct pilha{
		int cont; 
		Aluno *node;	
	}Pilha;	

Pilha* createStack(void);
bool pushStack(Pilha* stack, int* DataInPtr);
int* popstack(Pilha* stack);
int* stackTop(Pilha* stack);
bool emptystack(Pilha* stack);
bool fullstack(Pilha* stack);
int stackcount(Pilha* stack);
Pilha* destroyStack(Pilha* stack);

#endif
