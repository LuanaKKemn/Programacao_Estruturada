#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
  Faça uma função que recebe dois vetores e intercala os elementos de 
  ambos formando um terceiro vetor. O terceiro vetor deve começar do 
  primeiro elemento do menor vetor. O maior vetor deverá ter seus 
  elementos restantes repetidos no fim do vetor de resposta.
  Exemplo:
  intercalar_vetor([1,2,3,4], [10,20,30,40,50,15])
  [1,10,2,20,3,30,4,40,50,15
*/

int intercalaVets(int vet1, int vet2);

int main(void) {
  int vet1[] = {1,2,3,4}; 
  int vet2[] = {10,20,30,40,50,15};
  int soma =  ((sizeof(vet1)+(sizeof(vet2)
  int *vet3 = (int*) malloc ((sizeof(int))*soma);
  

  
  return 0;
}


int intercalaVets(int vet1, int vet2){
  
  if ((sizeof(vet1) > (sizeof(vet2)) {
    return intercalaVets(vet2, vet1);
  }
  int k = 0;
  for (int i=0; i<(sizeof(vet1); i++)){
    for (int j=0; j<(sizeof(vet2); j++)){
      vet3[k] = 
      k++;
      
  }


    
}