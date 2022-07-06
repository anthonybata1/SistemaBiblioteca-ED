#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "lista_servidores.h"
#include "fila_encomendas.h"
#include "abb_pedidos.h"

int main(){    
    add_servidor(2569, "lauriana", 2345678, 't');
    add_servidor(2509, "claudianilda", 856974, 'b');  
    add_servidor(2533, "jose", 856974, 't'); 

    add_abb("nome3", 1528, "livro3");
    add_abb("nome1", 1526, "livro1");
    add_abb("nome2", 1527, "livro2");
    add_abb("nome5", 1528, "livro5");
    add_abb("nome6", 1526, "livro6");
    add_abb("nome7", 1527, "livro7");

    printf("in_ordem01_____________________________________\n");
    in_ordem(raiz);
    printf("\n");
    remover_abb(raiz,50);
    remover_abb(raiz,40);
    printf("in_ordem02________________________________\n");
    in_ordem(raiz);
    printf("\n");
    add_abb("nome4", 1530, "livro4");
    printf("in_ordem03________________________________\n");
    in_ordem(raiz);

    //toda vez que remove a raiz inicial remove ela o numero diretamente menor que ele
    //raiz = remover_abb(raiz,50); //toda vez que remove a raiz inicial remove ela o numero diretamente menor que ele
    /* printf("ABB:________________________________________________________________\n");
    in_ordem(raiz); */
    //printf("FILA:________________________________________________________________\n");
    //imprimir_fila();
   // remover_fila(40);
    printf("\n");
    return 0;
} 
