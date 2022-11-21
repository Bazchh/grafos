#include "bibliotecas/grafos.cpp"

int main(){
    dataItem *d = (dataItem*)malloc(sizeof(dataItem));

    int i = 0, j = 0;
    dataItem **m;
    m = aloca_grafo(m);
    char *arquivo1 =(char*) "cidades.csv";
    char *arquivo2 =(char*) "coordenada.csv";    
    cidade *cidades = getCidades(arquivo1);
    gps *local = getGps(arquivo2,cidades);
    d = getItens(cidades,local);
    inserir_dados(d,m); 
     m = quilometros(m);
    return 0;
}