#ifndef FILA_DINAMICA_H
#define FILA_DINAMICA_H

#include "atleta.h"

struct celula{

	Atleta atleta;
	struct celula *prox;
};

typedef struct celula *celula_ptr;

typedef struct{
	celula_ptr inicio;
}Fila;

void iniciaFila(Fila *f);
int vazioFila(Fila f);
void insereFila(Fila *f, Atleta a);
void mostraFila(Fila f);
Atleta removeFila(Fila *f);

#endif
