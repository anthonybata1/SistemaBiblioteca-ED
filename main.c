#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "lista_servidores.h"
#include "fila_encomendas.h"
#include "abb_pedidos.h"

int main(){  
    add_servidor(0001, "Laura", 2345678, 't');
    add_servidor(4101, "Patricia", 123654, 't');  
    add_servidor(2502, "Jose", 142536, 't'); 
    add_servidor(2323, "Joao", 635241, 't');  
    add_servidor(8564, "Lucas", 748596, 't');  
    add_servidor(5569, "Louise", 695847, 'b');  
    add_servidor(8521, "Pamela", 784512, 'b');  
    add_servidor(4736, "Felipe", 986532, 'b');  
    add_servidor(2300, "Fernando", 125634, 'b');  
    add_servidor(1256, "Flavia", 325614, 'b');  
 
    printf("\nSISTEMA DE ENCOMENDA DE LIVRO DA UFC\n");
    int resp = -1;
    while(resp != 0){
        printf("\n 1 - Pedir um livro.\n");
        printf(" 2 - Visualizar pedido.\n");
        printf(" 3 - Remover um pedido.\n");
        printf(" 4 - Visualizar encomendas.\n");
        printf(" 5 - Remover um encomendas.\n");
        printf(" 0 - Sair do sistema!\n");
        printf("Digite a funcionalidade desejada:");
        scanf("%d", &resp);
        if(resp == 1){
             printf("\n     Digite o nome do aluno: ");
             char * nome = malloc(sizeof(char));
             scanf(" %[^\n]s", nome);
             printf("\n     Digite a matricula do aluno: ");
             int matricula;
             scanf("%d", &matricula);
             printf("\n     Digite o descricao do livro que deseja buscar: ");
             char * descricao = malloc(sizeof(char));
             scanf(" %[^\n]s", descricao);
            add_abb(nome, matricula, descricao);
        }else if(resp == 3){ 
            printf("\n      Digite o ID do pedido que deseja remover: ");
            int id_teste;
            scanf("%d", &id_teste);
            printf("\n");
            raiz = remover_abb(raiz, id_teste);
        }else if(resp == 4){ 
            printf("\n      FILA DE ENCOMENDAS:\n\n");
            imprimir_fila();
        }else if(resp == 2){
             printf("\n     ENCOMENDAS DE LIVROS\n\n");
            in_ordem(raiz);
        }else if(resp == 5){
            remover_fila();
        }
    }
    return 0; 
} 