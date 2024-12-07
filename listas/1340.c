#include<stdio.h> //lê as entradas em forma de lista, analisa qual é a estrutura de dados e imprime a resposta
#include<stdlib.h>

typedef struct no{ //nó de uma lista duplamente encadeada para facilitar a comparação de estruturas
    int comando;
    int x;
    struct no *prox;
    struct no *ant;
}No;

void inserir_fim(No **lista, int valor1, int valor2){
    No *novo=malloc(sizeof(No)),*aux;

    if (novo){
        novo->comando=valor1;
        novo->x=valor2;
        novo->prox=NULL;
        if(*lista==NULL){
            *lista=novo;
        }
        else{
            aux=*lista;
            while(aux->prox) aux=aux->prox;
            aux->prox=novo;
            novo->ant=aux;

        }
    }
}
int fila (No **lista, No *inicio){ //testa se é uma fila, retorna 1 se verdadeiro
    No *aux,*marcador;
    aux=*lista;
    marcador=inicio; //recebe um marcador para o início da lista

    while(aux->comando!=2){
        aux=aux->prox;
    }
    if(aux->x==marcador->x) return 1;
    else{
        marcador=marcador->prox;
        aux=aux->prox;
        fila(&aux, marcador);
        return 0; //faz sentido usar uma função recursiva aqui? será que funciona?
    } //funciona para os casos que entram pessoas depois?
}

int pilha (No **lista, No *m){ //testa se é uma pilha, retorna 1 se verdadeiro
    No *aux, *marcador;
    aux=*lista;
    marcador=m;

    while(aux->comando!=2){
        marcador=aux;
        aux=aux->prox;
    }
    if(aux->x==marcador->x) return 1;
    else{
        aux=aux->prox;
        marcador=marcador->ant;
        pilha(&aux,marcador);
    }
    //consigo garantir que colocando depois da primeira leva, a comparação ainda funciona?
}

int filap //testa se é uma fila de prioridade, retorna 1 se verdadeiro (usar heap sort para identificar a estrutura heap max e tirar o maior valor)

//se não for nenhum desses, é impossível; se for mais de um, é indeterminado

int main(){
    int n,v1,v2;
    No *lista=NULL,*temp;

    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&v1,&v2);
        inserir_fim(&lista,v1,v2);
    }
  /*  temp = inicio;
    while (temp != NULL) {
        No* aux = temp;
        temp = temp->prox;
        free(aux);
    }
*/

}
