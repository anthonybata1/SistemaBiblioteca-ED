#include <stdio.h>
#include <stdlib.h>

servidor * inicio_lista = NULL;
servidor * fim_lista = NULL;
int tamanho_lista = 0;

void add_servidor(int cpf, char *nome, int senha, char *ocupacao){   
            servidor * novo = malloc(sizeof(servidor));
            novo->cpf = cpf;
            novo->nome_serv = nome;
            novo->senha = senha;
            novo->ocupacao = ocupacao;
            novo->prox = NULL;
            novo->ant = NULL;

            if( inicio_lista == NULL ){ //pilha vazia
                inicio_lista = novo;
                fim_lista = novo;
                tamanho_lista++;
            
            }else { // add (todo os casos) antigo inicio_lista da lista
                novo->prox = inicio_lista;
                inicio_lista->ant = novo;
                inicio_lista = novo;
                tamanho_lista++;
                }
}

void imprimir_servidores(){
    servidor * aux = inicio_lista;
    for(int i = 0; i < tamanho_lista; i++){
        printf("Nome do servidor: %s\n", aux->nome_serv);
            aux = aux->prox;
    }
}

int buscar_servidor(int cpf, int senha){
    int resposta = 0;
        if(inicio_lista->cpf == cpf && inicio_lista->senha == senha){//se for o primeiro registro
            resposta = 1;
        }else if(fim_lista->cpf == cpf && fim_lista->senha == senha){//se for o ultimo registro
            resposta = 1;
        }else{
            servidor * aux = inicio_lista;
            for(int i= 0; i < tamanho_lista; i++){
                if(aux->cpf != cpf || aux->senha != senha)
                    aux = aux->prox;
                else
                    break;
            }
            resposta = 1;
        }
        if(resposta == 1){
            
        }
    return resposta;
}
