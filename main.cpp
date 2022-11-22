#include "bibliotecas/grafos.cpp"

int main(){
    
    //dataItem **m;
    //m = aloca_grafo(m);
    dataItem *G = cria_grafo((char*) "cidades.csv",(char*) "coordenada.csv");
    float D[] = {0.05,0.1,0.15,0.20,0.25};

    vizinhanca R;
    for(int i = 0; i < 5; i++){
    R = matriz_grafo(G,D[i]);
    printf("\nA cidade com mais vizinhos com base na distancia minima D = %f está"
    "\nna posição [%i] %s com %i vizinhos\n",D[i], R.pos,G[R.pos].city.cidade, R.qntvizinhos);
    if(R.pos == R.posvoid){
        printf("\nNão existe cidade sem vizinhos com base na distancia minima %f\n", D[i]);
        printf("\n==========================================================================\n\n");
    }else if(R.pos != R.posvoid){
        printf("\nA cidade que não possui vizinhos com base na distancia minima %f está"
    "\nna posição [%i] %s", D[i], R.posvoid, G[R.posvoid].city.cidade);
    printf("\n\n============================================================================\n\n");
    }
    
    }
    //inserir_dados(d,m); 
     //m = quilometros(m);
    return 0;
}