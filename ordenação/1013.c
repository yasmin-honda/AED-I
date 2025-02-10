#include<stdio.h>

void insertionSort(int v[], int n) {
    int i, j, x, min;

    for (i = 0; i < n - 1; i++){
        min = i;
    for (j = i + 1; j < n; j++) {
        if (v[j] < v[min]) {
        min = j;
        }
    }
    x = v[i];
    v[i] = v[min];
    v[min] = x;
    }
}

int main(){
    int vetor[3];
    
    for(int i=0;i<3;i++){
        scanf("%d",&vetor[i]);
    }
    insertionSort(vetor,3);
    printf("%d eh o maior\n",vetor[2]);
}
