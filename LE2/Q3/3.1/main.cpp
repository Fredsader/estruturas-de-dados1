#include <stdio.h>
#include <stdlib.h>
#include "FilaEsInt.h"

void imprimeSequencia(int *sequencia, int tamanho) {
    int i;

    queue* fila = createQueue();

    for (i = 0; i < tamanho; i++) {
        enqueue(fila, sequencia[i]);
    }

    printf("Sequencia: ");
    while (!queueEmpty(fila)) {
        int numero = dequeue(fila);
        printf("%d ", numero);
    }

    printf("\n");
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

