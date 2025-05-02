#include <stdio.h>
#include <math.h>

/*
  Implemente uma função que retorne uma aproximação do valor de PI, de 
  acordo com a fórmula de Leibniz abaixo. A função deve receber como entrada 
  o número que indica a quantidade de termos na série. Após, escreva um 
  programa completo que leia o número de termos via teclado e chame a função 
  implementad

*/

// sempre da boom


double piLeibniz(int termos){
  int i, j;
  int termino;
  double pi=0.0;


  for(i=0; i<termos; i++){
    pi += pow(-1, i) / (2*i+1); // brabo ta
  }
  
  pi *= 4;

  return pi;
  
}

int main(void) {
  int termos;
  double resultado;

  printf("Escreva o numero de termos:\n");
  scanf("%d", &termos);

  resultado = piLeibniz(termos);

  printf("O valor eh %f", resultado);


  
  return 0;
}