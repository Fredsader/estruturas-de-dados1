#ifndef LISTADUP_H_INCLUDED
#define LISTADUP_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node {
    char cidade[50];
    int populacao;
    struct node* next;
    struct node* prev;
} node;

typedef struct lista {
    node* ini;
    node* fim;
    int cont;
} lista;

lista* criaLista();
bool insereListaInicio(lista* li, const char* cidade, int populacao);
bool insereListaFinal(lista* li, const char* cidade, int populacao);
bool insereListaOrdenada(lista* li, const char* cidade, int populacao);
node* removeListaInicio(lista* li);
node* removeListaFinal(lista* li);
node* removeLista(lista* li, const char* cidade);
int tamanhoLista(lista* li);
bool listaCheia(lista* li);
bool listaVazia(lista* li);
node* buscaListaDado(lista* li, const char* cidade);
node* buscaListaPos(lista* li, int pos);
void liberaLista(lista* li);

#endif

