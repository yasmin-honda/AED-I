//Recebe uma lista de números inteiros não negativos e ordena os pares em ordem crescente e os ímpares em ordem decrescente
#include<stdio.h>
#include<stdlib.h>
#define MAX 100000

void intercala(int v[MAX],int inicio, int meio, int fim){
    int i=inicio,j=meio,k=0,*vt;

    vt=malloc(sizeof(int)*(fim-inicio));
    while(i<meio && j<fim){
        if(v[i]<v[j]) vt[k++]=v[i++];
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
    int n,vetori[MAX],vetorp[MAX],aux,tamp=0,tami=0;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&aux);
        if(aux%2==0)vetorp[tamp++]=aux;
        else vetori[tami++]=aux;
    }
    merge_sort(vetori,0,tami);
    merge_sort(vetorp,0,tamp);
    for(int i=0;i<tamp;i++){
        printf("%d\n",vetorp[i]);
    }
    for(int j=tami-1;j>=0;j--){
        printf("%d\n",vetori[j]);
    }
}

