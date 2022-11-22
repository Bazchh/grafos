#ifndef GRAFOS_CPP
#define GRAFOS_CPP
#define SIZEG 159
#include "hash.h"

/*dataItem **aloca_grafo(dataItem **d){
    int i;
    d = (dataItem**)malloc(SIZEG*sizeof(dataItem*));
    for(i = 0; i < SIZEG; i++){
        d[i] = (dataItem*)malloc(SIZEG*sizeof(dataItem));
    }
   return d;
}*/



/*int inserir_dados(dataItem *d, dataItem **m){
    int i, j;

    for(i = 0; i < SIZEG; i++){
       m[i][j] = d[i];
    }
    i = 0;
    for(j = 0; j < SIZEG; j++){
        m[i][j] = d[j];
    }
    return 0;
}*/

struct vizinhanca{
    int pos;
    int qntvizinhos;
};

float convert_la_lo(float la_lo){
    float result;
    la_lo = la_lo/60;
    result = la_lo*1852;
    return result;    
}

float dist(gps A, gps B){
    float d = 0;
    d = sqrt(pow((A.la - B.la),2)+pow((A.lo - B.lo),2));
 
    return d;

}

dataItem *cria_grafo(char *arquivo1, char *arquivo2){
    dataItem *d = (dataItem*)malloc(sizeof(dataItem));

    int i = 0;
    cidade *cidades = getCidades(arquivo1);
    gps *local = getGps(arquivo2);
    d = getItens(cidades,local);
    int k = 0;
    dataItem *cidadesRN = (dataItem*)malloc(167*sizeof(dataItem));
    
    for(int i = 0; i < 5570; i++){
        if(strcmp(d[i].city.estado,"RN") == 0){
            cidadesRN[k] = d[i];
            k++;
        }
    }

    return cidadesRN;
}

vizinhanca matriz_grafo(dataItem *G, float D){
    int j, i;
float g[167][167], V;
    for(i = 0; i < 167; i++){
       j = 0; 
        while(j < 167){

           V = dist(G[i].GPS,G[j].GPS); 

                if(V < D){
                            
                g[i][j] = V;
                g[j][i] = V;

                } else {
                    g[i][j] = 0;
                    g[i][j] = 0;
                }
                            
            j++;
        }    
    }

    int aux = 0;
    vizinhanca vizinhos;
    vizinhos.qntvizinhos = 0;
    vizinhos.pos = 0; 

    for(i = 0; i < 167; i++){
        j = 0;
        while(j < 167){
            if (g[i][j] > 0){
                aux++;
            }
        }
        if (aux > vizinhos.qntvizinhos){
            vizinhos.qntvizinhos = aux;
            vizinhos.pos = i;
            aux = 0;
        }
    }

    return vizinhos;
}

/*dataItem **quilometros(dataItem **d){
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
}*/

#endif