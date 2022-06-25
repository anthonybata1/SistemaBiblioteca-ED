#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

dadosCompletos * inicio = NULL;
dadosCompletos * fim = NULL;
int tam = 0;

void add_fila(int id, char * nome_aluno, int matricula, char *descricao, char *campus_aluno, char *campus_livro, int prioridade){
    
        dadosCompletos * novo = malloc(sizeof(dadosCompletos));
        novo->id = id;
        novo->nome_aluno = nome_aluno;
        novo->matricula = matricula;
        novo->descricao = descricao;
        novo->campus_aluno = campus_aluno;
        novo->campus_livro = campus_livro;
        novo->prioridade = prioridade;
        novo->prox = NULL;
    
        if(inicio == NULL){ //lista vazia
            inicio = novo;
            fim = novo;
            tam++;
        }else if(inicio->prioridade < novo->prioridade){ //inicio
            novo->prox = inicio;
            inicio = novo;
            tam++;
        }else if(fim->prioridade > novo->prioridade){ //fim
            fim->prox = novo;
            fim = novo;
            tam++;
        }else{ // "no meio"
            dadosCompletos * aux = inicio;
            for(int i = 0; i < tam; i++){
                if(aux->prioridade > novo->prioridade)
                    aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
            tam++;
        }
}

void imprimir_fila(){
    dadosCompletos * aux = inicio;
    for(int i = 0; i < tam; i++){
        printf("Matricula: %d\n", aux->matricula);
            aux = aux->prox;
    }
}