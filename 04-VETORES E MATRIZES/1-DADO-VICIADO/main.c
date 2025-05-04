#include <stdio.h>
#include <stdlib.h>

/*
  Tentando descobrir se um dado era viciado, um dono de cassino honesto o lançou n
  vezes. Leia os n resultados dos lançamentos, guarde-os em um vetor e determine o
  número de ocorrências de cada face.
*/


void dadoViciado(int *vetoResults, int *vetor, int n, int num);

int main(void) {
  int n;


  // ENTRADA
  printf("Digite quantas vezes irá jogar o dado: ");
  scanf("%d", &n);

  int *vetor;
  vetor = (int*) malloc(n*sizeof(int));

  int *vetoResults;
  vetoResults = (int*) malloc(6*sizeof(int));
  
  for (int i=0; i<n; i++){
    scanf("%d", &vetor[i]);
  }
  // PROCESSAMENTO

  dadoViciado(vetoResults, vetor, n, 0);

  // SAIDA
  printf("Resultados:\n");
  for (int i=0; i<6; i++){
    printf("%d", vetoResults[i]);
  }
  

  
  
  
  free(vetor); // O ESPAÇO DEVE SER LIBERADO
  return 0;
}

void dadoViciado(int *vetoResults, int *vetor, int n, int num){

  for (int i=0; i<6; i++){
    for (int j=0; j<n; j++){
      if (vetor[j] == num){
        vetoResults[i] ++;
      }
    }
  }


  
}
