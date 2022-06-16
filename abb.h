#include <stdio.h>
#include <stdlib.h>

typedef struct dadosBasicos{
   
    //Dados iniciais da encomenda de um livro
    int id; //identificador
    char * nome_aluno;
    int matricula;
    char * descricao;
    
    //mecanismo p/ unir nos!
    struct dadosBasicos * pai;
    struct dadosBasicos * esq;
    struct dadosBasicos * dir;
}dadosBasicos;

typedef struct dadosCompletos{
   
    //Dados iniciais da encomenda de um livro
    int id; //identificador
    char * nome_aluno;
    int matricula;
    char * descricao;
    char * campus_aluno;
    char * campus_livro;
    int prioridade;
    
}dadosCompletos;

dadosBasicos * raiz = NULL;

dadosBasicos* buscar(int id, dadosBasicos *aux){
    
    if(aux != NULL){
        if(aux->id == id){
            return aux;
        }else if(id < aux->id){
            if(aux->esq != NULL){
                return buscar(id, aux->esq);
            }else{
                return aux;
            }
        }else if(id > aux->id){
            if(aux->dir != NULL){
                return buscar(id, aux->dir);
            }else{
                return aux;
            }
        }
    }else{
        return NULL;
    }
}

void add_abb(int id, char *nome_aluno, int matricula, char *descricao){

    dadosBasicos* aux = buscar(id, raiz);
    
    if(aux != NULL && aux->id == id){
        printf("Insercao invalida!\n");
    }else{
        
        dadosBasicos* novo = malloc(sizeof(dadosBasicos));
        novo->id = id;
        novo->nome_aluno = nome_aluno;
        novo->matricula = matricula;
        novo->descricao = descricao;
        novo->esq = NULL;
        novo->dir = NULL;
        
        if(aux == NULL){//arvore esta vazia
            raiz = novo;
        }else{
            if(id < aux->id){
                aux->esq = novo;
            }else{
                aux->dir = novo;
            }
        }
    }
}

dadosBasicos* remover( int id, dadosBasicos* raiz){

    dadosCompletos dadosCompletos;
    dadosBasicos* aux = busca(id, raiz);
    //caso 1: remove quando é uma folha
    if(aux->esq == NULL && aux->dir == NULL){
        if(aux->id <= aux->pai->id){
            aux->pai->esq = NULL;
        }else{
            aux->pai->dir = NULL;
        }

        //adicionadno os dados da struct que será removida na que será adicionadoa na lista de encomendas
        dadosCompletos.id = aux->id;
        dadosCompletos.nome_aluno = aux->nome_aluno;
        dadosCompletos.matricula = aux->matricula;
        dadosCompletos.descricao = aux->descricao;

        free(aux);
        return NULL;
    }else{
        //remove quando tem 1 filho na esquerda
        if(aux->esq != NULL && aux->dir == NULL){
            if(aux->id <= aux->pai->id){
            aux->pai->esq = aux->esq;

             //adicionadno os dados da struct que será removida na que será adicionadoa na lista de encomendas
            dadosCompletos.id = aux->id;
            dadosCompletos.nome_aluno = aux->nome_aluno;
            dadosCompletos.matricula = aux->matricula;
            dadosCompletos.descricao = aux->descricao;

            free(aux);
            return NULL;
            }
        }//remove quando tem 1 filho na direita
        if(aux->esq == NULL && aux->dir != NULL){
            if(aux->id > aux->pai->id){
                aux->pai->dir = aux->dir;
                //adicionadno os dados da struct que será removida na que será adicionadoa na lista de encomendas
                dadosCompletos.id = aux->id;
                dadosCompletos.nome_aluno = aux->nome_aluno;
                dadosCompletos.matricula = aux->matricula;
                dadosCompletos.descricao = aux->descricao;
                free(aux);
                return NULL;
            }
        }
        //remove quando tem 2 filhos
        if(aux->esq != NULL && aux->dir != NULL){
            //efetuo a busca usando o maior dos menores
            dadosBasicos* buscar_maior_dos_menores = aux->esq;
            while(buscar_maior_dos_menores->dir  != NULL){
                buscar_maior_dos_menores= buscar_maior_dos_menores->dir;
            }
            //o ponteiro m apontando para o no com id maior entre as ids menores
            //agora eu efetuo uma troca entre o buscar_maior_dos_menores e o aux
            aux->id = buscar_maior_dos_menores->id;
            return remover(buscar_maior_dos_menores, aux->id);
        }
    }
}

void in_ordem(dadosBasicos *aux){
    
    if(aux->esq != NULL){
        in_ordem(aux->esq);
    }
    printf("%d\n", aux->id);
    printf("%s\n", aux->nome_aluno);
    printf("%d\n", aux->matricula);
    printf("%s\n", aux->descricao);
    if(aux->dir != NULL){
        in_ordem(aux->dir);
        }
}


