#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  - (a) Construa uma função sufixo que, dados dois inteiros positivos a e b,
  verifica se b corresponde aos últimos dígitos de a.

  */
//% 2 [0, 1]
//% 3 [0, 1, 2]
//% 10 [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

int sufixo(int a, int b) {
  int ultimo_a = a % 10;
  int ultimo_b = b % 10;
  while (b != 0) {
    if (ultimo_a != ultimo_b)
      return 0;
    a = a / 10;
    b = b / 10;
    ultimo_a = a % 10;
    ultimo_b = b % 10;
  }
  return 1;

  // int final_a = a % (int)pow(10, (int)log10(b));
  // if (final_a == b) {
  //   return 1;
  // } else {
  //   return 0;
  // }
}

int main(void) {
  int a, b;

  printf("Digite a:\n");
  scanf("%d", &a);

  printf("Digite b:\n");
  scanf("%d", &b);

  int resultado = sufixo(a, b);

  printf("O sufixo de %d %s %d", a, resultado == 1 ? "eh" : "nao eh", b);

  return 0;
}