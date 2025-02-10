/*Programa que recebe uma string e conta quantas vezes os caracteres presentes aparecem
Imprime o caractere no seu valor da tabela ascii e mostra a frequência em ordem crescente
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct{
	char ascii;
	unsigned short frequencia;
} dados;

void quickSortInterno(dados *caractere, int inicio, int fim);
void quickSort(dados *caractere, int tam);
void insertionSort(dados *caractere, unsigned short tam);

int main (){
	unsigned short i, j, k, z = 0;
	char texto[1001];
	short frequencia;
	bool foivisto[1001];
	dados caractere[1001];

	while (scanf(" %[^\n]", texto) != EOF){
		k = 0;
		// Função memset preenche um bloco de memória com um conteúdo especificado
		memset(foivisto, false, sizeof(foivisto));
		for (i = 0; texto[i]; i++){
			frequencia = 0;
			if (!foivisto[i]){
				for (j = 0; texto[j]; j++){
					if (texto[i] == texto[j]){
						foivisto[j] = true;
						frequencia++;
					}
				}
				caractere[k].ascii = texto[i];
				caractere[k].frequencia = frequencia;
				k++;
			}
		}
		quickSort(caractere, k);
		insertionSort(caractere, k);
		if (z)printf("\n");
		else z++;
		for (i = 0; i < k; i++){
			printf("%hhd %hu\n", caractere[i].ascii, caractere[i].frequencia);
    }
	}
}

void quickSortInterno(dados *caractere, int inicio, int fim){
	dados pivo;
	dados temp;
	int i, j;

	if (fim - inicio > 0){
		if (inicio < fim){
			i = inicio;
			j = fim;
			pivo = caractere[(i + j) / 2];

			do{
				while (caractere[i].ascii > pivo.ascii)	i++;
				while (caractere[j].ascii < pivo.ascii) j--;

				if (i <= j){
					temp = caractere[i];
					caractere[i] = caractere[j];
					caractere[j] = temp;
					i++; j--;
        }
			} while (i <= j);

			quickSortInterno(caractere, inicio, j);
			quickSortInterno(caractere, i, fim);
		}
	}
}

void quickSort(dados *caractere, int tam){
	quickSortInterno(caractere, 0, tam - 1);
}

void insertionSort(dados *caractere, unsigned short tam){
	short i = 1, j;
	dados pivo;

	while (i < tam){
		j = i - 1;
		pivo = caractere[i];
		while (j >= 0 && caractere[j].frequencia > pivo.frequencia){
			caractere[j + 1] = caractere[j];
			j--;
		}
		caractere[j + 1] = pivo;
		i++;
	}
}
