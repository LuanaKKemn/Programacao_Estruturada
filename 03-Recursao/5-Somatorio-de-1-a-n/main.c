#include <stdio.h>

/*
  Crie uma função recursiva que receba um número inteiro positivo N e 
  calcule o somatório dos números de 1 a N.
*/

int somatudo(int n);

int main(void) {
  int n;
  
  //ENTRADA
  printf("Digite n: ");
  scanf("%d", &n);
  
  //PROCESSAMENTO
  int resultado = somatudo(n);
  
  // SAIDA
  printf("A soma é: %d", resultado);
  
  return 0;
}

// SEMPRE SOMA UM VALOR A RECURSÃO // 

int somatudo(int n){
  if (n < 1) {return 0;}
  return n + somatudo(n-1);
}