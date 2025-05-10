#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
  Faça uma função MAX que recebe como entrada um inteiro n, uma matriz inteira nxn e devolve 
  três inteiros: k, l e c. k é o maior elemento de A e é igual a A[l][c]. Se o elemento máximo ocorrer mais 
  de uma vez, indique em l e c qualquer uma das possíveis posições. Use ponteiros para os 
  argumentos.
*/

void escreverMatriz(int **matriz, int n);

void printaMatriz(int **matriz, int n);

void MAX(int n, int **matriz);


int main(void) {
  int n;
  
  // ENTRADA
  printf("Digite n: ");
  scanf("%d", &n);

  int **matriz;
  matriz = (int**) malloc (n*sizeof(int)); // ALOCAR A MATRIZ E AS LINHAS DA MATRIZ
  for (int i=0; i<n; i++){
    matriz[i] = (int*) malloc (n*sizeof(int)); // ALOCAR AS LINHAS DA MATRIZ
  }
  
  if (matriz == NULL){
    printf("Espaço insuficiente\n");
    return 1;
  }
  
  // PROCESSAMENTO
  escreverMatriz(matriz, n);
  printaMatriz(matriz, n);


  
  // SAÍDA
  MAX(n, matriz);

  // LIMPAR TODA A MATRIZ - LINHA POR LINHA
  for (int i = 0; i < n; i++) {
    free(matriz[i]);
  }
  free(matriz);
  return 0;
}


void escreverMatriz(int **matriz, int n){
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      printf("Digite matriz[%d][%d]: ", i, j);
      scanf("%d", &matriz[i][j]); 
    }
  }
}


void printaMatriz(int **matriz, int n){
  printf("\nMatriz:\n{{");
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      if (j == n-1){
        printf("%d}", matriz[i][j]);
      } else{
        printf("%d, ", matriz[i][j]);
      }
    }if (i != n-1) {printf("\n {");}
  }printf("}\n");
}


void MAX(int n, int **matriz){
  int k = matriz[0][0]; // maior elemento
  int l = 0;
  int c = 0;
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      if (k < matriz[i][j]){
        l = i;
        c = j;
        k = matriz[i][j];
      }
    }
  }
  printf("\nMatriz[%d][%d] = %d", l, c, matriz[l][c]);
  printf("\nk = %d\nl = %d\nc = %d", k, l, c);
}
