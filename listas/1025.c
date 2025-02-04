/*Programa que recebe x casos de teste (x<=65) com dois inteiros dizendo o número de peças de mármore e a quantidade de buscas a serem feitas, respectivamente
Utiliza merge sort para ordenação dos vetores
Busca e retorna
*/
#include<stdio.h>
#define MAX 10000

void intercala(int inicio, int meio, int fim, int vetor[]) {

    int i, j, k, *vt;

    vt = (int*)malloc(sizeof(int) * (fim - inicio));
    i = inicio;
    j = meio;
    k = 0;
    while (i < meio && j < fim) {

        if (vetor[i] < vetor[j]) vt[k++] = vetor[i++];
        else vt[k++] = vetor[j++];
    }
    while (i < meio) {
      vt[k++] = vetor[i++];
    }
    while (j < fim) {
      vt[k++] = vetor[j++];
    }
    for (i = inicio; i < fim; i++) {
      vetor[i] = vt[i - inicio];
    }
    free(vt);

}

void mergeSort(int inicio, int fim, int vetor[]) {

  if (inicio < fim - 1) {
    int q = (inicio + fim)/2;

    mergeSort(inicio, q, vetor);
    mergeSort(q, fim, vetor);
    intercala(inicio, q, fim, vetor);
  }
}

int busca(int vetor[MAX],int tam,int chave){
    for(int i=0;i<tam;i++){
        if(vetor[i]==chave)return i+1;
    }
    return 0;
}

int main(){
    int n,q,marmore[MAX],achou[MAX][2],teste=0;

    while(1){
        scanf("%d %d",&n,&q);
        if(n==0 && q==0)break;
        teste++;
        for(int i=0;i<n;i++){
            scanf("%d",&marmore[i]);
        }
        mergeSort(0,n,marmore);
        for(int i=0;i<q;i++){
            scanf("%d",&achou[i][0]);
            achou[i][1]=busca(marmore,n,achou[i][0]);
        }
        printf("CASE# %d:\n",teste);
        for(int i=0;i<q;i++){
            if(achou[i][1]==0)printf("%d not found\n",achou[i][0]);
            else printf("%d found at %d\n",achou[i][0],achou[i][1]);
        }
    }
}
