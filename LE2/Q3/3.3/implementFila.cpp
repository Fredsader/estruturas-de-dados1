#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "queue.h"


QUEUE_H* createQueue (void){	//Cria a fila
	QUEUE_H* queue;
	
	queue = (QUEUE_H*)malloc(sizeof(QUEUE_H));	//Aloca espa�o para o cabe�alho;
	if(queue){
		queue->front = NULL;	//Ponteiro do inicio � nulo
		queue->rear = NULL;	    //Ponteiro do fim � nulo
		queue->count = 0;		//Contador � zero
	}
	return queue;
}

bool enqueue (QUEUE_H* queue, void** itemPtr){	//Insere n� na fila;
	QUEUE_NODE* newPtr;	//Declara novo n�
	
	if(!(newPtr = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE)))){	//Caso n�o haja espa�o para alocar novo n�;
		return false;
	}
	
	newPtr->dataPtr = itemPtr;		//O ponteiro gen�rico de data do n� recebe o ponteiro gen�rico de data recebido na fun��o;
	newPtr->next = NULL;			//O pr�ximo n� recebe vazio;
	
	if (queue->count == 0){			//Caso n�o haja n� na fila;
		queue->front = newPtr;		//O n� da frente recebe o novo n�;
	}else{							//Caso tenha n� na fila;
		queue->rear->next = newPtr; //O 'pr�ximo' do atual �ltimo ponteiro recebe o novo ponteiro;
	}
	(queue->count)++;	//Aumenta a contagem de n�s na fila;
	queue->rear = newPtr;	//O fim da fila recebe esse novo n�;
	return true;
}

bool dequeue (QUEUE_H* queue, void** itemPtr){	//Retira e devolve o primeiro n� da lista;
	QUEUE_NODE* deleteLoc;
	
	if(!queue->count){
		return false;		//Retorna falso se n�o houve n� na fila;
	}else{
		*itemPtr = queue->front->dataPtr;		//Devolve o endere�o da data do primeiro n�;
		deleteLoc = queue->front;				//Ponteiro para o primeiro n� � recebido pelo ponteiro local;
	}
	if (queue->count == 1){
		queue->rear = queue->front = NULL;		//Caso haja apenas um n� na fila, os ponteiros de incio e fim recebem vazio;
	}else{
		queue->front = queue->front->next;		//Caso tenha mais de um n�, o ponteiro para o pr�ximo recebe o pr�ximo que esse primeiro estava apontando;
	}	
	(queue->count)--;
	free(deleteLoc);
	
	return true;
}

bool queueFront (QUEUE_H* queue, void** itemPtr){	//Devolve o endere�o do dado do inicio (sem retirar esse n� da fila);

	if(!queue->count){
		return false;	//Retorna falso se n�o houve n� na fila;
	}else{
		*itemPtr = queue->front->dataPtr; //Retorna o dado do ponteiro para o ponteiro para o dado do primeiro n�
		return true;
	}	
}

bool queueRear (QUEUE_H* queue, void** itemPtr){		//Devolve o endere�o do dado do fim da fila;
	
	if(!queue->count){
		return false;	//Retorna falso se n�o houve n� na fila;
	}else{
		*itemPtr = queue->rear->dataPtr; //Retorna o dado do ponteiro para o ponteiro para o dado do �ltimo n�
		return true;
	}	
}

int queueCount(QUEUE_H* queue){		//Simplesmente devolve o n�mero no contador;
	return queue->count;
}

bool emptyQueue (QUEUE_H* queue){	//verifica se a fila est� vazia;
	return (queue->count == 0);
}

bool fullQueue (QUEUE_H* queue){	//verifica se a fila est� cheia;
	QUEUE_NODE* temp;
	
	temp = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE)); //Tenta alocar mem�ria;
	if (temp){
		free (temp);
		return false;	//Caso donsiga, libera a vari�vel tempor�ria e retorna falso;
	}
	return true; //Caso n�o consiga, retorna verdadeiro;
}

QUEUE_H* destroyQueue (QUEUE_H* queue){		//Destr�i a fila;
	QUEUE_NODE* deletePtr;
	
	if(queue){		//Se ainda existir o cabe�alho
		while(queue->front != NULL){	//E enquanto o ponteiro ao primeiro da fila existir;
			free(queue->front->dataPtr);	//Libera o ponteiro pro pronteiro ao dado do primeiro n�;
			deletePtr = queue->front;		//Ponteiro temporario recebe o ponteiro ao primeiro n�;
			queue->front = queue->front->next; //Ponteiro ao primeiro n� recebe o seguinte ao primeiro;
			free(deletePtr);	//Libera o temporario
		}
		free(queue); //Libera o cabe�alho
	}
	return NULL;
}

