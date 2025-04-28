#include <stdio.h>
/*
  Escreva um programa em C que recebe como entrada um número inteiro e 
  devolve o fatorial deste número
*/

int main(void) {
  int n;
  int i;
  int fatorial = 1;
  
  scanf("%d", &n);

  for (i=1; i<=n; i++){
    fatorial *= i;
  }

  printf("%d", fatorial);
  
  return 0;
}


/*
  #include <stdio.h>

int main(void) {
  int n;
  int i;
  int fatorial = 1;

  printf("Digite um número inteiro positivo: ");
  scanf("%d", &n);

  for (i = 1; i <= n; i++) {
    fatorial *= i;
  }

  printf("O fatorial de %d é: %d\n", n, fatorial);

  return 0;
}
*/

