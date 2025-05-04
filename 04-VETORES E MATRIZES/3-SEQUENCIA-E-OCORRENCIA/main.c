#include <stdio.h>
#include <stdlib.h>
#include <time.h> // gerar numeros random



int escreverVetor(int *vetor);


int main(void) {
  int n;

  // ENTRADA
  printf("Digite n: ");
  scanf("%d", &n);

  float *vetor;

  vetor = (float*) malloc (n * sizeof(float));

  escreverVetor(vetor);
  
  

  
  
  return 0;
}


void escreverVetor(float *vetor){
  for (int i=0; i<sizeof(vetor); i++){
    if (i== (sizeof(vetor)-1)){
      printf("%d\n", vetor[i]);
    } else {
      printf("%d ", vetor[i]);
    }
  }
}