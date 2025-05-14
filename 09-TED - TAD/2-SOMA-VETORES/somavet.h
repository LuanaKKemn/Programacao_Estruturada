// TAD: Vetor (maallocar) //
// Tipo exportado //


// CRIAR TIPO //
typedef struct vetor Vetor;


// ALLOCAR ESPAÇO DE MEMÓRIA // --> USO PONTEIROS E RETORNO O VALOR DO TPO QUE CRIEI
Vetor* criarVet(int qnt);

Vetor* atribuirVetor(Vetor* v);


// LIBERAR O ESPAÇO QUE ALOQUEI //
void liberarVet(Vetor* vet);



Vetor* somaVetores(Vetor* vet, Vetor* w);

float minimo(Vetor* vet);

float maximo(Vetor* vet);

int buscaElemento(Vetor* vet, float elemento);



// PRINTAR VETOR //
void printa_vetores(Vetor* v);




