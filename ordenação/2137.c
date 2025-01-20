//Recebe um inteiro n com o número de casos de teste (a leitura só termina quando receber o número "0000")
//ordena os valores inteiros recebidos nas próximas n linhas e imprime

#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

void troca(int* a, int* b) {
    int temp=*a;

    *a = *b;
    *b = temp;
}

int particionar(int vetor[], int baixo, int alto) {
    int pivo=vetor[alto],i=(baixo - 1);

    for(int j=baixo;j<=alto-1;j++){
        if(vetor[j]<=pivo){
            i++;
            troca(&vetor[i], &vetor[j]);
        }
    }
    troca(&vetor[i+1], &vetor[alto]);
    return (i+1);
}

void quickSort(int vetor[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particionar(vetor, baixo, alto);
        quickSort(vetor, baixo, pi - 1);
        quickSort(vetor, pi + 1, alto);
    }
}

int main(){
    int n=1,j=0,vetor[100][MAX],tam[100];

    while(scanf("%d",&n)!=EOF){
        if(n==0)break;
        for(int i=0;i<n;i++){
            scanf("%d",&vetor[j][i]);
        }
        tam[j]=n;
        j++;
    }
    for(int i=0;i<j;i++){
        quickSort(vetor[i],0,tam[i]-1);
        for(int c=0;c<tam[i];c++){
            printf("%04d\n",vetor[i][c]);
        }
    }
}
