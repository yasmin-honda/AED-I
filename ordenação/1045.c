/*Programa que recebe 3 numeros reais a,b,c, representando os 3 lados de um triangulo
Ordena os lados em ordem decrescente
Diz qual é o tipo de triangulo fornecido
*/
#include<stdio.h>

void insertionSort(float v[], int n) {
    int i, j, min;
    float x;

    for (i = 0; i < n - 1; i++){
        min = i;
    for (j = i + 1; j < n; j++) {
        if (v[j] > v[min]) {
        min = j;
        }
    }
    x = v[i];
    v[i] = v[min];
    v[min] = x;
    }
}

int main(){
    float vetor[3];
    
    for(int i=0;i<3;i++){
        scanf("%f",&vetor[i]);
    }
    insertionSort(vetor,3);
    if(vetor[0]>=vetor[1]+vetor[2])printf("NAO FORMA TRIANGULO\n");
    else if(vetor[0]*vetor[0]==(vetor[1]*vetor[1])+(vetor[2]*vetor[2]))printf("TRIANGULO RETANGULO\n");
    else if(vetor[0]*vetor[0]>(vetor[1]*vetor[1])+(vetor[2]*vetor[2]))printf("TRIANGULO OBTUSANGULO\n");
    else if(vetor[0]*vetor[0]<(vetor[1]*vetor[1])+(vetor[2]*vetor[2]))printf("TRIANGULO ACUTANGULO\n");
    if(vetor[0]==vetor[1] && vetor[1]==vetor[2])printf("TRIANGULO EQUILATERO\n");
    else if(vetor[0]==vetor[1] || vetor[2]==vetor[0] || vetor[2]==vetor[1])printf("TRIANGULO ISOSCELES\n");
}
