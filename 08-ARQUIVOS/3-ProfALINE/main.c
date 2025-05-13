/*Desenvolva um jogo da forca. O programa terÃ¡ uma lista de palavras lidas de um arquivo
texto (palavras.txt) e escolherÃ¡ uma palavra aleatoriamente. Seu programa deve ler as palavras
do arquivo e colocÃ¡-las em um vetor. ApÃ³s, ele deve sortear uma posiÃ§Ã£o vÃ¡lida da lista e obter
a palavra. O jogador poderÃ¡ errar 6 vezes antes de ser enforcado.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void criar_palavra_vazia(char ptemp[20], int len){
  for (int i = 0; i < len; i++)
    ptemp[i] = '-';
}


int leitura(char nome_arquivo[40], char palavras[100][100]){
  FILE *fp;
  fp = fopen(nome_arquivo, "r");
  char palavra[100];
  /* teste para verificar se houve algum erro */
  if (fp == NULL) {
    printf("Erro na abertura do arquivo de leitura.\n");
    exit(1); /* aborta programa ( retorna da funÃ§Ã£o main) */
  }
  int i = 0;
  while (fscanf(fp, " %s", palavra) == 1) {
    strcpy(palavras[i], palavra);
    i += 1;
  }

  fclose(fp);
  return i;
}

void modificar_palavra(char temp[20], char palavra[20], char c){
  for (int i = 0; palavra[i] != '\0'; i++)
    if (palavra[i] == c)
      temp[i] = c;
}

int comparar(char palavra[20], char teste[20]){
  for (int i = 0; palavra[i] != '\0'; i++)
    if (teste[i] != palavra[i])
      return 0;
  return 1;
}

int forca(int npalavras, char palavras[npalavras][100]){
  char c;
  int pos;
  char palavra[20], teste[20], ptemp[20];
  srand(time(NULL));   
  strcpy(palavra, palavras[rand() % npalavras]); 
  //printf("%s", palavra);
  criar_palavra_vazia(ptemp, strlen(palavra));
  for (int i = 0; i < 6; i++){
    puts(" char: ");
    scanf("\n%c", &c);
    modificar_palavra(ptemp, palavra, c);
    printf("%s\n", ptemp);
    puts("Adivinhe: ");
    scanf("%s", teste);
    if (comparar(palavra, teste)){
      printf("Acertou!!");
      return 1;
    }
    else
      puts("Ainda nÃ£o...");
  }
  printf("Tentativas esgotadas!!");
  return 0;
}


int main () {
  char* nome_arquivo = "arquivos/teste_forca.txt";
  char palavras[20][100];
  int npalavras = leitura(nome_arquivo, palavras);
  forca(npalavras, palavras);
  return 0;
}