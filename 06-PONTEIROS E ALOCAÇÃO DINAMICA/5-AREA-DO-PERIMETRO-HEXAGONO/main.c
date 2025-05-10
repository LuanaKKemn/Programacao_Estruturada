#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
  Faça um programa para calcular a área e o perímetro de um hexágono. O programa deve 
  implementar uma função chamada calc_hexa que calcula a área e o perímetro de um hexágono 
  regular de lado L. O programa deve solicitar ao usuário o lado do polígono, calcular e imprimir a área 
  e o perímetro do polígono. O programa termina quando for digitado um valor negativo qualquer para o 
  lado. A função deve obedecer o seguinte protótipo:
  void calc_hexa(float l, float *area, float *perimetro);
*/

void calc_hexa(float l, float *area, float *perimetro);

int main(void) {
  int l=0;
  float area;
  float perimetro;

  // ENTRADA

  printf("Digite o tamanho dos lados: ");
  scanf("%d", &l);
    
  while (l >= 0){
    

    // PROCESSAMENTO
    calc_hexa(l, &area, &perimetro);
    
    // SAÍDA
    printf("Perimetro: %.2f\nArea: %.2f\n", perimetro, area );


    // ENTRADA
    printf("Digite o tamanho dos lados: ");
    scanf("%d", &l);
  }
  printf("FIM");
  return 0;
}


void calc_hexa(float l, float *area, float *perimetro){
  *perimetro = l * 6;
  //  (3√3 * L^2) / 2
  *area = (3*(sqrt(3)) * l*l) / 2;
}