#include <stdio.h>
#include <stdlib.h>
#include "grafo2.h"

int main(){
    grafo2 g;
    leGrafo(&g, "grafo.txt");
    mostrarGrafo(g);
    return 0;
}