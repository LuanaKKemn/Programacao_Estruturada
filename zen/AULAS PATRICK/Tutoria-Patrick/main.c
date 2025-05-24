#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// int main(void)
// {
//    char frase[23]="Programacao Estruturada";
//    char *p;
//    p = frase;
//    p[8]='\0';
//    printf("%s\n", frase);
//    p = p + 3;
//    printf("%s\n",p);
//    printf("%lu\n",strlen(frase));
// }

// int main() {
//   int **matriz = (int **) malloc(3 * sizeof(int *));

//   if (matriz == NULL) {
//     printf("Falha na alocação de memória\n");
//     return 1;
//   }

//   for (int i = 0; i < 3; i++) {
//     matriz[i] = (int *) malloc(5 * sizeof(int));

//     if (matriz[i] == NULL) {
//       printf("Falha na alocação de memória\n");
//       return 1;
//     }

//     for (int j = 0; j < 5; j++) {
//       matriz[i][j] = i * 5 + j;
//     }
//   }
//   for (int i = 0; i < 3; i++) {
//     for (int j = 0; j < 5; j++) {
//       printf("%d ", matriz[i][j]);
//     }
//     printf("\n");
//   }
//   return 0;
// }

int *somaVetores(int *vetor1, int *vetor2, int tamanho) {
    int i;
    int *resultado;
    resultado = (int*) malloc(tamanho * sizeof(int));
    for(i=0;i<tamanho;i++)
        resultado[i] = vetor1[i] + vetor2[i];
    return resultado;
}

void somaVetoresRef(int *vetor1, int *vetor2, int tamanho, int *resultado) {
  for(int i=0;i<tamanho;i++)
    resultado[i] = vetor1[i] + vetor2[i];
}

int main(void){
  int vet1 [] = {1, 2, 3};
  int vet2 [] = {1, 2, 3};
  int tamanho = sizeof(vet1)/sizeof(int);

  int *resultado = (int*) malloc(tamanho * sizeof(int));


  //int *resultado=somaVetores(vet1, vet2, tamanho);
  somaVetoresRef(vet1, vet2, tamanho, resultado);

  for(int i = 0; i < tamanho; i++) {
    printf("%d ", resultado[i]);
  }
  
  return 0;
}