#include <stdlib.h>
#include <stdio.h>
#include "FilaDint.h"
#include <locale.h>

void imprimeSequencia(int* sequencia, int tamanho) {
    int i;

    QUEUE_H* fila = createQueue();
    for (i = 0; i < tamanho; i++) {
        enqueue(fila, (int**)&sequencia[i]);
    }

    printf("Sequencia: ");
    while (!emptyQueue(fila)) {
        int* p;
		dequeue(fila, &p);
        printf("%d ", p);
    }
    destroyQueue(fila);
}

int main() {
    int sequencia[10];
    int tamanho, i;

    printf("Digite o tamanho da sequencia: ");
    scanf("%d", &tamanho);

    printf("Informe a sequencia numérica:\n");
    for (i = 0; i < tamanho; i++) {
        scanf("%d", &sequencia[i]);
    }

    imprimeSequencia(sequencia, tamanho);

    return 0;
}


