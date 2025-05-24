#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include <time.h>


#define TAMANHO_PALAVRA 50
#define TAMANHO_VETOR 50
#define TAMANHO_CATEGORIA 15

int i, j;

struct WordsDrist;

struct NO;

struct DistCategoria;

NO* mallocarNo(WordsDrist dado);

void liberarListaE(NO* chainees);


NO* motsCles(FILE* arq, int tamLinha);

int compararPalavras(const void* a, const void* b);



NO* ordemAlfabetica(NO* chainees);

void printarListEnq(NO* chainees);

 
float calcularNorma(float vetor[]);

int compararNorma(const void* a, const void* b);

NO* ordemNorma(NO* chainees);



NO* encontrarPalavraX(char* palavraX, NO* chainees);
float* wordNotIN();

char** palavrasDistanciaEuclidiana(NO* chainees, char* palavraX, float d);

char** palavrasDistanciaCosseno(NO* chainees, char* palavraX, float d);




char** categorizaWords(NO* chainees, char *categoria, int* tamCategoria);

char** mallocarMAT(int m, int n);

void printarMAT(char** vet, char* categoria, int tamanho);

void freeMAT(char** vet, int tamanho);



char* categoriaPrevalecente(NO* chainees, char* palavraX, int k);

int compararDistancia(const void* a, const void* b);



char*** agrupamentosVizinhos(NO* chainees, int m, int k) ;