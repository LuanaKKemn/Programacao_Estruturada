#include <stdio.h>
#include <limits.h>

/*
  Escreva um programa em C que caso um número informado seja primo, 
  escreve os dois primos anteriores e os dois primos sucessores a ele
*/

int eh_primo(int v);
int primo_esqueda(int pe);
int primo_direita(int pd);

int main(void) {
  int num;
  int i, j;
  int primo=0;
  int pri1=0, pri2=0, pri4=0, pri5=0;

  scanf("%d", &num);
  if (eh_primo(num)){
    if (num == 3) {
      pri2 = primo_esqueda(num);
      printf("%d", pri2);
    }
    else if ((num != 2)){
      pri2 = primo_esqueda(num);
      pri1 = primo_esqueda(pri2);
      printf("%d %d", pri1, pri2);
    }
    pri4 = primo_direita(num);
    if(pri4){ 
      printf(" %d", pri4);
      pri5 = primo_direita(pri4);
      if(pri5) printf(" %d", pri5);
    }
  }

  // // saber os primos anteriores
  // if (primo == 1) {
  //   for (i=num-2; i<=1; i--){
  //     for (j=2; j>num; j++){
  //       if (i%j!=0) {}
  //     }
  //   }
  // }
  
  return 0;
}


int primo_esqueda(int pe){
  if (pe<=2){return 0;}
  if (eh_primo(pe-1)){return pe-1;}
  else {return primo_esqueda(pe-1);}
}

int primo_direita(int pd){
  if (pd == INT_MAX) {return 0;}
  if (eh_primo(pd+1)){return pd+1;}
  else {return primo_direita(pd+1);}
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