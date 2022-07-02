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
 
    printf("\nSISTEMA DE ENCOMENDA DE LIVRO DA UFC\n");
    int resp = -1;
    while(resp != 0){
        printf(" 1 - Encomendar um livro.\n");
        printf(" 2 - Visualizar encomandas.\n");
        printf(" 3 - Remover uma encomenda de livro.\n");
        printf(" 4 - Remover um pedido de livro.\n");
        printf(" 0 - Sair do sistema!\n");
        printf("Digite a funcionalidade desejada:");
        scanf("%d", &resp);
        if(resp == 1){
            //encomendar um livro
             printf("\nDigite o nome do aluno: ");
             char * nome = malloc(sizeof(char));
             scanf(" %[^\n]s", nome);
             printf("\nDigite a matricula do aluno: ");
             int matricula;
             scanf(" %d", &matricula);
             printf("\nDigite o descricao do livro que deseja buscar: ");
             char * descricao = malloc(sizeof(char));
             scanf(" %[^\n]s", descricao);
            add_abb(nome, matricula, descricao);
        }else if(resp == 3){ 
            printf("\nDigite o ID da encomenda que deseja remover: ");
            int id;
            scanf("%d", &id);
            printf("\n");
            raiz = remover_abb(raiz, id);
            printf("\nFILA DE ENCOMENDAS:\n");
            imprimir_fila();
        }else if(resp == 2){
            in_ordem(raiz);
        }else if(resp == 4){
            //remover da fila de pedidos
        }
    }
    return 0; 
} 
