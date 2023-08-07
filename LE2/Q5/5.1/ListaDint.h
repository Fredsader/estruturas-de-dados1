#ifndef LISTADINT_H_INCLUDED
#define LISTADINT_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
	int* dataPtr;
	struct node* next;
}node;

typedef struct lista{
	node* ini;
	node* fim;
	int cont;
}lista;

lista* criaLista();

bool insereListaInicio (lista* li, int* dado);
bool insereListaFinal (lista* li, int* dado);
bool insereListaOrdenada (lista* li, int* dado);
int* removeListaInicio (lista* li);
int* removeListaFinal (lista* li);
int* removeLista (lista* li, int* dado);
int tamanhoLista (lista* li);
bool listaCheia (lista* li);
bool listaVazia (lista* li);
int* buscaListaDado (lista* li, int dado);
int* buscaListaPos (lista* li, int pos);

void liberaLista(lista* li);
#endif
