#ifndef GRAFOS_CPP
#define GRAFOS_CPP
#define SIZEG 161
#include "hash.h"


dataItem **aloca_grafo(dataItem **d){
    int i;
    d = (dataItem**)malloc(SIZEG*sizeof(dataItem*));
    for(i = 0; i < SIZEG; i++){
        d[i] = (dataItem*)malloc(SIZEG*sizeof(dataItem));
    }
   return d;
}

int inserir_dados(dataItem *d, dataItem **m){
    int i, j;

    for(i = 0; i < SIZEG; i++){
       m[i][j] = d[i];
    }
    i = 0;
    for(j = 0; j < SIZEG; j++){
        m[i][j] = d[j];
    }
    return 0;
}

float dist(latitude la,longitude lo, latitude lx, longitude ly){
    float distancia;
    distancia = (sqrt((pow(2,la-lx))+(pow(2,lo-ly))));
    return distancia;
}

#endif