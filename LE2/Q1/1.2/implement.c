#include "PilhaDint.h"

Pilha* createStack(void){
	
	Pilha* stack;  //Definição local
	
	stack = (Pilha*)malloc(sizeof(Pilha)); //Alocação dinâmica
	if (stack){
		stack->cont = 0;
		stack->node = NULL;
	}
	return stack; // Retorna a pilha
}

bool pushStack(Pilha* stack, int* dataInPtr){
	
	Aluno* newPtr; // Definição local
	
	newPtr = (Aluno*) malloc (sizeof(Aluno));
	
	if(!newPtr){
		return false;	
	}
	
	newPtr->dataPtr = dataInPtr;  //Recebe o dado passado na função e insere no dado do nó
	newPtr->link = stack->node;   //Recebe  o ponteiro para o topo da pilha
	stack->node = newPtr;		  //Atualiza o topo da pilha com o novo nó 
	
	(stack->cont)++;	//Aumenta o contador da pilha
	return true;
}

int* popstack (Pilha* stack){
	
	int* dataOutPtr;	//Ponteiro genérico (ao dado que será removido)
	Aluno* temp;	//Ponteiro a um nó
	
	if (stack->cont == 0){
		dataOutPtr = NULL;
	}else{
		temp = stack->node; //Recebe o ponteiro ao primeiro nó
		dataOutPtr = stack->node->dataPtr; //Recebe o dado do nó no topo
		stack->node = stack->node->link; //Recebe como topo o nó seguinte
		free (temp);
		(stack->cont)--;
	}
	return dataOutPtr; //Retorna ponteiro ao dado removido
}

int* stackTop (Pilha *stack){ 	//Retorna ponteiro genérico
	
	if(stack->cont == 0){
		return NULL;
	}else{
		return stack->node->dataPtr;    //Retorna um ponteiro para o ponteiro do dado do nó
	}
}

bool emptystack (Pilha* stack){
	return(stack->cont == 0);	//Retorna false ou true
}

bool fullstack (Pilha* stack){
	
	Aluno* temp;
	
	if ((temp = (Aluno*)malloc(sizeof(*(stack->node))))){ //Se a tentativa de alocação funcionar
		free (temp);
		return false;
	}
	
	return true;
 }
 
 int stackcount (Pilha* stack){
	return stack->cont;
}

Pilha* destroyStack (Pilha* stack){
	
	Aluno* temp;
	
	if (stack){
		
		while (stack->node != NULL){  //Enquanto tiver algum nó no pilha
			free(stack->node->dataPtr);	//Liberar o ponteiro ao dado
			
			temp = stack->node; //Guarda o nó do topo para liberar depois
			stack->node = stack->node->link;  //Aponta para o sucessor do que ja está salvo
			free(temp);  //Libera o antigo topo
			
		}
		free(stack);  //destrói o cabeçalho
	}
	return NULL;
}

