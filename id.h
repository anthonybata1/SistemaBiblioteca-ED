Dados_Basicos* raiz = NULL;


int busca_id(int x, Dados_Basicos* auxiliar){
    if(auxiliar == NULL){
        return 0; 
    }else if(x == auxiliar->id){
        return 1; 
    }else if(x<auxiliar->id){ 
        if(auxiliar->esq != NULL){
            return busca_id(x, auxiliar->esq);
        }else{
            return 0; 
        }
    }else{
        if(auxiliar->dir != NULL){
            return busca_id(x, auxiliar->dir);
        }else{
            return 0; 
        }
    }
}

int id_aleatorio(int tamanho_abb){
    
    int numero_aleatorio;
    int verificador_id = 1;
   
    if(tamanho_abb == 0){
        return 50;
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