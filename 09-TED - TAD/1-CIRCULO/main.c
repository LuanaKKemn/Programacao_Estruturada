#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "circulo.h"


int main(void) {
  float x, y, r;

  printf("Digite x y r:\n");
  scanf("%f %f %f", &x, &y, &r);

  Ponto* p = criarPonto(x, y);
  Circulo* c = criarCirculo(p, r);

  float a = areaCir(c);
  printf("A area do circulo é: %.2f\n", a);

  printf("Digite as coordenadas x y de um ponto.\n");
  float x1, y1;
  scanf("%f %f", &x1, &y1);

  int interno = interior(c, p, x1, y1);

  printf("O ponto %.2f, %.2f %s no circulo.\n", x1, y1, (interno == 0)? "nao esta":"esta");


  liberacao_Ponto(p);
  liberacao_Circulo(c);
  return 0;
}