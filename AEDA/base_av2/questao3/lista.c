 
#include <stdio.h>
#include "lista.h"

void mostraLista(Lista l);
void insereLista(Lista *l, int a);
int removeLista(Lista *l, int elemento);
int vazioLista(Lista l);
int cheioLista(Lista l);
void iniciaLista(Lista *l);

void iniciaLista(Lista *l){
    l->ultimo = 0;
}

int vazioLista(Lista l){
    if (l.ultimo == 0)
        return 1;

    return 0;
}

int removeLista(Lista *l, int elemento){
    if (vazioLista(*l) == 1){
        printf("Lista vazia. Nao eh possivel remover elementos.");
        return -1;
    }

    int i = 0;
    int retorno;
    for (i = 0; i < l->ultimo - 1; i++){
        if (l->v[i] == elemento){
            retorno = elemento;
            break;
        }
    }

    for (; i < l->ultimo - 1; i++){
        l->v[i] = l->v[i + 1];
    }
    l->ultimo--;

    return retorno;
}

int cheioLista(Lista l){
    if (l.ultimo == MAX){
        return 1;
    }
    return 0;
}

void insereLista(Lista *l, int a){
    if (cheioLista(*l) == 1){
        printf("Lista cheia. Nao eh possivel inserir.");
        return;
    }

    l->v[l->ultimo] = a;
    l->ultimo++;
}

void mostraLista(Lista l){
    if (vazioLista(l) == 1){
        printf("Nao a elementos na fila a serem mostrados.");
        return;
    }

    for (int i = 0; i < l.ultimo; i++)
        printf("%d ",l.v[i]);
    printf("\n");
}