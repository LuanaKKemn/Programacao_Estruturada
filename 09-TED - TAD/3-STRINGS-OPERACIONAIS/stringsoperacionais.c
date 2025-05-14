#include "stringsoperacionais.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct palavra{
  int tam;
  char* str;
} Palavra;


// ALOCAR STRING //
Palavra* criar_palavra(char* word){
  Palavra* p = (Palavra*) malloc(sizeof(Palavra));
  if (p == NULL){
    printf("Espaço Insuficiente.");
    exit(1);
  }
  
  p->tam = strlen(word);

  (p->str) = (char*) malloc(sizeof(char)*(p->tam+1));
  if (!(p->str)){
    printf("Espaço Insuficiente");
    exit(1);
  }
  
  for (int i = 0; i<(p->tam); i++){
    p->str[i] = word[i];
  }
  
  return p;
}


// DAR FREE //
void livra(Palavra *p){
  free(p->str);
  free(p);
}


// FUNÇÕES //
char* inversao(Palavra* p){
  char* invertida = (char*) malloc (sizeof(char)*(p->tam+1));
  if (!invertida){
    printf("Espaço insuficiente");
    exit(1);
  }
  
  int j = (p->tam)-1;
  for (int i=0; (p->str[i] != '\0'); i++){
    invertida[j] = p->str[i];
    j--;
  }
  invertida[p->tam] = '\0';
  return invertida;
}


int palindroma(Palavra* p){
  int j = (p->tam)-1;
  for (int i=0; (p->str[i] != '\0'); i++){
    if (p->str[i] != p->str[j]){
      return 0; // --> NÃO É PALINDROMA 
    } else {
      j--;
    }
  }
  return 1; // --> SE SAIR DO FOR É PQ É PALINDROMA
}


// PREFIXO //

char* prefixo(Palavra* p, int parametro){
  if (parametro<0 || parametro >= p->tam){
    printf("Posição invalida para o prefixo.\n");
    return NULL;
  }
  
  char* pre = (char*) malloc (sizeof(char)*parametro+2);
  if (!pre){
    printf("Espaço Insuficiente");
    exit(1);
  }
  
  for (int i=0; i<=parametro; i++){
    pre[i] = p->str[i];
  }
  pre[parametro+1] = '\0';
  return pre;
}


// SUFIXO //

char* sufixo(Palavra* p, int final){
  if (final <0 || final >= p->tam){
    printf("Posição inválida para o sufixo\n");
    return NULL;
  }
  int qnt = (p->tam) - final;
  char* suf = (char*) malloc (sizeof(char)*(qnt+1));
  if (!suf){
    printf("Espaço Insuficiente");
    exit(1);
  }

  int j = 0;
  for (int i=final; i<p->tam; i++){
    suf[j] = (p->str[i]);
    j++;
  }
  suf[qnt] = '\0';
  return suf;
}

// MUDAR LETRA // 

char* trocaLetras(Palavra* p, char letra1, char letra2){
  for (int i=0; i<(p->tam); i++){
    if (p->str[i] == letra1){
      p->str[i] = letra2;
    }
  }
  return p->str;
}

void printarStrings(Palavra* s){
  printf("%s\n", s->str);
}