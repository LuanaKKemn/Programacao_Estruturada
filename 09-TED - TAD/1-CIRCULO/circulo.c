#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "circulo.h"

// TADS //

// PONTO (x,y) // // ✔
typedef struct ponto {
  float x;
  float y;
}Ponto; 


// CIRCULO --> DEFINIÇÃO DO TIPO CIRCULO //
typedef struct circulo {
  Ponto ponto;
  float raio;
}Circulo;

//---------------------------------------------------------------//


// ALLOCAÇÕES DINAMICAS //

// CRIA UM PONTEIRO PARA PONTO E ALOCA DINAMICAMENTE // // ✔
Ponto* criarPonto(float x, float y){
  Ponto * p = (Ponto*) malloc (sizeof(Ponto));
  if (p == NULL){
    printf("Espaço insuficiente.");
    exit(1);
  }
  p -> x = x;
  p -> y = y;
  return p;
}

// CRIAR PONTEIRO PARA CIRCULO E ALOCAR DINAMICAMENTE //
Circulo* criarCirculo(Ponto *p, float r){
  Circulo * c = (Circulo*) malloc (sizeof(Circulo));
  if (c == NULL){
    printf("Espaço Insuficiente.\n");
    exit(1);
  }
  c -> ponto = *p; // SEMPRE UTILIZAR PONTEIROS //
  c -> raio = r;
  return c;
}


// ------------------------------------------------------------//

// FUNÇÕES //

float areaCir(Circulo* c){
  float area = M_PI * (c->raio)*(c->raio);
  return area;
}


int interior(Circulo* c, Ponto* p, float x1, float y1){
  if ( (x1 > (p->x)+(c->raio)) || (y1 > (p->y)+(c->raio)) || (x1 < (p->x)-(c->raio)) || (y1 < (p->y)-(c->raio)) ){
    return 0; // FALSO --> NÃO ESTÁ NO INTERIOR DO CIRCULO
  }
  return 1; // VERDADEIRO --> O PONTO ESTA NO CIRCULO
}



//-------------------------------------------------------------//

// LIBERAÇÕES //
// ✔
void liberacao_Ponto(Ponto *p){
  free(p);
}

void liberacao_Circulo(Circulo *c){
  free(c);
}


