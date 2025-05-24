#include "wordsDistrib.h"
#include "listaEncadeada.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include <time.h>


int main(void) {
  FILE *arq = fopen("cbow_s50.txt", "r");
  if (!arq) {
    printf("Não foi possível abrir o arquivo!");
    exit(-1);
  }
  
  int linhas, tamLinhas;
  fscanf(arq, "%d %d", &linhas, &tamLinhas);


  // IMPLEMENTAÇÕES DAS FUNÇÕES ... //

  // ... ///
  
  fclose(arq);
  return 0;
}