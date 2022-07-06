#include <stdlib.h>

Dados_Completos * inicio_fila = NULL;
Dados_Completos * fim_fila = NULL;
int tamanho_fila = 0; 

void add_fila(int id, char * nome_aluno, int matricula, char *descricao, char *campus_aluno, char *campus_livro, int prioridade){
    
        Dados_Completos* novo = malloc(sizeof(Dados_Completos));
        novo->id = id;
        novo->nome_aluno = nome_aluno;
        novo->matricula = matricula;
        novo->descricao = descricao;
        novo->campus_aluno = campus_aluno;
        novo->campus_livro = campus_livro;
        novo->prioridade = prioridade;
        novo->prox = NULL;
    
        if(inicio_fila == NULL){ 
            inicio_fila = novo;
            fim_fila = novo;
            tamanho_fila++;
        }else if(inicio_fila->prioridade < novo->prioridade){ 
            novo->prox = inicio_fila;
            inicio_fila = novo;
            tamanho_fila++;
        }else if(fim_fila->prioridade > novo->prioridade){ 
            fim_fila->prox = novo;
            fim_fila = novo;
            tamanho_fila++;
        }else{ 
            Dados_Completos * aux = inicio_fila;
            for(int i = 0; i < tamanho_fila; i++){
                if(aux->prioridade > novo->prioridade)
                    aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
            tamanho_fila++;
        }
}

void remover_fila(){
    Dados_Completos *aux = inicio_fila;

    printf("    LOGIN DE ACESSO: \n");
    int cpf;
    printf("        Digite seu CPF: ");
    scanf("%d", &cpf);
    int senha;
    printf("        Digite sua senha: ");
    scanf("%d", &senha);
             
    int acesso = busca_transportador(cpf, senha);
    if(acesso == 1){
        
        inicio_fila = inicio_fila->prox;
        printf("    Removido com sucesso! \n");
        printf("    Dados do item removido \n");
        printf("        Codigo do pedido: %d\n", aux->id);
        printf("        Matricula do estudante: %d\n", aux->matricula);
        printf("        Nome do aluno: %s\n", aux->nome_aluno);
        printf("        Descricao do pedido: %s\n", aux->descricao);
        printf("        Campus do aluno: %s\n", aux->campus_aluno);
        printf("        Campus do livro: %s\n", aux->campus_livro);
        printf("        Prioridade do pedido: %d\n\n", aux->prioridade);
    free(aux);   
    } 
}

void imprimir_fila(){
    Dados_Completos* aux = inicio_fila;
    for(int i = 0; i < tamanho_fila; i++){
        printf("        Codigo do pedido: %d\n", aux->id);
        printf("        Matricula do estudante: %d\n", aux->matricula);
        printf("        Nome do aluno: %s\n", aux->nome_aluno);
        printf("        Descricao do pedido: %s\n", aux->descricao);
        printf("        Campus do aluno: %s\n", aux->campus_aluno);
        printf("        Campus do livro: %s\n", aux->campus_livro);
        printf("        Prioridade do pedido: %d\n\n", aux->prioridade);
        aux = aux->prox;
    }
}