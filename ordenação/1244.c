//salva as palavra de uma linha em uma string[x][y] e depois joga no quicksort adaptado para ordenar pelo tamanho

//outra opção: formar uma lista de lista e identificar cada palavra de um caso de teste como um valor do nó da primeira lista
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct no{
    char valor[51];
    int tam;
    struct no *prox;
}No;

typedef struct l{
    No oi;
}lista;

void inserir_ordenado(No *head, char string[51],int tam1){
    No *aux=head,*novo=(No*)malloc(sizeof(No));
    
    for(int i=0;i<tam;i++)novo->valor[i]=string[i];
    novo->prox=NULL;
    if(head->prox==NULL){
        head->prox=novo;
    }
    else{
        if(aux->tam>tam1)
        while(aux->prox)aux=aux->prox;
        aux->prox=novo;
    }
}

int main(){

}
