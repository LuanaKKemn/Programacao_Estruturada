#include <stdio.h>

void impostodeRenda(float salario){
  float desconto=0;
  if (salario <= 1499.14){
      printf("Isento\n");
  } else if (salario >= 1499.15 && salario <= 2246.75) {
    desconto = (salario*0.075)-112.43;
  } else if (salario >= 2246.76 && salario <= 2995.70) {
    desconto =  (salario*0.15)-280.94;
  } else if (salario >= 2995.71 && salario <= 3743.19) {
    desconto = (salario*0.225)-505.62;
  } else if (salario > 3743.19){
    desconto = (salario*0.275)-692.78;
  }
  printf("Salário líquido: R$ %.2f\nDesconto: R$ %.2f\n", salario-desconto, desconto);
}

int main(){
  float salario;
  printf("Digite o salario: ");
  scanf("%f", &salario);
  impostodeRenda(salario);
  return 1;
}