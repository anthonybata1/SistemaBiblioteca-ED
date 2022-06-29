#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "lista_servidores.h"
#include "fila.h"
#include "abb.h"

int main(){
    add_abb("Lucas1", 1526, "diario de um banana");
    add_abb("Lucas2", 1527, "diario de um banana");
    add_abb("Lucas3", 1528, "diario de um banana");
    add_abb("Lucas4", 1529, "diario de um banana");
    add_abb("Lucas5", 1530, "diario de um banana");
    add_abb("Lucas6", 1531, "diario de um banana");
    add_abb("Lucas7", 1532, "diario de um banana");
    in_ordem(raiz);
    printf("\n");
    raiz = remover_abb(raiz,40);
    printf("\n");
    raiz = remover_abb(raiz,11);
    //toda vez que remove a raiz inicial remove ela o numero diretamente menor que ele
    imprimir_fila();
    printf("\n");
    return 0;
}