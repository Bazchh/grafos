#ifndef  CABEÇALHO_CIDADE_CPP
#include "hash.cpp"

struct cidade;
struct gps;
struct dataItem;
dataItem *getItens(cidade *, gps *);
void printDataItens(dataItem *);
void saveDataItens(dataItem *);
cidade *getCidades(char *arquivo);
gps *getGps(char *);
char* remover(char* text);
#endif