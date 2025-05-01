# include <stdio.h>
# include <stdlib.h>
# include <math.h>

/*
  - Sabe-se que um número da forma n^3 é igual a soma de n ímpares consecutivos. 
  Por exemplo: 1^3= 1, 2^3= 3+5, 3^3= 7+9+11, 4^3= 13+15+17+19,... 
  Escreva um programa que, dado um número m, 
  sejam informados os ímpares consecutivos cuja soma é igual a n^3 para n assumindo valores de 1 a m. 
  No exemplo acima, m = 4.
*/

// NÃO ENTENDI COMO FAZ
int *achar_impares(int n, int *vet);

int main(void) {
  
  // Entrada de dados
  int m;
  printf("Digite m: ");
  scanf("%d", &m);
  
  // Processamento
  for(int n=1; n < m+1; n++){

    // Achar impares
    int *vet = (int *) malloc(sizeof(int) * n);
    vet = achar_impares(n, vet);
    
    // Saída de dados

    // Printa os impares
    printf("%d³ = ", n);
    printf("%d", vet[0]);
    for(int i=1; i<n; i++) printf(" + %d", vet[i]);
    printf("\n\n");
  }
  
  return 0;
}

int *achar_impares(int n, int *vet){

  // Define os impares inicias
  for(int i=0; i<n; i++) vet[i] = 1 + i * 2;

  // Definindo as variáveis necessárias
  int cubo = n * n * n, soma = 0;

  // Calcula a soma
  for(int i=0; i<n; i++) soma += vet[i];

  // Enquanto a soma for diferente do cubo
  while(soma != cubo){

    // Vai pro pŕoximo impar
    for(int i=1; i<n; i++) vet[i-1] = vet[i];
    vet[n-1] = vet[n-2] + 2;

    // Atualizar a soma
    soma += (vet[n-1] - vet[0]) + 2; 
  }

  // Retorna o vetor correto
  return vet;
}




// int m;
// int n; 
// int i, j;


// int valorbase;

// int x;
// int calc;

// scanf("%d", &m);

// int matriz[m];


// int resultado;
// resultado = m^3;

// valorbase = (resultado/m); // 16 (media)


// if (m%2==0) { //4
//   calc = m/2; //2
//   x = calc-1;
//   matriz[x] = valorbase-1;
//   matriz[calc] = valorbase+1;
//   while (x>=1){
//     x -=1;
//     matriz[x] = matriz[x+1] - 2;
//   }
//   while (calc<m){
//     calc +=1;
//     matriz[calc] = matriz[calc-1] + 2;
//   }
// }

//   if (m%2!=0){
//     int calc = m/2;
//     x = calc +1;
//     matriz[x] = valorbase; 

//     while (x>=1){
//       x--;
//       matriz[x] = matriz[x+1] - 2;
//     }
//     while (x<m){
//       x++;
//       matriz[x]= matriz[x-1]+2;
//     }

//   }

// printf("%d", *matriz);