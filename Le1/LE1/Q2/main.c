#include <stdlib.h>
#include <stdio.h>
#include "cilindros.h"
#include <locale.h>

int main(){
	setlocale (LC_ALL, "Portuguese");
	

	float x, y, z;
	float r, h, a1, v1, a2, v2;
	Cilindro *c1, *c2;
	
	printf("Digite a posição do cilindro 1 (x,y,z):");
	scanf( "%f%f%f", &x, &y, &z);
	printf("Digite o raio do cilindro 1:");
	scanf("%f", &r);
	printf("Digite a altura do cilindro 1:");
	scanf("%f", &h);
	
	c1 = cilindro_cria(x, y, z, r, h);
	a1 = cilindro_area (c1);
	v1 = cilindro_volume (c1);
	
	printf("\n");
	printf("Digite a posição do cilindro 2:");
	scanf( "%f%f%f", &x, &y, &z);
	printf("Digite o raio do cilindro 2:");
	scanf("%f", &r);
	printf("Digite a altura do cilindro 2:");
	scanf("%f", &h);
	
	c2 = cilindro_cria(x, y, z, r, h);
	a2 = cilindro_area (c2);
	v2 = cilindro_volume (c2);
	
	printf("\nArea do cilindro 1: %.2f", a1);
	printf("\nVolume do cilindro 1: %.2f", v1);
	printf("\n");
	printf("\nArea do cilindro 2: %.2f", a2);
	printf("\nVolume do cilindro 2: %.2f", v2);
	printf("\n");
	printf("\n");
	
	cilindro_dados (c1, x, y ,z, r, h);
	printf("\n");
	cilindro_dados (c2, x, y, z, r, h);
	
	a1 = cilindro_area (c1);
	v1 = cilindro_volume (c1);
	
	a2 = cilindro_area (c2);
	v2 = cilindro_volume (c2);
	
	printf("\nArea do cilindro 1: %.2f", a1);
	printf("\nVolume do cilindro 1: %.2f", v1);
	printf("\n");
	printf("\nArea do cilindro 2: %.2f", a2);
	printf("\nVolume do cilindro 2: %.2f", v2);
	printf("\n");
	printf("\n");
	
	cilindro_libera (c1);
	cilindro_libera (c2);
}


