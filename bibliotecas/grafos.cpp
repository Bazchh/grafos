#ifndef GRAFOS_CPP
#define GRAFOS_CPP
#define SIZEG 159
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

float convert_la_lo(float la_lo){
    float result;
    la_lo = la_lo/60;
    result = la_lo*1852;
    return result;    
}

float dist(latitude latA,longitude loA, latitude latB, longitude loB){
    float distancia = 0, lo,la;
    la = latA - latB;
    lo = loA - loB;
    la = convert_la_lo(la);
    lo = convert_la_lo(lo);
    distancia = pow(la,2)+pow(lo,2);
    distancia = sqrt(distancia);
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