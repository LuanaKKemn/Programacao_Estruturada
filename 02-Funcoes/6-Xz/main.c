#include <stdio.h>

/*
  Escreva uma função que recebe dois valores x e z e calcula e retorna xz
  (sem utilizar funções ou operadores de potência prontos).

*/


int potencia(int x, int z){
  int i, j;
  int pot=1;
  
  for (i=1; i<=z; i++){
    pot *= x;
  }
  return pot;
  
}

int main(void) {
  int x, z;
  int resultado=0;

  printf("Digite x: \n");
  scanf("%d", &x);
  
  printf("Digite z: \n");
  scanf("%d", &z);

  resultado = potencia(x,z);

  printf("O resultado eh %d", resultado); // pq não colocar o & ?
  
  return 0;
}