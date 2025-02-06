#include<stdio.h>

int main(){
    float valor,notas2[6]={100,50,20,10,5,2},moedas2[6]={1.00,0.50,0.25,0.10,0.05,0.01};
    int notas[6]={},moedas[6]={};

    scanf("%f",&valor);
    valor+=0.005;
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
            moedas[0]++;
        }
    }
    if(valor<1){
        while(valor>=0.50){
            valor-=0.50;
            moedas[1]++;
        }
        while(valor>=0.25){
            valor-=0.25;
            moedas[2]++;
        }
        while(valor>=0.10){
            valor-=0.10;
            moedas[3]++;
        }
        while(valor>=0.05){
            valor-=0.05;
            moedas[4]++;
        }
        while(valor>=0.01){ //POR QUE ESSA PORRA NÃO FUNCIONA???
            valor-=0.01;
            moedas[5]++;
        }
    }
    printf("NOTAS:\n");
    for(int i=0;i<6;i++){
        printf("%d nota(s) de R$ %.2f\n",notas[i],notas2[i]);
    }
    printf("MOEDAS:\n");
    for(int i=0;i<6;i++){
        printf("%d moeda(s) de R$ %.2f\n",moedas[i],moedas2[i]);
    }
}
