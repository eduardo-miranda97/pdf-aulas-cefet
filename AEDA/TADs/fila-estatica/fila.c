#include "atleta.h"
#include "fila.h"
#include <stdio.h>

void mostraFila(Fila f);
void insereFila(Fila *f, Atleta a);
Atleta removeFila(Fila *f);
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

Atleta removeFila(Fila *f){
    if (vazioFila(*f) == 1){
        printf("Fila vazia. Nao eh possivel remover elementos.");
        return;
    }

    Atleta primeiro = f->atletas[0];
    for (int i = 0; i < f->ultimo - 1; i++){
        f->atletas[i] = f->atletas[i + 1];
    }
    f->ultimo--;

    return primeiro;
}

int cheioFila(Fila f){
    if (f.ultimo == 5){
        return 1;
    }
    return 0;
}

void insereFila(Fila *f, Atleta a){
    if (cheioFila(*f) == 1){
        printf("Fila cheia. Nao eh possivel inserir.");
        return;
    }

    f->atletas[f->ultimo] = a;
    f->ultimo++;
}

void mostraFila(Fila f){
    if (vazioFila(f) == 1){
        printf("Nao a elementos na fila a serem mostrados.");
        return;
    }

    for (int i = 0; i < f.ultimo; i++)
        printAtleta(f.atletas[i]);
}