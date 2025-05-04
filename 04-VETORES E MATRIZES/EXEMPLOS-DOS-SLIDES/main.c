#include <stdio.h>
#include <stdlib.h>


// int main(void) {
//   int qtd, cont;
//   float soma = 0.0, media;
  
//   // descobrindo o tamanho do vetor
//   puts("Digite a quantidade de elementos a serem digitados: ");
//   scanf("%i", &qtd);
  
//   float valores[qtd]; // declaração do vetor, tamanho dele vem da variável
//   // lendo e armazenando os valores
//   for (cont = 0; cont < qtd; cont ++){
//   puts("Digite o próximo valor: ");
//   scanf("%f", &valores[cont]);
//   }
  
//   // cálculo da média
//   for (cont = 0; cont < qtd; cont ++)
//   soma += valores[cont];
//   media = soma / qtd;
//   printf("A média é: %.2f\n", media);

  
  
//   return 0;
// }


/////////////////////////////////////////////////////////////////////////////////////

/* Função para cálculo da média */
// float media (int n, float v[]) {
//   float s = 0.0;
//   for (int i = 0; i < n; i++)
//     s += v[i];
//   return s/n;
// }
// /* Função para cálculo da variância */
// float variancia (int n, float v[], float m) {
//   float s = 0.0;
//   for (int i = 0; i < n; i++)
//     s += (v[i] - m) * (v[i] - m);
//   return s/n;
// }

// int main ( ) {
//   int n;
  
//   printf("Digite a quantidade de dados que quer analisar: ");
//   scanf("%d", &n);
  
//   float v[n];
//   float med, var;
//   /* leitura dos valores */
//   for (int i = 0; i < n; i++ ){
//     printf("Vetor[%d]: ", i);
//     scanf("%f", &v[i]); // 
//   }
  
//   med = media(n,v);
//   var = variancia(n,v,med);
//   printf ( "Media = %f\nVariancia = %f \n", med, var);
//   return 0;
// }


/////////////////////////////////////////////////////////////////////////////////////

// void altera_vetor(int v[]){
//   printf("%d\n", v[0]);
//   v[0] = 10;
//    printf("%d\n", v[0]);
// }

// int main(){
//   int v[] = {1,2,3};
//   printf("%d\n", v[0]);
//   altera_vetor(v);
//   printf("%d\n", v[0]);
//   return 0;
// }


/////////////////////////////////////////////////////////////////////////////////////

// int main(){
//   int v[] = {1,2,3};
//   int len = sizeof(v);
//   printf("%d\n", len);
//   return 0;
// }



////////////////////////////////////////////////////////////////////////////////////

// int main(){
// int v[] = {1,2,3};
// int len = sizeof(v)/sizeof(v[0]);
//  printf("%d\n", len);
// return 0;
// }


///////////////////////////////////////////////////////////////////////////////////

// int tamanho_vetor(int v[]){
//   int len = sizeof(v)/sizeof(v[0]);
//   return len;
// }

// int main(){
//   int v[] = {1,2,3};
//   printf("%d\n", tamanho_vetor(v));
//   return 0;
// }


///////////////////////////////////////////////////////////////////////////////////

// void incr_vetor ( int n, int v[]) {
//   int i;
//   for (i = 0; i < n; i++)
//   v[i]++;
// }

// int main ( ) {
//   int a[ ] = {1, 3, 5};
//   incr_vetor(3, a);
//   printf("%d %d %d \n", a[0], a[1], a[2]);
//   return 0;
// }

////////////////////////////////////////////////////////////////////////////////////

// busca binária // --> TERMINAR DEPOIS

int busca_binaria (int elemento, int termos, int vetor[]) {
 int esquerda = -1, direita = termos;
  while (esquerda < direita-1) {
 int meio = (esquerda + direita)/2;
 if (vetor[meio] < elemento)
 esquerda = meio;
 else direita = meio;
 }
 if (vetor[direita] == elemento)
 return direita;
return -1;
}

int main(){
  
  
  busca_binaria(elemento, termos, *vetor);
}
