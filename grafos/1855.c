#include<stdio.h>

int main(){
    char matriz[100][100];
    int x,y,i=0,j=0,cont=0;

    scanf("%d %d",&x,&y);
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            scanf(" %c",matriz[i][j]);
        }
    }
    while(matriz[i][j]!='*'){
        printf("OI");
        if(matriz[i][j]=='>'){
            j++;
            while(matriz[i][j]=='.')j++;
            cont++;
        }
        if(matriz[i][j]=='<'){
            j--;
            while(matriz[i][j]=='.')j--;
            cont++;
        }
        if(matriz[i][j]=='^'){
            i--;
            while(matriz[i][j]=='.')i--;
            cont++;
        }
        if(matriz[i][j]=='v'){
            i++;
            while(matriz[i][j]=='.')i++;
            cont++;
        }
        if(matriz[i][j]=='*'){
            cont++;
            printf("*\n");
            break;
        }
        if(cont>=x*y){
            printf("!\n");
            break;
        }
    }

}


