// INTERFACE --> ".h" // 
// TADs & PROTÓTIPOS //


// criação dos tipos // 
typedef struct ponto Ponto; // ✔

typedef struct circulo Circulo;


//  alocação na memória // 
Ponto* criarPonto(float x, float y); // ✔

Circulo* criarCirculo(Ponto* p, float r);


// funções do problema //
float areaCir(Circulo* c);

int interior(Circulo* c, Ponto* p, float x1, float y1);


// liberações //
void liberacao_Ponto(Ponto *p); // ✔

void liberacao_Circulo(Circulo *c);





/* 
  FunÃ§Ã£o acessa - Retorna os valores das coordenadas de um ponto 
void pto_acessa(Ponto* p, float* x, float* y);

 FunÃ§Ã£o atribui - Atribui novos valores Ã s coordenadas de um ponto 
void pto_atribui(Ponto* p, float x, float y);

 FunÃ§Ã£o distancia - Retorna a distÃ¢ncia entre dois pontos 
float pto_distancia(Ponto* p1, Ponto* p2);

*/