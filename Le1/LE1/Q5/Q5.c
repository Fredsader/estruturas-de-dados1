#include <stdio.h>
#include <string.h>
#include <locale.h>

int palindromo(char str[], int inicio, int fim) {
  	if(inicio >= fim){
  		return 1;
	}
    if (str[inicio] == ' ') {
      return palindromo(str, inicio+1, fim);
    }
    if (str[fim] == ' ') {
      return palindromo(str, inicio, fim-1);
    }
    if (str[inicio] >= 'A' && str[inicio] <= 'Z') {
      str[inicio] += 32; // converte letra maiúscula para minúscula
    }
    if (str[fim] >= 'A' && str[fim] <= 'Z') {
      str[fim] += 32; // converte letra maiúscula para minúscula
    }
    if (str[inicio] != str[fim]) {
      return 0; // não é um palíndromo
    }
    return (palindromo (str, inicio + 1, fim - 1));
  }
  

int main() {
  setlocale(LC_ALL, "Portuguese");	
	
  char str[100];
  int inicio = 0;
  
  
  printf("Digite a frase: ");
  fgets(str, 100, stdin);
  
  str[strlen(str) - 1] = '\0'; // substitui o caractere '\n' por '\0'
  int fim = strlen(str) - 1;
  
  if(palindromo(str, inicio, fim)){
  	printf("\nPalindromo");
  }else{
  	printf("\nNão é palindromo");
  }
 
  return 0;
}

