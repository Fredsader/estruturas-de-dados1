#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Algoritmo iterativo para calcular o n-ésimo número de Fibonacci
int fibonacci_iterativo(unsigned long long n){
    if (n <= 1) {
        return n;
    } else {
        int a = 0, b = 1, temp, i;
        for (i = 2; i <= n; i++) {
            temp = a + b;
            a = b;
            b = temp;
        }
        return b;
    }
}

int main (){
	unsigned long long n = 50, b;
	
	clock_t antes = clock();
	b = fibonacci_iterativo (n);
	clock_t depois = clock();
	
	
	printf("\nn-esimo numero de fibonacci (iterativo): %d", b);
	
	double tempo = (double)(depois - antes) / CLOCKS_PER_SEC;
	printf("\nTempo de ordenação: %f", tempo);
}
