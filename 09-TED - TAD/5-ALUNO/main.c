#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void) {
  char n[25];

  printf("Digite o nome do Aluno: ");
  scanf("%c", n);

  Aluno *n1;
  n1 = mallocado(n1);
  printf("Maloquei\n");

  Vetor *notas;
  Vetor *cargaH;

  notas = atribuiValores(notas);
  cargaH = atribuirCH(cargaH);
  printaVet(notas);
  printaVet(cargaH);

  printf("Pre - Atribui\n");

  n1 = atribuicaoAluno(n1, notas, cargaH, n);

  printf("Atribui\n");

  printarAluno(n1);



  float media = mediaNotas(notas);
  printf("A media do aluno é: %.2f\n", media);

  float cr = calCR(notas, cargaH);
  printf("O CR do aluno é %.2f\n", cr);

  float maior, menor;
  maior_Menor(&maior, &menor, notas);

  printf("A maior nota foi: %.2f\n", maior);

  printf("A menor nota foi: %.2f\n", menor);


  return 0;
}