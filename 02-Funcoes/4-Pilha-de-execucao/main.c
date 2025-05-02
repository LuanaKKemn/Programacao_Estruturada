#include <stdio.h>


/*
  Simule a execução do programa a seguir e desenhe sua pilha de execução, considerando a 
  entrada como 2, 5, 3.0, 2.0

  PRECISO DE UMA EXPLICAÇÃO

*/
  

float f1 (int x, int y) {
 float res;
 if (y != 0) 
res = (float) x / y;
 else 
res = (float) 1 / x;
 while (x > y) {
res = res + (float) y / x;
x = x - 1;
 }
 return(res);
}


int main() {
 int a, b;
 float c, d;
 puts("Digite quatro numeros.\n");
 scanf("%d %d %f %f", &a, &b, &c, &d);
 printf("a = %d b = %d c = %f d = %f\n", a, b, c, d);
 while (a < b) {
if (c > d) { 
 d = f1(b,a);
 b = b - 1;
}
else{
 c = 1 / f1(a,b);
 a = a + 1;
}
printf("a = %d b = %d c = %f d = %f\n", a, b, c, d);
 }
 return 0;
}
