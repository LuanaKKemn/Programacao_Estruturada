typedef struct vetor Vetor;


Vetor* allocar(Vetor** vet);

void atribuirVetor(Vetor* v);


void printa_vetores(Vetor* v);

void liberarVet(Vetor* vet);



Vetor* soma(Vetor *vet1, Vetor *vet2);

Vetor* subtracao(Vetor *vet1, Vetor *vet2);

Vetor* multEscalar(Vetor *vet1, float escalar);
