#ifndef GRAFO_H
#define GRAFO_H

struct celula{
    int vertice;
    struct celula *prox;
};

typedef struct celula *celula_ptr;

typedef struct{
    int nVertices;
    celula_ptr *vertices;
}grafo;

void leGrafo(grafo *g, char arq[]);
void mostrarGrafo(grafo g);

#endif