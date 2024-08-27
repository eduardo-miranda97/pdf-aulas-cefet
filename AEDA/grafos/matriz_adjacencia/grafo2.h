#ifndef GRAFO2_H
#define GRAFO2_H


typedef struct{
    int **m;
    int nVertices;
}grafo2;

void leGrafo(grafo2 *g, char arq[]);
void mostrarGrafo(grafo2 g);
void eliminaGrafo(grafo2 *g);

#endif