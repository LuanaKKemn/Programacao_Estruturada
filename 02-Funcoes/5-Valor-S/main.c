#include <stdio.h>

/*
  Escreva uma função que recebe por parâmetro um valor inteiro e positivo n
  e retorna o valor de S, calculado pela fórmula
  S = 1 + 1/1! + ½! + 1/3! + 1/N!

*/

int fatorial(int num){
  int i,j;
  int fat = 1;
  
  for (i=1; i<=num; i++){
    fat *= i;  
  }
  return fat;
}


float valor_S(int n){
  int s;

  // sera se me emocionei ou sera se era pra fazer assim mesmo? 
  s = 1 + 1/1 + 1/(fatorial(2)) + 1/(fatorial(3)) + 1/(fatorial(n));
  printf("%f\n", s);

  return s;

  
}


int main(void) {
  int n;

  puts("Digite n:\n");
  scanf("%d", &n);

  float resultado = valor_S(n);

  printf("%f", resultado);
  
  return 0;
}