#include <stdlib.h>
#include <stdio.h>
#include "condominio.h"


typedef struct apartamento{
  char nome[100];
  int num;
  float area;
  int moradores;
  float valor;
} Apartamento;


typedef struct vetorE{
  Apartamento* ape[40];
  int tam;
} VetorE;


// alocar //
Apartamento* mmalocar(void){
  Apartamento *a = (Apartamento*) malloc(sizeof(Apartamento));
  if (a == NULL){
    printf("Espaço Insuficiente");
    exit(1);
  }
  return a;
}


VetorE* malloke(VetorE *e){
  e = (VetorE*) malloc(sizeof(VetorE));
  if (e==NULL){
    printf("Espaço insuficiente");
    exit(1);
  }
  // precisa alocar mais alguma coisa?
  return e;
}


// atribuir valores  AP --> fazer em um for na main//
Apartamento* atrib(char* name, int number, float area, int morad){
  Apartamento *ap = mmalocar();
  ap->nome = name[];
  ap->num = number;
  ap->area = area;
  ap->moradores = morad;
}


// free //
void livre(Apartamento *a){
  free(a);
}


VetorE libre(VetorE *vet){
  free(vet->ape);
  free(vet);
}


// printar //
void printarAPs(Apartamento a){
  printf("Nome: \t%s\nNumero: \t%d\nArea: \t%.2f m²\nMoradores: \t%d\nValor: \tR$ %.2f\n", a.nome, a.num, a.area, a.moradores, a.valor);
}



// funções //

// AREA TOTAL //

float areaCond(VetorE *e){
  float areaTotal=0;

  for (int i=0; i<(e->tam); i++){
    areaTotal+= (e->ape[i]->area);
  }
  
  return areaTotal;
}


// VALOR PROPORCIONAL //
void valorPagar(float despesas, VetorE *e, float areat){
  float metroV = despesas / areat;

  for (int i=0; i< (e->tam); i++){
    float valorPagar = (e->ape[i]->area) * metroV;
    (e->ape[i]->valor) = valorPagar;
  }
}


// MAIOR LOTAÇÃO//

void moradoresMax(VetorE * e){
  int m=0;
  int pos;

  for (int i=0; i<(e->tam); i++){
    if (e->ape[i]->moradores > m){
      m = e->ape[i]->moradores;
      pos = i;
    }
  }
  printf("O apartamento com maior número de moradores é:\n");
  printarAPs(*e->ape[pos]);
}