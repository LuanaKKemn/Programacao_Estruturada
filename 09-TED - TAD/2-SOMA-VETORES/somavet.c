/* somavet.c: Implementação do TAD somaVet*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "somavet.h"

#include <math.h>

#define EPSILON 1e-6



// CRIA TIPO ABSTRATO VETOR // --> ao criar o tipo: não esquecer de atribuir valor a cada variável
typedef struct vetor {
  float *elementos;
  int qnt;
} Vetor;


// CRIAR VETOR COM ALOCAÇÃO DINAMICA //
Vetor* criarVet(int qnt){
  Vetor* vet = (Vetor*) malloc (sizeof(Vetor));
  if (vet == NULL){
    printf("Espaço Insuficiente.");
    exit(1);
  }

  vet->qnt = qnt; // PRECISA ATRIBUIR O VALOR QNT A ESTRUTURA ABSTRATA DE DADOS // 
  
  (vet->elementos) = (float*) malloc (sizeof(float)*qnt);
  if ((vet->elementos) == NULL){
    printf("Espaço Insuficiente.");
    exit(1);
  }
  //printf("Criei o vetor!\n");
  return vet;
}


// ATRIBUR VALORES AO VETOR //
Vetor* atribuirVetor(Vetor* v){
  srand((unsigned int)time(NULL)); // --> gerar aleatorios em cada execução //
  
  float a = 0.1; // --> Valor minimo desejado //
  float b = 9.9; // --> Valor maximo desejado //
  
  for (int i=0; i<(v->qnt); i++){
    v->elementos[i] = a + ((float)rand() / (float)RAND_MAX) * (b-a);
  }
  return v;
}


// PRINT FORMATADINHO // 
void printa_vetores(Vetor* v){
  for (int i=0; i<(v->qnt); i++){
    if (i == (v->qnt)-1){
      printf("%.2f}\n", (v->elementos[i]));
    } else {
      printf("%.2f, ", (v->elementos[i]));
    }
  }
}



// -> ponteiro LIBERAR VETORES //
void liberarVet(Vetor* vet){
  free(vet->elementos); // não pode fazer ao contrario
  free(vet);           // pra não perder a referencia
}



// FUNÇÕES //

Vetor* somaVetores(Vetor* vet, Vetor* w){
  w->elementos[0] = vet->elementos[0];
  
  for (int i=1; i<(vet->qnt); i++){
    w->elementos[i] = vet->elementos[i] + w->elementos[i-1];
  }
  return w;
}


float minimo(Vetor* vet){
  float min;
  for (int i=0; i<(vet->qnt); i++){
    if (i==0){
      min = vet->elementos[i];
    } else {
      if (vet->elementos[i]<min){
        min = vet->elementos[i];
      }
    }
  }
  return min;
}


float maximo(Vetor* vet){
  float max;
  for (int i=0; i<(vet->qnt); i++){
    if (i == 0){
      max = vet->elementos[i];
    } else {
      if (vet->elementos[i]>max){
        max = vet->elementos[i];
      }
    }
  }
  return max;
}


int buscaElemento(Vetor* vet, float elemento){
  for(int i = 0; i<vet->qnt; i++){
    if (vet->elementos[i] == elemento){
      return i;
    }
  }
  return -1;
}


  

