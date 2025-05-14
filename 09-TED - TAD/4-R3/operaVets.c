#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "operaVets.h"


// tipo vetor //
typedef struct vetor{
  int tam;
  int *elementos;
} Vetor;


// alocar espaço // 
Vetor* allocar(Vetor** vet){
  (*vet) = (Vetor *) malloc (sizeof(Vetor));
  if ((*vet) == NULL){
    printf("Espaço Insuficiente");
    exit(1);
  }
  (*vet)->tam = 3;
  (*vet)->elementos = (int*) malloc (sizeof(int)*((*vet)->tam));
  if (((*vet)->elementos) == NULL){
    printf("Espaço Insuficiente");
    exit(1);
  }
  return (*vet);
}



// ATRIBUR VALORES AO VETOR //
void atribuirVetor(Vetor* v){
  static int initialized = 0; // Variável estática para controlar a inicialização única
  if (!initialized) {
      srand((unsigned int)time(NULL)); // Inicialize apenas uma vez
      initialized = 1;
  }

  float a = 0.1; // --> Valor minimo desejado //
  float b = 9.9; // --> Valor maximo desejado //

  for (int i=0; i<(v->tam); i++){
    v->elementos[i] = a + ((float)rand() / (float)RAND_MAX) * (b-a);
  }
}


// PRINTO O VETOR FORMATADINHO //
void printa_vetores(Vetor* v){
  printf("{");
  for (int i=0; i<(v->tam); i++){
    if (i == (v->tam)-1){
      printf("%d}\n", (v->elementos[i]));
    } else {
      printf("%d, ", (v->elementos[i]));
    }
  }
}


// -> ponteiro LIBERAR VETORES //
void liberarVet(Vetor* vet){
  free(vet->elementos); // não pode fazer ao contrario
  free(vet);           // pra não perder a referencia
}



// FUNÇÕES//

// ▪ soma simples de dois vetores //
Vetor* soma(Vetor *vet1, Vetor *vet2){
  Vetor *vet3;
  vet3 = allocar(&vet3);
  for (int i = 0; i<3; i++){
    vet3->elementos[i] = vet1->elementos[i] + vet2->elementos[i]; // -> setinha quando for ponteiro e . ponto quando não for ponteiro
  }
  return vet3;
}

// ▪ subtração simples de dois vetores //
Vetor* subtracao(Vetor *vet1, Vetor *vet2){
  Vetor * vet3;
  vet3 = allocar(&vet3);
  for (int i = 0; i<3; i++){
    vet3->elementos[i] = vet1->elementos[i] - vet2->elementos[i]; // -> setinha quando for ponteiro e . ponto quando não for ponteiro
  }
  return vet3;
}

// ▪ multiplicação por um escalar //
Vetor* multEscalar(Vetor *vet1, float escalar){
  Vetor * vetEsc;
  vetEsc = allocar(&vetEsc);
  for (int i = 0; i<3; i++){
    vetEsc->elementos[i] = vet1->elementos[i] * escalar;
  }
  return vetEsc;
}


