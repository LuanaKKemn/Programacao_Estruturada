#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
  Escreva uma função para multiplicar os elementos da diagonal principal de 
  uma matriz por um valor k. 
*/

int multplicaDP(int matriz, int k, int dimensaoMat);

void printaMatriz(int matriz, int dimensaoMat);

void criaMatriz();

void matrizRandom();



int main(void) {
  int k;
  int dimensaoMat;
  int matriz[][];

  
  return 0;
}


int multplicaDP(int matriz, int k, int dimensaoMat){

  for (int i=0; i<(dimensaoMat); i++ ){
    for (int j=0; j<(dimensaoMat); j++ ){
      if (i==j){
        matriz[i][j] *= k;
      }
    }
  }


  
}

void printaMatriz(int matriz, int dimensaoMat){
  printf("Matriiz[] = {");
  for (int i=0; i<(dimensaoMat); i++ ){
    for (int j=0; j<(dimensaoMat); j++ ){
      printf(" %d", matriz[i][j]);
    }
  }
  printf("}");
}

