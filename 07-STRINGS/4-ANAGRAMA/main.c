#include <stdio.h>
#include <string.h>

/*
  Um anagrama é uma palavra que é feita a partir da transposição das letras de outra 
  palavra ou frase. Por exemplo, “Iracema” é um anagrama para “America”. Escreva um 
  programa que decida se uma string é um anagrama de outra string, ignorando espaços e 
  pontuações
*/


void removeEspacosePontuacao( char palavra[], char frase[]);

int anagrama(char *palavra1, char *palavra2);

int main(void) {
  char palavra1[81];
  char palavra2[81];

  // ENTRADA --> 2 PALAVRAS
  printf("Digite a primeira palavra: ");
  scanf("%s", palavra1);

  printf("Digite a segunda palavra: ");
  scanf("%s", palavra2);


  // PROCESSAMENTO
  int resultado = anagrama(palavra1, palavra2);


  // SAIDA
  printf("\n\nA palavra %s %s anagrama da palavra %s", palavra1, resultado == 1? "é": "não é", palavra2);
  
  
  return 0;
}



int anagrama(char *palavra1, char *palavra2){
  int aux_linhas = 0;
  
  for (int i=0; palavra1[i] != '\0'; i++){
    aux_linhas = 0;
    
    for (int j=0; palavra2[j] != '\0'; j++){
      if (palavra1[i] == palavra2[j]){
        printf("\nLetra %c", palavra1[i]);
        aux_linhas++;
      }
    }
    
    if (aux_linhas == 0){
      return 0; // 0 == NÃO É ANAGRAMA
    }
    
  }
  return 1;
}





// VER DEPOIS --> REMOVER PONTUAÇÃO
void removeEspacosePontuacao( char palavra[], char frase[]){
  int j=0;
  for (int i=0; palavra[i] != '\0'; i++){
    if (palavra[i] != ' ') {
      frase[j] = palavra[i];
      j++;
    }

  }printf("%s", frase);
}

