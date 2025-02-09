/* Programa que recebe quantas pessoas tem na fila e seus marcadores; mostra o resultado final da fila depois de alguns saírem
Entrada: N (número de pessoas na fila)
N inteiros com os marcadores
M (número de pessoas que saíram da fila)
M inteiros com os marcadores de quem saiu
Saída: marcadores de quem permaneceu na fila, em ordem*/
#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int valor;
    struct no *prox;
}No;

No* inserir(No *lista, int num){ //estratégia que encontrei para tornar o processo menos demorado e não estourar o limite de tempo de novo
    No *aux=lista->prox,*novo=malloc(sizeof(No));

    novo->valor=num;
    novo->prox=NULL;
    if(lista->prox==NULL){
        lista->prox=novo;
    }
    else{
        while(aux->prox)aux=aux->prox;
        aux->prox=novo;
    }
    return novo;
}

void remover(No *lista, int num){
    No *aux=lista, *aux2;

    while(aux->valor!=num){
        aux2=aux;
        aux=aux->prox;
    }
    aux2->prox=aux->prox;

}

void imprimir(No *lista){
    No *aux=lista->prox;
    
    while(aux){ 
        printf("%d",aux->valor);
        if(aux->prox)printf(" ");
        aux=aux->prox;
    }
}

int main(){
    No *head=malloc(sizeof(No)),*ultimo;
    int n,m,aux;
    
    head->prox=NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&aux);
        if(i==0)ultimo=inserir(head,aux);
        else ultimo=inserir(ultimo,aux);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&aux);
        remover(head,aux);
    }
    imprimir(head);
    printf("\n");
}

