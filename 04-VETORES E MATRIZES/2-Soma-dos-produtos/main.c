#include <stdio.h>
#include <stdlib.h>


/*
  Dados dois vetores x e y, ambos com n elementos, determinar a soma dos produtos dos
  elementos desses vetores.
*/


int escreverVetor(int *vetor);


int main(void) {
  int *vetorX;
  int *vetory;
  int n;

  // ENTRADA
  printf("Digite n: ");
  scanf("%d", &n);

  vetorX = (int*) malloc (n * sizeof(int));
  vetory = (int*) malloc (n * sizeof(int));

  // vou definir o vetor
  for (int i=0; i<n; i++){
    vetorX[i] = 1;
    vetory[i] = 2;
  }

  escreverVetor(vetorX);
  escreverVetor(vetory);

  


  // printf("Preencha o vetor x\n");
  // for (int i=0; i<n; i++){
  //   scanf("%d\n", &vetorX[i]);
    
  // }
  
  // printf("Preencha o vetor y\n");
  // for (int i=0; i<n; i++){
  //   scanf("%d\n", &vetorX[i]);
  // }
  
  // printf("%d", vetorX[n]);
  // printf("%d", vetory[n]);
  // PROCESSAMENTO

  
  // SAIDA


  free(vetorX);
  free(vetory);
  return 0;
}


int escreverVetor(int *vetor){
  for (int i=0; i<sizeof(vetor); i++){
    if (i== (sizeof(vetor)-1)){
      printf("%d\n", vetor[i]);

    } else {
      printf("%d ", vetor[i]);
    }
  }

  
}