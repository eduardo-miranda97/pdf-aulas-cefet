
#include <stdio.h>
#include <stdlib.h>
#include "grafo2.h"


void leGrafo(grafo2 *g, char arq[]);
void mostrarGrafo(grafo2 g);
void eliminaGrafo(grafo2 *g);

void leGrafo(grafo2 *g, char arquivo[]){
    FILE *arq;
    arq = fopen(arquivo, "rt");
    if (&arq == NULL){
        printf("Problemas na criacao do arquivo \n");
    }

    int result, x, y, i, j;
    result = fscanf(arq, "%d", &x);
    g->nVertices = x;
    g->m = malloc(sizeof(int*) * g->nVertices);
    for (i = 0; i < g->nVertices; i++) {
        g->m[i] = malloc(sizeof(int));
    }

    for(i = 0; i<g->nVertices; i++){
        for(j = 0; j<g->nVertices; j++){
            g->m[i][j] = 0;
            g->m[i][j] = 0;
        }
    }

    result = fscanf(arq, "%d %d", &x, &y);
    while (result != EOF){
        g->m[x][y] = 1;
        g->m[y][x] = 1;
        result = fscanf(arq, "%d %d", &x, &y);
    }
    fclose(arq);
}

void mostrarGrafo(grafo2 g){
    for (int i=0; i<g.nVertices; i++){
        printf("%d:", i);
        for (int j=0; j<g.nVertices; j++){
            if (g.m[i][j] == 1)
                printf("%d ", j);
        }
        printf("\n");
    }
}

void eliminaGrafo(grafo2 *g){
    int i;
    for (i = 0; i < g->nVertices; i++) {
        free(g->m[i]);
    }
    free(g->m);
}