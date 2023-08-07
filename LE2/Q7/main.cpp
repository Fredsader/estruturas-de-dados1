#include "listaDup.h"

void imprimeListaForward(lista* li);
void imprimeListaBackward(lista* li);


int main() {
    lista* li = criaLista();

    insereListaOrdenada(li, "New York", 21199865);
    insereListaOrdenada(li, "Atlanta area", 4112198);
    insereListaOrdenada(li, "Los Angeles area", 16373645);
    insereListaOrdenada(li, "Miami-Fort Lauderdale", 3876380);
    insereListaOrdenada(li, "Chicago area", 9157540);
    insereListaOrdenada(li, "Seattle area", 3554760);
    insereListaOrdenada(li, "Washington-Baltimore", 7608070);
    insereListaOrdenada(li, "Phoenix area", 3251876);
    insereListaOrdenada(li, "San Francisco area", 7039362);
    insereListaOrdenada(li, "Minneapolis-St Paul", 2968806);
    insereListaOrdenada(li, "Philadelphia-Atlantic City area", 6188463);
    insereListaOrdenada(li, "Cleveland area", 2945833);
    insereListaOrdenada(li, "Boston area", 5819100);
    insereListaOrdenada(li, "San Diego area", 2813833);
    insereListaOrdenada(li, "Detroit area", 5456428);
    insereListaOrdenada(li, "St Louis area", 2603607);
    insereListaOrdenada(li, "Dallas-Fort Worth", 5221800);
    insereListaOrdenada(li, "Denver area", 2581506);
    insereListaOrdenada(li, "Houston-Galveston area", 4669570);
    insereListaOrdenada(li, "San Juan, PR, area", 2450292);

    imprimeListaForward(li);
    imprimeListaBackward(li);

    liberaLista(li);

    return 0;
}

void imprimeListaForward(lista* li) {
    if (!li || listaVazia(li)) {
        printf("Lista vazia.\n");
        return;
    }

    node* atual = li->ini;

    printf("Sequencia (forward):\n");
    while (atual != NULL) {
        printf("%s - %d\n", atual->cidade, atual->populacao);
        atual = atual->next;
    }
    printf("\n");
}

void imprimeListaBackward(lista* li) {
    if (!li || listaVazia(li)) {
        printf("Lista vazia.\n");
        return;
    }

    node* atual = li->fim;

    printf("Sequencia (backward):\n");
    while (atual != NULL) {
        printf("%s - %d\n", atual->cidade, atual->populacao);
        atual = atual->prev;
    }
    printf("\n");
}
