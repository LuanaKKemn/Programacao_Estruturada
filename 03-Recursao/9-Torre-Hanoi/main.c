#include <stdio.h>
#include <stdlib.h>

/*
  -Implementar a torre de Hanoi: Tabuleiro com 3 pinos no qual são encaixados 
  discos de tamanho decrescente. A idéia é mover os discos de um pino para 
  outro sendo que:
  Só um disco é movimentado por vez
  Um disco maior nunca pode ser posto sobre um meno

*/

void hanoi(int discos);

void mallocar_a_poha_toda(int discos, int ***torre_mat);


int main(void) {
  int torres = 3;
  int discos;
  // ENTRADA
  printf("Digite a quantidade de discos: ");
  scanf("%d", &discos);

  int **torre_mat;

  

  printf("\nTodos os discos então na Torre 1\nEm ordem crescente de tamanho\nCom o maior em baixo e o menor em cima\n");
  printf("\n");

  // PROCESSAMENTO
  hanoi(discos);

  // SAÍDA
  
  return 0;
}


// SABER QUAL TORRE IRA MOVER O DISCO --> SABER SE É POSSÍVEL MOVER
// SABER PARA QUAL TORRE QUER COLOCAR O DISCO --> SABER SE PODE

void hanoi(int discos){
  int escolha;
  printf("De qual torre você quer remover um disco?");
  scanf("%d", &escolha);


  
}

// CRIAR UMA MATRIZ QUE GUARDA A POSIÇÃO DE CADA DISCO
void mallocar_a_poha_toda(int discos, int ***torre_mat){
  **torre_mat = (int**) malloc (3*sizeof(int));
  for (int i=0; i<discos; i++){
    torre_mat[i] = (int*) malloc ()
  }
}