
#ifndef FILA_H
#define FILA_H

#define MAX 10

typedef struct 
{
    int v[MAX];
    int ultimo;
}Lista;

void mostraLista(Lista l);
void insereLista(Lista *l, int a);
int removeLista(Lista *l, int elemento);
int vazioLista(Lista l);
int cheioLista(Lista l);
void iniciaLista(Lista *l);

#endif