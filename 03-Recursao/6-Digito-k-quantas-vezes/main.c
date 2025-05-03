#include <stdio.h>

/*
  Escreva uma função recursiva que determine quantas vezes um dígito K 
  ocorre em um número natural N. Por exemplo, o dígito 2 ocorre 3 vezes em 
  762021192.
*/

int contaNuNat(int k, int n, int *soma);


int main(void) {
  int k;
  int n;
  int soma=0;

  // ENTRADA
  printf("Digite o digito k: ");
  scanf("%d", &k);

  printf("\nDigite o numero natural n: ");
  scanf("%d", &n);
  
  // PROCESSAMENTO
  contaNuNat(k, n, &soma);

  // SAIDA
  printf("\nO digito %d aparece %d vezes em %d.", k, soma, n);
  
  
  
  return 0;
}


// qq ta dando erradooooooooo?? // 
int contaNuNat(int k, int n, int *soma){
  if (n<10) { // finaliza
    if (n == k){
      return *soma + 1;
    }
    return *soma;
  }
  
  if (n%10 == k) {
    *soma += 1;
    return contaNuNat(k, n/10, soma);
  } else {
    return contaNuNat(k, n/10, soma);

  }
  

  
}