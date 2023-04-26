#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Algoritmo recursivo para calcular o n-ésimo número de Fibonacci
int fibonacci_recursivo(long long int n){
    if (n <= 1) {
        return n;
    } else {
        return fibonacci_recursivo(n-1) + fibonacci_recursivo(n-2);
    }
}

int main (){
	long long int n = 50, b;
	
	clock_t antes = clock();
	b = fibonacci_recursivo (n);
	clock_t depois = clock();
	
	printf("\nn-esimo numero de fibonacci (recursivo): %d", b);
	
	double tempo = (double)(depois - antes) / CLOCKS_PER_SEC;
	printf("Tempo de ordenação: %f", tempo);
	
}
