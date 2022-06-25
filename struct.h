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
    struct dadosCompletos *prox;
    
}dadosCompletos;