#ifndef PILHA_DINAMICA_H
#define PILHA_DINAMICA_H

struct celula{
	int elem;
	struct celula *ant;
};

typedef struct celula *celula_ptr;

typedef struct{
	celula_ptr topo;
}Pilha;

void iniciaPilha(Pilha *f);
int vazioPilha(Pilha f);
void inserePilha(Pilha *f, int a);
void mostraPilha(Pilha f);
int removePilha(Pilha *f);

#endif
