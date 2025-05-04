#include <stdio.h>
#include <string.h>
#include <stdlib.h>



/*
  Faça uma função que dadas duas matrizes A e B de mesmo tamanho, 
  calcula a matriz C que é a matriz soma de A e B.
*/

int somaMatriz(int mat1, int mat2, int matSomada, int tamanho);
void criamatriz(int tamanho, int matriz[tamanho][tamanho]);
void printaMatriz(int dimensaoMat, int **matriz);




int main(void) {
  int tamanho = 2;
  int mat1 = (int**) malloc (tamanho * (sizeof(int));
  int mat2 = (int**) malloc (tamanho * (sizeof(int));
  int matSomada = (int**) malloc (tamanho * (sizeof(int));

  
  criamatriz(tamanho, mat1[][tamanho]);
  printaMatriz(tamanho, mat1);





  
  return 0;
}


int somaMatriz(int mat1, int mat2, int matSomada, int tamanho){
  for (int i=0; i<(tamanho); i++) {
      for (int j=0; i<(tamanho); j++) {
          matSomada[i][j] = mat1[i][j] + mat2[i][j];
        }
   }
}


void criamatriz(int tamanho, int matriz[tamanho][tamanho]){
   for (int i=0; i<(tamanho); i++) {
      for (int j=0; i<(tamanho); j++) {
        //scanf("%d", &matriz[i][j]);
        matriz[i][j] = rand();
      }
   }
}

void printaMatriz(int dimensaoMat, int **matriz){
  printf("Matriiz[] = {");
  for (int i=0; i<(dimensaoMat); i++ ){
    for (int j=0; j<(dimensaoMat); j++ ){
      printf(" %d", matriz[i][j]);
    }
  }
  printf("}");
}