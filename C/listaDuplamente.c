#include<stdio.h>
#include<stdlib.h>

typedef struct capsula{
    int dado;
    struct capsula *anterior;
    struct capsula *proximo;
}CAPS;

typedef struct{
    CAPS* inicio;
}LISTAD;

LISTAD* Criar(){
    LISTAD* pi=(LISTAD*)malloc(sizeof(LISTAD));
    if(pi!=NULL){
        pi->inicio=NULL;
    }
    return pi;

}
void inserirListaD(LISTAD *li,int num){
    if(li==NULL){
        //ERRO
    }else{
        CAPS* novo=(CAPS*)malloc(sizeof(CAPS));
        if(novo!=NULL){
            novo->dado=num;
            if(li->inicio==NULL){//vazia
                novo->proximo=NULL;
                novo->anterior=NULL;
                li->inicio=novo;
            }else{//no inicio
                CAPS* aux=li->inicio;
                if(aux->dado>novo->dado){
                    novo->anterior=NULL;
                    novo->proximo=li->inicio;
                    li->inicio->anterior=novo;
                    li->inicio=novo;
                }else{//no meio ou fim
                    CAPS *ante;
                    while((aux!=NULL)&&(aux->dado > novo->dado)){
                        ante= aux;
                        aux = aux->proximo;
                    }
                    //quando for inserir dps do while so mexe com o novo
                    ante->proximo=novo;//anterior aponta para o novo
                    novo->anterior=ante;//o novo aponta para tras para o anterior
                    novo->proximo=aux;//novo proximo aponta para o aux que é o q ta na frente
                    if(aux!=NULL){//se o proximo nao for NULL
                        aux->anterior=novo;//ele ira apontar para tras para o novo
                    }
                }
            }
        }

    }
}

void removerListaD(LISTAD* li, int num){
    if(li==NULL){
        //ERRO
    }else{
        if(li->inicio==NULL){
            //VAIZIA
        }else{
            CAPS *aux=li->inicio;
            if(aux->dado==num){//se for o 1 elemento
                li->inicio=aux->proximo;//inicio aponta para o proximo
                free(aux);
            }else{
                CAPS* ante;
                while((aux!=NULL)&&(aux->dado!=num)){
                    ante=aux;//o anterior do elemento que quero apagar
                    aux=aux->proximo;
                }
                if(aux==NULL){
                    return;//NAO ENCONTROU
                }
                ante->proximo=aux->proximo;//anterior ao que eu apaguei aponta para o proximo que apaguei
                                //|ante| -> |aux|->|aux proximo |
                if(aux->proximo!=NULL){
                    aux->proximo->anterior=ante;//o proximo elemento aponta para o antes do apagado
                }
                free(aux);
            }

            }
        }
    }
}

void mostrar(LISTAD *li){
    if(li==NULL){
        //erro
    }else{
        if(li->inicio==NULL){
            //VAZIA
        }else{
            CAPS *aux=li->inicio;
            while(aux!=NULL){
                printf("%d ",aux->dado);
                aux=aux->proximo;
            }
        }
    }
}

int tamanho(LISTAD *li){
    if(li ==NULL){
        //erro
    }else{
        if(li->inicio==NULL){
            //VAZIA
        }else{
            int cont=0;
            CAPS* aux=li->inicio;
            while(aux!=NULL){
                cont++;
                aux=aux->proximo;
            }
            return cont;
        }
    }
}

void liberarListaD(LISTAD *li){
    if(li==NULL){
        //ERRO
    }else{
        CAPS *aux;
        while(li->inicio!=NULL){
            aux = li->inicio;
            li->inicio=li->inicio->proximo;
            free(aux);
        }
        free(li);
    }


}
main(){

LISTAD* li=Criar();
inserirListaD(li,2);
inserirListaD(li,7);
inserirListaD(li,5);
inserirListaD(li,12);
inserirListaD(li,8);
printf("\n%d\n",tamanho(li));
mostrar(li);
removerListaD(li,5);
mostrar(li);
liberarListaD(li);
}




