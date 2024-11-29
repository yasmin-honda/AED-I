// fazer um programa que receba uma lista de nomes, coloque em ordem alfabética e identifique qual nome corresponde ao número sorteado
#include <stdio.h>
#include <string.h>

void merge(char v[][22], int inicio, int meio, int fim) {
    int i = inicio, j = meio + 1, k = 0;
    char temp[fim - inicio + 1][22];

    while (i <= meio && j <= fim) {
        if (strcmp(v[i], v[j]) < 0) strcpy(temp[k++], v[i++]);
        else strcpy(temp[k++], v[j++]);
    }
    while (i<=meio) strcpy(temp[k++], v[i++]);
    while(j<=fim) strcpy(temp[k++], v[j++]);
    for (i = inicio; i <= fim; i++) {
        strcpy(v[i], temp[i - inicio]);
    }
}

void merge_sort(char v[][22], int inicio, int fim) {
    if(inicio<fim){ //define o caso de parada da função recursiva, ou seja, quando o inicio se iguala ao fim
        int meio = (inicio + fim) / 2;
        merge_sort(v, inicio, meio);
        merge_sort(v, meio + 1, fim);
        merge(v, inicio, meio, fim);
    }
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);
    getchar(); //sem o getchar o programa armazena a primeira quebra de linha como a informação da primeira string
    char nomes[n][22]; //gambiarra para permitir que o número maximo de caracteres inseridos seja 20

    for (int i=0; i<n;i++) {
        fgets(nomes[i], 22, stdin);
        nomes[i][strcspn(nomes[i], "\n")] = '\0';

    }
    merge_sort(nomes, 0, n-1);
    printf("%s\n", nomes[k-1]);
}
