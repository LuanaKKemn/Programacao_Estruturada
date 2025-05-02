#include <stdio.h>
/*
  Escreva um programa que informa a soma de uma progressão aritmética, 
  dados os valores inicial, final e o número de termos.
  Considere a seguir que não temos o último termo, mas no lugar dele 
  temos a razão.
  A razão de uma progressão aritmética é o valor que, somado ao termo anterior, resulta no próximo termo da sequência. 
*/


int somaPA(int inicial, int final, int num_termos, int razon){
  int i, j;
  int soma=0;
  razon = (final - inicial)/num_termos;
  
  for (i=inicial; i<=final; i+=razon) {
    soma =  i;
  }

  return soma;

}

int soma_PA_semFinal(){

  
}



int main(void) {
  int inicial, final, num_termos;
  int razao;

  int i, j;
  
  printf("Valor inicial:\n");
  scanf("%d", &inicial);
  
  printf("Valor final:\n");
  scanf("%d", &final);

  printf("Numero de termos:\n");
  scanf("%d", &num_termos);
  

  int soma = somaPA(inicial, final, num_termos, razao);
  printf("%d \n", soma);

  printf("Razao:\n");
  scanf("%d", &razao);

  

    

  
  
  
  
  return 0;
}