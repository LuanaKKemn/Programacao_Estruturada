typedef struct aluno Aluno;

typedef struct endereco Endereco;

typedef struct vetor Vetor;

typedef struct palavra Palavra;

// ALOCAÇÕES //
Aluno* mallocado(Aluno *student);

Endereco* criar(Endereco end);

Palavra* alocarpalavras(Palavra *p);

Vetor* criarVet(Vetor** vet);



// ATRIBUIÇÕES //
Aluno* atribuicaoAluno(Aluno* student, Vetor* n, Vetor* c, char *nome, Endereco* local);


void atrubuir_end(Endereco end);

Vetor* atribuiValores(Vetor* v);
Vetor* atribuirCH(Vetor* v);





// FUNÇÕES //

float mediaNotas(Vetor* notas);

float calCR(Vetor* notas, Vetor* cargaH);

void maior_Menor(float *maior, float *menor, Vetor* notas);




int matriculaRand(void);

char* cepVetor(void);



// SAÍDAS //

void printarAluno(Aluno *a);

void printaVet(Vetor *v);



// LIBERAÇÕES //

void liberar_a(Aluno* nome);

void liberar_end(Endereco* loc);


void liberar_vet(Vetor* v);

