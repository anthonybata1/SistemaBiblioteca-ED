Dados_Basicos* raiz = NULL;
int tamanho_abb;

int busca_id(int x, Dados_Basicos* auxiliar){
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

int id_aleatorio(){
    //Dado a TAD ser de tamanho_abbanho pequeno irei definir como se nao tivessem 
    //mais de 100 pedidos a serem adicionados
    int numero_aleatorio;
    int verificador_id = 1;
    if(tamanho_abb == 0){
        return 50;
    //assim adicionando sempre uma vez na direita e uma na esquerda
    }else if(tamanho_abb % 2 == 0){  
        while(verificador_id == 1){
            numero_aleatorio = 1 + (rand() % 49);
            verificador_id = busca_id(numero_aleatorio, raiz);
        }
        return numero_aleatorio; 
    }else if(tamanho_abb % 2 != 0){
        while(verificador_id == 1){
            numero_aleatorio = 51 + (rand() % 49);
            verificador_id = busca_id(numero_aleatorio, raiz);
        }
        return numero_aleatorio; 
    }    

}