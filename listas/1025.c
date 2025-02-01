/*Programa que recebe x casos de teste (x<=65) com dois inteiros dizendo o número de peças de mármore e a quantidade de buscas a serem feitas, respectivamente
Utiliza lista com inserção ordenada para garantir o funcionamento correto da busca
Retorna a posição da chave de busca, se encontrado, ou imprime "not found"
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 10000

typedef struct no{
    int valor;
    struct no *prox;
}No;

void inserir_ordenado(No *head, int num){
    No *aux=head,*novo=malloc(sizeof(No));

    novo->valor=num;
    if(head->prox==NULL){
        novo->prox=NULL;
        head->prox=novo;
    }
    else{
        while(aux->prox && aux->prox->valor<novo->valor)aux=aux->prox;
        No *aux2=aux->prox;
        aux->prox=novo;
        novo->prox=aux2;
    }
}

int busca(No *head,int chave){
    No *aux=head;
    int cont=1;

    while(aux->prox &&aux->prox->valor<chave){
        aux=aux->prox;
        cont++;
    }
    if(aux->prox->valor==chave)return cont;
    else return 0;
}

void limpar(No *head){
    No *temp,*aux=head->prox;

    while(aux){
        temp=aux;
        aux=aux->prox;
        free(temp);
    }
}

int main(){
    No *lista=malloc(sizeof(No));
    int n,q,marmore,achou[MAX][2],teste=0;

    while(1){
        scanf("%d %d",&n,&q);
        if(n==0 && q==0)break;
        teste++;
        lista->prox=NULL;
        for(int i=0;i<n;i++){
            scanf("%d",&marmore);
            inserir_ordenado(lista,marmore);
        }
        for(int i=0;i<q;i++){
            scanf("%d",&achou[i][0]);
            achou[i][1]=busca(lista,achou[i][0]);
        }
        printf("CASE# %d:\n",teste);
        for(int i=0;i<q;i++){
            if(achou[i][1]==0)printf("%d not found\n",achou[i][0]);
            else printf("%d found at %d\n",achou[i][0],achou[i][1]);
        }
        limpar(lista);
    }
}
