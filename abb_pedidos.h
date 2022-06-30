#include <stdio.h>
#include <stdlib.h>
#include "id.h"

Dados_Basicos* busca(int x, Dados_Basicos* aux){
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

void add_abb(char * nome_aluno, int matricula, char * descricao){
    int x = id_aleatorio();
    Dados_Basicos* resp = busca(x, raiz);
    if(resp == NULL || resp->id != x){// vazia ou eu posso adicionar
        Dados_Basicos* novo = malloc(sizeof(Dados_Basicos));
        novo->id = x;
        novo->nome_aluno = nome_aluno;
        novo->matricula = matricula;
        novo->descricao = descricao;
        novo->pai = resp;
        novo->esq = NULL;
        novo->dir = NULL;

        if(resp == NULL){ //add na raiz
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
    }else{//nao posso deixar add novamente pq neste caso
        //havera ids duplicadas
        printf("Add inválida. id duplicada");
    }
}

Dados_Basicos* remover_abb(Dados_Basicos* aux, int x){

    if(aux == NULL){//se não existe esse aux
        return NULL;
    }else{
        if(aux->id > x){//se o id desse aux é maior que o valor passado para ser encontrado
            aux->esq = remover_abb(aux->esq, x);
        }else if (aux->id < x){//se o id desse aux é menor que o valor passado para ser encontrado
            aux->dir = remover_abb(aux->dir, x);
        }else{//se foi encontrado o x, começa-se os formatos de remoção       
            
 
            //LOGIN DE ACESSO DOS SERVIDORES
            printf("LOGIN DE ACESSO: \n");
            int cpf;
            printf("Digite seu CPF: ");
            scanf("%d", &cpf);
            int senha;
            printf("Digite sua senha: ");
            scanf("%d", &senha);
            
            int acesso = buscar_servidor(cpf, senha);          
            
            if(acesso == 1){

                //ADICIONAR NA FILA DEPOIS DO ACESSO FEITO
                char * campus_aluno = malloc(sizeof(char));
                printf("Escreva o nome do campus onde o aluno que fez o pedido estuda: ");
                scanf("%s", campus_aluno);
                char * campus_livro = malloc(sizeof(char));
                printf("Escreva o nome do campus onde se encontra o livro desejado: ");
                scanf("%s", campus_livro);
                int prioridade;
                printf("Escreva o valor da prioridade deste pedido: ");
                scanf("%d",&prioridade);
                printf("\n");  

                add_fila(aux->id, aux->nome_aluno, aux->matricula, aux->descricao, campus_aluno, campus_livro, prioridade);
        
                
                //POR FIM, REMOVE DA ABB
                if(aux->esq == NULL && aux->dir == NULL){//sem filhos
                    aux = NULL;
                    free(aux);
                }else if(aux->esq == NULL){//só tem um filho a diretia
                    Dados_Basicos* aux_dir =  aux;
                    aux = aux->dir;               
                    free(aux_dir);

                }else if(aux->dir == NULL){//so tem um filho a esquerda
                    Dados_Basicos* aux_esq =  aux;
                    aux = aux->esq;
                    free(aux_esq);

                }else{//tem os dois filhos
                    Dados_Basicos * maior_dos_menores = aux->esq;//recebe uma vez para a esquerda
                    while(maior_dos_menores->dir != NULL){
                        maior_dos_menores = maior_dos_menores->dir;//e o maximo que der para direita
                    }
                    aux->id = maior_dos_menores->id;//troca os valores (todos os dados)
                    maior_dos_menores->id = x;
                    aux->esq  = remover_abb(aux->esq, x);//quando achar o maior valor a esquerda chama a função pois entrará nos 3 casos anteriores para remover_abb
                }
                tamanho_abb--;
                return aux;
            }else{
                printf("Acesso Negado!");
                return 0;
            }    
        }    
    }
}

void in_ordem(Dados_Basicos* aux){
    if(aux->esq != NULL){
        in_ordem(aux->esq);
    }
    printf("%d \n", aux->id);
    printf("%s\n", aux->nome_aluno);
    printf("%d\n", aux->matricula);
    printf("%s\n", aux->descricao);
    printf("\n");
    if(aux->dir != NULL){
        in_ordem(aux->dir);
    }
}
