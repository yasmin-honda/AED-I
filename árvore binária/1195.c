#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int valor;
    struct no *esq,*dir;
}No;

No* inserir(No *arv, int num){
    if(arv==NULL){
        No *novo=(No*)(malloc(sizeof(No)));
        novo->valor=num;
        novo->esq=NULL;
        novo->dir=NULL;
        return novo;
    }
    else{
        if(num < arv->valor) arv->esq=inserir(arv->esq,num);
        else arv->dir=inserir(arv->dir,num);
        return arv;
    }
}

void prefixo(No *arv){
    printf(" %d",arv->valor);
    if(arv->esq != NULL){
        prefixo(arv->esq);
    }
    if(arv->dir != NULL){
        prefixo(arv->dir);
    }

}

void infixo(No *arv){
    if(arv->esq != NULL){
        infixo(arv->esq);
    }
    printf(" %d",arv->valor);
    if(arv->dir != NULL){
        infixo(arv->dir);
    }
}

void posfixo(No *arv){
    if(arv->esq != NULL){
        posfixo(arv->esq);
    }
    if(arv->dir != NULL){
        posfixo(arv->dir);
    }
    printf(" %d",arv->valor);
}

int main(){
    No *arvore=NULL;
    int c,n,aux;

    scanf("%d",&c);
    for(int i=1;i<=c;i++){
        scanf("%d",&n);
        for(int j=0;j<n;j++){
            scanf("%d",&aux);
            arvore=inserir(arvore,aux);
        }
        printf("Case %d:\n", i);
        printf("Pre.:");
        prefixo(arvore);
        printf("\n");
        printf("In..:");
        infixo(arvore);
        printf("\n");
        printf("Post:");
        posfixo(arvore);
        printf("\n");
        printf("\n");
        arvore=NULL;
    }

}
