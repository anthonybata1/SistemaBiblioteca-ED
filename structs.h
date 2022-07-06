typedef struct Dados_Basicos{
    int id;
    char *nome_aluno;
    int matricula;
    char *descricao;
    struct Dados_Basicos *pai;
    struct Dados_Basicos *esq;
    struct Dados_Basicos *dir;
}Dados_Basicos;

typedef struct Dados_Completos{   
    int id; 
    char * nome_aluno;
    int matricula;
    char * descricao;
    char * campus_aluno;
    char * campus_livro;
    int prioridade;
    struct Dados_Completos *prox;
}Dados_Completos;

typedef struct servidor{
    int cpf;
    char *nome_serv;
    int senha;
    char ocupacao;
    struct servidor *prox;
    struct servidor *ant;
}servidor;


