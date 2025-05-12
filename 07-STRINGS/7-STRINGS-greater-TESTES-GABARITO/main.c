#include <stdio.h>



int tamanho5(char* palavra){
  int len = 0;
  for (int i = 0; palavra[i] != '\0'; i++)
    len++;
  return len;
}


void para_minuscula5(char* s1){
  for (int i = 0; s1[i] != '\0'; i++ )
    if (s1[i] >= 'A' && s1[i] <= 'Z')
      s1[i] = (s1[i] - 'A') + 'a';

}

int subseq(char* palavra, char chr){
  para_minuscula5(palavra);
  if (chr >= 'A' && chr <= 'Z')
      chr = (chr - 'A') + 'a';
  
  int tam = tamanho5(palavra);
  int pos_ini = 0, pos_fim = tam-1;
  
  for (int i = 0; palavra[i] != '\0'; i++){
    if (palavra[i] == chr){
      pos_ini = i+1;
    }

    if (palavra[tam-i-1] == chr){
      pos_fim = tam-i-2;
      break;
    }
  }
  if (pos_ini > 0){
    for (int i = pos_ini; i <=pos_fim; i++)
      printf("%c", palavra[i]);
    printf("\n");
  }
}



///////////////////////////////////////////////////

int main(){
  char palavra[80], chr;
  puts("digite o caracter");
  scanf("%c", &chr); 
  puts("digite a palavra");
  scanf(" %80[^\n]", palavra); 


  subseq(palavra, chr);
  return 1;
}