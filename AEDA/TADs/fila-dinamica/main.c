
#include "atleta.h"
#include "fila_dinamica.h"

#include <stdio.h>

int main(){
    Fila f;
    iniciaFila(&f);
    
    Atleta a1;
    inicializa(&a1);
    insereFila(&f, a1);

    Atleta a2;
    inicializa(&a2);
    insereFila(&f, a2);

    Atleta a3;
    inicializa(&a3);
    insereFila(&f, a3);

    mostraFila(f);

    removeFila(&f);
    mostraFila(f);

    return 0;
}