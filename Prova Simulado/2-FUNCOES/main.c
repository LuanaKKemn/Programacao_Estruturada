#include <stdio.h>
#include <math.h>

/*
  2. (3 pontos) Alguns n´umeros possuem uma propriedade interessante: se vocˆe recuperar seus dois
  primeiros d´ıgitos e seus dois ´ultimos d´ıgitos e elevar ao quadrado a soma deles, vocˆe obter´a
  a concatena¸c˜ao desses 4 d´ıgitos. Por exemplo, o n´umero 203125 possui essa propriedade, pois
  (20 + 25)2 = 2025. Por outro lado, o mesmo n˜ao ´e observado para 20326, pois (20 + 26)2 = 2116 6=
  2026. Escreva um programa que informa se um n´umero possui essa propriedade.
  
*/


// PROTOTIPOS

int contaDigitos(int num);

int acharprimeiros(int num, int digitos);

int concatenacao(int num, int digitos, int primeiros);


int main(void) {
  int num;

  printf("Digite num: ");
  scanf("%d", &num);

  int digitos = contaDigitos(num);
  printf("\nTESTE DIGITOS = %d\n", digitos);

  int primeiros = acharprimeiros(num, digitos);

  int resposta = concatenacao(num, digitos, primeiros);

  printf("\nO numero %d %s a propriedade.", num, (resposta == 1)? "possui" :"não possui");
  
  return 0;
}


int acharprimeiros(int num, int digitos){
  int p1, p2;

  p1 = num % (int) pow (10, (digitos-2));
  p2 = (num - p1)/(pow (10, (digitos-2)));
  
  printf("\nTESTE PRIMEIROS : %d\n", p2);
  
  return (p2);
}


int concatenacao(int num, int digitos, int primeiros){
  int ultimos = (num % 100);
  printf("\nTESTE ULTIMOS: %d\n", ultimos);  
  
  if (pow((ultimos+primeiros),2) == primeiros*100 + ultimos){
    return 1;
  }
  return 0;
}


int contaDigitos(int num){
  int cont = 1;
  while (num > 9){
    num = num/10;
    cont++;
  }
  return cont;
}




