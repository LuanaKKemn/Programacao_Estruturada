/*Escreva um programa que lÃª em um arquivo texto os dados da populaÃ§Ã£o de uma cidade,
considerando as seguintes caracterÃ­sticas: nome, gÃªnero, altura, peso, idade, cor dos olhos e
grau de escolaridade. Cada linha do arquivo contÃ©m uma sequÃªncia com os dados de cada
habitante. Seu programa deve informar a mÃ©dia das idades e das alturas das pessoas; a
porcentagem de pessoas com idade maior que a mÃ©dia e a quantidade de mulheres de olhos
verdes com mais de 50 anos.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparar_string(char* str1, char* str2){
  int i;
  for (i = 0; str1[i] != '\0'; i++)
    if (str1[i] != str2[i])
      return 0;
  if (str2[i] != '\0')
    return 0;
  return 1;
}

int stats_cidade(char* nome_arquivo){
  FILE *fp = fopen(nome_arquivo, "r");
  if (fp == NULL) {
    printf("Erro na abertura do arquivo de leitura.\n");
    exit(1); /* aborta programa ( retorna da funÃ§Ã£o main) */
  }
  char nome[10], genero[10], olhos[10], esc[20];
  float altura, peso, media_idades, media_alturas, idades[100];
  int idade, total = 0, qtd_m_v = 0;

   while (fscanf(fp, "%s%s%f%f%d%s%s", nome,genero,&altura,&peso,&idade,olhos,esc) == 7) {
    idades[total] = idade;
    total ++;
    media_alturas += altura;
    media_idades += idade;
    if (comparar_string(genero, "mulher") && idade > 50 && comparar_string(olhos,"verdes"))
      qtd_m_v ++;
   }
  printf("MÃ©dia das alturas: %.2f\n", media_alturas/total);
  printf("MÃ©dia das idades: %.2f\n", media_idades/total);
  printf("Mulheres de olhos verdes com mais de 50 anos: %d\n", qtd_m_v);
  float perc_maior_media = 0;
  for (int i = 0; i < total; i++){
    if (idades[i] > media_idades/total)
      perc_maior_media ++;
  }
  printf("Porcentagem de pessoas com idade maior que a mÃ©dia: %.2f\n", perc_maior_media/total);


  fclose(fp);
}

int main(){
  char* nome_arquivo = "arquivos/cidade.txt";
  stats_cidade(nome_arquivo);
  return 1;
}