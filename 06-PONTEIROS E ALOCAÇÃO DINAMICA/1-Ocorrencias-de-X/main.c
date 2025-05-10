#include <stdio.h>
#include <stdlib.h>

//Ler o conteúdo de um endereço de memória, a partir do endereço: *
/*

  Elabore um programa em C que preencha um vetor com N valores inteiros. Após, o 
  programa deverá ler um número qualquer X. O programa deverá buscar no vetor as 
  ocorrências de X, armazenando em um vetor de saída os endereços na memória, 
  nos quais X aparecem no vetor.

*/

void ler_vetor(int n, int vetor[n]);

void escrever_vetor(int n, int vetor[n]);

void procurar_elemento(int *vetor, int *vetorEnderecos, int x, int n, int *j);

void escrever_ends(int *vetorEnderecos, int *j);



int main(void) {
  int n, x;
  int j=0;
  int *vetor;
  int *vetorEnderecos;

  // ENTRADAS
  printf("Digite n: ");
  scanf("%d", &n);


  vetor = (int*) malloc(n*sizeof(int));
  vetorEnderecos = (int*) malloc (n* sizeof(int));

  
  ler_vetor(n, vetor);
  escrever_vetor(n, vetor);

  printf("\nDigite x: ");
  scanf("%d", &x);
  
  // PROCESSAMENTO
  procurar_elemento(vetor, vetorEnderecos, x, n, &j);
  //printf("j = %d", j);

  // SAÍDAS
  escrever_ends(vetorEnderecos, &j);
  
  free(vetor);
  free(vetorEnderecos);
  return 0;
}



void ler_vetor(int n, int vetor[n]){
  for (int i=0; i<n ;i++){
    printf("\nDigite vetor[%d]: ", i);
    scanf("%d", &vetor[i]);
  }
}



void escrever_vetor(int n, int vetor[n]){
  printf("\nVetor = {");
  for (int i=0; i<n ;i++){
    if (i == n-1) {
      printf("%d}\n", vetor[i]);
    } else {
      printf("%d, ", vetor[i]);
    }
  }
}



void procurar_elemento(int *vetor, int *vetorEnderecos, int x, int n, int *j){
  for (int i=0; i < n; i ++){
    if (vetor[i] == x){
      vetorEnderecos[*j] = i;
      (*j)++;
    }
  }
}

void escrever_ends(int *vetorEnderecos, int *j){
  printf("\nVetorEndereços = {");
  for (int i=0; i<(*j); i++){
    if (i == (*j)-1) {
      printf("%d}\n", vetorEnderecos[i]);
    } else {
      printf("%d, ", vetorEnderecos[i]);
    }
  }

}

