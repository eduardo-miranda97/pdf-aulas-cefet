
#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

void leGrafo(grafo *g, char arq[]);
void mostrarGrafo(grafo g);

void leGrafo(grafo *g, char arquivo[]){
    FILE *arq;
    arq = fopen(arquivo, "rt");
    if (&arq == NULL){
        printf("Problemas na criacao do arquivo \n");
    }

    int result, x, y;

    result = fscanf(arq, "%d", &x);
    g->vertices = malloc(x * sizeof(struct celula *));
    g->nVertices = x;

    for (int i=0; i<x; i++){
        g->vertices[i] = malloc(sizeof(celula_ptr));
        g->vertices[i]->vertice = -1;
        g->vertices[i]->prox = NULL;
    }

    result = fscanf(arq, "%d %d", &x, &y);
    celula_ptr aux;
    while (result != EOF){
        
        aux = g->vertices[x];
        while (aux->prox != NULL){
            aux = aux->prox;
        }
        celula_ptr aux2 = (celula_ptr)malloc(sizeof(struct celula));
        aux2->vertice = y;
        aux2->prox = NULL;
        aux->prox = aux2;

        aux = g->vertices[y];
        while (aux->prox != NULL){
            aux = aux->prox;
        }
        aux2 = (celula_ptr)malloc(sizeof(struct celula));
        aux2->vertice = x;
        aux2->prox = NULL;
        aux->prox = aux2;

        result = fscanf(arq, "%d %d", &x, &y);
    }

    fclose(arq);
}

void mostrarGrafo(grafo g){
    celula_ptr aux;
    for (int i=0; i<g.nVertices; i++){
        aux = g.vertices[i];
        printf("%d:", i);
        aux = aux->prox;
        while (aux != NULL){
            printf("%d ", aux->vertice);
            aux = aux->prox;
        }
        printf("\n");
    }
}
