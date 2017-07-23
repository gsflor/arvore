#ifndef ABB_H_
#define ABB_H_

typedef struct arvore Arv;

Arv* criavazia();

Arv* criaArv(int key, Arv* esq, Arv* dir);

Arv* chkVazia(Arv* p);

Arv* libera(Arv* p);

Arv* chkKey(Arv* p, int key);

void imprime(Arv* p);

int seekMin(Arv* p);

Arv* busca (arvore r, int k);

Arv* buscaMin(Arv* p);

#endif /* ABB_H_ */
