#include <stdlib.h>
#include <stdio.h>

// Algoritmo recursivo para calcular o n-ésimo número de Fibonacci
int fibonacci_recursivo(long long int n){
    if (n <= 1) {
        return n;
    } else {
        return fibonacci_recursivo(n-1) + fibonacci_recursivo(n-2);
    }
}

int main (){
	long long int n = 5, b;
	
	
	b = fibonacci_recursivo (n);
	printf("\nn-esimo numero de fibonacci (recursivo): %d", b);
	
}
