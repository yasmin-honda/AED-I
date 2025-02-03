/*Programa que recebe uma lista contendo os idiomas e traduções da frase "feliz natal" nesse idioma
Depois recebe uma lista com os nomes das crianças e seus respectivos idiomas
Imprime o nome da criança e "feliz natal" na sua lingua
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct no{
    struct no *prox;
    char idioma[11],frase[50]; //a frase pode ser um nome ou a saudação naquele idioma
}No;

void inserir(No *head,char frase1[11],frase2[50]){
    No *novo=malloc(sizeof(No)),*aux=head;
    
    for(int i=0;i<strlen(frase1);i++)novo->idioma[i]=frase1[i];
    for(int i=0;i<strlen(frase2);i++)novo->frase[i]=frase2[i];
    novo->prox=NULL;
    while(aux->prox)aux=aux->prox;
    aux->prox=novo;
}

void imprimir(No *lista1,No *lista2){ 
    No *aux1=lista1,*aux2=lista2;
    
    while(aux2){
        printf("%s\n",aux2->frase)
    }
}

int main(){
    No *lista1=malloc(sizeof(No)),*lista2=malloc(sizeof(No));
    int n,m;
    char aux1[11],aux2[50];
    
    lista1->prox=NULL;
    lista2->prox=NULL;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
        gets(aux1);
        gets(aux2);
        inserir(lista1,aux1,aux2);
    }
    scanf("%d",&m);
    getchar();
    for(int i=0;i<m;i++){
        gets(aux2);
        gets(aux1);
        inserir(lista1,aux1,aux2);
    }
}
