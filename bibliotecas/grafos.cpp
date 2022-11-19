#ifndef GRAFOS_CPP
#define GRAFOS_CPP
#define SIZEG 160
#include "main.h"
typedef dataItem **grafo[SIZEG][SIZEG];
void init_grafo(grafo G){
    int i;
    int j;
    for(i = 0; i < SIZEG; i++){
        for(j = 0; j < SIZEG; j++){
            G[i][j] = 0;
        }
    }
}

#endif