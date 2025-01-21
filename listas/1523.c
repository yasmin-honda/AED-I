//forma uma pilha com os carros e verifica se o carro desejado está na última posição e pode ser retirado
#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int chegada,saida;
    struct no *prox;
}No;

void inserir(No *head,int valor1,int valor2){
    No *novo=(No*)malloc(sizeof(No)),*aux=head;

    novo->chegada=valor1;
    novo->chegada=valor2;
    novo->prox=NULL;
    if(head->prox==NULL) head->prox=novo;
    else{
        while(aux->prox)aux=aux->prox;
        aux->prox=novo;
    }
}

int remover(No *head){ //como é uma pilha, sempre vai remover o último elemento
    No *aux=head,*vt;

    while(aux->prox)aux=aux->prox;
    vt=aux;
    free(vt);

}

int main(){
    int n=1,k=1,x,y;
    No *pilha=(No*)malloc(sizeof(No));

    pilha->prox=NULL;
    while(n!=0 && k!=0){
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++){
            scanf("%d %d",&x,&y)
            if(i<=k){
                
            }
        }
    }

}
