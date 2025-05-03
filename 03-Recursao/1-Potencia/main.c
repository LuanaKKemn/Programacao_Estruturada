#include <stdio.h>
#include <math.h>


/*
   Crie uma função recursiva que calcula a 
  potência de um número positivo.
   - Como escrever a função para o termo n
  em função do termo anterior?
  - Qual a condição de parada?

  */


int potencia(int n, int x){
  if((n == 1) || (x == 0)) return 1;
  if(x == 1) return n;
  return potencia(n, x-1) * n;
}

// int potencia(int n, int x, int *p){
//   if((n == 1) || (x == 0)) return 1;
//   if(x == 1) return n;
//   return potencia(n, x-1, (int)(*p) * n);
// }


// if (n == 0 || n == 1){
//   return 1;

// } else {

//   return valor * (potencia(n, x-1));
// }


// return valor;


int main(void) {
  int n;
  int resultado;
  int x;
  
  printf("Digite n:\n");
  scanf("%d", &n);

  printf("Digite x:\n");
  scanf("%d", &x);

  resultado = potencia(n, x);

  printf("A potencia eh: %d", resultado);

  
  
  
  return 0;
}