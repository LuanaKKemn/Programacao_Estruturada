#include <stdio.h>

int main() {
  float salario;
  printf("Qual o valor do seu salário bruto?\n");
  scanf("%f", &salario);

  if (salario <= 1499.14){
    printf("Isento\n");
  } else if (salario >= 1499.14 && salario <= 2246.75){
    printf("%.2f\n", 0.075 * salario);
  } else if (salario >= 2246.76 && salario <= 2995.70){
    printf("%.2f\n", 0.15 * salario);
  } else if (salario >= 2995.71 && salario <= 3743.19){
    printf("%.2f\n", 0.225 * salario);
  } else
    printf("%.2f\n", 0.275 * salario);

  return 0;
}