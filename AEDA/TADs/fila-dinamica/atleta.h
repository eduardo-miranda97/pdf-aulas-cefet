
#ifndef ATLETA_H
#define ATLETA_H

typedef struct{
    int idade;
    float peso;
    float altura;
    char nome[50];
    int cpf;
    int cansaco;
}Atleta;

void correr(Atleta *a1);
void descansar(Atleta *a1);
void inicializa(Atleta *a1);
void printAtleta(Atleta a1);

#endif
