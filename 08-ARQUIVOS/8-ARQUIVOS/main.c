#include <stdio.h>

float media_notas(void) {
  int n = 0; // Inicialize n com 0
  float nota, soma = 0.0;
  FILE *fp ;

  // Abertura do arquivo para leitura
  fp = fopen("notas.txt", "r");
  // Teste para verificar se houve algum erro
  if (fp == NULL) {
    printf("Erro na abertura do arquivo.\n");
    return 1; // Aborta programa (retorna da função main)
  }

  // Leitura de cada nota e cálculo da soma
  while (fscanf(fp, "%f", &nota) == 1) {
    soma = soma + nota;
    n++; // Conta o número de notas lidas
  }

  // Fechamento do arquivo
  fclose(fp);

  // Verifica se há notas no arquivo para evitar divisão por zero
  if (n > 0) {
    // Cálculo da média e retorno
    return soma / n;
  } else {
    // Se não houver notas, retorna 0
    return 0;
  }
}

int main(void) {
  printf("Media = %.2f\n", media_notas());
  return 0;
}
