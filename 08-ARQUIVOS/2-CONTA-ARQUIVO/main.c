#include <stdio.h>
#include <string.h>

/*
  Faça um programa que recebe o nome de um arquivo e conta o total de letras, vogais,
  consoantes, espaços em branco, palavras e o total de linhas encontradas no arquivo.
  Considere que uma palavra é separada de outra por um espaço em branco ou um fim de linha.
*/

int contaTudo(void);


int main(void) {
  FILE *arquivo = fopen("exercio2.txt", "r");
  if (arquivo == NULL){
    printf("Não foi possível abrir o arquivo");
    return 1;
  }

  int letras=0;
  int vogais=0, consoantes=0;
  int espaços_branco=0;
  int palavras=0;
  int linhas=0;

  
  
  



  fclose(arquivo);
  return 0;
}


int contaTudo(void){
  
}