#include<stdio.h>

int main(){
    int valor,notas2[7]={100,50,20,10,5,2,1};
    int notas[7]={};

    scanf("%d",&valor);
    printf("%d\n",valor);
    if(valor>=1){
        while(valor>=100){
            valor-=100;
            notas[0]++;
        }
        while(valor>=50){
            valor-=50;
            notas[1]++;
        }
        while(valor>=20){
            valor-=20;
            notas[2]++;
        }
        while(valor>=10){
            valor-=10;
            notas[3]++;
        }
        while(valor>=5){
            valor-=5;
            notas[4]++;
        }
        while(valor>=2){
            valor-=2;
            notas[5]++;
        }
        while(valor>=1){
            valor-=1;
            notas[6]++;
        }
    }
    for(int i=0;i<7;i++){
        printf("%d nota(s) de R$ %d,00\n",notas[i],notas2[i]);
    }
}
