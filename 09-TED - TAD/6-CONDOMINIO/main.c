#include <stdlib.h>
#include <stdio.h>
#include "condominio.h"


int main(void) {
  int n;
  float despesas;

  

  printf("Digite o número de apartamentos:\n");
  scanf("%d", &n);


  VetorE* c = malloke(c);
  
  
  for (int i=0; i<n; i++){
    char nome[100];
    int num;
    float area;
    int moradores;

    printf("\nNome:\t");
    scanf("%99[^\n]s", nome);

    printf("\nNumero:\t ");
    scanf("%d", &num);

    printf("\nArea:\t");
    scanf("%f", &area);

    printf("\nMoradores:\t");
    scanf("%d", &moradores);

    c->ape[i] = atrib(nome, num, area, moradores);
    
  }


  
  return 0;
}