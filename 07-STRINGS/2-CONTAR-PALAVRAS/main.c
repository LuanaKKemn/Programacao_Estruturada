#include <stdio.h>

// Faça uma função que dada uma frase, retora o número de palavras da frase. Considere que a frase pode ter espaços no início e no final e que entre duas palavras você pode ter vários espaços.

// c = 0
// "  não    se  i  " 
// c += 1      c = 1
// c += 0      c = 1
// c += 0      c = 1

int contar_palavras(char *frase);

int main(void) {
  char frase[81];
  // ENTRADA
  printf("Digite a frase: ");
  scanf(" %80[^\n]", frase);
  // PROCESSAMENTO
  int resultado = contar_palavras(frase);
  // SAIDA
  printf("O número de palavras é %d", resultado);
  return 0;
}



int contar_palavras(char *frase){
  int c = 0;
  // SOMA 1 PARA O CASO DE COMEÇAR COM UMA PALAVRA NA PRIMEIRA POSIÇÃO
  if (frase[0] != ' ' && frase[0] != '\0'){  
    c++;
  }
  for (int i=0; frase[i] != '\0'; i++){

    if (frase[i] == ' ' && frase[i+1] != ' ' && frase[i+1] != '\0'){
      c++;
    }
  }
  
  return c;
}