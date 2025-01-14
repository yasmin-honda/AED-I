/* Cria um programa que recebe um inteiro n indicando o numero de conjuntos a serem testados
Guarda as informações do conjunto em uma lista e analisa quantos diamantes podem ser formados
"Reseta" as informações da lista e repete para cada n linha
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

typedef struct l{
    char valor;
    struct l *prox;
}no;

void inserir(no *head, char simbolo){
    no *novo=malloc(sizeof(no)),*aux=head;

    if(novo){
        novo->prox=NULL;
        novo->valor=simbolo;
    }
    else printf("Erro de alocação");
    while(aux->prox) aux=aux->prox;
    aux->prox=novo;
}

void retirar(no *head,no *marcador){
    no *aux=head->prox,*aux2;
    while(aux!=marcador){
      aux2=aux;
      aux=aux->prox;
    }
    aux2->prox=aux->prox;
}

int contar_diamante(no *head, int cont){ //por algum motivo essa função não está retornando e o erro no código começa aqui
    int num=0;
    no *aux,*marcador1,*marcador2;

    for(int j=0;j<cont;j++){
        aux=head->prox;
        while(aux->valor!='<') aux=aux->prox;
        marcador1=aux;
        while(aux->valor!='>'){
            if(aux->prox==NULL) break;
            aux=aux->prox;
        }
        if(aux->valor!='>') break;
        marcador2=aux;
        if(marcador1->valor=='<' && marcador2->valor=='>'){
            num++;
            retirar(head,marcador1);
            retirar(head,marcador2);
        }
    }
    return num;
}

void limpar(no *lista) {
    no *aux=lista->prox,*temp;

    while(aux){
        temp=aux;
        aux=aux->prox;
        free(temp);
    }
}


int main(){
    no *lista=malloc(sizeof(no));
    int n,diamantes[MAX],cont=0;
    char c=' ';

    scanf("%d",&n);
    lista->prox=NULL;
    for(int i=0;i<n;i++){
        //analisa uma linha e conta quantos diamantes
        getchar();
        while(c!='\n'){
           scanf("%c",&c);
           inserir(lista,c);
           if(c=='<') cont++;
        }
        diamantes[i]=contar_diamante(lista,cont);
        printf("oi2");
        limpar(lista);
        cont=0; //zera a contagem quando a lista for resetar
    }
    for(int i=0;i<n;i++){
        printf("%d\n", diamantes[i]);
    }
}

SEGUNDA ABORDAGEM!!

/* Cria um programa que recebe um inteiro n indicando o numero de conjuntos a serem testados, que serão os nós da lista
Guarda as informações do conjunto em uma string e analisa quantos diamantes podem ser formados
Repete o processo para os nós subsequentes da lista
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

typedef struct no{
    char string[MAX];
    struct no *prox;
}No;

void inserir_no(No **lista,char simbolo){
    No *novo=malloc(sizeof(No)),*aux=*lista;

    novo->valor=num;
    novo->prox=NULL;
    if(*lista==NULL){
        *lista=novo;
    }
    else{
        while(aux->prox)aux=aux->prox;
        aux->prox=novo;
    }
}

int main(){
    No *lista=malloc(sizeof(No));
    int n;
    char vetor[MAX];

    lista=NULL; //a lista será sem cabeça porque não há necessidade de um marcador inicial neste caso
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        gets(vetor);
        inserir_no(&lista,vetor);
    }
}
