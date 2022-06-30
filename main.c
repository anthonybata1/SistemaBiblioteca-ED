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

    add_abb("nome1", 1526, "livro1");
    add_abb("nome2", 1527, "livro2");
    add_abb("nome3", 1528, "livro3");
    add_abb("nome4", 1529, "livro4");
    add_abb("nome5", 1530, "livro5");
    add_abb("nome6", 1531, "livro6");
    add_abb("nome7", 1532, "livro7");
    in_ordem(raiz);
    printf("\n");
    raiz = remover_abb(raiz,50); //toda vez que remove a raiz inicial remove ela o numero diretamente menor que ele
    imprimir_fila();
    printf("\n"); 
    return 0; 
}