#include <stdlib.h>
#include <stdio.h>
#include "StackADT.h"
#include <locale.h>

void inverteSequencia(float* sequencia, int tamanho) {
    int i;

    stack_head* pilha = createStack();
    for (i = 0; i < tamanho; i++) {
        pushStack(pilha, (void*)&sequencia[i]);
    }

    printf("Sequencia: ");
    while (!emptystack(pilha)) {
        float* p = (float*)stackTop(pilha);
        printf("%.2f ", *p);
        popstack(pilha);
    }
    destroyStack(pilha);
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

    inverteSequencia(sequencia, tamanho);

    return 0;
}

