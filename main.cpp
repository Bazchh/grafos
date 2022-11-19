#include "bibliotecas/grafos.cpp"

int main(){
    dataItem *d = (dataItem*)malloc(sizeof(dataItem));
    grafo g;
    char *arquivo1 =(char*) "cidades.txt";
    char *arquivo2 =(char*) "coordenadasrn.csv";    
    cidade *cidades =  getCidades(arquivo1);
    gps *localizacao =  getGps(arquivo2);
    d = getItens(cidades,localizacao);
    init_grafo(g);
    return 0;
}