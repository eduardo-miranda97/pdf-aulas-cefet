
#ifndef FILA_H
#define FILA_H

#define MAX 10

typedef struct 
{
    int v[MAX];
    int ultimo;
}Fila;

void mostraFila(Fila f);
void insereFila(Fila *f, int a);
int removeFila(Fila *f);
int vazioFila(Fila f);
int cheioFila(Fila f);
void iniciaFila(Fila *f);

#endif