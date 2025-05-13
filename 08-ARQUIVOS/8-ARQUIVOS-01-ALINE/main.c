#include <stdio.h>


void cript(char texto[50], int k){
  for (int i = 0; texto[i] != '\0'; i++)
    texto[i] = texto[i] +  (k % 128);
}

void decript(char texto[50], int k){
  for (int i = 0; texto[i] != '\0'; i++)
    texto[i] = texto[i] -  (k % 128);
}




int criptografa(char nomer[20], char nomew[20], int k){
  char texto[50];
  FILE *fp1, *fp2;

  
  /* abertura do arquivo para leitura */
  fp1 = fopen(nomer, "r");
  /* teste para verificar se houve algum erro */
  if (fp1 == NULL) {
    printf("Erro na abertura do arquivo de leitura.\n");
    return 0; /* aborta programa ( retorna da funÃ§Ã£o main) */
  }

  /* abertura do arquivo para escrita */
  fp2 = fopen(nomew, "w");
  /* teste para verificar se houve algum erro */
  if (fp2 == NULL) {
    printf("Erro na abertura do arquivo de escrita.\n");
    return 0; /* aborta programa ( retorna da funÃ§Ã£o main) */
  }


  
  while (fscanf(fp1, "%s ", texto) == 1) {
    cript(texto,k);

    fprintf(fp2, "%s ", texto);
  }
  /* fechamento do arquivo */
  fclose(fp1);
  fclose(fp2);

  return 1;

}


int descriptografa(char nomer[20], char nomew[20], int k){
  char texto[50];
  FILE *fp1, *fp2;
  /* abertura do arquivo para leitura */
  fp1 = fopen(nomer, "r");
  /* teste para verificar se houve algum erro */
  if (fp1 == NULL) {
    printf("Erro na abertura do arquivo de leitura.\n");
    return 0; /* aborta programa ( retorna da funÃ§Ã£o main) */
  }

  /* abertura do arquivo para escrita */
  fp2 = fopen(nomew, "w");
  /* teste para verificar se houve algum erro */
  if (fp2 == NULL) {
    printf("Erro na abertura do arquivo de escrita.\n");
    return 0; /* aborta programa ( retorna da funÃ§Ã£o main) */
  }

  while (fscanf(fp1, "%s ", texto) == 1) {
    decript(texto,k);
    fprintf(fp2, "%s ", texto);    
  }
  /* fechamento do arquivo */
  fclose(fp1);
  fclose(fp2);

  return 1;

}


int main () {
  char nome_arquivo1[40], nome_arquivo2[40];
  int k;
  puts("valor de k: ");
  scanf("%d", &k);
  puts("Arquivo de leitura: ");
  scanf(" %30[^\n]", nome_arquivo1);
  puts("Arquivo de escrita: ");
  scanf(" %30[^\n]", nome_arquivo2);
  criptografa(nome_arquivo1, nome_arquivo2, k);
  return 0;
}