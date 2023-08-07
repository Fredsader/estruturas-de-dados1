#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{		//Nó da fila
	void* dataPtr;
	struct node* next;
}QUEUE_NODE;

typedef struct queue{		//Cabeçalho da fila
	QUEUE_NODE* front;
	QUEUE_NODE* rear;
	int count;
}QUEUE_H;


QUEUE_H* createQueue (void);	//Criar a fila.;
QUEUE_H* destroyQueue (QUEUE_H* queue);  //Destrói a fila;

bool dequeue (QUEUE_H* queue, void** itemPtr);		//Deleta um nó da fila;
bool enqueue (QUEUE_H* queue, void** itemPtr);		//Adiciona um nó à fila;
bool queueFront (QUEUE_H* queue, void** itemPtr); 	//Repassa o endereço do dado no inicio da fila;
bool queueRear (QUEUE_H* queue, void** itemPtr);		//Repassa o endereço do dado no fim da fila;
int queueCount (QUEUE_H* queue);		//

bool emptyQueue (QUEUE_H* queue);				//Verifica se a fila está vazia;
bool fullQueue (QUEUE_H* queue)	;				//Verifica se a fila está cheia;

#endif
