#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

struct arvore{
    int key;
    Arv* esq;
    Arv* dir;
};

typedef struct arvore Arv;

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

Arv* chkVazia(Arv* p){
    return p==NULL;
}

Arv* libera(Arv* p){
    if(!chkVazia(p)){
        free(p->esq);
        free(p->dir);
        free(p);
    }
    return NULL;
    
}

Arv* chkKey(Arv* p, int key){
    if(chkVazia(p)){
        return 0;
    } else{
        return p->key||p->esq->key||p->dir->key;
    }
}

void imprime(Arv* p){
    if(!chkVazia(p)){
        printf("%d",p->key);
        printf("%d",p->dir->key);
        printf("%d",p->esq->key);
    }
}

int seekMin(Arv* p){
    int minKey = 99999;
    Arv* l1,r1;
    l1 = p->esq;
    r1 = p->dir;
    if(p->key<minKey){
        minKey = p->key;
    }
    while(!chkVazia(l1)){
     if(l1->key<minKey){
         minKey = l1->key;
         if(!chkVazia(l1->esq)){
             l1 = l1->esq;
         }
     }   
    }
}

Arv* busca (arvore r, int k) {
    if (r == NULL || r->chave == k)
       return r;
    if (r->chave > k)
       return busca (r->esq, k);
    else
       return busca (r->dir, k);
}

Arv* buscaMin(Arv* p){
    int min = 99999;
    if(chkVazia(p)==NULL){
        return NULL;
    }
    if(p->key<min){
        min = p->key;
        buscaMin(p->esq);
        buscaMin(p->dir);
    }
}
