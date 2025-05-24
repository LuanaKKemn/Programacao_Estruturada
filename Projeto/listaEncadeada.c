#include "wordsDistrib.h"
#include "listaEncadeada.h"

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

/*

  CCC      H   H     A    IIIII   N   N  EEEEE  EEEEE   SSSS 
 C   C     H   H    A A     I     NN  N  E      E       S
C          HHHHH   AAAAA    I     N N N  EEEEE  EEEEE    SSS 
C          H   H   A   A    I     N  NN  E      E          S
 C   C     H   H   A   A  IIIII   N   N  EEEEE  EEEEE  SSSS     
  CCC 

*/

// TAD PALAVRA E SEMANTICA DISTRIBUCIONAL // 
typedef struct WordsDrist{
  char palavra[TAMANHO_PALAVRA];
  float vetSD[TAMANHO_VETOR];
  char categoria[4][TAMANHO_CATEGORIA];
} WordsDrist;

// LISTA ENCADEADA DO TAD // 
typedef struct NO{
  WordsDrist dado;
  struct NO *ant;
  struct NO *prox;
} NO;

typedef struct DistCategoria{
    float distancia;
    char categoria[TAMANHO_CATEGORIA];
} DistCategoria;

// ALOCAÇÃO LISTA ENCADEADA // 
NO* mallocarNo(WordsDrist dado){
  NO* chainees = (NO*) malloc(sizeof(NO));

  if (chainees){
    chainees->dado = dado;
    chainees->prox = NULL;
    chainees->ant = NULL;
  }
  return chainees;
}

// LIBERAÇÃO LISTA //
void liberarListaE(NO* chainees){
  NO* atual = chainees;
  NO* seguinte;

  while (atual){
    seguinte = atual->prox;
    free(atual);
    atual = seguinte;
  }
}

// CRIAR LISTA DE PALAVRAS COM NOME E VETOR //
NO* motsCles(FILE* arq, int tamLinha) {
    int linha = 1;
    NO* new = NULL;
    NO* atual = NULL;

    while (linha <= tamLinha) {
        WordsDrist* wordAtual = atribuir(arq, linha, tamLinha);
        if (wordAtual == NULL) {
            break;
        }

        NO* novoNo = mallocarNo(*wordAtual);
        free(wordAtual); 

        if (new == NULL) {
            new = novoNo;
            atual = novoNo;
        } else {
            atual->prox = novoNo;
            novoNo->ant = atual;
            atual = novoNo;
        }
        linha++;
    }

    return new;
}


int compararPalavras(const void* a, const void* b) {
    WordsDrist* wordA = *(WordsDrist**)a;
    WordsDrist* wordB = *(WordsDrist**)b;
    return strcmp(wordA->palavra, wordB->palavra);
}

// RETORNAR PALAVRAS DA LISTA ORDENADAS ALFABETICAMENTE //
NO* ordemAlfabetica(NO* chainees) {
    if (!chainees) return NULL;

    int tamanho = 0;
    NO* temp = chainees;
    while (temp) {
        tamanho++;
        temp = temp->prox;
    }

    WordsDrist** array = malloc(tamanho * sizeof(WordsDrist*));
    temp = chainees;
    for (int i = 0; i < tamanho; i++) {
        array[i] = &temp->dado;
        temp = temp->prox;
    }

    qsort(array, tamanho, sizeof(WordsDrist*), compararPalavras);

    NO* novaLista = NULL; // Inicializa novaLista como NULL
    NO* atual = NULL;
    for (int i = 0; i < tamanho; i++) {
        NO* novoNo = mallocarNo(*array[i]);
        if (novaLista == NULL) {
            novaLista = novoNo;
            atual = novoNo;
        } else {
            atual->prox = novoNo;
            novoNo->ant = atual;
            atual = atual->prox;
        }
    }

    free(array);
    return novaLista;
}

// PRINTAR LISTA ENCADEADA //
void printarListEnq(NO* chainees){
  NO* temp = chainees;

  while (temp){
    printf("%s", temp->dado.palavra);
    temp = temp->prox;
  }
}


// RETORNAR PALAVRAS ORDENADAS PELA NORMA DO VETOR 
float calcularNorma(float vetor[]) {
  float soma = 0.0;
  for (int i = 0; i < TAMANHO_VETOR; i++) {
      soma += vetor[i] * vetor[i];
  }
  return sqrt(soma);
}

// COMPARA NORMA
int compararNorma(const void* a, const void* b) {
  WordsDrist* wordA = *(WordsDrist**)a;
  WordsDrist* wordB = *(WordsDrist**)b;
  float normaA = calcularNorma(wordA->vetSD);
  float normaB = calcularNorma(wordB->vetSD);
  return (normaA > normaB) - (normaA < normaB);
}

// ORDENA PALAVRAS PELA NORMA DO VETOR
NO* ordemNorma(NO* chainees) {
    if (!chainees) return NULL;

    int tamanho = 0;
    NO* temp = chainees;
    while (temp) {
        tamanho++;
        temp = temp->prox;
    }

    WordsDrist** array = malloc(tamanho * sizeof(WordsDrist*));
    temp = chainees;
    for (int i = 0; i < tamanho; i++) {
        array[i] = &temp->dado;
        temp = temp->prox;
    }

    qsort(array, tamanho, sizeof(WordsDrist*), compararNorma);

    NO* novaLista = NULL; // Inicializa novaLista como NULL
    NO* atual = NULL;
    for (int i = 0; i < tamanho; i++) {
        NO* novoNo = mallocarNo(*array[i]);
        if (novaLista == NULL) {
            novaLista = novoNo;
            atual = novoNo;
        } else {
            atual->prox = novoNo;
            novoNo->ant = atual;
            atual = atual->prox;
        }
    }

    free(array);
    return novaLista;
}



// RETORNAR PALAVRAS QUE ESTEJAM A DISTANCIA "d" DE UMA PALAVRA "x" // {
// ENCONTRAR A PALAVRA //
NO* encontrarPalavraX(char* palavraX, NO* chainees){
    NO* temp = chainees;
    while (temp) {
        if (strcmp(temp->dado.palavra, palavraX) == 0) {
            return temp;
        }
        temp = temp->prox;
    }
    return NULL;
}

// RETORNAR UM VETOR DE -1 SE A PALAVRA NÃO ESTIVER NA LISTA //{
float* wordNotIN() {
    float* vetorNotFond = (float*) malloc(TAMANHO_VETOR * sizeof(float));
    if (!vetorNotFond) {
        printf("Espaço Insuficiente!");
        exit(1);
    }
    for (int i = 0; i < TAMANHO_VETOR; i++) {
        vetorNotFond[i] = -1.0;
    }
    return vetorNotFond;
}


// USANDO DISTANCIA EUCLIDIANA //
char** palavrasDistanciaEuclidiana(NO* chainees, char* palavraX, float d) {
    NO* pX = encontrarPalavraX(palavraX, chainees);
    if (!pX) {
        printf("Palavra não encontrada!");
        float** result = (float**) malloc(1 * sizeof(float*));
        result[0] = wordNotIN();
        return (char**)result;
    }

    int count = 0;
    NO* temp = chainees;
    while (temp) {
        if (distanciaEuclidiana(&pX->dado, &temp->dado) == d) {
            count++;
        }
        temp = temp->prox;
    }

    if (count == 0) {
        return NULL;
    }

    char** wordsDistants = (char**) malloc(count * sizeof(char*));
    temp = chainees;
    int index = 0;
    while (temp) {
        if (distanciaEuclidiana(&pX->dado, &temp->dado) == d) {
            wordsDistants[index] = (char*) malloc(TAMANHO_PALAVRA * sizeof(char));
            strcpy(wordsDistants[index], temp->dado.palavra);
            index++;
        }
        temp = temp->prox;
    }

    return wordsDistants;
}


// USANDO DISTANCIA DOS COSSENOS //
char** palavrasDistanciaCosseno(NO* chainees, char* palavraX, float d) {
    NO* pX = encontrarPalavraX(palavraX, chainees);
    if (!pX) {
        printf("Palavra não encontrada!");
        float** result = (float**) malloc(1 * sizeof(float*));
        result[0] = wordNotIN();
        return (char**)result;
        
    }

    int count = 0;
    NO* temp = chainees;
    while (temp) {
        if (distanciaCossenos(&pX->dado, &temp->dado) == d) {
            count++;
        }
        temp = temp->prox;
    }

    if (count == 0) {
        return NULL;
    }

    char** wordsDistants = (char**) malloc(count * sizeof(char*));
    temp = chainees;
    int index = 0;
    while (temp) {
        if (distanciaCossenos(&pX->dado, &temp->dado) == d) {
            wordsDistants[index] = (char*) malloc(TAMANHO_PALAVRA * sizeof(char));
            strcpy(wordsDistants[index], temp->dado.palavra);
            index++;
        }
        temp = temp->prox;
    }

    return wordsDistants;
}

//}

// RETORNAR PALAVRAS DA MESMA CATEGORIA //
char** categorizaWords(NO* chainees, char *categoria, int* tamCategoria){
    int j = 0;
    NO* temp = chainees;

    while (temp){
        if (strcmp(temp->dado.categoria[0], categoria) == 0){
            j++;
        }
        temp = temp->prox;
    }

    char** vetorCategoria = mallocarMAT(j, TAMANHO_PALAVRA);
    if (!vetorCategoria) {
        printf("Erro ao alocar memoria");
        exit(1);
    }

    temp = chainees;
    int index = 0;
    while (temp){
        if (strcmp(temp->dado.categoria[0], categoria) == 0){
            strcpy(vetorCategoria[index], temp->dado.palavra);
            index++;
        }
        temp = temp->prox;
    }

    *tamCategoria = j;
    return vetorCategoria;
}


// ALLOCAR, PRINTAR E DAR FREE EM VETOR DE CATEGORIAS //
char** mallocarMAT(int m, int n) {
    char** vet = (char**) malloc(sizeof(char*) * m);
    if (!vet) {
        printf("Espaco Insuficiente!");
        exit(1);
    }

    for (int i = 0; i < m; i++) {
        vet[i] = (char*) malloc(sizeof(char) * (n + 1));
        if (!vet[i]) {
            printf("Espaco Insuficiente!");
            exit(1);
        }
    }
    return vet;
}

void printarMAT(char** vet, char* categoria, int tamanho){
  printf("PALAVRAS DA CATEGORIA %s:\n", categoria);
  for (i=0; i<tamanho; i++){
    printf("%s\n", vet[i]);
  }
}

void freeMAT(char** vet, int tamanho){
  for (i=0; i< tamanho ; i++){
    free(vet[i]);
  }
  free(vet);
}


//}

// RETORNAR A CATEGORIA PREVALECENTE DOS "k" VIZINHOS MAIS PROXIMOS DE UMA PALAVRA // {
char* categoriaPrevalecente(NO* chainees, char* palavraX, int k) {
    NO* pX = encontrarPalavraX(palavraX, chainees);
    if (!pX) {
        printf("Palavra não encontrada!\n");
        return NULL;
    }

    DistCategoria* distancias = (DistCategoria*) malloc(sizeof(DistCategoria) * TAMANHO_CATEGORIA);
    if (!distancias) {
        perror("Erro ao alocar memória para distâncias!\n");
        exit(1);
    }

    int count = 0;
    NO* temp = chainees;
    while (temp) {
        if (temp != pX) {
            distancias[count].distancia = distanciaEuclidiana(&pX->dado, &temp->dado);
            strcpy(distancias[count].categoria, temp->dado.categoria[0]); 
            count++;
        }
        temp = temp->prox;
    }

    qsort(distancias, count, sizeof(DistCategoria), compararDistancia);

    int* freq = (int*) calloc(26, sizeof(int)); 
    if (!freq) {
        perror("Erro ao alocar memória para frequências!\n");
        exit(1);
    }

    for (int i = 0; i < k && i < count; i++) {
        int index = distancias[i].categoria[0] - 'a';
        freq[index]++;
    }

    int maxFreq = 0;
    char* categoriaPrevalecente = (char*) malloc(TAMANHO_CATEGORIA * sizeof(char));
    if (!categoriaPrevalecente) {
        perror("Erro ao alocar memória para categoria prevalecente!\n");
        exit(1);
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            categoriaPrevalecente[0] = 'a' + i; 
            categoriaPrevalecente[1] = '\0';  
        }
    }

    free(distancias);
    free(freq);

    return categoriaPrevalecente;
}

// FCOMPARAR DISTANCIAS //
int compararDistancia(const void* a, const void* b) {
    const DistCategoria* dist1 = (const DistCategoria*) a;
    const DistCategoria* dist2 = (const DistCategoria*) b;
    if (dist1->distancia < dist2->distancia) return -1;
    else if (dist1->distancia > dist2->distancia) return 1;
    else return 0;
}
// }

//RETORNAR "m" AGRUPAMENTOS DE "k" VIZINHOS MAIS PRÓXIMOS ONDE CADA AGRUPAMENTO COMAÇA COM NÚMERO ALEATÓRIO //
char*** agrupamentosVizinhos(NO* chainees, int m, int k) {
    int tamanho = 0;
    NO* temp = chainees;
    while (temp) {
        tamanho++;
        temp = temp->prox;
    }

    if (m > tamanho) m = tamanho;

    srand(time(NULL));

    NO** selecionados = (NO**) malloc(m * sizeof(NO*));
    if (!selecionados) {
        perror("Erro ao alocar memória para selecionados!\n");
        exit(1);
    }

    for (int i = 0; i < m; i++) {
        int r = rand() % tamanho;
        temp = chainees;
        for (int j = 0; j < r; j++) {
            temp = temp->prox;
        }
        selecionados[i] = temp;
    }

    char*** agrupamentos = (char***) malloc(m * sizeof(char**));
    if (!agrupamentos) {
        perror("Erro ao alocar memória para agrupamentos!\n");
        exit(1);
    }

    for (int i = 0; i < m; i++) {
        agrupamentos[i] = (char**) malloc(k * sizeof(char*));
        if (!agrupamentos[i]) {
            perror("Erro ao alocar memória para agrupamento!\n");
            exit(1);
        }

        DistCategoria* distancias = (DistCategoria*) malloc(tamanho * sizeof(DistCategoria));
        if (!distancias) {
            perror("Erro ao alocar memória para distâncias!\n");
            exit(1);
        }

        int count = 0;
        temp = chainees;
        while (temp) {
            if (temp != selecionados[i]) {
                distancias[count].distancia = distanciaEuclidiana(&selecionados[i]->dado, &temp->dado);
                strcpy(distancias[count].categoria, temp->dado.categoria[0]);  
                count++;
            }
            temp = temp->prox;
        }

        qsort(distancias, count, sizeof(DistCategoria), compararDistancia);

        for (int j = 0; j < k && j < count; j++) {
            agrupamentos[i][j] = (char*) malloc(TAMANHO_PALAVRA * sizeof(char));
            if (!agrupamentos[i][j]) {
                perror("Erro ao alocar memória para agrupamento!\n");
                exit(1);
            }
            strcpy(agrupamentos[i][j], distancias[j].categoria);
        }

        free(distancias);
    }

    free(selecionados);
    return agrupamentos;
}