#include <stdio.h>
#include <stdlib.h>

// int main(void) {
//   int n, soma=0;
//   int i, j;
//   int valor;
//   int primo=0;

//   printf("Digite qunatidade de numeros: ");
//   scanf("%d", &n);

//   for (i=0; i>n; i++){
//     scanf("%d", &valor);

//     for (j=2; j<valor; j++){
//       if (valor==2) {primo=1;}
//       if (valor%i==0){break;}
//       if (valor%i!=0){primo+=1;}
//     }
    
//   }

  
//   return 0;

// }

// /*
//   3 - Escreva um programa que dados n números inteiros positivos, seja 
//   informada a soma dos números que são primos.
// */
int eh_primo(int n);

int main(void){
  
  // Entrada de dados
  int n, *vet;
  int soma=0;
  
  printf("Digite quantidade de numeros: ");
  scanf("%d", &n);
  vet = (int *) malloc(sizeof(int) * n);

  for (int i=0; i<n; i++){
    scanf(" %d", &vet[i]);
    if (eh_primo(vet[i])){
     soma += vet[i]; 
    }
  }
  
  // Processamento
  // Varre o vetor
    // Descobre se o elemento é primo
    // Se for primo soma se nao nao soma
  
  // Saída de dados
  printf("%d", soma);

  return 0;
}

int eh_primo(int v){
  if (v==1){return 0;}
  for (int i=2; i<v; i++){
    if (v%i == 0) {
      return 0;
    } 
  }
  return 1;
}





