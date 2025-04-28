#include <stdio.h>

int main(){
  int num, i, contador = 0;
  
  puts("Digite o numero: ");
  scanf("%d", &num);

  if (num < 1)
    printf("Nao eh um numero primo\n");
    
  if ((num == 1) | (num == 2))
    contador += 1;
    
  
  else if (num > 1)
    for (i=3; i<=num; i++){
      
      if (num % i == 0)
        contador += 1;
    }
    
  if ((contador == 1) && (num !=4))
    printf("Eh um numero primo\n");
  else
    printf("Nao eh um numero primo\n");

}