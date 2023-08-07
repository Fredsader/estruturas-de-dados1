#include "PilhaDint.h"

Pilha* createStack(void){
	
	Pilha* stack;  //Defini��o local
	
	stack = (Pilha*)malloc(sizeof(Pilha)); //Aloca��o din�mica
	if (stack){
		stack->cont = 0;
		stack->node = NULL;
	}
	return stack; // Retorna a pilha
}

bool pushStack(Pilha* stack, int* dataInPtr){
	
	Aluno* newPtr; // Defini��o local
	
	newPtr = (Aluno*) malloc (sizeof(Aluno));
	
	if(!newPtr){
		return false;	
	}
	
	newPtr->dataPtr = dataInPtr;  //Recebe o dado passado na fun��o e insere no dado do n�
	newPtr->link = stack->node;   //Recebe  o ponteiro para o topo da pilha
	stack->node = newPtr;		  //Atualiza o topo da pilha com o novo n� 
	
	(stack->cont)++;	//Aumenta o contador da pilha
	return true;
}

int* popstack (Pilha* stack){
	
	int* dataOutPtr;	//Ponteiro gen�rico (ao dado que ser� removido)
	Aluno* temp;	//Ponteiro a um n�
	
	if (stack->cont == 0){
		dataOutPtr = NULL;
	}else{
		temp = stack->node; //Recebe o ponteiro ao primeiro n�
		dataOutPtr = stack->node->dataPtr; //Recebe o dado do n� no topo
		stack->node = stack->node->link; //Recebe como topo o n� seguinte
		free (temp);
		(stack->cont)--;
	}
	return dataOutPtr; //Retorna ponteiro ao dado removido
}

int* stackTop (Pilha *stack){ 	//Retorna ponteiro gen�rico
	
	if(stack->cont == 0){
		return NULL;
	}else{
		return stack->node->dataPtr;    //Retorna um ponteiro para o ponteiro do dado do n�
	}
}

bool emptystack (Pilha* stack){
	return(stack->cont == 0);	//Retorna false ou true
}

bool fullstack (Pilha* stack){
	
	Aluno* temp;
	
	if ((temp = (Aluno*)malloc(sizeof(*(stack->node))))){ //Se a tentativa de aloca��o funcionar
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
		
		while (stack->node != NULL){  //Enquanto tiver algum n� no pilha
			free(stack->node->dataPtr);	//Liberar o ponteiro ao dado
			
			temp = stack->node; //Guarda o n� do topo para liberar depois
			stack->node = stack->node->link;  //Aponta para o sucessor do que ja est� salvo
			free(temp);  //Libera o antigo topo
			
		}
		free(stack);  //destr�i o cabe�alho
	}
	return NULL;
}

