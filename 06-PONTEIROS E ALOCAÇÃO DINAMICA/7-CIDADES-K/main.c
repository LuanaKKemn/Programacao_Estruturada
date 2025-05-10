#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*
  Considere n cidades numeradas de 0 a n-1 que estão interligadas por uma série de estradas de mão única. 
  As ligações entre as cidades são representadas pelos elementos de uma matriz quadrada L nxn, cujos elementos l ij assumem o valor 1 ou 0, conforme exista ou não estrada direta que saia da cidade i e chegue à cidade j. 
  Assim, os elementos da linha i indicam as estradas que saem da cidade i, e os elementos da coluna j indicam as estradas que chegam à cidade j. Por convenção l ii = 1.
  (a) Dado k, determinar quantas estradas saem e quantas chegam à cidade k.
  (b) A qual das cidades chega o maior número de estradas?
  (c) Dado k, verificar se todas as ligações diretas entre a cidade k e outras são de mão dupla.
  (d) Relacionar as cidades que possuem saídas diretas para a cidade k.
  (e) Relacionar, se existirem:
  i. As cidades isoladas, isto é, as que não têm ligação com nenhuma outra; 
  ii. As cidades das quais não há saída, apesar de haver entrada; 
  iii. As cidades das quais há saída sem haver entrada. 
  (f) Dada uma seqüência de m inteiros cujos valores estão entre 0 e n-1, verificar se é possível
  realizar o roteiro correspondente. No exemplo dado, o roteiro representado pela seqüência (m=5)
  2 3 2 1 0 é impossível.
  (g) Dados k e p, determinar se é possível ir da cidade k para a cidade p pelas estradas 
  existentes. Você consegue encontrar o menor caminho entre as duas cidades?
*/


void cidades_isoladas(int **matriz, int n);

int main(void) {
  int n=4;
  // 0 --> NÃO EXISTE ESTRADA QUE SAI DA CIDADE
  // 1 -->     EXISTE ESTRADA QUE SAI DA CIDADE
  int matriz[][] = {{0, 1, 1, 1}, {0, 1, 0, 0}, {1, 0, 1, 1}, {0, 0, 1, 1}};

  
  
  
  
  
  
  
  return 0;
}

void cidades_isoladas(int **matriz, int n){
  
}