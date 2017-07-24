#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

int main()
{
    //parte esquerda da árvore
    //Aqui eu deixei como null pq tava funcionando dessa forma
    Arv* a1 = criaArv(4,NULL,NULL);
    Arv* a2 = criaArv(7,NULL,NULL);
    Arv* a3 = criaArv(6,a1,a2);
    Arv* a4 = criaArv(1,NULL,NULL);
    Arv* a5 = criaArv(3,a4,a3);
    //parte direita da árvore
    Arv* a6 = criaArv(13,NULL,NULL);
    Arv* a7 = criaArv(14,a6,NULL);
    Arv* a8 = criaArv(10,a7,NULL);
    //nó raiz
    Arv* raiz = criaArv(8,a5,a8);
	imprime(a1);
	imprime(a5);
	imprime(raiz);
	
    //buscaMin(raiz); < essa funçao ta bugada
};
