// fazer um programa que receba uma lista de nomes, coloque em ordem alfabética e identifique qual nome corresponde ao número sorteado
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void merge_sort(char *v[],int inicio, int fim){
        int meio;
        meio=(inicio+fim)/2;
        merge_sort(v,inicio,meio);
        merge_sort(v,meio+1,fim);
        merge(v,inicio,meio,fim);
}
void merge(char *v[],int inicio, int meio, int fim){
    int i=inicio, j=meio+1, k=0;
    char *temp[fim - inicio+1];

    while (i<=meio && j<=fim){
        if(strcmp(v[i], v[j]) < 0){
            temp[k++] = v[i++];
        }
        else temp[k++] = v[j++];
    }
    while (i<=meio) temp[k++] = v[i++];
    while (j<=fim) temp[k++] = v[j++];

    for (i=inicio; i<=fim; i++){
        free(v[i]);
        strncpy(v[i],temp[i-inicio], strlen(temp[i-inicio]));
    }
}

int main(){
    int n,k;

    scanf("%d %d",&n,&k);
    char *nomes[n];
    getchar();
    for(int i=0;i<n;i++){ 
        nomes[i]=malloc(20*sizeof(char));
        gets(nomes[i]);
    }
    merge_sort(nomes,0,n-1);
    printf("%s\n",nomes[k]);
    for(int i=0;i<n;i++){
        free(nomes[i]);
    }
}
