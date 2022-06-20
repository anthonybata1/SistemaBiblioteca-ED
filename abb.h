#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structs.h"

dadosBasicos* raiz = NULL;
int tamanho_arvore = 0;
//TESTADO
int busca_id(int x, dadosBasicos* auxiliar){
    if(auxiliar == NULL){
        return 0; //vazia
    }else if(x == auxiliar->id){
        return 1; //Id já cadastrado
    }else if(x<auxiliar->id){ //buscar no lado esq
        if(auxiliar->esq != NULL){
            return busca_id(x, auxiliar->esq);
        }else{//esq esta vazia
            return 0; //não há id's iguais no lado esquerdo
        }
    }else{//buscar no lado dir
        if(auxiliar->dir != NULL){
            return busca_id(x, auxiliar->dir);
        }else{//dir esta vazia
            return 0; //não há id's iguais no lado direito
        }
    }
}

//TESTADO
int id_aleatorio(){
    //Dado a TAD ser de tamanho pequeno irei definir como se nao tivessem 
    //mais de 100 pedidos a serem adicionados
    int numero_aleatorio;
    int verificador_id = 1;
    if(tamanho_arvore == 0){
        return 50;
    //assim adicionando sempre uma vez na direita e uma na esquerda
    }else if(tamanho_arvore % 2 == 0){  
        while(verificador_id == 1){
            numero_aleatorio = 1 + (rand() % 49);
            verificador_id = busca_id(numero_aleatorio, raiz);
        }
        return numero_aleatorio; 
    }else if(tamanho_arvore % 2 != 0){
        while(verificador_id == 1){
            numero_aleatorio = 51 + (rand() % 49);
            verificador_id = busca_id(numero_aleatorio, raiz);
        }
        return numero_aleatorio; 
    }    

}

//TESTADO
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

//TESTADO
void add(char * nome_aluno, int matricula, char * descricao){

    int x = id_aleatorio();
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
            tamanho_arvore++;
        }else{
            if(x < resp->id){
                resp->esq = novo;
                tamanho_arvore++;
            }else{
                resp->dir = novo;
                tamanho_arvore++;
            }
        }
    }/* Não precisa desse else pois não há como existir ID's duplicadas. 
    else{//nao posso deixar add novamente pq neste caso havera ids duplicada
        printf("Add inválida. id duplicada");
    }*/
}

//TESTADO
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
        tamanho_arvore--;
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
            tamanho_arvore--;
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
                tamanho_arvore--;
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

//TESTADO
dadosBasicos* buscar_arvore(int x){
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

//TESTADO
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

/*
int main(){
    add("Lucas_01", 1526, "diario de um banana");
    add("Lucas_02", 1527, "diario de um banana");
    add("Lucas_03", 1528, "diario de um banana");
    add("Lucas_04", 1529, "diario de um banana");
    add("Lucas_05", 1530, "diario de um banana");
    add("Lucas_06", 1531, "diario de um banana");
    add("Lucas_07", 1532, "diario de um banana");
    in_ordem(raiz);
    return 0;
}
*/