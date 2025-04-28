#include <stdio.h>

/*
  - Escreva um programa em C que imprima os N primeiros termos da série de 
Fibonacci, lembrando que esta série é definida da seguinte forma:
Termo 1 = 1
Termo 2 = 1
Termo (x +1) = termo (x) + termo (x − 1)

*/

int main(void) {
  int n;
  
  int i;
  
  scanf("%d", &n);

  int fibonacci[n];
  
  for (i=0; i>n; i++){
    if (i==0 || i==1){
      fibonacci[i] = 1; 
    }
    else {
      fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
      
    }
  
  }
  printf("%d", fibonacci[n]);
  return 0;
}