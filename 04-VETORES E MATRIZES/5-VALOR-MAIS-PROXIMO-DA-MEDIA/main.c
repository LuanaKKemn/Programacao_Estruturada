#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
  Faça uma função que recebe um vetor de reais e retorna o valor mais 
  próximo da média. 
  Exemplo: supondo vetor = {2.5, 7.5, 10.0, 4.0}
  (média = 6.0 (não deve ser impresso))
  - Valor mais próximo da média = 7.5 
*/

double proximo_media();

int main(void) {
  double vet[] = {2.5, 7.5, 10.0, 4.0};
  double media = 0;

  // ENTRADA 

  
  // PROCESSAMENTO
  double proximo = proximo_media(vet, media);
  
  
  // SAIDA
  printf("Valor mais próximo da média = %.2f", proximo);

  

    return 0;
}

double proximo_media(double vetor, double *media){
  // MEDIA VETOR
  for (int i=0; i<(sizeof(vetor)); i++){
    *media += vetor[i];
  }
  *media /= sizeof(vetor);

  double *menor = (double*) malloc (sizeof(double)*1);
  for (int i=0; i<(sizeof(vetor)); i++){
     
      if ((vetor[i] - media) < 0){
        
      }
    
    
  }

}