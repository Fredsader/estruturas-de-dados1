#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "queue.h"


QUEUE_H* createQueue (void){	//Cria a fila
	QUEUE_H* queue;
	
	queue = (QUEUE_H*)malloc(sizeof(QUEUE_H));	//Aloca espaço para o cabeçalho;
	if(queue){
		queue->front = NULL;	//Ponteiro do inicio é nulo
		queue->rear = NULL;	    //Ponteiro do fim é nulo
		queue->count = 0;		//Contador é zero
	}
	return queue;
}

bool enqueue (QUEUE_H* queue, void** itemPtr){	//Insere nó na fila;
	QUEUE_NODE* newPtr;	//Declara novo nó
	
	if(!(newPtr = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE)))){	//Caso não haja espaço para alocar novo nó;
		return false;
	}
	
	newPtr->dataPtr = itemPtr;		//O ponteiro genérico de data do nó recebe o ponteiro genérico de data recebido na função;
	newPtr->next = NULL;			//O próximo nó recebe vazio;
	
	if (queue->count == 0){			//Caso não haja nó na fila;
		queue->front = newPtr;		//O nó da frente recebe o novo nó;
	}else{							//Caso tenha nó na fila;
		queue->rear->next = newPtr; //O 'próximo' do atual último ponteiro recebe o novo ponteiro;
	}
	(queue->count)++;	//Aumenta a contagem de nós na fila;
	queue->rear = newPtr;	//O fim da fila recebe esse novo nó;
	return true;
}

bool dequeue (QUEUE_H* queue, void** itemPtr){	//Retira e devolve o primeiro nó da lista;
	QUEUE_NODE* deleteLoc;
	
	if(!queue->count){
		return false;		//Retorna falso se não houve nó na fila;
	}else{
		*itemPtr = queue->front->dataPtr;		//Devolve o endereço da data do primeiro nó;
		deleteLoc = queue->front;				//Ponteiro para o primeiro nó é recebido pelo ponteiro local;
	}
	if (queue->count == 1){
		queue->rear = queue->front = NULL;		//Caso haja apenas um nó na fila, os ponteiros de incio e fim recebem vazio;
	}else{
		queue->front = queue->front->next;		//Caso tenha mais de um nó, o ponteiro para o próximo recebe o próximo que esse primeiro estava apontando;
	}	
	(queue->count)--;
	free(deleteLoc);
	
	return true;
}

bool queueFront (QUEUE_H* queue, void** itemPtr){	//Devolve o endereço do dado do inicio (sem retirar esse nó da fila);

	if(!queue->count){
		return false;	//Retorna falso se não houve nó na fila;
	}else{
		*itemPtr = queue->front->dataPtr; //Retorna o dado do ponteiro para o ponteiro para o dado do primeiro nó
		return true;
	}	
}

bool queueRear (QUEUE_H* queue, void** itemPtr){		//Devolve o endereço do dado do fim da fila;
	
	if(!queue->count){
		return false;	//Retorna falso se não houve nó na fila;
	}else{
		*itemPtr = queue->rear->dataPtr; //Retorna o dado do ponteiro para o ponteiro para o dado do último nó
		return true;
	}	
}

int queueCount(QUEUE_H* queue){		//Simplesmente devolve o número no contador;
	return queue->count;
}

bool emptyQueue (QUEUE_H* queue){	//verifica se a fila está vazia;
	return (queue->count == 0);
}

bool fullQueue (QUEUE_H* queue){	//verifica se a fila está cheia;
	QUEUE_NODE* temp;
	
	temp = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE)); //Tenta alocar memória;
	if (temp){
		free (temp);
		return false;	//Caso donsiga, libera a variável temporária e retorna falso;
	}
	return true; //Caso não consiga, retorna verdadeiro;
}

QUEUE_H* destroyQueue (QUEUE_H* queue){		//Destrói a fila;
	QUEUE_NODE* deletePtr;
	
	if(queue){		//Se ainda existir o cabeçalho
		while(queue->front != NULL){	//E enquanto o ponteiro ao primeiro da fila existir;
			free(queue->front->dataPtr);	//Libera o ponteiro pro pronteiro ao dado do primeiro nó;
			deletePtr = queue->front;		//Ponteiro temporario recebe o ponteiro ao primeiro nó;
			queue->front = queue->front->next; //Ponteiro ao primeiro nó recebe o seguinte ao primeiro;
			free(deletePtr);	//Libera o temporario
		}
		free(queue); //Libera o cabeçalho
	}
	return NULL;
}

