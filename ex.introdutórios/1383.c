#include <stdio.h>
#include <stdbool.h>

bool temRepetidos(int vetor[9]) {
    bool encontrado[10] = { false }; //vetor para marcar números de 1 a 9
    for (int i = 0; i < 9; i++) {
        int num = vetor[i];
        if (encontrado[num]) {
            return true;
        }
        encontrado[num] = true;
    }
    return false;
}

bool verificaSudoku(int matriz[9][9]) {

    for (int i = 0; i < 9; i++) { //verifica linhas
        if (temRepetidos(matriz[i])) {
            return false;
        }
    }
    for (int j = 0; j < 9; j++) { //verifica colunas
        int coluna[9];
        for (int i = 0; i < 9; i++) {
            coluna[i] = matriz[i][j];
        }
        if (temRepetidos(coluna)) {
            return false;
        }
    }
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            int quadrante[9],indice=0;
            for (int x = i; x < i + 3; x++) {
                for (int y = j; y < j + 3; y++) {
                    quadrante[indice++] = matriz[x][y]; //passa o conteúdo de cada quadrante para um vetor por causa da função de busca
                }
            }
            if (temRepetidos(quadrante)) return false;
        }
    }
    return true;
}

int main() {
    int n;

    scanf("%d", &n);
    int matriz[n][9][9];
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &matriz[k][i][j]);
            }
        }
    }
    for (int k = 0; k < n; k++) {
        printf("Instancia %d\n", k + 1);
        if (verificaSudoku(matriz[k])) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n");
    }
}
