#include <stdio.h>
#include <string.h>

/*
  Escreva uma função que recebe uma string e um caracter e retorne apenas o trecho da 
  string situado entre a primeira e a última ocorrência daquele caracter, excluindo os 
  extremos. Por exemplo, se a entrada for "abcabc" e "a", a saída deve ser "bc". Se a 
  entrada for "abcabcabc", a saída será "bcabc"
*/


void trecho(char letra, char *string);


int main(void) {
  char letra;
  char string[81];


  // ENTRADA
  printf("Digite a string: ");
  scanf(" %80[^\n]", string);

  printf("\nDigite a letra: ");
  scanf(" %c", &letra);

  // SAIDA
  printf("O trecho é ");
  trecho(letra, string);
  
  return 0;
}


void trecho(char letra, char *string){
  int tam = (strlen(string));
  
  int indice_inicial=0, indice_final = tam-1;

  
  for (int i=0; string[i] != '\0'; i++){
    if (string[i] == letra){
      indice_inicial = i+1;
    }
    if (string[tam-i-1] == letra){
      indice_final = (tam - i - 2);
      break;
    }
  }
  printf("\nPosição inicial %d\nPosição Final %d\n", indice_inicial, indice_final);
  if (indice_inicial > 0){
    for (int i = indice_inicial; i <= indice_final; i++){
      printf("%c", string[i]);
    }
  }
}