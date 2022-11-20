#include "bibliotecas/grafos.cpp"

int main(){
    dataItem *d = (dataItem*)malloc(sizeof(dataItem));
    grafo g;
    init_grafo(g);
    int i = 0, j = 0;
    dataItem **m = (dataItem**)malloc(SIZEG*sizeof(dataItem*));
    
    for(i = 0; i < SIZEG; i++){
        m[i] = (dataItem*)malloc(sizeof(dataItem));
    }
    
    char *arquivo1 =(char*) "cidades.txt";
    char *arquivo2 =(char*) "coordenadas.csv";    
    cidade *cidades = getCidades(arquivo1);
    gps *local = getGps(arquivo2);
    d = getItens(cidades,local);   
    return 0;
}