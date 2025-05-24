#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Escreva um programa que leia um texto de um arquivo e informe a quantidade de
// vezes que cada palavra aparece no texto. Pense nas funçõoes que você precisa implementar para
// resolver o problema e nas estruturas que você deve considerar.


int cont_palavras(FILE *f);

char procura_inicio_palavra(FILE *f);

char procura_fim_palavra(FILE *f);

char *cria_palavra(FILE *f, int i, int j);

char **arq_get_palavras(FILE *f, int *n);

void imprime_vetor(char **vet, int n);

char **retira_repeticoes(char **vet, int n, int *m);

int elemento_no_vet(char *string, char **vet, int n);

int conta_palavra(char *string, char **vet, int n);

void conta_palavras(char **vet1, int n, char **vet2, int m);


//////////////////////////////////////////////////////////////

int main(void){

    FILE *f = fopen("arquivo_texto", "r");

    int n, m;
    char **vet = arq_get_palavras(f, &n), **vet2;
  
    imprime_vetor(vet, n);
  
    vet2 = retira_repeticoes(vet, n, &m);
  
    conta_palavras(vet2, m, vet, n);

    imprime_vetor(vet2, n);

    fclose(f);

    return 0;
}

///////////////////////////////////////////////////////////////

// Conta a quantidade de palavras que tem dentro do arquivo
int cont_palavras(FILE *f){
    char caractere, anterior;
    anterior = getc(f);

    // Se for a primeira iteração e o formato for 'x ' ou 'xx' soma no contador
    int c = (anterior != ' ') ? 1 : 0;

    // Vai varrendo até o final do arquivo
    while(!feof(f)){
        caractere = getc(f);

        // Verifica de dois em dois: anterior e caractere
        // for no formato ' x' adiciona um no contador
        if((anterior == ' ') && (caractere != ' ') && (caractere != EOF)) c++;

        // Atualiza o anterior
        anterior = caractere;
    }

    // Volta o ponteiro do arquivo para o início
    fseek(f, 0l, SEEK_SET);

    return c;
}

// DEFINITR PALAVRA //

char procura_fim_palavra(FILE *f){
    // Procura caracter até achar algum preenchido
    char caracter;
    while(((caracter = getc(f)) != ' ') && (caracter != EOF));

    // Volta um caractere se não estiver no final arquivo
    if (caracter != EOF) fseek(f, -1l, SEEK_CUR);

    return caracter;
}


char procura_inicio_palavra(FILE *f){
    // Procura espaço ou caracter nulo
    char caracter;
    while(((caracter = getc(f)) == ' ') && (caracter != EOF));

    // Volta um caractere
    if(caracter != EOF) fseek(f, -1l, SEEK_CUR);

    return caracter;
}


char *cria_palavra(FILE *f, int i, int j){

    // Calcula a quantidade de caracteres da palavra
    int n = j - i + 1;              // +1 por conta do \0

    // Posiciona o cursor em i
    fseek(f, i, SEEK_SET);

    // Aloca a palavra
    char *palavra = (char *) malloc(sizeof(char) * n);

    // Copia o vetor usando fgets()
    palavra = fgets(palavra, n, f);

    return palavra;
}


// MANIPULAR DADOS DO ARQUIVO //

// Transforma arquivo em vetor de strings
char **arq_get_palavras(FILE *f, int *n){

    // Conta a quantidade de palavras que tem o arquivo
    (*n) = cont_palavras(f);

    // Aloca o ponteiro de strings 
    char **vet = (char **) malloc(sizeof(char *) * (*n));

    // Roda esse mesmo algoritmo para cada palavra
    char caracter = ' ';
    for(int p=0; p<(*n); p++){

        // Aponta o i para o início da palavra

        // Fica catando palavra até achar um espaço em branco
        caracter = procura_inicio_palavra(f);

        // Guarda a posição i
        int i = ftell(f);

        // Aponta o j para o final da palavra

        // Procura o final da palavra
        caracter = procura_fim_palavra(f);

        // Guarda a posição j
        int j = ftell(f);

        // Cria a palavra
        char *palavra = cria_palavra(f, i, j);

        // Coloca a palavra no vetor
        vet[p] = palavra;
    }

    return vet;
}


///////////////////////////////////////////////////////////

// NÃO ESTÁ IMPRIMINDO NADA  // 
// Imprime um vetor de strings
void imprime_vetor(char **vet, int n){
    for(int i=0; i<n; i++)
        printf("%s ", vet[i]);
}



// Verifica se determinada string está no vetor
int elemento_no_vet(char *string, char **vet, int n){
    for(int i=0; i<n; i++)
        if(strcmp(vet[i], string) == 0) return 1;
    return 0;
}



// Retira repetições de um vetor em uma cópia (como se criasse um conjunto à partir de um vetor)
char **retira_repeticoes(char **vet, int n, int *m){
    (*m) = 0;

    // Aloca o primeiro vetor de acordo com o número inicial
    char **vet2 = (char **) malloc(sizeof(char *) * n);

    // Varre o vetor inicial
    for(int i=0; i<n; i++){

        // Se o elemento não estiver no segundo vetor, adiciona ele
        if(!elemento_no_vet(vet[i], vet2, (*m))){
            vet2[(*m)] = (char *) malloc(sizeof(char) * strlen(vet[i]));
            strcpy(vet2[(*m)], vet[i]);
            (*m)++;
        }
    }

    // Realoca para a nova quantidade de elementos
    vet2 = (char **) realloc(vet2, sizeof(char *) * (*m));

    return vet2;
}


// Conta quantas vezes uma palavra aparece em uma string
int conta_palavra(char *string, char **vet, int n){
    int c = 0;
    for(int i=0; i<n; i++)
        if(strcmp(string, vet[i]) == 0) c++;
    return c;
}


// Compara um vetor em que palavras não se repetem com um em que as palavras podem ser repetir
void conta_palavras(char **vet1, int n, char **vet2, int m){

    // Para cada palavra no vetor 1
    for(int i=0; i<n; i++){
        printf("%s: %d\n", vet1[i], conta_palavra(vet1[i], vet2, m));
    }
}