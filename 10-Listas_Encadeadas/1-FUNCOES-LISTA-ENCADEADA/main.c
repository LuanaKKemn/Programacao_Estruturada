#include <stdlib.h>
#include <stdio.h>
#include "listasEncadeadas.h"


int i, j;


int main(void) {
  int q = 4;
  int num[] = {2,4,7,9};

  No *listEnq;

  mallocarListaEnc(listEnq);

  No* li = criaList(listEnq, q, &num[q]);

  exibirList(li);

  
  


  
  return 0;
}