#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "lista_servidores.h"
#include "fila.h"
#include "abb.h"


int main(){

    add_servidor(2569, "lauriana silva", 2345678, "transportadora");
    add_servidor(2509, "claudianilda silva", 856974, "bibliotecaria");  
    add_servidor(2596, "jose silva", 856974, "transportador");  
    imprimir_servidor();      
    return 0;
}