#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "lista_servidores.h"
#include "fila_encomendas.h"
#include "abb_pedidos.h"


int main(){
    add_servidor(2569, "lauriana", 2345678, "transportadora");
    add_servidor(2509, "claudianilda", 856974, "bibliotecaria");  
    add_servidor(2533, "jose", 856974, "transportador"); 
    imprimir_servidores(); 
    buscar_servidor(2569, 2345678);   
    return 0;
}