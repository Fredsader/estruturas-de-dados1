#include "ListaDint.h"

lista* criaLista(){
	lista* li;
	
	li = (lista*)malloc(sizeof(lista));
	if(li){
		li->fim = NULL;
		li->ini = NULL;
		li->cont = 0;
	}
	return li;
}

bool insereListaInicio (lista* li, int* dado){
	if (!li){
		return false;
	}
	
	node* novoNode = (node*) malloc (sizeof(node));
	if (!novoNode){
		return false;
	}
	
	novoNode->dataPtr = dado;
	novoNode->next = li->ini;
	
	li->ini = novoNode;
	li->cont++;
	
	return true;
}

bool insereListaFinal (lista* li, int* dado){
	if (!li){
		return false;
	}
	
	node* novoNode = (node*) malloc (sizeof(node));
	if (!novoNode){
		return false;
	}
	
	novoNode->dataPtr = dado;
	novoNode->next = NULL;
	
	if (li->ini == NULL){
		li->ini = novoNode;
		li->fim = novoNode;
	}else{
		li->fim->next = novoNode;
		li->fim = novoNode;
	}
	
	li->cont++;
	
	return true;
}

bool insereListaOrdenada(lista* li, int* dado) {
	if (!li) {
		return false;
	}

	node* novoNode = (node*)malloc(sizeof(node));
	if (!novoNode) {
		return false;
	}

	novoNode->dataPtr = dado;

	if (li->ini == NULL || *(li->ini->dataPtr) >= *dado) {
		novoNode->next = li->ini;
		li->ini = novoNode;
	} else {
		node* atual = li->ini;
		node* ant = NULL;

		while (atual != NULL && *(atual->dataPtr) < *dado) {
			ant = atual;
			atual = atual->next;
		}

		if (ant == NULL) {
			novoNode->next = li->ini;
			li->ini = novoNode;
		} else {
			novoNode->next = atual;
			ant->next = novoNode;
		 }

	}

	li->cont++;

	return true;
}


int* removeListaInicio (lista* li){
	if (!li){
		return NULL;
	}
	if(li->ini == NULL){
		return NULL;
	}
	
	int* dado = li->ini->dataPtr;
	node* temp = li->ini;

	li->ini = li->ini->next;
	
	if(li->ini == NULL){
		li->fim = NULL;
	}
	
	free(temp);
	li->cont--;
	
	return dado;
}

int* removeListaFinal (lista* li){
	if(!li || !li->ini){
		return NULL;
	}
	
	int* dado;
	node* atual = li->ini;
	node* ant = NULL;
	
	while (atual->next != NULL){
		ant = atual;
		atual = atual->next;
	}
	dado = atual->dataPtr;
	
	if(ant == NULL){
		li->ini = NULL;
	} else{
		ant->next = NULL;
	}
	
	free(atual);
	li->cont--;
	
	return dado;
}

int* removeLista (lista* li, int *dado){
	if(!li || !li->ini){
		return NULL;
	}
	
	int* dado_removido;
	node* atual = li->ini;
	node* ant = NULL;
	
	while (atual != NULL && *(atual->dataPtr)!= *dado){
		ant = atual;
		atual = atual->next;
	}
	if(atual == NULL){
		return NULL;
	}
	
	dado_removido = atual->dataPtr;
	
	if(atual == li->ini){
		li->ini = atual->next;
	}else{
		ant->next = atual->next;
	}
	
	free(atual);
	return dado_removido;
}

int tamanhoLista (lista* li){
	return li->cont;
}

bool listaCheia (lista* li){
	node* novoNode;
	if(!(novoNode = (node*)malloc(sizeof(node)))){
		return true;
	}
	free(novoNode);
	return false;
}

bool listaVazia (lista* li){
	if(li->cont == 0){
		return true;
	}
	return false;
}

int* buscaListaPos (lista* li, int pos){
	if(!li || !li->ini || pos <= 0){
		return NULL;
	}
	node* novoNode = li->ini;
	int i = 1;
	
	while (novoNode != NULL && i < pos){
		novoNode = novoNode->next;
		i++;
	}
	if(novoNode == NULL){
		return NULL;
	}else{
		return novoNode->dataPtr;
	}
	
}

int* buscaListaDado (lista* li, int dado){
	if(!li || !li->ini || dado <= 0){
		return NULL;
	}
	node* novoNode = li->ini;
	int i = 1;
	
	while (novoNode != NULL && i != dado){
		novoNode = novoNode->next;
		i++;
	}
	if(novoNode == NULL){
		return NULL;
	}else{
		return novoNode->dataPtr;
	}
	
}


void liberaLista(lista* li) {
    if (li == NULL) {
        return;
    }
    
    node* atual = li->ini;
    
    while (atual != NULL) {
        node* proximo = atual->next;
        free(atual);
        atual = proximo;
    }
    
    li->ini = NULL;
    li->fim = NULL;
    li->cont = 0;
}

