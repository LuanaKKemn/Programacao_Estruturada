#include <stdio.h>

/*
  Implemente um programa que gere uma versão criptografada de um arquivo texto trocando
  cada caractere de código ASCII 𝑗 pelo caractere de código ASCII 𝑗 + 𝑘, onde 𝑘 é um parâmetro
  especificado pelo usuário. Fique atento para não gerar códigos ASCII fora da faixa permitida.
  Em seguida, implemente outro programa que desfaça a criptografia. Evidente que se um
  arquivo texto for criptografado pelo primeiro programa e descriptografado pelo segundo, o
  resultado deverá ser idêntico à entrada original.
*/

// EOF --> final do arquivo

// PROTOTIPOS
void criptografar(int k, FILE *zafArq, FILE *arqCrip);
void descriptografar(int k, FILE *zafArq, FILE *arqCrip);
void printar_arquivo(FILE *arqCrip);

int main(void) {
  int k;
  FILE *zafArq;
  FILE *arqCrip;

  zafArq = fopen("secreto.txt", "r+");
  if (zafArq == NULL) {
    printf("Erro ao abrir o arquivo.");
    return 1;
  }

  arqCrip = fopen("cripto.txt", "w+");
  if (zafArq == NULL) {
    printf("Erro ao abrir o arquivo.");
    return 1;
  }

  // ENTRADA
  printf("Digite k: ");
  scanf("%d", &k);
  
  criptografar(k, zafArq, arqCrip);
  fseek(arqCrip, 0l, SEEK_SET);

  printf("Arquivo criptografado:\n");
  printar_arquivo(arqCrip);

  
  fseek(arqCrip, 0l, SEEK_SET);
  fseek(zafArq, 0l, SEEK_SET);

  descriptografar(k, zafArq, arqCrip);

  fseek(arqCrip, 0l, SEEK_SET);
  printf("\n\nArquivo descriptografado:\n");
  printar_arquivo(arqCrip);

  // SAÍDA
  

  fclose(zafArq);
  return 0;
}


void criptografar(int k, FILE *zafArq, FILE *arqCrip){
  char c;
  
  while(!feof(zafArq)){
      c = getc(zafArq)+k;
      putc(c, arqCrip);
  }
}

  
void descriptografar(int k, FILE *zafArq, FILE *arqCrip){
  char c;

  while(!feof(arqCrip)){
    
      c = getc(arqCrip)-k;
      if(c != EOF-k) {fseek(arqCrip, -1l, SEEK_CUR);}

      putc(c, arqCrip);
  }
}

  
void printar_arquivo(FILE *arqCrip){
    while (!feof(arqCrip)){
      printf("%c", getc(arqCrip) );
    }
}

