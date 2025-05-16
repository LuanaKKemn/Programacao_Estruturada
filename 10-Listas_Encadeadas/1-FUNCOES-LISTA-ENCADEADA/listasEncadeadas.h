
typedef struct No No;

typedef struct Twolists Twolists;


void mallocar2Lists(Twolists **listas);

No *criaNo(int a);

void mallocarListaEnc(No *a);

No* criaList(int q, int vet[q]);

void exibirList(No * list);

No* divid2lists(No *l);

No* porElement(int elemento, No* l);




void liberarNos(No *n);

void liberarStucts(Twolists *to2);

