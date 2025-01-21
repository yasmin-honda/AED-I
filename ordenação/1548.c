//programa recebe várias "filas" com inteiros representando as notas de cada aluno, ordena em ordem decrescente e compara com a original para ver quantos permaneceram na mesma posição
#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

void intercala(int v[MAX],int inicio, int meio, int fim){
    int i=inicio,j=meio,k=0,*vt,cont=0;

    vt=malloc(sizeof(int)*(fim-inicio));
    while(i<meio && j<fim){
        if(v[i]>v[j]){
            vt[k++]=v[i++];
        }
        else{
            vt[k++]=v[j++];
        }
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
    int n,m,j=0;

    scanf("%d",&n);
    int troca[n],vetor[n][MAX],aux[n][MAX];
    for(int i=0;i<n;i++)troca[i]=0; //inicializa todas as posições com 0 para não dar erro
    for(int i=0;i<n;i++){
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf("%d",&vetor[j][i]);
            aux[j][i]=vetor[j][i];
        }
        merge_sort(vetor[j],0,m);
        j++;
        for(int c=0;c<m;c++){
            if(aux[i][c]==vetor[i][c])troca[i]++; //verifica quantos "alunos" não precisaram trocar de posição
        }
    }
    for(int i=0;i<n;i++){
        printf("%d\n",troca[i]);
    }
}
