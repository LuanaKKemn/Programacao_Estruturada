#include <stdlib.h>
#include <stdio.h>
#include "listasEncadeadas.h"

// TIPOS ABSTRATOS // 
typedef struct No {
  int num;
  No *prox;
} No;


typedef struct Twolists{
  No* lista1;
  No* lista2;
} Twolists;


// ALOCAÇÕES DINAMICAS //

void mallocar2Lists(Twolists **listas){
  *listas = (Twolists*) malloc(sizeof(Twolists));
  if (!listas){
    printf("Erro ao alocar memoria");
    exit(1);
  }
  (*listas) -> lista1 = NULL;
  (*listas) -> lista2 = NULL;
}


No *criaNo(int a){
 No *novoNo = (No*)malloc(sizeof(No));
  if (!novoNo){
    printf("Espaco insufiente");
    exit(1);
  }
  novoNo->num = a;
  novoNo->prox = NULL;

  return novoNo;
}

// EXIBIÇÃO // 

// EXIBIR LISTA // 
void exibirList(No * list){
  No* l = list;
  printf("LISTA ENCADEADA:\n");
  while (l){
    printf("%d", l->num);
    l = l->prox;
  }
  printf("\n");
}

// FUNÇÕES // 

// VETOR PARA LISTA //
No* criaList(int q, int vet[q]){
  if (q==0) return NULL;
  
  No *first = criaNo(vet[0]);
  No *now = first;

  for(int i=1; i<q; i++){
    now->prox = criaNo(vet[i]);
    now = now->prox;
  }
  return first;
}


// CONTAR ELEMENTOS ENCADEADOS // 

int contElements(No *list){
  int cont =0;

  No* l = list;

  while (l != NULL){
    cont++;
    l = l->prox;
  }
  return cont;
}


// DIVIDIR LISTA NO MEIO //
No* divid2lists(No *l){
  Twolists *q1;
  mallocar2Lists(&q1);

  int tamList = contElements(l) / 2; 
  
  No *auxiliar = l;
  No *segundaLista = NULL;
  
  
  int i=0;
  while (l != NULL){
    if (i>tamList){
      segundaLista = l->prox;
      l->prox = NULL;
      break;
    }
    else {
      auxiliar = l;
      l = l->prox;
    }
    i++;
  }
  
  q1->lista1 = auxiliar;
  q1->lista2 = segundaLista;
  
  return q1->lista2;
}

/////////////////////////////////////////////////


// DIVIDIR LISTA ANTES E DEPOIS DE ELEMENTO //
No* porElement(int elemento, No* l){
  Twolists *q2;
  mallocar2Lists(&q2);

  No *auxiliar = l;
  No *s = NULL;
  
  while (auxiliar != NULL){
    if (auxiliar->num == elemento){
      s = auxiliar->prox;
      auxiliar->prox = NULL;
    }
    else{
      auxiliar = l;
      l = l->prox;
    }
    return q2->lista2;
    
  }

  q2->lista1 = auxiliar;
  q2->lista2 = s;

  return q2->lista2;
}



// DIVIDIR LISTA ANTES E DEPOIS DE POSIÇÃO //
Twolists* porPosicao(int pos, No *l){
  Twolists *q3;
  mallocar2Lists(&q3);

  No *aux = l;

  No *list2 = NULL;

  int i=0;
  while (l!= NULL){
    if (i == (pos)){
      list2 = aux->prox;
      aux->prox = NULL;
      break;
    }
    else{
      aux = l;
      l = l->prox;
    }
    
  }
  aux->prox = NULL;
  q3->lista1 = aux;
  q3->lista2 = list2;
  
  return q3;
}





// LIBERAÇÃO // 

// LIBERAR LISTAS ENCADEADAS //
void liberarNos(No *n){
  No *temp;

  while (n != NULL){
    temp = n;
    n = n->prox;
    free(temp);
  }
}


// LIBERAR STRUCT DE LISTAS //
void liberarStucts(Twolists *to2){
  if (to2 != NULL){
    liberarNos(to2->lista1);
    liberarNos(to2->lista2);
    free(to2);
  }
}