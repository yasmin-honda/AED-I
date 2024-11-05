#include<stdio.h> //ler 2 listas (amigos velhos e amigos novos),juntar as duas e imprimir (se a 3 linha tiver um nome, colocar todos os novos antes desse nome)
#include<stdlib.h>
#define MAX 1000

struct no{
    char nome[20];
    struct no *prox;
};

typedef struct no No;

typedef struct{
    struct no *inicio;
}lista;

int main(){
    char vetor1[MAX],vetor2[MAX],vetor3[MAX];
    int i=0,j=0,h=0;
    lista *l1,*l2;

    gets(vetor1);
    gets(vetor2);
    gets(vetor3);

    while(vetor1[i]!='\0'){ //começa a dividir as palavras em listas
        while(vetor1[i]!=' '){
            No *no1; //cria uma variável dinâmica
            no1=malloc(sizeof(No));
            l1->inicio=no1;
            no1->nome[h]=vetor1[i];
            i++;
        }
        //no1->prox como linkar o nó com o próximo se ele não existe ainda?
        h=0;
    }
    i=0;
    h=0;
    while(vetor2[i]!='\0'){
        while(vetor2[i]!=' '){
            No *no2;
            no2=malloc(sizeof(No));
            no2->nome[h]=vetor2[i];
            i++;
        }
        h=0;
    }
    if(vetor3=='nao'){
        //continua o programa normalmente
    }
    else{
        //le o nome do amigo
    }
}
