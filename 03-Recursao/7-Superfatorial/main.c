#include <stdio.h>

/*
  - O superfatorial de um número N é definida pelo produto dos N primeiros 
  fatoriais de N. Assim, o superfatorial de 4 é sf(4) = 1! * 2! * 3! * 4! = 288
  Faça uma função recursiva que receba um número inteiro positivo N e retorne 
  o superfatorial desse número
*/

int fatorial(int fat);

int superfatorial(int n, int fat, int *total);


int main(void) {
  int n;
  int total=1;

  // ENTRADA
  printf("Digite n: ");
  scanf("%d", &n);

  // PROCESSAMENTO
  int fat = n;
  int superfat = superfatorial(n, fat, &total);

  // SAÍDA
  printf("O superfatorial de %d é %d", n, superfat);
  
  
  
  return 0;
}


// FATORIAL RECURSIVO // 

//--> RECURCIVA VAI VOLTANDO ATE CHEGAR NUM VALOR MINIMO QUE RETORNA 1
//--> QND ISSO AOCNTECE ELA VOLTA MULTIPLICANDO TUDO E DA O RESULTADO
// SÓ PODE FAZER ISSO SE HOUVER UMA OPERAÇÃO NO RETURN

int fatorial(int fat){
  if (fat == 1) {return 1;}
  return fat*fatorial(fat-1);
}
// 5*(4*3*2*1)

// SUPER FATORIAL //

// --> GUARDA O RESULTADO EM UM PONTEIRO E VAI ACUMULANDO ELE
// --> QUANDO CHEGA NO CASO BASE ELE RETORNA O PONTEIRO COM O VALOR ACUMULADO


int superfatorial(int n, int fat, int *total){
    if (fat == 1) {return *total;}
    
    *total *= (fatorial(fat));
    
    return (superfatorial(n, fat-1, total));
  
}




