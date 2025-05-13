#include <stdio.h>
#include <stdlib.h>



int stats(char nome[20]){
  FILE *fp;
  char texto[200];
  int linhas = 0, espacos = 0, vogais = 0, palavras = 0, cons = 0, letras = 0;
  /* abertura do arquivo para leitura */
  fp = fopen(nome, "r");
  /* teste para verificar se houve algum erro */
  if (fp == NULL) {
    printf("Erro na abertura do arquivo de leitura.\n");
    exit(1); /* aborta programa ( retorna da funÃ§Ã£o main) */
  }

  while (fscanf(fp, " %200[^\n]", texto) == 1) {
    linhas += 1;
    if (texto[0] != '\0')
      palavras += 1;
    for (int i = 0; texto[i] != '\0'; i++){
      if (texto[i] == ' '){
        espacos += 1;
        palavras += 1;
      }
      if ( (texto[i] > 64 && texto[i] < 91) || (texto[i] > 96 && texto[i] < 123)){
        letras += 1;
        if (texto[i] == 'a' | texto[i] == 'e' | texto[i] == 'i' | texto[i] == 'o' | texto[i] == 'u')
          vogais += 1;
        else if (texto[i] == 'A' | texto[i] == 'E' | texto[i] == 'I' | texto[i] == 'O' | texto[i] == 'U')
          vogais += 1;
        else 
          cons += 1;
      }
    }
    printf(" Linhas = %d\n Espacos = %d\n Vogais = %d\n Consoantes = %d\n Letras = %d\n Palavras = %d\n", linhas, espacos, vogais, cons, letras, palavras);

  }
  /* fechamento do arquivo */
  fclose(fp);


  return 1;

}


int main () {
  char nome_arquivo[40];
  puts("Arquivo com texto: ");
  scanf(" %30[^\n]", nome_arquivo);
  stats(nome_arquivo);
  return 0;
}