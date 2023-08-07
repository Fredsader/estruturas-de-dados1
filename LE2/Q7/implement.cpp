#include "listadup.h"

lista* criaLista() {
    lista* li = (lista*)malloc(sizeof(lista));
    if (li) {
        li->ini = NULL;
        li->fim = NULL;
        li->cont = 0;
    }
    return li;
}

bool insereListaInicio(lista* li, const char* cidade, int populacao) {
    if (!li) {
        return false;
    }

    node* novoNode = (node*)malloc(sizeof(node));
    if (!novoNode) {
        return false;
    }

    strcpy(novoNode->cidade, cidade);
    novoNode->populacao = populacao;
    novoNode->next = li->ini;
    novoNode->prev = NULL;

    if (li->ini) {
        li->ini->prev = novoNode;
    } else {
        li->fim = novoNode;
    }

    li->ini = novoNode;
    li->cont++;

    return true;
}

bool insereListaFinal(lista* li, const char* cidade, int populacao) {
    if (!li) {
        return false;
    }

    node* novoNode = (node*)malloc(sizeof(node));
    if (!novoNode) {
        return false;
    }

    strcpy(novoNode->cidade, cidade);
    novoNode->populacao = populacao;
    novoNode->next = NULL;
    novoNode->prev = li->fim;

    if (li->fim) {
        li->fim->next = novoNode;
    } else {
        li->ini = novoNode;
    }

    li->fim = novoNode;
    li->cont++;

    return true;
}

bool insereListaOrdenada(lista* li, const char* cidade, int populacao) {
    if (!li) {
        return false;
    }

    node* novoNode = (node*)malloc(sizeof(node));
    if (!novoNode) {
        return false;
    }

    strcpy(novoNode->cidade, cidade);
    novoNode->populacao = populacao;
    novoNode->next = NULL;
    novoNode->prev = NULL;

    if (listaVazia(li) || populacao <= li->ini->populacao) {
        novoNode->next = li->ini;
        if (li->ini) {
            li->ini->prev = novoNode;
        } else {
            li->fim = novoNode;
        }
        li->ini = novoNode;
    } else if (populacao >= li->fim->populacao) {
        novoNode->prev = li->fim;
        li->fim->next = novoNode;
        li->fim = novoNode;
    } else {
        node* atual = li->ini->next;
        while (atual->populacao < populacao) {
            atual = atual->next;
        }

        novoNode->next = atual;
        novoNode->prev = atual->prev;
        atual->prev->next = novoNode;
        atual->prev = novoNode;
    }

    li->cont++;

    return true;
}

node* removeListaInicio(lista* li) {
    if (!li || listaVazia(li)) {
        return NULL;
    }

    node* removido = li->ini;
    li->ini = li->ini->next;

    if (li->ini) {
        li->ini->prev = NULL;
    } else {
        li->fim = NULL;
    }

    li->cont--;

    return removido;
}

node* removeListaFinal(lista* li) {
    if (!li || listaVazia(li)) {
        return NULL;
    }

    node* removido = li->fim;
    li->fim = li->fim->prev;

    if (li->fim) {
        li->fim->next = NULL;
    } else {
        li->ini = NULL;
    }

    li->cont--;

    return removido;
}

node* removeLista(lista* li, const char* cidade) {
    if (!li || listaVazia(li)) {
        return NULL;
    }

    node* atual = li->ini;
    while (atual != NULL && strcmp(atual->cidade, cidade) != 0) {
        atual = atual->next;
    }

    if (atual == NULL) {
        return NULL;
    }

    if (atual == li->ini) {
        li->ini = li->ini->next;
        if (li->ini) {
            li->ini->prev = NULL;
        } else {
            li->fim = NULL;
        }
    } else if (atual == li->fim) {
        li->fim = li->fim->prev;
        if (li->fim) {
            li->fim->next = NULL;
        } else {
            li->ini = NULL;
        }
    } else {
        atual->prev->next = atual->next;
        atual->next->prev = atual->prev;
    }

    li->cont--;

    return atual;
}

int tamanhoLista(lista* li) {
    if (!li) {
        return 0;
    }
    return li->cont;
}

bool listaCheia(lista* li) {
    return false; // Não há limite de capacidade na lista encadeada
}

bool listaVazia(lista* li) {
    if (!li || li->ini == NULL) {
        return true;
    }
    return false;
}

node* buscaListaDado(lista* li, const char* cidade) {
    if (!li || listaVazia(li)) {
        return NULL;
    }

    node* atual = li->ini;
    while (atual != NULL && strcmp(atual->cidade, cidade) != 0) {
        atual = atual->next;
    }

    return atual;
}

node* buscaListaPos(lista* li, int pos) {
    if (!li || listaVazia(li) || pos <= 0 || pos > li->cont) {
        return NULL;
    }

    node* atual = li->ini;
    int i = 1;
    while (atual != NULL && i < pos) {
        atual = atual->next;
        i++;
    }

    return atual;
}

void liberaLista(lista* li) {
    if (!li) {
        return;
    }

    node* atual = li->ini;

    while (atual != NULL) {
        node* proximo = atual->next;
        free(atual);
        atual = proximo;
    }

    free(li);
}


