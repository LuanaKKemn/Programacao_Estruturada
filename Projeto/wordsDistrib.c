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
#define TAMANHO_CATEGORIA 20

int i, j;

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


// FUNÇÕES PRA EXTRAIR PALAVRA E VETOR DO ARQUIVO //
char* ExtraiPalavra(FILE* arq, int linha, int tamLinha) {
    char linhaAtual[tamLinha];
    fseek(arq, 0, SEEK_SET);

    for (int i = 0; i < linha; i++) {
        if (fgets(linhaAtual, sizeof(linhaAtual), arq) == NULL) {
            fprintf(stderr, "Erro ao ler a linha %d do arquivo.\n", linha);
            return NULL;
        }
    }

    char* palavra = strtok(linhaAtual, " ");
    if (palavra == NULL) {
        fprintf(stderr, "Erro: Linha %d não contém uma palavra válida.\n", linha);
        return NULL;
    }

    char* copiaPalavra = malloc(strlen(palavra) + 1);
    if (copiaPalavra == NULL) {
        perror("Erro ao alocar memória para copiaPalavra.\n");
        exit(1);
    }
    strcpy(copiaPalavra, palavra);
    return copiaPalavra;
}

float* extraiVetor(FILE* arq, int linha, int tamLinha) {
    char linhaAtual[tamLinha];
    fseek(arq, 0, SEEK_SET);

    for (int i = 0; i < linha; i++) {
        if (fgets(linhaAtual, sizeof(linhaAtual), arq) == NULL) {
            fprintf(stderr, "Erro ao ler a linha %d do arquivo.\n", linha);
            return NULL;
        }
    }

    char* token = strtok(linhaAtual, " ");
    if (token == NULL) {
        fprintf(stderr, "Erro: Linha %d não contém um vetor válido.\n", linha);
        return NULL;
    }

    float* vetor = (float*) malloc(TAMANHO_VETOR * sizeof(float));
    if (vetor == NULL) {
        perror("Erro ao alocar memória para vetor.\n");
        exit(1);
    }

    for (int i = 0; i < TAMANHO_VETOR; i++) {
        token = strtok(NULL, " ");
        if (token == NULL) {
            fprintf(stderr, "Erro: Vetor na linha %d incompleto.\n", linha);
            free(vetor);
            return NULL;
        }
        vetor[i] = atof(token);
    }
    return vetor;
}

// FUNÇÃO PRA DEFINIR CATEGORIAS //
char* tamanhoWord(char* palavra) {
    int tam = strlen(palavra);

    char* quantidadeLetters[5] = {"caracthere", "Minipalavras", "Fiveletters", "TenLetters", "Palavronas"};

    switch (tam) {
        case 1:
            return quantidadeLetters[0];
        case 2:
        case 3:
            return quantidadeLetters[1];
        case 5:
            return quantidadeLetters[2];
        case 10:
            return quantidadeLetters[3];
        default:
            if (tam > 12) {
                return quantidadeLetters[4];
            } else {
                return "Irrelevante";
            }
    }
}

char* primeiraLetra(char* palavra) {
    char* letrasIniciais[5] = {"A", "L", "I", "N", "E"};

    for (int i = 0; i < 5; i++) {
        if (palavra[0] == letrasIniciais[i][0])
            return letrasIniciais[i];
    }
    return "Irrelevante";
}


char* contemLetras(char* palavra) {
    char letrasImportantes[5] = {'A', 'L', 'I', 'N', 'E'};
    char* substring = (char*) malloc(sizeof(char) * 6);
    if (substring == NULL) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        exit(1);
    }
    int index = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < strlen(palavra); j++) {
            if (palavra[j] == letrasImportantes[i]) {
                substring[index++] = letrasImportantes[i];
                break; 
            }
        }
    }
    substring[index] = '\0'; 

    return substring;
}

char* ultimaLetra(char* palavra) {
    char letrasFinais[5] = {'L', 'U', 'A', 'K', 'W'};
    char* categoria = (char*) malloc(sizeof(char) * 2); 
    if (categoria == NULL) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        exit(1);
    }

    char ultimaLetra = palavra[strlen(palavra) - 1];

    for (int i = 0; i < 5; i++) {
        if (ultimaLetra == letrasFinais[i]) {
            categoria[0] = letrasFinais[i];
            categoria[1] = '\0'; 
            return categoria;
        }
    }

    strcpy(categoria, "Outra");
    return categoria;
}


char** defineCategorias(FILE* arq, int linha, int tamLinha) {
    char* word = ExtraiPalavra(arq, linha, tamLinha);

    char** categorias = (char**) malloc(4 * sizeof(char*));
    if (categorias == NULL) {
        perror("Erro ao alocar memória para categorias.\n");
        exit(1);
    }
    for (int i = 0; i < 4; i++) {
        categorias[i] = (char*) malloc((TAMANHO_CATEGORIA + 1) * sizeof(char));
        if (categorias[i] == NULL) {
            perror("Erro ao alocar memória para categoria.\n");
            exit(1);
        }
    }

    strcpy(categorias[0], tamanhoWord(word));
    strcpy(categorias[1], primeiraLetra(word));
    strcpy(categorias[2], ultimaLetra(word));
    strcpy(categorias[3], contemLetras(word));

    free(word);
    return categorias;
}


// ALOCAR STRUCT E ATRIBUIR PALAVRAS //
WordsDrist* atribuir(FILE* arq, int linha, int tamLinha) {
    WordsDrist* infos = (WordsDrist*) malloc(sizeof(WordsDrist));
    if (infos == NULL) {
        perror("Espaco Insuficiente");
        exit(1);
    }

    strcpy(infos->palavra, ExtraiPalavra(arq, linha, tamLinha));
    float* vetor = extraiVetor(arq, linha, tamLinha);
    memcpy(infos->vetSD, vetor, TAMANHO_VETOR * sizeof(float));
    free(vetor);

    char** categorias = defineCategorias(arq, linha, tamLinha);
    for (int i = 0; i < 4; i++) {
        strcpy(infos->categoria[i], categorias[i]);
        free(categorias[i]);
    }
    free(categorias); 

    return infos;
}


// COMPARAR LEXICAMENTE PALAVRAS DE 2 VARIAVEIS //
int compararLexamente(WordsDrist* first, WordsDrist* second){
  return strcmp(first->palavra, second->palavra);
}

// COMPARAR TAMANHO DE VETORES DE 2 PALAVRAS (TAMANHO MAIOR, MENOR OU IGUAL) //
int compararVet(WordsDrist* first, WordsDrist* second) {
    int tamanhoPrimeiro = 0, tamanhoSegundo = 0;

    while (first->vetSD[tamanhoPrimeiro] && tamanhoPrimeiro < TAMANHO_VETOR) {
        tamanhoPrimeiro++;
    }

    while (second->vetSD[tamanhoSegundo] && tamanhoSegundo < TAMANHO_VETOR) {
        tamanhoSegundo++;
    }

    if (tamanhoPrimeiro > tamanhoSegundo) {
        return 1;
    } else if (tamanhoPrimeiro == tamanhoSegundo) {
        return 0;
    } else {
        return -1;
    }
}

// DISTANCIA EUCLIDIANA DOS VETORES DE 2 APALVRAS //
float distanciaEuclidiana(WordsDrist* first, WordsDrist* second){
  float soma = 0.0;

  for (i=0; i< TAMANHO_VETOR; i++){
    float diferenca = (first->vetSD[i]) - (second->vetSD[i]);
    soma += diferenca * diferenca;
  }
  return sqrt(soma);
}

// DISTANCIA DO COSSENO DOS VETORES DE 2 PALAVRAS //
float distanciaCossenos(WordsDrist* first, WordsDrist* second){
  float produtoescalar = 0.0;
  float primeiraNorma = 0.0;
  float segundaNorma = 0.0;
  
  for (i = 0; i<TAMANHO_VETOR; i++){
    produtoescalar += first->vetSD[i] * second->vetSD[i];
    primeiraNorma += first->vetSD[i] * first->vetSD[i];
    segundaNorma += second->vetSD[i] * second->vetSD[i];
  }

  primeiraNorma = sqrt(primeiraNorma);
  segundaNorma = sqrt(segundaNorma);

  float similaridade = produtoescalar/(primeiraNorma*segundaNorma);
  return 1.0 - similaridade;
}



