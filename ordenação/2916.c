/*Programa que recebe dois inteiros n e k, o tamanho do vetor e os k números que teremos que somar, respectivamente
Ordena o vetor em ordem decrescente e soma o k primeiros números
Imprime a soma
*/
#include<stdlib.h>
#include<stdio.h>

void intercala(long int v[],int inicio, int meio, int fim){
    int i=inicio,j=meio,k=0,*vt;

    vt=malloc(sizeof(long int)*(fim-inicio));
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

void merge_sort(long int v[],int inicio, int fim){
    int q;

    if(inicio<fim-1){
        q=(inicio+fim)/2;
        merge_sort(v,inicio,q);
        merge_sort(v,q,fim);
        intercala(v,inicio,q,fim);
    }
}

int main(){
    int n,k;
    long int nota;
    
    while(scanf("%d %d",&n,&k)!=EOF){
        nota=0;
        long int *vetor=malloc(n*sizeof(long int));
        for(int i=0;i<n;i++){
            scanf("%ld",&vetor[i]);
        }
        merge_sort(vetor,0,n);
        for(int i=0;i<k;i++){
            nota+=vetor[i]; //deve ter algum problema nessa parte de soma ou na parte de ordenação pq ta imprimindo um valor 
        }                   //menor do que o esperado
        nota=nota%1000000007;
        printf("%ld\n",nota);
        free(vetor);
    }
}

