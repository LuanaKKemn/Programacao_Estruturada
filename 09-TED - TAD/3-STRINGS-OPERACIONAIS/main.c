#include "stringsoperacionais.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


int main(void) {
  char word[100];

  printf("Digite a palavra:\n");
  scanf("%s", word);

  Palavra* p = criar_palavra(word);

  printarStrings(p);

  char *invert = inversao(p);
  printf("A palavra %s, invertida fica: %s\n", word, invert);
  

  int resp = palindroma(p);

  printf("A palavra %s %s palindroma.\n", word, (resp == 0)? "não é" : "é");

  int prefi;
  printf("Digite a posição máxima do prefixo: ");
  scanf("%d", &prefi);

  char *prefix = prefixo(p, prefi);
  if (prefix){
    printf("O prefixo é %s\n", prefix);
  }
  


  int suf;
  printf("Digite a posição minima do sufixo: ");
  scanf("%d", &suf);


  char *sufix = sufixo(p, prefi);
  if (sufix){
    printf("O sufixo é %s\n", sufix);
  }
  

  printf("Digite a letra original que deseja trocar por uma substituta: ");
  char let1;
  scanf(" %c", &let1);

  printf("Digite a letra susbtituta: ");
  char let2;
  scanf(" %c", &let2);


  char* new = trocaLetras(p, let1, let2);

  printf("A nova string com as letras trocadas é %s", new);

  
  livra(p);
  free(invert);
  if (prefix) free(prefix);
  if (sufix) free(sufix);

  
  return 0;
}