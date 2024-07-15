
#include <stdio.h>
#include <stdlib.h>

#include "atleta.h"
#include "fila_dinamica.h"

void iniciaFila(Fila *f);
int vazioFila(Fila f);
void insereFila(Fila *f, Atleta a);
void mostraFila(Fila f);
Atleta removeFila(Fila *f);

void iniciaFila(Fila *f){
    // Inicia a fila com nenhum endereco
    f->inicio = NULL;
}

void insereFila(Fila *f, Atleta a){
    // Caso a fila esteja vazia
    if (vazioFila(*f)){
        // Cria uma nova celula e coloca ela como celula inicial da fila
        celula_ptr a1 = (celula_ptr) malloc(sizeof(struct celula));
        a1->atleta = a;
        a1->prox = NULL;
        f->inicio = a1;
        return;
    }


    // Caso contrario percorremos ate a ultima celula preenchida
    celula_ptr a1 = f->inicio;
    while (a1->prox != NULL){
        a1 = a1->prox;
    }

    // Criamos uma nova celula com o atleta que foi passado
    celula_ptr a2 = (celula_ptr) malloc(sizeof(struct celula));
    a2->atleta = a;
    a2->prox = NULL;

    // Encadeamos a nova celula criada com o restante da fila
    a1->prox = a2;
    return;
}

void mostraFila(Fila f){
    // Inicia uma celula auxiliar com o inicio da fila

    /* Percorre toda a fila "caminhando" utilizando os enderecos "prox"
     e chama a funcao printAtleta para mostrar os dados de cada atleta na fila
    */
}


Atleta removeFila(Fila *f){

    // Verifica se a fila nao esta vazia
        // Caso esteja avisar que nao e possivel remover atletas de filas vazias e encerrar a funcao
        // Retornando um novo atleta com as informacoes vazias.


    // Caso contrario
    // Salva a informacao do primeiro atleta da fila

    // Salva a primeira celula da fila em uma variavel auxiliar

    // Atualiza o primeiro da fila para o proximo elemento da fila

    // Libera a memoria da primeira celula utilizando a funcao free()
    // Exemplo: free(aux);

    // Retorna o atleta que foi salvo
}


int vazioFila(Fila f){
    // Verifica se o ponteiro pro inicio da fila esta vazio
        // Retornar 1 caso verdadeiro
    
    // Retornar 0 caso contrario
}
