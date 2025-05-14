typedef struct apartamento Apartamento;

typedef struct vetorE VetorE;

Apartamento* mmalocar(void);

VetorE* malloke(VetorE *e);

Apartamento* atrib(char* name, int number, float area, int morad);

void livre(Apartamento *a);

VetorE libre(VetorE *vet);

float areaCond(VetorE *e);

void valorPagar(float despesas, VetorE *e, float areat);