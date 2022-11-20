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

float dist(latitude latA,longitude loA, latitude latB, longitude loB){
    float distancia = 0;
    distancia = sqrt((pow((latA-latB),2)+pow((loA-loB),2)));
    if(distancia >= 0){
        return distancia;
    }
    return -1;
}

dataItem **quilometros(dataItem **d){
    float latA,loA,latB,loB, distancia;
    int i = 0, j = 0;
    for(i = 0; i < SIZEG; i++){
        latA = d[i][j].GPS.la;
        loA = d[i][j].GPS.lo;
        for(j = 0; j < SIZEG; j++){
            latB = d[0][j].GPS.la;
            loB = d[0][j].GPS.lo;
            distancia = dist(latA,loA,latB,loB);
            if(distancia > 0){
                d[i][0].vizinhos++;
                d[i][j].km = distancia;
                d[j][i].km = distancia;
            } 
        }
    }
    return d;
}

#endif