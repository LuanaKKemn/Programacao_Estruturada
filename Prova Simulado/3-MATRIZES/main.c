#include <stdio.h>
#include <stdlib.h>


void mallocar(int ***matriz, int n);

void liberarMatriz(int **matriz, int n);

void leiamatriz(int n, int **matriz);

void printarMatriz(int **matriz, int n);

void matriztrasposta(int **matriz, int **matrizTrasposta, int n);

void matrizIdentidade(int **matriz, int n);

void ortogonal(int **matOrtogonal, int **matriz, int **matrizTrasposta, int **matrizId, int n);

int verificaOrtogonalidade(int **matOrtonal, int n);



int main(void) {
  int n;

  printf("Digite n: ");
  scanf("%d", &n);

  int **matriz;
  int **matrizTransposta;
  int **matrizId;

  int **matOrtogonal;

  mallocar(&matriz, n);
  mallocar(&matrizTransposta, n);
  mallocar(&matrizId, n);
  
  mallocar(&matOrtogonal, n);

  
  leiamatriz(n, matriz);
  
  matriztrasposta(matriz, matrizTransposta, n);
  matrizIdentidade(matrizId, n);
  ortogonal(matOrtogonal, matriz, matrizTransposta, matrizId, n);


  printf("\nMatriz:\n");
  printarMatriz(matriz, n);

  printf("\nMatriz Transposta:\n");
  printarMatriz(matrizTransposta, n);

  printf("\nMatriz Identidade:\n");
  printarMatriz(matrizId, n);

  printf("\nTentativa de Matriz Ortogonal:\n");
  printarMatriz(matOrtogonal, n);

  int resposta = verificaOrtogonalidade(matOrtogonal, n);

  printf("\nA matriz %s ortogonal", (resposta==1)? "é":"não é");

  liberarMatriz(matriz, n);
  liberarMatriz(matrizTransposta, n);
  liberarMatriz(matrizId, n);
  liberarMatriz(matOrtogonal, n);
  
  return 0;
}

////////////////////////////////////////////////////////////

// FUNÇÕES // 

// ENTRADAS DE MATRIZES //

void mallocar(int ***matriz, int n){
  *matriz = (int **) malloc(n*sizeof(int*));
  if (*matriz==NULL){
    printf("Espaço insuficiente.");
    exit(1);
    }
  // ALOCAR LINHAS
  for (int i=0; i<n; i++){
    (*matriz)[i] = (int*) malloc (n* sizeof(int));
    if ((*matriz)[i]==NULL){
      printf("Espaço insuficiente.");
      exit(1);
    }
  }
}


void leiamatriz(int n, int **matriz){
  for (int i=0; i < n; i++){
    for (int j=0; j < n; j++){
      printf("Digite matriz[%d][%d]:", i, j);
      scanf("%d", &matriz[i][j]);
    }
  }
}

void printarMatriz(int **matriz, int n){
  printf("{{");
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      if (j == n-1){
        printf("%d}", matriz[i][j]);
      } else{
        printf("%d, ", matriz[i][j]);
      }
    }if (i != n-1) {printf("\n {");}
  }printf("}\n");
}


// MATRIZES DO PROBLEMA DO PROGRAMA // 

void matriztrasposta(int **matriz, int **matrizTrasposta, int n){
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      matrizTrasposta[j][i] = matriz[i][j];
    }
  }
}

void matrizIdentidade(int **matriz, int n){
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      if (i==j){
        matriz[i][j] = 1;
      } else {
        matriz[i][j] = 0;
      }
    }
  }
}

void ortogonal(int **matOrtogonal, int **matriz, int **matrizTrasposta, int **matrizId, int n){
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      int soma=0;
      for (int k=0; k<n; k++){
        soma += matriz[i][k] * matrizTrasposta[k][j];
      }
      matOrtogonal[i][j] = soma;
    }
  }
}

int verificaOrtogonalidade(int **matOrtonal, int n){
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      if ( i == j && matOrtonal[i][j] != 1){
        return 0;
      } else if (i != j && matOrtonal[i][j] != 0){
        return 0;
      }
    }
  }
  return 1;
}



void liberarMatriz(int **matriz, int n){
  for (int i=0; i < n; i++){
    free(matriz[i]);
  }
  free(matriz);
}