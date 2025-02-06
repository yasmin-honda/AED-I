/*Programa que implementa uma tabela hash utilizando lista encadeada
Recebe um inteiro n, representando o número de casos. Cada linha seguinte contém o tamanho da tabela e a qtd de chaves
Imprime a tabela formada
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct no{
    int valor;
    struct no *prox;
}No;

void inicializar_tabela(No t[MAX],int tam){
    for(int i=0;i<tam;i++){
        t[i].prox=NULL;
    }
}

void inserir_semcabeca(No **lista,int num){
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

int espalhamento(int chave,int tam){
    return chave % tam;
}

void inserir_tabela(No t[MAX], int num, int tam){ //tem algum problema por aqui que nn ta permitindo mais de 2 inserções
    int indice = espalhamento(num,tam);
    inserir_semcabeca(&t[indice].prox, num);
}

void imprimir_lista(No *lista){
    No *aux=lista;
    while(aux){
        printf("%d -> ",aux->valor);
        aux=aux->prox;
    }
}

void imprimir_tabela(No t[MAX],int tam){
    for(int i=0;i<tam;i++){
        printf("%d -> ",i);
        imprimir_lista(t[i].prox);
        printf("\\\n");
    }
}

int main(){
    int n,qtd_chaves,tam,chave;
    No table[MAX];

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&tam,&qtd_chaves);
        inicializar_tabela(table,tam);
        for(int j=0;j<qtd_chaves;j++){
            scanf("%d",&chave);
            inserir_tabela(table,chave,tam);
        }
        imprimir_tabela(table,tam);
        if(i!=n-1)printf("\n");
    }
}
