#ifndef GRAFOS_CPP
#define GRAFOS_CPP
#define SIZEG 161
#include "hash.h"
typedef dataItem **grafo[SIZEG][SIZEG];

void init_grafo(grafo G){
    int i, j;

    for(i = 0; i < SIZEG; i++){
        for(j = 0; j < SIZEG; j++){
            G[i][j] = 0;
        } 
    }
}

int inserir_dados(dataItem *d, grafo g){
    int i, j;
    dataItem aux;
    for(i = 0; i < SIZEG; i++){
       
    }
    return 0;
}

#endif