#include "ListaDint.h"

void imprimeSequencia(int* sequencia, int tamanho) {
    int i;

    lista* li = criaLista();
    for (i = 0; i < tamanho; i++) {
        insereListaOrdenada (li, &sequencia[i]);
    }

    printf("Sequencia: ");
    while (!listaVazia(li)) {
        int* p;
		p = removeListaInicio(li);
        printf("%d ", *p);
    }
    liberaLista(li);
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

