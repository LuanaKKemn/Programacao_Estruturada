#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// ARQUIVO.C --> TADS, ALOCAÇÕES DINAMICAS, ATRIBUIÇÕES DE VALORES, FUNÇÕES, LIBERAÇÕES //

//  CRIAR TIPOS - TADS //

// ALUNO //
typedef struct aluno{
  char nome[100];
  int matricula;
  Endereco *end;
  Vetor *notas;
  Vetor *cargaHoraria;
} Aluno;

// VETOR //
typedef struct vetor{
  float *elementos;
  int posicoes;
}Vetor;

// PALAVRAS //
// typedef struct palavra{
//   char letras[100];
// }Palavra;

// ENDEREÇO //
typedef struct endereco{
  char rua[30];
  int numero;
  char bairro[100];
  char cidade[100];
  char estado[30];
  char CEP[9];
}Endereco;


// MALLOCAR // ALOCAÇÕES
Aluno* mallocado(Aluno *student){
  student = (Aluno*) malloc (sizeof(Aluno));
  if (student == NULL){
    printf("Espaço Insuficiente.");
    exit(1);
  }
  return student;
}


Endereco* mallocarEndereco(Endereco *end){
  end = (Endereco*) malloc(sizeof(Endereco));
  if (end == NULL){
    printf("Espaço Insuficiente.");
    exit(1);
  }  
  return end;
}


// Palavra* alocarpalavras(Palavra *p){
//   p = (Palavra*) malloc(sizeof(Palavra));
//   if (p == NULL){
//     printf("Espaço Insuficiente");
//     exit(1);
//   }
//   return p;
// }


// ALLOCAR ESPAÇO PRO VETOR COMO PONTEIRO DE PONTEIRO //
Vetor* criarVet(Vetor** vet){
  (*vet) = (Vetor*) malloc(sizeof(Vetor));
  if (*vet == NULL){
    printf("Espaço insuficiente.");
    exit(1);
  }
  (*vet)->posicoes = 10;
  (*vet)->elementos = (float*) malloc(sizeof(float)*((*vet)->posicoes));
  if (((*vet)->elementos) == NULL){
    printf("Espaço Insuficiente");
    exit(1);
  }
  return (*vet);
}




//__________________________________________________________________________//

// ATRIBUIÇÕES // // PASSAR O VETOR COMO PONTEIRO //

// ATRIBUIR ALUNO //
Aluno* atribuicaoAluno(Aluno* student, Vetor* n, Vetor* c, char *nome, Endereco* local){
  strcpy(student->nome, nome);
  student->matricula = matriculaRand();

  student->end = local;
  
  student->notas = atribuiValores(n);
  student->cargaHoraria = atribuirCH(c);

  return student;
}



Endereco* atribuirEnd(Endereco* local){
  local->CEP[9] = cepVetor();
  
  local->rua = 
  local->numero = 
  local->bairro =
  local->cidade =
  local->estado =
}




// ATRIBUIR NOTAS ALEATÓRIAS PARA O ALUNO // 
Vetor* atribuiValores(Vetor* v){
  srand((unsigned int)time(NULL)); // --> GERAR ALEATÓRIOS A CADA EXECUÇÃO //

  float a = 0.0;   // --> NOTA MÍNIMA (TEORICAMENTE)
  float b = 10.0; //  --> NOTA MÁXIMA (POR SUPUESTO)

  for (int i=0; i<(v->posicoes); i++){
    v->elementos[i] = a + ((float)rand() / (float)RAND_MAX) * (b-a);
  }
  return v;
}

// ATRIBUIR HORAS PRA TODAS AS MATÉRIAS
Vetor* atribuirCH(Vetor* v){
  for (int i=0; i<(v->posicoes); i++){
    if (i<4){
      v->elementos[i] = 30;
    } else {
      v->elementos[i] = 60;
    }
  }
  return v;
}



//_________________________________________________________________//

// FUNÇÕES //
float mediaNotas(Vetor* notas){
  float media = 0;
  for (int i=0; i<(notas->posicoes); i++){
    media += notas->elementos[i];
  }
  return media/(notas->posicoes);
}

float calCR(Vetor* notas, Vetor* cargaH){
  float soma=0;
  float totalCH=0;
  for (int i=0; i<(notas->posicoes); i++){
    soma += notas->elementos[i] * cargaH->elementos[i];
    totalCH += cargaH->elementos[i];
  }
  return soma / totalCH;
}

void maior_Menor(float *maior, float *menor, Vetor* notas){
  for (int i=0; i<(notas->posicoes); i++){
    if (i==0){
      *maior = notas->elementos[i];
      *menor = notas->elementos[i];
    }
    if (notas->elementos[i] > *maior){
      *maior = notas->elementos[i];
    }
    if (notas->elementos[i] < *menor){
      *menor = notas->elementos[i];
    }
  }
}


// // CRIAR CEP //
// char* cepVetor(void){
//   char* cep = (char*) malloc (sizeof(char)*10);
//   for (int i=0; i<9; i++){
//     if (i == 5){
//       cep[i] = '-';
//     }
//     else{
//       cep[i] = rand() % 10 + '0';
//     }
//   }
//   cep[9] = '\0';
  
//   return cep;
// }


// CRIAR MATRICULA //
int matriculaRand(void){
  srand(time(NULL));
  int num = rand() % 900000000 + 100000000;
  return num;
}


///////////////////////////////////////////////////////////////////
// SAIDA DE DADOS //

void printarAluno(Aluno *a){
  printf("Nome: %p\n", &(a->nome));
  printf("Matricula: %p\n", &(a->matricula));

  printf("Endereço:\n");
  
  printf("Notas:\n");
  printaVet((a->notas));
  printf("\nCarga horária:\n");
  printaVet((a->cargaHoraria));

}

void printaVet(Vetor *v){
  printf("{");
  for (int i=0; i <(v->posicoes); i++){
    if (i == (v->posicoes)-1){
      printf("%p}", &(v->elementos[i]));
    } else {
      printf("%p", &(v->elementos[i]));
    }
  }
}

//________________________________________________________________________________//


// LIBERAR // LUBERAÇÕES

void liberar_a(Aluno* nome){
  free(nome->nome);
  //free(nome->matricula);
  free(nome->end);

  free(nome->notas->elementos);
  free(nome->notas);

  free(nome->cargaHoraria->elementos);
  free(nome->cargaHoraria);
}


void liberar_end(Endereco* loc){
  free(loc);
}

void liberar_palavras(Palavra* p){
  free(p);
}

void liberar_vet(Vetor* v){
  free(v->elementos);
  free(v);
}

