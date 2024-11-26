// fazer um programa que receba uma lista de nomes, coloque em ordem alfabética e identifique qual nome corresponde ao número sorteado
#include<stdio.h> 
#include<string.h>

void merge_sort(char v[][20],int inicio, int fim){
        int meio; //tentaremos sem o passo de inicio<fim pq na minha cabeça nn precisa
        meio=(inicio+fim)/2;
        merge_sort(v,inicio,meio);
        merge_sort(v,meio+1,fim);
        merge(v,inicio,meio,fim);
}
void merge(char v[][20],int inicio, int meio, int fim){
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
        strncpy(v[i],temp[i-inicio],strlen(temp[i-inicio]));
    }
}

int main(){
    int n,k;

    scanf("%d %d",&n,&k);
    char nomes[n][20];
    for(int i=-1;i<n;i++){ //por que ele não pega a palavra da linha 0?
        gets(nomes[i]);
    }
    merge_sort(nomes[n][20],0,n);
    printf("%s\n",nomes[k]);
}
