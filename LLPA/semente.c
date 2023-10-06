
#include <stdio.h>

typedef struct
{
    char marca[50];
    float preco;
    int volume;

} Caneca;

Caneca cadastra_caneca(){
    Caneca c;
    printf("Digite a marca da caneca");
    scanf("%s", c.marca);
    printf("Digite o preco da caneca");
    scanf("%f", &c.preco);
    printf("Digite o volume da caneca em ML");
    scanf("%d", &c.volume);
    return c;
}

void caneca_cara(Caneca canecas[]){
    int i;
    int indMaisCara=0;
    for (i=0;/*Ir até a última caneca cadastrada*/; i++){
        if (canecas[indMaisCara].preco < canecas[i].preco)
            indMaisCara = i;
    }
    printf("Marca mais cara %s", canecas[indMaisCara].marca);
    printf("Preço mais cara %f", canecas[indMaisCara].preco);
    printf("Volum mais cara %d", canecas[indMaisCara].volume);
}

void controleDiscos(){
    int op=0;
    Caneca canecas[5];

    printf("Digite 1 para cadastrar uma Caneca.\n");
    printf("Digite 2 para mostrar a Caneca mais cara.\n");
    scanf("%d", &op);
    if (op==1){
        canecas[0] = cadastra_caneca();
    }
    else if(op==2){
        caneca_cara(canecas);
    }
    caneca_cara(canecas);
}

int main(){
    int op=0;

    while (op!=6){
        /*Devemos ler a opcao da funcao menu "Função 6"*/
        if (op==4){
            controleDiscos();
        }
    }
    return 0;
}
