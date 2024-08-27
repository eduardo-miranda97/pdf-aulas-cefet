#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main(){
    grafo g;
    leGrafo(&g, "grafo.txt");
    mostrarGrafo(g);
    return 0;
}