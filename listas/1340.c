#include<stdio.h> //lê as entradas em forma de lista, analisa qual é a estrutura de dados e imprime a resposta
#include<stdlib.h>

typedef struct no{
    int comando;
    int x;
    struct no *prox;
}No;

/*int fila //testa se é uma fila, retorna 1 se verdadeiro

int pilha //testa se é uma pilha, retorna 1 se verdadeiro

int filap //testa se é uma fila de prioridade, retorna 1 se verdadeiro

//se não for nenhum desses, é impossível; se for mais de um, é indeterminado
*/
int main(){
    int n;
    No *lista,*inicio,*temp;

    scanf("%d", &n);
    inicio->prox=NULL;
    for(int i=0;i<n;i++){
        lista=malloc(sizeof(No));
        scanf("%d %d",lista->comando,lista->x);
        if(inicio->prox==NULL){
            inicio->prox=lista;
            lista->prox=NULL;
            printf("inicio: %d %d\n",inicio->comando,inicio->x);
        }
        else{
            No *aux;
            aux=inicio;
            while(aux) aux=aux->prox;
            aux->prox=lista;
            lista->prox=NULL;
            printf("no[%d]: %d %d\n",i,aux->comando,aux->x);

        }

    }
    temp = inicio;
    while (temp != NULL) {
        No* aux = temp;
        temp = temp->prox;
        free(aux);
    }


}
