#include <stdio.h>
# include <math.h>
/*
  Escreva um programa que lê números reais a, b e c, e calcula as raízes de
  uma equação do 2o grau da forma ax2 + bx + c = 0. Caso a raiz seja
  complexa, informe a parte real e a parte imaginária.
  Observação: Em C, para extrair raiz quadrada use a função sqrt, definida na
  biblioteca math
  b±√(b²-4ac))/(2a)
*/



int main(void) {
  int a, b, c;
  double x1, x2;
  double delta;
  scanf("%d, %d, %d", &a, &b, &c);
  double real, imaginativa, imaginativaN;

  
  delta = (b^2 - 4*a*c);
  
  if (delta < 0){
    real = -b/(2*a);
    imaginativa = (sqrt(delta))/2*a;

    imaginativaN = -(sqrt(delta))/2*a;

    printf("Parte real: %f\nParte imaginativa Positiva: %f\nParte imaginativa Negativa: %f\n", real, imaginativa, imaginativaN);
  } else {
    x1 = (b + sqrt(delta)) / (2*a);

    x2 = (b - sqrt(delta))/(2*a);

    printf("Raiz Positiva: %f\nRaiz Negativa: %f\n", x1, x2);
    
  }
  

  
  return 0;
}