#include<stdio.h>
#include<stdlib.h>

typedef struct capsula{
    int dado;
    struct capsula *proximo;
}CAPS;

typedef struct{
    CAPS *topo;
}PILHA;


PILHA* Criar(){
    PILHA* pi=(PILHA*)malloc(sizeof(PILHA));
    if(pi!=NULL){
        pi->topo=NULL;
    }else{
        printf("ERRO DE ALOCACAO");
    }
    return pi;
}

inserirPilha(PILHA *pi, int num){//ou STRUCT *ST e na função deve vim o &st
    if(pi==NULL){
        printf("ERRO NA ALOCACAO");
    }else{
        CAPS *aux = (CAPS*)malloc(sizeof(CAPS));
        aux->dado=num;
        if(pi->topo==NULL){
            aux->proximo=NULL;
        }else{
            aux->proximo = pi->topo;
        }
        pi->topo=aux;
    }
}

void remover(PILHA *pi){
    //so remover o topo
    if(pi==NULL){
        //Erro
    }else{
        if(pi->topo==NULL){
            //vazia
        }else{
            CAPS *aux=pi->topo;
            pi->topo=pi->topo->proximo;
            free(aux);
        }
    }


}

void mostrarPilha(PILHA *pi){
    if(pi==NULL){
        //ERRO
    }else{
        if(pi->topo==NULL){
            //pilha vazia
        }else{
            CAPS *aux=pi->topo;
            while(aux!=NULL){
                printf("%d ",aux->dado);
                aux=aux->proximo;
            }
        }
    }
}

int tamanho(PILHA *pi){
    if(pi==NULL){
        //ERRO
    }else{
        if(pi->topo==NULL){
            //pilha vazia
        }else{
            int cont=0;
            CAPS* aux=pi->topo;
            while(aux!=NULL){
                cont++;
                aux=aux->proximo;
            }
            return cont;
        }
    }
}
void liberarPilha(PILHA *pi){
    if(pi==NULL){
        //erro
    }else{
        if(pi->topo==NULL){
            //vazia
        }else{
            CAPS *aux;
            while(pi->topo!=NULL){
                aux = pi->topo;
                pi->topo=pi->topo->proximo;
                free(aux);
            }
            free(pi);
        }
    }

}

main(){
    PILHA* pi = Criar();
    inserirPilha(pi,9);
    inserirPilha(pi,11);
    inserirPilha(pi,18);
    mostrarPilha(pi);
    printf("\n");
    remover(pi);
    mostrarPilha(pi);

    printf("\n%d",tamanho(pi));
    liberarPilha(pi);
}
