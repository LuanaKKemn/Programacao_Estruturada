#include <stdio.h>


/*
  Defina o máximo divisor comum (MDC) de 
  dois inteiros, x e y, por:
  mdc(x, y) = y se (y <= x && x % y == 0)
  mdc(x, y) = mdc(y, x) se(x < y)
  mdc(x, y) = mdc(y, x % y) caso contrário
  Escreva uma função recursiva em C para calcular mdc(x, 
  y).
*/

int mdc(int x, int y);

  
int main(void) {
  int x,y;
  int resultado;

  printf("Digite x e y separados por um espaço:\n");
  scanf("%d %d", &x, &y);

  resultado = mdc(x,y);

  printf("\nO MDC entre %d e %d é %d", x, y, resultado);
  
  
  return 0;
}


int mdc(int x, int y){
  if (y<=x && x%y == 0){
    return y;
  }
  if (x < y) {
    return mdc(y, x);
  }
  return mdc(y, x%y);
}


