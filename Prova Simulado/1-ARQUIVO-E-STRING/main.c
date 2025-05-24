#include <stdio.h>
#include <stdlib.h>

/*
  Escreva um programa que leia um texto de um arquivo e informe a quantidade de
  vezes que cada palavra aparece no texto. Pense nas fun ̧c ̃oes que vocˆe precisa implementar para
  resolver o problema e nas estruturas que vocˆe deve considerar.
*/

void arquivoPraVetor(FILE *arq, char *tudodoarquivo, int n);

int mallocar(char *vetor, int n);

int mallocarInt(int *vetor, int n);


int main(void) {
  int n = 200;
  char tudodoarquivo[n];
  char *vetorPalavras;
  int *vetorQuantidades;

  if (!mallocar(vetorPalavras, n))        {return 1;}
  if (!mallocarInt(vetorQuantidades, n))  {return 1;}
  
  FILE *arq;
  arq = fopen("arqtexto.txt", "r");
  if (arq == NULL){
    printf("Não foi possivel abrir o arquivo.");
    return 1;
  }

  arquivoPraVetor(arq, tudodoarquivo, n);

  printf(" %s", tudodoarquivo);
  
  free(vetorPalavras);
  free(vetorQuantidades);
  
  fclose(arq);
  return 0;
}

//////////////////////////////////////////////////////////
// PASSAR CONTEUDO DE UM ARQUIVO PARA UMA STRING
void arquivoPraVetor(FILE *arq, char *tudodoarquivo, int n){
  while (! feof(arq)){
    char y = getc(arq);
    int i=0;
    tudodoarquivo[i] = y;
    i++;
  }
}

// cata palavra
// verifica se a palavra esta no vetor
// quantidade de palavras

char catapalavra(char *tudodoarquivo, int n){
  int controle=0;
  
  while (controle < n){
    for (int i=0; tudodoarquivo[i] != '\0'; i++){
      
      controle++;
    }
  }
  
}

void quantidadePalavras(char *tudodoarquivo, int n){
  
}

/////////////////////////////////////////////////////////
int mallocar(char *vetor, int n){
  vetor = (char *) malloc(n*sizeof(char));
  if (vetor==NULL){
    printf("Espaço insuficiente.");
    return 1;
  }
  return 0;
}

int mallocarInt(int *vetor, int n){
  vetor = (int *) malloc(n*sizeof(int));
  if (vetor==NULL){
    printf("Espaço insuficiente.");
    return 1;
  }
  return 0;
}
