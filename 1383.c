#include<stdio.h> //fazer um programa que identifica se uma matriz é solução de um sudoku ou não
// 1)possui apenas um representante de cada número numa linha 2)mesma coisa na coluna 3)apenas um representante em cada quadrante

int main(){
    int n,k;

    scanf("%d",&n);
    int result[n],matriz[n][9][9];
    for(k=0;k<n;k++){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                scanf("%d",&matriz[k][i][j]);
            }
        }
        result[k]=1;
    }
    for(k=0;k<n;k++){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                for(int m=j+1;m<9;m++){
                    if(matriz[k][i][j]==matriz[k][i][m]){
                        result[k]*=0;
                        break;
                    }
                    if(matriz[k][j][i]==matriz[k][m][i]){
                        result[k]*=0;
                        break;
                    }
                }
            }
        }
        if(result[k]==1){
            int a=0,b=0,c=1,cont[9]={},i,j;
            while(c<=9){
                for(i=a;i<a+3;i++){
                    for(j=b;j<b+3;j++){
                        if(matriz[k][i][j]==c)cont[c-1]++;
                        if(cont[c-1]>1){
                            result[k]*=0;
                            break;
                        }
                    }
                }
                c++;
                if(c==9 && i==a+2 && j==b+2){
                        a=a+3;
                        b=b+3;
                        c=1;
                        if(a+3>9)break;
                    }
            }
        }
    }
    for(int i=1;i<=n;i++){
        printf("Instancia %d\n",i);
        if(result[i-1]==1)printf("SIM\n");
        else printf("NAO\n");
        printf("\n");
    }

}

