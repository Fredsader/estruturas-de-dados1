#ifndef PILHAINT_H
#define PILHAINT_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define MAX 30

typedef struct aluno{
		int matricula; 	
	}Aluno;

typedef	struct pilha{
		int cont;
		struct aluno dados[MAX];	
	}Pilha;

Pilha* createStack(void);
bool pushStack(Pilha* stack, Aluno al);
bool popstack(Pilha* stack);
int stackTop(Pilha* stack, struct aluno *al);
bool emptystack(Pilha* stack);
bool fullstack(Pilha* stack);
int stackcount(Pilha* stack);
void* destroyStack(Pilha* stack);

#endif
