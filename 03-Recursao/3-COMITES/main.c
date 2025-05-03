#include <stdio.h>

/*
  Imagine que comm(n,k) representa o número de 
  diferentes comitês de k pessoas, que podem ser formados, 
  dadas n pessoas a partir das quais escolher. Por exemplo, 
  comm(4,3) = 4, porque dadas quatro pessoas, A, B, C e D 
  existem quatro possíveis comitês de três pessoas: ABC, 
  ABD, ACD e BCD. O número de comitês pode ser 
  calculado a partir da seguinte expressão:
  comm(n ,k) = comm(n - 1, k) + comm(n - 1, k - 1)
  Escreva e teste um programa recursivo em C para calcular 
  comm(n,k) para n,k >= 1.

*/


int comm(int n, int k);


int main(void) {
  int n, k;

  //ENTRADAS 
  printf("Digite n e k:");
  scanf("%d %d", &n, &k);

  //PROCESSAMENTO
  int resultado = comm(n, k);
  
  //SAÍDAS
  printf("O número de comites possíveis é %d", resultado);
  

  return 0;
}


// TA DANDO ALGUM ERRO DE LÓGICA // 

int comm(int n, int k){
  if (k>n) {
    return 0;
  }
  if (k == 1 || (n == 1)){
    return n;
  }
  return (comm(n-1, k) + comm(n-1, k-1));
  
}
