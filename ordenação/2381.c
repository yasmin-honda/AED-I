#include<stdio.h>
#include<stdlib.h>
 //verificar se a letra é maior ou menor do que o do nome já existente na lista e colocar na posição certa
// ou colocar tudo na ordem escrita e depois ordenar em ordem alfabética
typedef struct l{
    char nome[20];
    struct l *prox;
}lista;

void inserir_fim(lista **chamada, char v[]){
    lista *nome1,*aux;

    aux=*chamada;
    nome1=malloc(sizeof(lista));
    if(aux->prox==NULL){
        for(int i=0;v[i]!='/0';i++){
            nome1->nome[0]=v[0];
        }
        nome1->prox=NULL;
        aux->prox=nome1;
    }
    else{
        while(aux->prox){
            aux=aux->prox;
        }
        for(int i=0;v[i]!='/0';i++){
            nome1->nome[0]=v[0];
        }
        nome1->prox=NULL;
        aux->prox=nome1;
    }

}

void ordenar(lista **chamada){ //ordena a lista em ordem alfabetica; usar a estratégia de numero crescente?
    lista *aux1,*aux2;

    aux1=chamada->prox;
    aux2=(chamada->prox)->prox;
    while(aux1->prox){
        if(aux1->nome[0]>aux2->nome[0]){
            lista *aux3;

            aux3=aux1->prox;
            aux1->prox=aux2->prox;
            aux2->prox=aux3;
        }
    }
}

//criar função que verifica qual o nome correspondente ao numero sorteado
//imprimir o nome

int main(){
    int n,k;
    char nomes[20];
    lista *cabeca;

    cabeca=malloc(sizeof(lista));
    cabeca->prox=NULL;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        gets(nomes);
        inserir_fim(&cabeca,nomes);
    }
}
