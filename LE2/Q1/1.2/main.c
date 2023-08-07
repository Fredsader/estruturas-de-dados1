#include <stdlib.h>
#include <stdio.h>
#include "PilhaDint.h"
#include <locale.h>


void inverteSequencia (int* sequencia, int tamanho){
	int i;
	
	Pilha* pilha = createStack();
	for (i = 0; i < tamanho; i++){
		pushStack(pilha, &sequencia[i]);
	}
	
	printf("Sequencia:");
	while(!emptystack(pilha)){
		int* p;
		p = stackTop(pilha);
		printf("%d", *p);
		popstack(pilha);
	}
	destroyStack(pilha);
}


int main (){
	int sequencia[10];
	int tamanho, i;
	
	printf("Digite o tamanho da sequencia:");
	scanf("%d", &tamanho);
	
	printf("Informe a sequencia numérica:\n");
	for(i = 0; i < tamanho; i++){
		scanf("%d", &sequencia[i]);
	}
	
	inverteSequencia(sequencia, tamanho);
	
}

