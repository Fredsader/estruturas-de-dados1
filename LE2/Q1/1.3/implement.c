#include "StackADT.h"

	struct node{
		void* dataPtr;
		struct node *link;	
	};

	struct head{
		int cont; 
		stack_node *node;	
	};	

stack_head* createStack(void){
	
	stack_head* stack;  //Defini��o local
	
	stack = (stack_head*)malloc(sizeof(stack_head)); //Aloca��o din�mica
	if (stack){
		stack->cont = 0;
		stack->node = NULL;
	}
	return stack; // Retorna a pilha
}

bool pushStack(stack_head* stack, void* dataInPtr){
	
	stack_node* newPtr; // Defini��o local
	
	newPtr = (stack_node*) malloc (sizeof(stack_node));
	
	if(!newPtr){
		return false;	
	}
	
	newPtr->dataPtr = dataInPtr;  //Recebe o dado passado na fun��o e insere no dado do n�
	newPtr->link = stack->node;   //Recebe  o ponteiro para o topo da pilha
	stack->node = newPtr;		  //Atualiza o topo da pilha com o novo n� 
	
	(stack->cont)++;	//Aumenta o contador da pilha
	return true;
}

void* popstack (stack_head *stack){
	
	void* dataOutPtr;	//Ponteiro gen�rico (ao dado que ser� removido)
	stack_node* temp;	//Ponteiro a um n�
	
	if (stack->cont == 0){
		dataOutPtr = NULL;
	}else{
		temp = stack->node; //Recebe o ponteiro ao primeiro n�
		dataOutPtr = stack->node->dataPtr; //Recebe o dado do n� no topo
		stack->node = stack->node->link; //Recebe como topo o n� seguinte
		free (temp);
		(stack->cont)++;
	}
	return dataOutPtr; //Retorna ponteiro ao dado removido
}

void* stackTop (stack_head *stack){ 	//Retorna ponteiro gen�rico
	
	if(stack->cont == 0){
		return NULL;
	}else{
		return stack->node->dataPtr;    //Retorna um ponteiro para o ponteiro do dado do n�
	}
}

bool emptystack (stack_head* stack){
	return(stack->cont == 0);	//Retorna false ou true
}

bool fullstack (stack_head* stack){
	
	stack_node* temp;
	
	if ((temp = (stack_node*)malloc(sizeof(*(stack->node))))){ //Se a tentativa de aloca��o funcionar
		free (temp);
		return false;
	}
	
	return true;
 }
 
 int stackcount (stack_head* stack){
	return stack->cont;
}

stack_head* destroyStack (stack_head* stack){
	
	stack_node* temp;
	
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
