//Recebe uma lista de números inteiros não negativos e ordena os pares em ordem crescente e os ímpares em ordem decrescente
#include<stdio.h>
#include<stdlib.h>
#define MAX 100000

typedef struct no{
    int valor;
    struct no *prox;
}No;

void inserir_ordenado(No **lista, int num){ //a lista pode ser sem cabeça porque já vou ordenar aqui mesmo
    No *aux=*lista,*novo=malloc(sizeof(No));

    novo->valor=num;
    novo->prox=NULL;
    if(*lista==NULL) *lista=novo;
    else if(novo->valor<(*lista)->valor){
        novo->prox=*lista;
        *lista=novo;
    }
    else{
        while(aux->prox && novo->valor>aux->prox->valor)aux=aux->prox;
        novo->prox=aux->prox;
        aux->prox=novo;
        }
}

void imprimir_crescente(No *lista){
    No *aux=lista,*temp;
    while(aux){
        printf("%d\n",aux->valor);
        temp=aux;
        aux=aux->prox;
        free(temp);
    }
}

void imprimir_decrescente(No *lista,int tam){
    int temporario[MAX],i=tam-1;
    No *aux=lista;

    while(aux){
        temporario[i--]=aux->valor;
        aux=aux->prox;
    }
    for(int i=0;i<tam;i++){
        printf("%d\n",temporario[i]);
    }
}

int main(){
    int n,aux,cont=0;
    No *listap,*listai;

    scanf("%d",&n);
    listap=NULL;
    listai=NULL;
    for(int i=0;i<n;i++){
        scanf("%d",&aux);
        if(aux%2==0)inserir_ordenado(&listap,aux);
        else{
            inserir_ordenado(&listai,aux);
            cont++;
        }
    }
    imprimir_crescente(listap);
    imprimir_decrescente(listai,cont);
}
