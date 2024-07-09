#include "atleta.h"

typedef struct 
{
    Atleta atletas[5];
    int ultimo;
}Fila;

void mostraFila(Fila f);
void insereFila(Fila *f, Atleta a);
Atleta removeFila(Fila *f);
int vazioFila(Fila f);
int cheioFila(Fila f);
void iniciaFila(Fila *f);