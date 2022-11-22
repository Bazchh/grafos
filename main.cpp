#include "bibliotecas/grafos.cpp"

int main(){
    
    //dataItem **m;
    //m = aloca_grafo(m);
    dataItem *G = cria_grafo((char*) "cidades.csv",(char*) "coordenada.csv");
    float D[] = {0.05,0.1,0.15,0.20,0.25}, V;

    vizinhanca R;

    R = matriz_grafo(G,D[0]);

    printf("\nCidade com mais vizinhos: %i na posição %i\n\n", R.qntvizinhos, R.pos);
    //inserir_dados(d,m); 
     //m = quilometros(m);
    return 0;
}