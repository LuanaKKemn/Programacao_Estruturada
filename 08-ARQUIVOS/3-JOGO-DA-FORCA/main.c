#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Desenvolva um jogo da forca. O programa terá uma lista de palavras lidas de um arquivo texto (palavras.txt) e escolherá uma palavra aleatoriamente. Seu programa deve ler as palavras do arquivo e colocá-las em um vetor. Após, ele deve sortear uma posição válida da lista e obter a palavra. O jogador poderá errar 6 vezes antes de ser enforcado.

int completo(char *string, int n);
int letra_ta_na_palavra(char *string, char c, int n);
void alterar_posicoes(char *palavra, char *posicoes, char c, int n);

int main(void) {

  // ENTRADA

  // Abrir o arquivo
  FILE *f = fopen("palavras.txt", "r");

  // Contar as linhas do arquivo
  int n = 0;
  char *palavra = (char *) malloc(50 * sizeof(char));
  while(fgets(palavra, 50, f) != NULL){
    n++;
  }
  
  // Varre as linhas até o final
  fclose(f);
  f = fopen("palavras.txt", "r");
  char **vetor = (char **) malloc(n * sizeof(char *));
  int i = 0;
  while(fgets(palavra, 50, f) != NULL){
    vetor[i] = palavra;
    palavra = (char *) malloc(50 * sizeof(char));
    i++;
  }
  
  // Sorteia a linha que queremos
  i = rand() % n;
  char *palavra_sorteada = vetor[i];

  // Fecha o arquivo
  fclose(f);

  // PROCESSAMENTO
  int vidas = 6;
  
  // Cria o vetor de posições (letras acertadas)
  int num_letras = strlen(palavra_sorteada);
  char *posicoes = (char *) malloc(sizeof(char) * num_letras);
  for(i=0; i<num_letras; i++) posicoes[i] = '_';

  // Letras chutadas
  char *chutadas = (char *) malloc(sizeof(char) * 26);
  int i_chutadas = 0;

  int cond_parada = 0;

  while(cond_parada == 0){
    // Chute
    printf("-------------------------------------------------------\n");
    printf("Você tem %d vidas\n", vidas);
    printf("Letras já acertadas: ");
    for(i = 0; i<num_letras; i++) printf("%c ", posicoes[i]);
    printf("\nFoi chutado:\n| ");
    for(i = 0; i<i_chutadas; i++) printf("%c | ", chutadas[i]);
  
    printf("\nDigite seu chute: ");
    char c;
    scanf(" %c", &c);
  
    // Verificar se a letra tá na palavra
    if(letra_ta_na_palavra(palavra_sorteada, c, num_letras)){
  
      // Se tiver na palavra
      // Mostra as posições que a letra aparece
      alterar_posicoes(palavra_sorteada, posicoes, c, num_letras);

      // Condição de vitória
      if(completo(posicoes, num_letras)) cond_parada = 1;
      
    } else{
      
      // Se não
      // Perde uma vida
      vidas--;

      // Condição de derrota
      if(vidas == 0) cond_parada = -1;
    }

    // Adiciona na lista de letras que já foram chutadas
    chutadas[i_chutadas] = c;
    i_chutadas++;
    
  }
  
  return 0;
}


int letra_ta_na_palavra(char *string, char c, int n){
  for(int i=0; i<n; i++){
    printf("\n%c\n", string[i]);
    if(string[i] == c) return 1;
  }
  return 0;
}
int completo(char *string, int n){
  if(letra_ta_na_palavra(string, '_', n)) return 0;
  return 1;
}
void alterar_posicoes(char *palavra, char *posicoes, char c, int n){
  for(int i=0; i<n; i++)
    if(palavra[i] == c)
        posicoes[i] = c;
}