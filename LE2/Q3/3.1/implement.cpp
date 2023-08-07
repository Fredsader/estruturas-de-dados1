#include "FilaEsInt.h"

queue* createQueue(){
	queue* fila;
	
	fila = (queue*)malloc(sizeof(queue));
	if(fila){
		fila->rear = 0;
		fila->front = 0;
	}
	return fila;
}

bool enqueue(queue* fila, int dado){
	if (!fila){
		return false;
	}
	if (fila->rear == MAX){
		return false;
	}
	fila->dados[fila->rear] = dado;
	fila->rear++;
	return true;
}

int dequeue (queue* fila){
	if(!fila){
		return 0;
	}
	if(fila->rear == fila->front ){
		return 0;
	}
	int frontValue = fila->dados[fila->front];
	fila->front++;
	return frontValue;
}

int queueFront(queue* fila) {
    if (!fila) {
        return 0;
    }
    if (fila->front == fila->rear) {
        return 0;
    }
    return fila->dados[fila->front];
}

int queueRear(queue* fila) {
    if (!fila) {
        return 0;
    }
    if (fila->front == fila->rear) {
        return 0;
    }
    return fila->dados[fila->rear-1];
}

int queueCount (queue* fila){
	return (fila->rear-1);
}

bool queueEmpty(queue* fila){
	if (fila->rear == fila->front){
		return true;
	}else{
		return false;
	}
}

bool queueFull(queue* fila){
	if (fila->rear == MAX){
		return true;
	}
	return false;
}

void destroyQueue (queue* fila){
	free (fila);
}
