#include <stdio.h>
#include <stdlib.h>
#include "id.h"

int tamanho_abb = 0;
Dados_Basicos* busca(int x, Dados_Basicos* aux){
    if(aux == NULL){
        return NULL; 
    }else if(x == aux->id){
        return aux; 
    }else if(x<aux->id){ 
        if(aux->esq != NULL){
            return busca(x, aux->esq);
        }else{
            return aux; 
        }
    }else{
        if(aux->dir != NULL){
            return busca(x, aux->dir);
        }else{
            return aux;
        }
    }
}

void add_abb(char * nome_aluno, int matricula, char * descricao){
    int x = id_aleatorio(tamanho_abb);
    Dados_Basicos* resp = busca(x, raiz);
    if(resp == NULL || resp->id != x){
        Dados_Basicos* novo = malloc(sizeof(Dados_Basicos));
        novo->id = x;
        novo->nome_aluno = nome_aluno;
        novo->matricula = matricula;
        novo->descricao = descricao;
        novo->pai = resp;
        novo->esq = NULL;
        novo->dir = NULL;

        if(resp == NULL){
            raiz = novo;
            tamanho_abb++;
        }else{
            if(x < resp->id){
                resp->esq = novo;
                tamanho_abb ++;
            }else{
                resp->dir = novo;
                tamanho_abb ++;
            }
        }
    }else{
        printf("Add inválida. id duplicada");
    }
}

Dados_Basicos* remover_abb(Dados_Basicos* aux, int x){
    
    
    if(aux == NULL){
        printf("arvore vazia");
        return NULL;
    }else{
        if(aux->id > x){
            aux->esq = remover_abb(aux->esq, x);
            printf("esq \n");
        }else if (aux->id < x){
            aux->dir = remover_abb(aux->dir, x);
            printf("esq \n");
        }else{

            printf("    ID ENCONTRADO\n\n");

            printf("    LOGIN DE ACESSO: \n");
            int cpf;
            printf("        Digite seu CPF: ");
            scanf("%d", &cpf);
            int senha;
            printf("        Digite sua senha: ");
            scanf("%d", &senha);
             
            int acesso = busca_bibliotecario(cpf, senha);
            if(acesso == 1){
                printf("    Escreva o nome do campus onde o aluno que fez o pedido estuda: ");
                char * campus_aluno = malloc(sizeof(char));
                scanf("%s", campus_aluno);
                printf("    Escreva o nome do campus onde se encontra o livro desejado: ");
                char * campus_livro = malloc(sizeof(char));
                scanf("%s", campus_livro);
                printf("    Escreva o valor da prioridade deste pedido: ");
                int prioridade;
                scanf("%d",&prioridade);
                printf("\n");  

                add_fila(aux->id, aux->nome_aluno, aux->matricula, aux->descricao, campus_aluno, campus_livro, prioridade);
            
                if(aux->esq == NULL && aux->dir == NULL){
                    aux = NULL;
                    free(aux);

                }else if(aux->esq == NULL){
                    Dados_Basicos* aux_dir =  aux;
                    aux = aux->dir;               
                    free(aux_dir);

                }else if(aux->dir == NULL){
                    Dados_Basicos* aux_esq =  aux;
                    aux = aux->esq;
                    free(aux_esq);

                }else{
                    Dados_Basicos * maior_dos_menores = aux->esq;
                    while(maior_dos_menores->dir != NULL){
                        maior_dos_menores = maior_dos_menores->dir;
                    } 
                    aux->id = maior_dos_menores->id;
                    aux->matricula = maior_dos_menores->matricula;
                    aux->descricao = maior_dos_menores->descricao;
                    aux->nome_aluno = maior_dos_menores->nome_aluno;
                    maior_dos_menores->id = x;
                    aux->esq  = remover_abb(aux->esq, x);
                }
               
            }
             tamanho_abb--;
        }
    return aux;
    }
}

void in_ordem(Dados_Basicos* aux){
    if(aux!= NULL){
    in_ordem(aux->esq);
    
    printf("        ID: %d\n", aux->id);
    printf("        NOME: %s\n", aux->nome_aluno);
    printf("        MATRICULA: %d\n", aux->matricula);
    printf("        DESCRICAO DO LIVRO: %s\n", aux->descricao);
    printf("\n");
    
    in_ordem(aux->dir);
    }if(raiz == NULL)
        printf("Arvore vazia");
}