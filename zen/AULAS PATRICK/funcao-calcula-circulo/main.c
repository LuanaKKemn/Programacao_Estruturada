#include <stdio.h>
#define pi 3.14159265

void cal_circulo(float r, float *circunferencia, float *area);
//prototipo de la funcion


int main(){
  int r = 20; float a, c;
  cal_circulo(r, &c, &a);
  printf("Circunferencia: %f, area: %f", c, a);
  return 0;
  
}

void cal_circulo(float r, float *circunferencia, float *area){
  *circunferencia = 2 * pi * r;
  *area = pi * r * r;
  
}