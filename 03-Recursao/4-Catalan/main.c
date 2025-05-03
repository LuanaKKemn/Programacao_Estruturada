#include <stdio.h>

/*
  - Os números de Catalan são definidos pela seguinte 
  recursão
  Alguns números desta sequência são: 1, 1, 2, 5, 14, 42, 
  132, 429, 1430, 4862, 16796, 58786...
  Faça uma função recursiva que receba um número N e 
  retorne o N-ésimo número de Catalan
  
*/

float catalan(float n);


int main(void) {
  float n;
  
  //ENTRADA
  printf("Digite n: ");
  scanf("%f", &n);
  
  //PROCESSAMENTO
  float resposta = catalan(n);
  
  //SAÍDA
  printf("O %.2fº número de Catan é %.2f", n, resposta);
  
  
  return 0;
}


// TA DANDO ALGUM ERRO DE LÓGICA // 

float catalan(float n){
  if (n==0 || n == 1) {return 1;}
  
  return ((2*(2*n-1))/(n+1)) * catalan(n-1);

}