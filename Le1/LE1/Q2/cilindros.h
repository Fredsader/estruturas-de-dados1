#ifndef CILINDROS_INCLUDED
#define CILINDROS_INCLUDED
#include <math.h>

typedef struct cilindro Cilindro; // Definindo estrutura cilindro 'Cilindro'

Cilindro* cilindro_cria (float x, float y, float z, float r, float h); //Aloca espaço para um Cilindro 

void cilindro_libera (Cilindro* c); //Libera uma instância do cilindro

void cilindro_dados (Cilindro* c, float x, float y, float z, float r, float h);// Altera os dados do Cilindro

float cilindro_area (Cilindro* c); // Retorna a area do cilindro
float cilindro_volume (Cilindro* c); // Retorna o volume do cilindro

#endif


