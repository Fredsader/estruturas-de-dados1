#include <stdlib.h>
#include <stdio.h>

// Algoritmo iterativo para calcular o n-ésimo número de Fibonacci
int fibonacci_iterativo(long long int n){
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
	long long int n = 5, b;
	
	b = fibonacci_iterativo (n);
	printf("\nn-esimo numero de fibonacci (iterativo): %d", b);
	
	
}
