#include<stdio.h>

int main(){
    int n,horas,salario;
    float valor;
    
    scanf("%d %d %f",&n,&horas,&valor);
    printf("NUMBER = %d\n",n);
    printf("SALARY = U$ %.2f\n",valor*horas);
}
