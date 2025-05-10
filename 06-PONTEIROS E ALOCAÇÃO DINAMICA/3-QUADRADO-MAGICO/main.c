#include <stdio.h>
#include <stdlib.h>

/*
Escreva uma função que descobre se uma matriz representa um quadrado mágico, 
usando ponteiros

// RASCUNHOS // 

// 0 - 3 i j --> i = somaDiagonalSecundaria += matriz[i][n - 1 - i];
// 1 - 2     --> j == n - 1 - i
// 2 - 1     --> i == n - 1 - j
// aaaaaaaaaaaaa

*/

void escrever_matriz(int q, int **quadrado);

// PRINTAR MATRIZ //
void printarMatriz(int **matriz, int n);

void preenche_soma(int q, int **quadrado, int *soma);

void printaVetor(int *vetor, int n);

int isMagic(int *soma, int q, int i);


int main(void) {
  int q;

  // ENTRADAS
  printf("Digite o lado do quadrado: ");
  scanf("%d", &q);

  int **quadrado;
  quadrado = (int**) malloc(q*sizeof(int));
  for (int i=0; i<q; i++){
    quadrado[i] = (int*) malloc (q * sizeof(int)); // ALOCAR CADA LINHA DA MATRIZ
  }
  
  escrever_matriz(q, quadrado);
  printarMatriz(quadrado, q);

  
  // PROCESSAMENTO
  
  int *soma;
  soma = (int*) malloc ((q*2+2)*sizeof(int));
  void criaVetor(int q, int *soma);

  
    
  int resposta = isMagic(soma, q, 0);


  // SAIDA
  printf("%s um quadrado mágico", resposta? "É" : "Não é");
  
  free(soma);
  free(quadrado);
  return 0;
}


// FUNÇÕES // 


// CRIAR MATRIZ // 

void escrever_matriz(int q, int **quadrado){
  for (int i=0; i<q; i++){
    for (int j=0; j < q; j++){
      //*quadradoMat[i][j] = 1; 
      printf("Digite o valor para quadrado[%d][%d]: ", i, j);
      scanf("%d", &quadrado[i][j]);
    }
  }
}

// PRINTAR MATRIZ //
void printarMatriz(int **matriz, int n){
  printf("\nMatriz:\n{{");
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


// CRIAR VETOR // 

void criaVetor(int q, int *soma){
  for (int i=0; i<(2*q+2); i++){
    soma[i] = 0;
  }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////

// PREEENCHER VETOR SOMA //
// SOMA DE CADA LINHA == SOMA DE CADA COLUNA == SOMA DA DIAGINAL PRINCIPAL == SOMA DIAGONAL SECUNDARIA

void preenche_soma(int q, int **quadrado, int *soma){
  int k = 0;
  for (int i=0; i<q; i++){
    for (int j=0; j<q; j++){
      soma[k] += quadrado[i][j]; // soma as linhas 
      if (i==j) {
        soma[-1] += quadrado[i][j]; // SOMA NA DIAGONAL PRINCIPAL (ULTIMA DO VETOR)
      }
      if (j == q - 1 - i){
        soma[-2] += quadrado[i][j]; // SOMA NA SECUNDARIA PRINCIPAL (PEN-ULTIMA DO VETOR)
      }
      // COLUNAS --> i muda - j nao muda
      if (j == k){
        soma[-3-k] += quadrado[i][j];
      }
    }
    k++;
  }
}

void printaVetor(int *vetor, int n){
  for (int i=0; i<n; i++){
    printf("%d, ", &vetor);

}

///////////////////////////////////////////////////////////////////////////////////////////////
// TA DANDO ERRADO O CALCULO // 
int isMagic(int *soma, int q, int i){
  if (i == (2*q+2)-1) {
    return 1;
  } // vai ate a penultima interação e compara com a seguinte
  if (soma[i] == soma[i+1]){ 
    return isMagic(soma, q, i+1);
  } else {
      return 0;
  }
}
