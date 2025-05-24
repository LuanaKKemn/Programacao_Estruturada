#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include <time.h>


#define TAMANHO_PALAVRA 50
#define TAMANHO_VETOR 50
#define TAMANHO_CATEGORIA 20

int i, j;

struct WordsDrist;

struct NO;

char* ExtraiPalavra(FILE* arq, int linha, int tamLinha);

float* extraiVetor(FILE* arq, int linha, int tamLinha);


char** defineCategorias(FILE* arq, int linha, int tamLinha);

char* tamanhoWord(char* palavra);

char* primeiraLetra(char* palavra);

char* contemLetras(char* palavra);

char* ultimaLetra(char* palavra);



WordsDrist* atribuir(FILE* arq, int linha, int tamLinha);


int compararLexamente(WordsDrist* first, WordsDrist* second);

int compararVet(WordsDrist* first, WordsDrist* second);

float distanciaEuclidiana(WordsDrist* first, WordsDrist* second);

float distanciaCossenos(WordsDrist* first, WordsDrist* second);
