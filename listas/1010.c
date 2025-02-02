#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int codigo,quantidade;
    float valor;
    struct no *prox;
}No;

void inserir(No **lista,int codigo,int quantidade,float valor){
    No *novo=malloc(sizeof(No));

    novo->codigo=codigo;
    novo->quantidade=quantidade;
    novo->valor=valor;
    novo->prox=NULL;
    if(*lista==NULL){
        *lista=novo;
    }
    else{
        No *aux=*lista;
        while(aux->prox)aux=aux->prox;
        aux->prox=novo;
    }
}

void imprimir(No *lista){
    No *aux=lista;
    float total=0;

    while(aux){
        total+=(aux->quantidade*aux->valor);
        aux=aux->prox;
    }
    printf("VALOR A PAGAR: R$ %.2f\n",total);
}

int main(){
    No *lista=NULL;
    int n,q;
    float v;

    for(int i=0;i<2;i++){
        scanf("%d %d",&n,&q);
        scanf("%f",&v);
        inserir(&lista,n,q,v);
    }
    imprimir(lista);
}
