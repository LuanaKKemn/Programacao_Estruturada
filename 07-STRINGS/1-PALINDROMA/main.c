#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int palindroma(char palavra[]);

void removeEspacos(char palavra[], char frase[]);

int main(void) {
  int n;
  char palavra[81];
  char frase[81];
  
  // ENTRADA
  // printf("Digite a quantidade de letras da palavra: ");
  // scanf("%d", &n);
  // n++;
  printf("Digite a palavra ou frase: ");
  scanf(" %80[^\n]", palavra);

  // PROCESSAMENTO
  removeEspacos(palavra, frase);
  
  int resp = palindroma(frase);
  
  // SAÍDA
  printf("\nA palavra/frase %s %s palíndroma", palavra, resp == 1 ? "é": "não é");
  
  return 0;
}


// DEU ALGUMA COISA ERRADA QND SUBI NO ONIBUS

int palindroma(char palavra[]){
  int j = strlen(palavra);
  //printf("%d\n", j);
  for (int i=0; i < j; i++){
    if (palavra[i] != palavra[j-1-i]){
      return 0; // não é
    }
  } return 1; // é
}


void removeEspacos( char palavra[], char frase[]){
  int j=0;
  for (int i=0; palavra[i] != '\0'; i++){
    if (palavra[i] != ' ') {
      frase[j] = palavra[i];
      j++;
    }
    frase[j] = '\0'; // NÃO ESQUECER DE COLOCAR O CARACTERE FINAL
  }printf("%s", frase);
}