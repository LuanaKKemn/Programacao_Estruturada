#include <stdio.h>
#include <stdlib.h>

/*
  Escreva uma função que recebe um vetor de inteiros e retorna o maior elemento e o 
  menor elemento.
*/

void escreve_vetor(int n, int *vetor);

void maiorEmenor(int *vetor,int n, int *resultados);



int main(void) {
  int n;
  int resultados[2];

  // ENTRADA
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);
  
  int *vetor;
  vetor = (int*) malloc (n*sizeof(int));
  if (vetor == NULL) {
    printf("Espaço insuficiente");
    return 1;
  }

  escreve_vetor(n, vetor);

  // PROCESSAMENTO
  maiorEmenor(vetor, n, resultados);

  // SAÍDA
  printf("\nMaior elemento = %d\nMenor elemento = %d", resultados[0], resultados[1]);

  free(vetor);
  return 0;
}



void escreve_vetor(int n, int *vetor){
  for (int i=0; i<n; i++){
    printf("\nDigite vetor[%d]: ", i);
    scanf("%d", &vetor[i]);
  }
}


void maiorEmenor(int *vetor,int n, int *resultados){
  //[0] == maior
  //[1] == menor

  for (int i=0; i<n; i++){  
    if (i == 0) {
      resultados[0] = vetor[i];
      resultados[1] = vetor[i];
    }
    if (vetor[i] > resultados[0]){
      resultados[0] = vetor[i];
      continue; // pula pra proxima iteração de i
    }
    if (vetor[i] < resultados[1]){
      resultados[1] = vetor[i];
    }
  }
}