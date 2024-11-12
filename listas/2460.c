/* Programa que recebe quantas pessoas tem na fila e seus marcadores; mostra o resultado final da fila depois de alguns saírem

Entrada: N (número de pessoas na fila)
N inteiros com os marcadores
M (número de pessoas que saíram da fila)
M inteiros com os marcadores de quem saiu

Saída: marcadores de quem permaneceu na fila, em ordem*/
#include<stdio.h> 
#include<stdlib.h>

typedef struct no{
    int marcador;
    struct no *prox;
}No;

void inserir_fim(No **fila,int num){
    No *novo;
    
    if(fila->prox==NULL){
        fila->prox=novo;
        novo->marcador=num;
        novo->prox=NULL;
    }
    
}

int main(){
    int n,m;
    No *fila;
    
    fila=malloc(sizeof(No));
    fila->prox=NULL;
    
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int d;
        scanf("%d",d);
        inserir_fim(alguma coisa,d);
    }

}

