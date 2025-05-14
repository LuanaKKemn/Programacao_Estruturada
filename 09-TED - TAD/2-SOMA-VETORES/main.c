#include <stdio.h>
#include <stdlib.h>

#include "somavet.h"

#include <math.h>

#define EPSILON 1e-6



int main(void) {
  int n;

  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);

  Vetor* vetor = criarVet(n);
  vetor = atribuirVetor(vetor);

  printf("\nVetor v :\n{");
  printa_vetores(vetor);
  
  Vetor* w = criarVet(n);
  w = somaVetores(vetor, w);

  printf("\nVetor w :\n{");
  printa_vetores(w);

  printf("\nELEMENTOS MÍNIMOS:\n");
  printf("O elemento minimo do vetor v eh: %.2f\n", minimo(vetor));
  printf("O elemento minimo do vetor w eh: %.2f\n", minimo(w));

  printf("\nELEMENTOS MÁXIMOS:\n");
  printf("O elemento maximo do vetor v eh: %.2f\n", maximo(vetor));
  printf("O elemento maximo do vetor w eh: %.2f\n", maximo(w));


    
  printf("\nDigite o valor que quer encontrar no vetor: ");
  float elemento;
  scanf("%f", &elemento);

  int resultado_v = buscaElemento(vetor, elemento);
  int resultado_w = buscaElemento(w, elemento);

  if (resultado_v != -1) {
      printf("O elemento esta na posição %d do vetor v\n", resultado_v);
  } else {
      printf("O elemento nao esta no vetor v\n");
  }


    
  if (resultado_w != -1) {
      printf("O elemento esta na posição %d do vetor w\n", resultado_w);
  } else {
      printf("O elemento nao esta no vetor w\n");
  }
  

  liberarVet(vetor);
  liberarVet(w);
  return 0;
}

