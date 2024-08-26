
#include <stdio.h>
#include <stdlib.h>

#include "lista_dinamica.h"

void iniciaFila(Lista *l);
int vazioLista(Lista l);
void insereLista(Lista *l, int a);
void mostraLista(Lista l);
int removeLista(Lista *l, int x);

void iniciaLista(Lista *l){
    l->inicio = NULL;
}

void insereLista(Lista *l, int a){
    if (vazioLista(*l) == 1){
        celula_ptr a1 = (celula_ptr) malloc(sizeof(struct celula));
        a1->elem = a;
        a1->prox = NULL;
        l->inicio = a1;
        return;
    }

    celula_ptr a1 = l->inicio;
    while (a1->prox != NULL){
        a1 = a1->prox;
    }

    celula_ptr a2 = (celula_ptr) malloc(sizeof(struct celula));
    a2->elem = a;
    a1->prox = a2;
    return;
}

void mostraLista(Lista l){
    celula_ptr a1 = l.inicio;
    while (a1 != NULL){
        printf("%d ", a1->elem);
        a1 = a1->prox;
    }
    printf("\n");
}


int removeLista(Lista *l, int x){
    if (vazioLista(*l) == 1){
        printf("Lista vazia, impossivel remover.");
        return -1;
    }

    celula_ptr a1 = l->inicio;
    if (a1->elem == x){//caso primeiro elemento
        l->inicio = a1->prox;
        free(a1);
        return x;
    }

    while (a1->prox != NULL && a1->prox->elem != x)
        a1 = a1->prox;

    if (a1->prox == NULL && a1->elem != x){
        printf("Elemento %d nao esta na lista", x);
        return -1;
    }

    if (a1->prox == NULL){//caso do ultimo elemento
        free(a1);
        a1=NULL;
        return x;
    }

    celula_ptr aux = a1->prox;
    a1->prox = a1->prox->prox;
    free(aux);
    return x;
}


int vazioLista(Lista l){
    if (l.inicio == NULL)
        return 1;

    return 0;
}
