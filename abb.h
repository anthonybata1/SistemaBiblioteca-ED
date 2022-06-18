#include <stdio.h>
#include <stdlib.h>

typedef struct dadosBasicos{
    int id;
    char * nome_aluno;
    int matricula;
    char * descricao;
    struct dadosBasicos *pai;
    struct dadosBasicos *esq;
    struct dadosBasicos *dir;
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

dadosBasicos* raiz = NULL;

dadosBasicos* busca(int x, dadosBasicos* aux){
    if(aux == NULL){
        return NULL; //vazia
    }else if(x == aux->id){
        return aux; //encontrei :D
    }else if(x<aux->id){ //buscar no lado esq
        if(aux->esq != NULL){
            return busca(x, aux->esq);
        }else{//esq esta vazia
            return aux; //pai do elemento que não foi encontrado
        }
    }else{//buscar no lado dir
        if(aux->dir != NULL){
            return busca(x, aux->dir);
        }else{//dir esta vazia
            return aux; //pai do elemento que não foi encontrado
        }
    }
}

void add(int x, char * nome_aluno, int matricula, char * descricao){
    dadosBasicos* resp = busca(x, raiz);
    if(resp == NULL || resp->id != x){// vazia ou eu posso adicionar
        dadosBasicos* novo = malloc(sizeof(dadosBasicos));
        novo->id = x;
        novo->nome_aluno = nome_aluno;
        novo->matricula = matricula;
        novo->descricao = descricao;
        novo->pai = resp;
        novo->esq = NULL;
        novo->dir = NULL;

        if(resp == NULL){ //add na raiz
            raiz = novo;
        }else{
            if(x < resp->id){
                resp->esq = novo;
            }else{
                resp->dir = novo;
            }
        }
    }else{//nao posso deixar add novamente pq neste caso
        //havera ids duplicadas
        printf("Add inválida. id duplicada");
    }
}

dadosBasicos* remover(dadosBasicos* raiz, int x){
    dadosCompletos dadosCompletos;
    dadosBasicos* aux = busca(x, raiz);
    //caso 1: remove quando é uma folha
    if(aux->esq == NULL && aux->dir == NULL){
        if(aux->id <= aux->pai->id){
            aux->pai->esq = NULL;
        }else{
            aux->pai->dir = NULL;
        }
        free(aux);
        return NULL;
    }else{
        //remove quando tem 1 filho
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
        }
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
            dadosBasicos* m = aux->esq;
            while(m->dir  != NULL){
                m= m->dir;
            }
            //o ponteiro m apontando para o no com id maior entre as ids menores
            //agora eu efetuo uma troca entre o m e o aux
            aux->id = m->id;
            return remover(m, aux->id);
        }
    }
}

dadosBasicos* busca_arvore(int x){
    dadosBasicos* resp = busca(x, raiz);
    if(resp == NULL){
        //valor nao foi encontrado
        return NULL;
    }else{
        if(resp->id == x){
            return resp;
        }else{
            return NULL;
        }
    }
}

void in_ordem(dadosBasicos* aux){
    if(aux->esq != NULL){
        in_ordem(aux->esq);
    }
    printf("%d \n", aux->id);
    printf("%s\n", aux->nome_aluno);
    printf("%d\n", aux->matricula);
    printf("%s\n", aux->descricao);
    if(aux->dir != NULL){
        in_ordem(aux->dir);
    }
}

int main(){
    add(50, "Lucas", 1526, "diario de um banana");
    add(100, "Lucas", 1527, "diario de um banana");
    add(49, "Lucas", 1528, "diario de um banana");
    add(51, "Lucas", 1529, "diario de um banana");
    add(30, "Lucas", 1530, "diario de um banana");
    add(62, "Lucas", 1531, "diario de um banana");
    add(17, "Lucas", 1532, "diario de um banana");
    in_ordem(raiz);
    remover(raiz, 51);
    printf("\n apos a remocao 1\n");
    in_ordem(raiz);
    remover(raiz, 49);
    printf("\n apos a remocao 2 \n");
    in_ordem(raiz);
    remover(raiz, 100);
    printf("\n apos a remocao 3\n");
    in_ordem(raiz);
     remover(raiz, 17);
    printf("\n apos a remocao 4\n");
    in_ordem(raiz);
    return 0;
}

/* 


 */
