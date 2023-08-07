#include <stdlib.h>
#include <stdio.h>
#include "pilhaInt.h"
#include <locale.h>


void inverteSequencia (int* sequencia, int tamanho){
	int i;
	
	Pilha* pilha = createStack();
	for (i = 0; i < tamanho; i++){
		Aluno al;
		al.matricula = sequencia[i];
		pushStack(pilha, al);
	}
	
	printf("Sequencia:");
	while(!emptystack(pilha)){
		Aluno al;
		stackTop(pilha, &al);
		printf("%d", al.matricula);
		popstack(pilha);
	}
	destroyStack(pilha);
}


int main (){
	int sequencia [10];
	int tamanho, i;
	
	printf("Digite o tamanho da sequencia:");
	scanf("%d", &tamanho);
	
	printf("Informe a sequencia numérica:\n");
	for(i = 0; i < tamanho; i++){
		scanf("%d", &sequencia[i]);
	}
	
	inverteSequencia(sequencia, tamanho);
	
}
