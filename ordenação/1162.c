//Programa que precisa ordenar os "vagões de um trem" apenas utilizando trocas de 2 em 2; devolve a quantidade de operações realizadas
#include<stdio.h>
#define MAX 50

int bubbleSort(int vetor[MAX], int n) {
    int i, j, temp,cont=0;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                cont++;
            }
        }
    }
    return cont;
}

int main(){
    int n,l,trocas=0;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&l);
        int vetor[l];

        for(int j=0;j<l;j++){
            scanf("%d",&vetor[j]);
        }
        trocas=bubbleSort(vetor,l);
        printf("Optimal train swapping takes %d swaps.\n",trocas);
    }
}
