#include <stdio.h>

// Escreva um programa que lê em um arquivo texto os dados da população de uma cidade, considerando as seguintes características: nome, gênero, altura, peso, idade, cor dos olhos e grau de escolaridade. Cada linha do arquivo contém uma sequência com os dados de cada habitante. Seu programa deve informar a média das idades e das alturas das pessoas; 
// a porcentagem de pessoas com idade maior que a média 
// e a quantidade de mulheres de olhos verdes com mais de 50 anos.


void medias(float *media_idades, float *media_alturas, int quantidade);

float porcentagemIdadeMMedia();

int mulheresOlhosVerdes();



int main(void) {

  // Abrir arquivo
  FILE *arquivo = fopen("teste.txt", "r");
  if (arquivo ==NULL){
    printf("Não foi possivel abrir o arquivo");
    return 1;
  }
  
  float media_idades=0, media_alturas=0;

  int acumulador = 0;

  int quantidade=0;
  // CAHAR A QUANTIDADE TOTAL DE PESSOAS NO ARQUIVO
  //for (int i=0; ..., i++){}

  
  char frase[100], *flag;
  
  do{
    char nome[2];
    char sexo;
    fscanf(arquivo, "%s %c", nome, &sexo);
    flag = fgets(frase, 100, arquivo);
    printf("%s - %c\n", nome, sexo);
  } while(flag != NULL);
  
  // Fecha o arquivo
  fclose(arquivo);
  
  
  return 0;
}

void medias(float *media_idades, float *media_alturas, int quantidade){

  // COMO EU PEGO OS VALORES DAS IDADES E SOMO NAS VARIÁVEIS??
  

  *media_idades /= quantidade;
  *media_alturas /= quantidade;
}



float porcentagemIdadeMMedia(float *media_idades, int quantidade){
  int cont=0;

  //for (int i = 0; ...; i++){}

  cont ++;

  // FAZER A PORCENTAGEM
  float porcentagem = (cont/quantidade) * 100;


  return porcentagem;
}




int mulheresOlhosVerdes(){
  int verdes=0;
  // if MULHER
  // IF "verdes"
    // verdes++;


  return verdes;
}