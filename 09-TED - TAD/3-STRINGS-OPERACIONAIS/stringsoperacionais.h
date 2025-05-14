typedef struct palavra Palavra;


Palavra* criar_palavra(char* word);

void livra(Palavra *p);


char* inversao(Palavra* p);


int palindroma(Palavra* p);


char *prefixo(Palavra* p, int parametro);

char *sufixo(Palavra* p, int final);


char* trocaLetras(Palavra* p, char letra1, char letra2);
                                                       

void printarStrings(Palavra* s);