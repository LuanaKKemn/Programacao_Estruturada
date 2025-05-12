#include <stdio.h>
#include <string.h>


/*
  Escreva um programa que decide se duas string lidas são palíndromas mútuas, ou seja, 
  se uma igual a outra, se escrita de trás para frente. Exs. amor e roma
*/

int palindromas_mutuas(char *palavra1, char *palavra2);

int main(void) {
  char palavra1[81];
  char palavra2[81];


  // ENTRADA --> 2 PALAVRAS
  printf("Digite a primeira palavra: ");
  scanf("%s", palavra1);

  printf("Digite a segunda palavra: ");
  scanf("%s", palavra2);


  // PROCESSAMENTO --> QUANTIDADE DE LETRAS E PALINDROMISMO
  int resposta = palindromas_mutuas(palavra1, palavra2);


  // SAIDA

  printf("As palavras %s e %s %s palindromas mútuas", palavra1, palavra2, resposta == 0 ? "não são": "são"); 

  
  return 0;
}



int palindromas_mutuas(char *palavra1, char *palavra2){
  if (strlen(palavra1) != strlen(palavra2)){
    return 0; // 1 --> NÃO É PALINDORMA mútua
  }
  // SE NÃO ENTRAR NO PRIMEIRO RETURN É PQ AS PALAVRAS TEM A MESMA QUANTIDADE DE LETRAS
  for (int i=0; palavra1[i] != '\0'; i++){
    if (palavra1[i] != palavra2[(strlen(palavra1)-1-i)]){
      return 0;
    }
    return 1;
  }
  return 0; 
}