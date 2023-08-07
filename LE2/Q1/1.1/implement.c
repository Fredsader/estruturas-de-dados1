#include "pilhaInt.h"

Pilha* createStack(void){
	
	Pilha* stack;  //Definição local
	
	stack = (Pilha*)malloc(sizeof(Pilha)); //Alocação dinâmica
	if (stack){
		stack->cont = 0;
	}
	return stack; // Retorna a pilha
}

bool pushStack(Pilha* stack, struct aluno al){

	if(!stack){
		return false;	
	}
	if (stack->cont == MAX){
		return false;
	}
	stack->dados[stack->cont] = al;
	stack->cont++;	//Aumenta o contador da pilha
	return true;
}

bool popstack (Pilha* stack){
	if(stack == NULL || stack->cont == 0){
		return false;
	}
	stack->cont--;
	return 1;
}

int stackTop (Pilha *stack, struct aluno *al){ 	//Retorna ponteiro genérico
	
	if(stack->cont == 0 || stack == NULL){
		return 0;
	}
	*al = stack->dados[stack->cont-1];    //Retorna um ponteiro para o ponteiro do dado do nó
	return 1;
}

bool emptystack (Pilha* stack){
	return(stack->cont == 0);	//Retorna false ou true
}

bool fullstack (Pilha* stack){
	return (stack->cont == MAX);
 }
 
 int stackcount (Pilha* stack){
	return stack->cont;
}

void* destroyStack (Pilha* stack){
	free(stack);
}

