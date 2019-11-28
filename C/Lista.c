#include<stdio.h>
#include<stdlib.h>

typedef struct capsula{
    int dado;
    struct capsula *proximo;
}CAPS;

typedef struct{
    CAPS *inicio;
}LISTA;

LISTA* Criar(){
    LISTA* li=(LISTA*)malloc(sizeof(LISTA));
    if(li!=NULL){
        li->inicio=NULL;
    }
    return li;

}


void inserirLista(LISTA *li,int num){
    if(li==NULL){
        //ERRO
    }else{
        CAPS *novo= (CAPS*)malloc(sizeof(CAPS));
        if(novo!=NULL){
            novo->dado= num;
            if(li->inicio==NULL){//insercao com lista vazia
                novo->proximo=NULL;
                li->inicio=novo;
            }else{//insercao no inicio quando ja tem alguem na lista
                CAPS *aux=li->inicio;
                if(aux->dado>novo->dado){// se o dado que tiver la for maior do que o que esta inserindo ai ele entra na frente[b] = [a,b]
                    novo->proximo=aux;
                    li->inicio=novo;
                }else{//insercao no meio ou no fim
                    CAPS *ante;
                    while((aux!=NULL)&&(aux->dado<novo->dado)){//enquanto o auxiliar for menor do que o dado inserido
                        ante = aux;//guarda qual capsula é menor do que o novo
                        aux = aux->proximo;//passa, e guar o proximo que ele ira apontar
                    }
                    ante->proximo=novo;//o numeros menor que o novo ira apontar para o novo
                    novo->proximo=aux;// aponta para o aux que era o proximo maior que ele
                }

            }

        }
    }

}

void removerLista(LISTA *li,int num){
    if(li==NULL){
        //ERRO
    }else{
        if(li->inicio==NULL){
            //VAZIA
        }else{
            CAPS *aux=li->inicio;
            if(aux->dado==num){//se for o 1 da lista
                li->inicio=aux->proximo;//inicio aponta pro proximo
                free(aux);
            }else{
                CAPS *ante;
                while((aux!=NULL)&&(aux->dado!=num)){//varre a lista e enquando nao for igual ao que procura ele roda
                    ante=aux;
                    aux=aux->proximo;
                }
                if(aux==NULL){//caso nao tenha enconrado nada na lista
                    printf("NAO ENCONTRADO");
                    return;
                }
                ante->proximo=aux->proximo;//
                free(aux);
            }
        }
    }

}

void liberar(LISTA *li){
    if(li==NULL){
        //ERRO
    }else{
        CAPS *aux;
        while(li->inicio!=NULL){
            aux=li->inicio;
            li->inicio=li->inicio->proximo;
            free(aux);
        }
        free(li);
    }
}

void mostrarLista(LISTA *li){
    if(li==NULL){
        //erro
    }else{
        if(li->inicio==NULL){
            //vazia
        }else{
            CAPS *aux = li->inicio;
            while(aux!=NULL){
                printf("%d ",aux->dado);
                aux=aux->proximo;
            }
        }
    }
}

int tamanhoLista(LISTA *li){
    if(li==NULL){
        //ERRO
    }else{
        if(li->inicio==NULL){
            //vazia
        }else{
            int cont=0;
            CAPS *aux=li->inicio;
            while(aux!=NULL){
                cont++;
                aux=aux->proximo;
            }
            return cont++;
        }
    }


}

main(){

    LISTA *li = Criar();
    inserirLista(li,8);
    inserirLista(li,4);
    inserirLista(li,2);
    inserirLista(li,6);
    printf("\n%d\n",tamanhoLista(li));
    mostrarLista(li);
    printf("\n");
    removerLista(li,4);
    mostrarLista(li);
    liberar(li);

}




