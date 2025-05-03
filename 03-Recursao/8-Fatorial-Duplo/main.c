#include <stdio.h>

/*

  A função fatorial duplo é definida como o produto de todos os números 
  naturais ímpares de 1 até algum número natural ímpar N.
  Assim, o fatorial duplo de 5 é 5!! = 1 * 3 * 5 = 15
  Faça uma função recursiva que receba um número inteiro positivo ímpar N e 
  retorne o fatorial duplo desse número.

*/

int fatorialDuplo(int n, int *total);

int main(void) {
  int n;


  // ENTRADA
  printf("Digite um número natural impar: ");
  scanf("%d", &n);
  
  int total = 1;

  // PROCESSAMENTO
  int resultado  = fatorialDuplo(n, &total);

  if (resultado != 0){
    // SAIDA
    printf("\nO fatorial duplo desse número é: %d", resultado);
  }
  
  
  return 0;
}



// RECURSÃO DE ACUMULO NA VARIÁVEL 
// --> E MUDA SÓ OS PARAMETROS 

int fatorialDuplo(int n, int *total){
  if (n%2 == 0) {
    printf("O número digitado não é impar.");
    return 0;
  }
  if  (n == 1) {return *total;}

  *total *= n;

  return (fatorialDuplo(n-2, total));
  
}
  



  

