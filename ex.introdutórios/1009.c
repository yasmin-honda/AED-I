#include<stdio.h>

int main(){
    char nome[50];
    double salario,vendas;
    
    gets(nome);
    scanf("%lf %lf",&salario,&vendas);
    salario=salario+(0.15*vendas);
    printf("TOTAL = R$ %.2lf\n",salario);
}
