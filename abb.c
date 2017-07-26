#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

//typedef struct arvore Arv;

struct arvore{
    int key;
    Arv* esq;
    Arv* dir;
};

//Da uma olhada nessa parte aqui, nao to conseguindo chamar a criaArv passando a criavazia como argumento pra ela
Arv* criavazia(){
    return NULL;
};

Arv* criaArv(int key, Arv* esq, Arv* dir){
    Arv* p = (Arv*)malloc(sizeof(Arv));
    p->key = key;
    p->esq = esq;
    p->dir = dir;
    return p;
}

// Adiciona um elemento na árvore binária de busca
Arv* addElemento(int key, Arv *raiz)
{
	Arv *andador;

	for (andador = raiz; andador != NULL;)
	{
		if(key > andador->key) // Se a chave for maior que o nó atual, vá para a direita
		{
			if(andador->dir == NULL)
			{
				andador->dir = criaArv(key, criavazia(), criavazia());
				return raiz;
			}

			andador = andador->esq;
		}

		else
		{
			if(andador->esq == NULL) // Se a chave for menor que o nó atual, vá para a esquerda
			{
				andador->esq = criaArv(key, criavazia(), criavazia());
				return raiz;
			}

			andador = andador->dir;
		}
	}

	return criaArv(key, criavazia(), criavazia());
}

int chkVazia(Arv* p){
    return p==NULL?1:0;
}

Arv* libera(Arv* p){
    if(!chkVazia(p)){
        free(p->esq);
        free(p->dir);
        free(p);
    }
    return NULL;
    
}

int chkKey(Arv* p, int key){ //Key nao ta sendo usado
    if(chkVazia(p)){
        return 0;
    } else{
        return p->key||p->esq->key||p->dir->key;
    }
}

void imprime(Arv* p){
    if(!chkVazia(p)){
		printf("Chave:\n");
        printf("%d\n",p->key);
	}
	if(!chkVazia(p->esq)){
		printf("Chave esq:\n");
        printf("%d\n",p->esq->key);	
	}
	if(!chkVazia(p->dir)){
		printf("Chave dir:\n");
        printf("%d\n",p->dir->key);	
    }
}

Arv* buscaMin(Arv* p)
{
	Arv *andador;

	for (andador = p; andador != NULL; andador = andador->esq) //Vai pra esqueda até achar o menor nó
	{
		if(andador->esq == NULL) //Se o nó da esquerda for vazio, parar o loop para retornar o nó atual
			break;
	}

	return andador; //Retorna ou NULL(caso a árvore seja vazia) ou o menor nó
}

/* Arv* buscaMin(Arv* p){ */
/*     int min = 999; */
/* 	printf("MIN: %d", min);	 */
	
/*     if((p->key)<min){ */
/*         min = p->key; */
/* 		printf("MIN: %d", min); */
/*         buscaMin(p->esq); */
/*         buscaMin(p->dir); */
/*     } */
/* 	printf("MIN: %d", min); */
/* 	printf("%d",p->esq->key); */

/* 	return p->esq; // Não sei o que retornaria porque a busca ta um pouco confusa. Mas precisa retornar alguma coisa pela declaração */
/* } */

Arv* busca (Arv *r, int k)
{
    if (r == NULL || r->key == k)
		return r;
    if (r->key > k)
		return busca (r->esq, k);
    else
		return busca (r->dir, k);
}

/* Arv* buscaMin(Arv* p){ */
/*     int min = 99999; */
/*     if(chkVazia(p)==NULL){ */
/*         return NULL; */
/*     } */
/*     if(p->key<min){ */
/*         min = p->key; */
/*         buscaMin(p->esq); */
/*         buscaMin(p->dir); */
/*     } */
/* } */
