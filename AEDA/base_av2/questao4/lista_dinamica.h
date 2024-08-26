#ifndef PILHA_DINAMICA_H
#define PILHA_DINAMICA_H

struct celula{
	int elem;
	struct celula *prox;
};

typedef struct celula *celula_ptr;

typedef struct{
	celula_ptr inicio;
}Lista;

void iniciaLista(Lista *l);
int vazioLista(Lista l);
void insereLista(Lista *l, int a);
void mostraLista(Lista l);
int removeLista(Lista *l, int x);

#endif
