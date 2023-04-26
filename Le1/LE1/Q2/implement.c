#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "cilindros.h"


struct cilindro { // Definição da estrutura do cilindro
	float x, y, z, r, h;
};

	
	Cilindro* cilindro_cria(float x, float y, float z, float r, float h){
		Cilindro* c = (Cilindro*) malloc (sizeof(Cilindro));
		if (c != NULL){
			c->h = h;
			c->x = x;
			c->y = y;
			c->z = z;
			c->r = r;
		}
		return c;
	}
	
	void cilindro_libera(Cilindro* c){
		free(c);
	}
	
	void cilindro_dados (Cilindro *c, float x, float y, float z, float r, float h){
		printf("Nova posição do cilindro:");
		scanf("%f %f %f", &x, &y, &z);
		printf("Novo raio do cilindro:");
		scanf("%f", &r);
		printf("Nova altura do cilindro:");
		scanf("%f", &h);
		
		c->x = x;
		c->y = y;
		c->z = z;
    	c->r = r;
    	c->h = h;
	}
	
	float cilindro_area (Cilindro* c){
		float area = 2*3.14*c->r*(c->r+c->h);
		return area;
	}
	
	float cilindro_volume (Cilindro* c){
		float volume = 3.14* pow(c->r, 2)*c->h;
		return volume;
	}
	

