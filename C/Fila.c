#include<stdio.h>
#include<stdlib.h>

typedef struct capsula{
    int dado;
    struct capsula *proximo;
}CAPS;

typedef struct{
    CAPS *inicio;
    CAPS *fim;
}FILA;

FILA* Criar(){
    FILA* fi=(FILA*)malloc(sizeof(FILA));
    if(fi==NULL){
        //erro
    }else{
        fi->inicio=NULL;
        fi->fim=NULL;
    }
    return fi;

}

void inserirFila(FILA *fi,int num){
    if(fi==NULL){
        //erro
    }else{
        CAPS *aux=(CAPS*)malloc(sizeof(CAPS));
        aux->dado=num;
        aux->proximo=NULL;//NULL ja que ele vai ser o ultimo
        if(fi->fim==NULL){
            fi->inicio=aux;
        }else{
            fi->fim->proximo=aux;
        }
        fi->fim=aux;
    }
}

void removerFila(FILA *fi){
    if(fi==NULL){
        //ERRp
    }else{
        if(fi->inicio==NULL){
            //FILA VAZIA
        }else{
            CAPS *aux=fi->inicio;
            fi->inicio=fi->inicio->proximo;
            if(fi->inicio==NULL){//caso so tenha 1 elemento quando ele sumir o fim deve apontar para nada
                fi->fim=NULL;
            }
            free(aux);
        }
    }
}


void mostrarFila(FILA *fi){
    if(fi==NULL){
        //erro
    }else{
        if(fi->inicio==NULL){
            //vazia
        }else{
            CAPS *aux=fi->inicio;
            while(aux!=NULL){
                printf("%d ",aux->dado);
                aux=aux->proximo;
            }
        }
    }
}

int tamanhoFila(FILA *fi){
    if(fi==NULL){
        //erro
    }else{
        if(fi->inicio==NULL){
            //vazia
        }else{
            int cont=0;
            CAPS *aux=fi->inicio;
            while(aux!=NULL){
                cont++;
                aux=aux->proximo;
            }
            return cont;
        }
    }

}

void liberarFila(FILA *fi){
    if(fi!=NULL){
        CAPS *aux;
        while(fi->inicio!=NULL){
            aux=fi->inicio;
            fi->inicio=fi->inicio->proximo;
            free(aux);
        }
        free(fi);
    }


}

main(){

FILA *fi = Criar();
inserirFila(fi,9);
inserirFila(fi,12);
mostrarFila(fi);
printf("\n%d\n ",tamanhoFila(fi));
removerFila(fi);
mostrarFila(fi);
liberarFila(fi);

}



