#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "id_aleatorio.h"

dadosBasicos* raiz = NULL;
int tam;

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
    if(tam == 0){
        return 50;
    //assim adicionando sempre uma vez na direita e uma na esquerda
    }else if(tam % 2 == 0){  
        while(verificador_id == 1){
            numero_aleatorio = 1 + (rand() % 49);
            verificador_id = busca_id(numero_aleatorio, raiz);
        }
        return numero_aleatorio; 
    }else if(tam % 2 != 0){
        while(verificador_id == 1){
            numero_aleatorio = 51 + (rand() % 49);
            verificador_id = busca_id(numero_aleatorio, raiz);
        }
        return numero_aleatorio; 
    }    

}

void add_abb(char * nome_aluno, int matricula, char * descricao){
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
            tam++;
        }else{
            if(x < resp->id){
                resp->esq = novo;
                tam ++;
            }else{
                resp->dir = novo;
                tam ++;
            }
        }
    }else{//nao posso deixar add novamente pq neste caso
        //havera ids duplicadas
        printf("Add inválida. id duplicada");
    }
}

//dadosCompletos dadosCompletos;

dadosBasicos* remover_abb(dadosBasicos* aux, int x){

    if(aux == NULL){//se não existe esse aux
        return NULL;
    }else{
        if(aux->id > x){//se o id desse aux é maior que o valor passado para ser encontrado
            aux->esq = remover_abb(aux->esq, x);
        }else if (aux->id < x){//se o id desse aux é menor que o valor passado para ser encontrado
            aux->dir = remover_abb(aux->dir, x);
        }else{//se foi encontrado o x, começa-se os formatos de remoção

            //adicionando na struct da fila de prioridades
            char * campus_aluno = malloc(sizeof(char));
            printf("Escreva o nome do campus do aluno que fez o pedido: ");
            scanf("%s",campus_aluno);
            char * campus_livro = malloc(sizeof(char));
            printf("Escreva o nome do campus do livre desejado: ");
            scanf("%s",campus_livro);
            int prioridade;
            printf("Escreva o nome do campus do aluno que fez o pedido: ");
            scanf("%d",&prioridade);
            //chama o add_fila(aux->id, aux->nome_aluno, aux->matricula, aux->descricao, campus_aluno, campus_livro, prioridade);
        
            if(aux->esq == NULL && aux->dir == NULL){//sem filhos
                aux = NULL;
                //free(aux);
            }else if(aux->esq == NULL){//só tem um filho a diretia
                dadosBasicos* aux_dir =  aux;
                aux = aux->dir;               
                //free(aux_dir);

            }else if(aux->dir == NULL){//so tem um filho a esquerda
                dadosBasicos* aux_esq =  aux;
                aux = aux->esq;
                //free(aux_esq);

            }else{//tem os dois filhos
                dadosBasicos * maior_dos_menores = aux->esq;//recebe uma vez para a esquerda
                while(maior_dos_menores->dir != NULL){
                    maior_dos_menores = maior_dos_menores->dir;//e o maximo que der para direita
                }
                aux->id = maior_dos_menores->id;//troca os valores (todos os dados)
                maior_dos_menores->id = x;
                aux->esq  = remover_abb(aux->esq, x);//quando achar o maior valor a esquerda chama a função pois entrará nos 3 casos anteriores para remover_abb
            }
            tam--;
        }
    
        return aux;    
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

/*int main(){
    add("Lucas", 1526, "diario de um banana");
    add("Lucas", 1527, "diario de um banana");
    add("Lucas", 1528, "diario de um banana");
    add("Lucas", 1529, "diario de um banana");
    add("Lucas", 1530, "diario de um banana");
    add("Lucas", 1531, "diario de um banana");
    add("Lucas", 1532, "diario de um banana");
    in_ordem(raiz);
    raiz = remover_abb(raiz, 51);
    printf("\n apos a remocao 1\n");
    in_ordem(raiz);
    raiz = remover_abb(raiz, 49);
    printf("\n apos a remocao 2 \n");
    in_ordem(raiz);
    raiz = remover_abb(raiz, 100);
    printf("\n apos a remocao 3\n");
    in_ordem(raiz);
    raiz = remover_abb(raiz, 17);
    printf("\n apos a remocao 4\n");
    in_ordem(raiz);
    return 0;
}*/