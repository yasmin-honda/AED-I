/*Código que recebe 2 inteiros com a largura e altura de uma matriz, respectivamente 
Identifica se a matriz recebida é um mapa válido (leva a um baú "*") ou inválido (não dá em nada "!")
*/
#include<stdio.h>
#include<string.h>

int main(){
    char matriz[100][100];
    int x, y, i=0, j=0,aux=0;
    
    scanf("%d %d", &x, &y);
    for(int i = 0; i < y; i++) {
        for(int j = 0; j < x; j++) {
            scanf(" %c", &matriz[i][j]);
            if(matriz[i][j] == '*') {
                aux++; 
            }
        }
    }
    if(aux == 1) {
        while(i >= 0 && i < y && j >= 0 && j < x) {
            if(matriz[i][j] == '*') {
                printf("*\n");
                break;
            }
            if(matriz[i][j] == '>') {
                j++;
                while(matriz[i][j] == '.') j++;
            } 
            else if(matriz[i][j] == '<') {
                j--;
                while(matriz[i][j] == '.') j--; 
            } 
            else if(matriz[i][j] == '^') {
                i--;
                while(matriz[i][j] == '.') i--; 
            } 
            else if(matriz[i][j] == 'v') {
                i++;
                while(matriz[i][j] == '.') i++; 
            } 
            if(matriz[i][j] != '*' && matriz[i][j] != '>' && matriz[i][j] != '<' && matriz[i][j] != '^' && matriz[i][j] != 'v') { //se percorreu todas as direções e não achou um baú, então é inválido
                printf("!\n");
                break;
            }
        }
    } 
    else{
        printf("!\n"); 
}
