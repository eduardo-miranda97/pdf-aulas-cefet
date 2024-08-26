 
#include <stdio.h>
#include "fila.h"

void mostraFila(Fila f);
void insereFila(Fila *f, int a);
int removeFila(Fila *f);
int vazioFila(Fila f);
int cheioFila(Fila f);
void iniciaFila(Fila *f);

void iniciaFila(Fila *f){
    f->ultimo = 0;
}

int vazioFila(Fila f){
    if (f.ultimo == 0)
        return 1;

    return 0;
}

int removeFila(Fila *f){
    if (vazioFila(*f) == 1){
        printf("Fila vazia. Nao eh possivel remover elementos.");
        return -1;
    }

    int primeiro = f->v[0];
    for (int i = 0; i < f->ultimo - 1; i++){
        f->v[i] = f->v[i + 1];
    }
    f->ultimo--;

    return primeiro;
}

int cheioFila(Fila f){
    if (f.ultimo == MAX){
        return 1;
    }
    return 0;
}

void insereFila(Fila *f, int a){
    if (cheioFila(*f) == 1){
        printf("Fila cheia. Nao eh possivel inserir.");
        return;
    }

    f->v[f->ultimo] = a;
    f->ultimo++;
}

void mostraFila(Fila f){
    if (vazioFila(f) == 1){
        printf("Nao a elementos na fila a serem mostrados.");
        return;
    }

    for (int i = 0; i < f.ultimo; i++)
        printf("%d ",f.v[i]);
}