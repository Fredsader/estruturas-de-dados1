#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include <locale.h>

void imprimeSequencia(float* sequencia, int tamanho) {
    int i;

    QUEUE_H* fila = createQueue();
    for (i = 0; i < tamanho; i++) {
        enqueue(fila, (void**)&sequencia[i]);
    }

    printf("Sequencia: ");
    while (!emptyQueue(fila)) {
        float* p;
		dequeue(fila,(void**)&p);
        printf("%f ", *p);
    }
    destroyQueue(fila);
}

int main() {
    float sequencia[10];
    int tamanho, i;

    printf("Digite o tamanho da sequencia: ");
    scanf("%d", &tamanho);

    printf("Informe a sequencia numérica:\n");
    for (i = 0; i < tamanho; i++) {
        scanf("%f", &sequencia[i]);
    }

    imprimeSequencia(sequencia, tamanho);

    return 0;
}

