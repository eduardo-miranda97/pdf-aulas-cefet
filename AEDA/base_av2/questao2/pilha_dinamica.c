
#include <stdio.h>
#include <stdlib.h>

#include "pilha_dinamica.h"

void iniciaFila(Pilha *f);
int vazioPilha(Pilha f);
void inserePilha(Pilha *f, int a);
void mostraPilha(Pilha f);
int removePilha(Pilha *f);

void iniciaPilha(Pilha *f){
    f->topo = NULL;
}

void inserePilha(Pilha *f, int a){
    if (vazioPilha(*f) == 1){
        celula_ptr a1 = (celula_ptr) malloc(sizeof(struct celula));
        a1->elem = a;
        a1->ant = NULL;
        f->topo = a1;
        return;
    }

    celula_ptr a2 = (celula_ptr) malloc(sizeof(struct celula));
    a2->elem = a;
    a2->ant = f->topo;

    f->topo = a2;
    return;
}

void mostraPilha(Pilha f){
    celula_ptr a1 = f.topo;
    while (a1 != NULL){
        printf("%d ", a1->elem);
        a1 = a1->ant;
    }
    printf("\n");
}


int removePilha(Pilha *f){

    if (vazioPilha(*f) == 1){
        printf("Pilha vazia, impossivel remover.");
        return -1;
    }

    int retorno = f->topo->elem;
    celula_ptr a1 = f->topo;

    f->topo = f->topo->ant;

    free(a1);
    return retorno;
}


int vazioPilha(Pilha f){
    if (f.topo == NULL)
        return 1;

    return 0;
}
