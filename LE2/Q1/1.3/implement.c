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
	
	stack_head* stack;  //Definição local
	
	stack = (stack_head*)malloc(sizeof(stack_head)); //Alocação dinâmica
	if (stack){
		stack->cont = 0;
		stack->node = NULL;
	}
	return stack; // Retorna a pilha
}

bool pushStack(stack_head* stack, void* dataInPtr){
	
	stack_node* newPtr; // Definição local
	
	newPtr = (stack_node*) malloc (sizeof(stack_node));
	
	if(!newPtr){
		return false;	
	}
	
	newPtr->dataPtr = dataInPtr;  //Recebe o dado passado na função e insere no dado do nó
	newPtr->link = stack->node;   //Recebe  o ponteiro para o topo da pilha
	stack->node = newPtr;		  //Atualiza o topo da pilha com o novo nó 
	
	(stack->cont)++;	//Aumenta o contador da pilha
	return true;
}

void* popstack (stack_head *stack){
	
	void* dataOutPtr;	//Ponteiro genérico (ao dado que será removido)
	stack_node* temp;	//Ponteiro a um nó
	
	if (stack->cont == 0){
		dataOutPtr = NULL;
	}else{
		temp = stack->node; //Recebe o ponteiro ao primeiro nó
		dataOutPtr = stack->node->dataPtr; //Recebe o dado do nó no topo
		stack->node = stack->node->link; //Recebe como topo o nó seguinte
		free (temp);
		(stack->cont)++;
	}
	return dataOutPtr; //Retorna ponteiro ao dado removido
}

void* stackTop (stack_head *stack){ 	//Retorna ponteiro genérico
	
	if(stack->cont == 0){
		return NULL;
	}else{
		return stack->node->dataPtr;    //Retorna um ponteiro para o ponteiro do dado do nó
	}
}

bool emptystack (stack_head* stack){
	return(stack->cont == 0);	//Retorna false ou true
}

bool fullstack (stack_head* stack){
	
	stack_node* temp;
	
	if ((temp = (stack_node*)malloc(sizeof(*(stack->node))))){ //Se a tentativa de alocação funcionar
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
