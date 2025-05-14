// main.c //

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "operaVets.h"



int main(void) {
  Vetor* vetor1;
  Vetor* vetor2;
  Vetor* vetSoma;
  Vetor* vetSub;
  Vetor* vetEscalar;

  vetor1 = allocar(&vetor1);
  vetor2 = allocar(&vetor2);

  //printf("Allocado\n");

  atribuirVetor(vetor1);
  atribuirVetor(vetor2);

  //printf("Atribui\n");

  printa_vetores(vetor1);
  printa_vetores(vetor2);

  //printf("Printei\n");

  printf("\nA soma simples dos vetores resulta em:\n");
  vetSoma = soma(vetor1, vetor2);
  printa_vetores(vetSoma);

  printf("\nA subtracao simples dos vetores resulta em:\n");
  vetSub = subtracao(vetor1, vetor2);
  printa_vetores(vetSub);

  float escalar;
  printf("\nDigite o valor do numero escalar: ");
  scanf("%f", &escalar);
  printf("\nA multipliplicação pelo escalar %.2f resulta em:\n", escalar);

  vetEscalar = multEscalar(vetor1, escalar);
  printa_vetores(vetEscalar);

  vetEscalar = multEscalar(vetor2, escalar);
  printa_vetores(vetEscalar);


  // TEM Q LIBERAR TUDO //

  return 0;
}