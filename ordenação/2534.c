/*Programa que recebe dois inteiros n e q, representando o tamanho do vetor e o número de consultas a serem feitas, respectivamente
Ordena o vetor em ordem decrescente
Imprime o valor contido na posição indicada em cada consulta
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void intercala(int v[MAX],int inicio, int meio, int fim){
    int i=inicio,j=meio,k=0,*vt;

    vt=malloc(sizeof(int)*(fim-inicio));
    while(i<meio && j<fim){
        if(v[i]>v[j]) vt[k++]=v[i++];
        else vt[k++]=v[j++];
    }
    while(i<meio)vt[k++]=v[i++];
    while(j<fim)vt[k++]=v[j++];

    for(i=inicio;i<fim;i++){
        v[i]=vt[i-inicio];
    }

    free(vt);
}

void merge_sort(int v[MAX],int inicio, int fim){
    int q;

    if(inicio<fim-1){
        q=(inicio+fim)/2;
        merge_sort(v,inicio,q);
        merge_sort(v,q,fim);
        intercala(v,inicio,q,fim);
    }
}

int main(){
    int q,n,vetor[MAX],aux;
    
    while(scanf("%d %d",&n,&q)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",&vetor[i]);
        }
        merge_sort(vetor,0,n);
        for(int i=0;i<q;i++){
            scanf("%d",&aux);
            printf("%d\n",vetor[aux-1]);
        }
    }
}

