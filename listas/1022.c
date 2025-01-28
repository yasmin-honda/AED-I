//Programa que recebe uma expressão matemática e devolve a solução em forma de número racional. Depois, se possível, simplica.
#include<stdio.h>
#define MAX 10000

int mdc(int num1,int num2){
    int aux=1, maior = num1;
    if(num1 == num2){
        return num1;
    }
    else if(num2 > num1){
        maior = num2;
    }
    for(int i = maior/2; i > 1; i--){
        if(num1 % i == 0 && num2 % i == 0){
            return i;
        }
    }
    return 1;
}

int main(){
    int n,N1,N2,D1,D2;
    int result[MAX][2],divisor;
    char aux,op;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&N1);
        scanf(" %c",&aux);
        scanf("%d",&D1);
        scanf(" %c",&op);
        scanf("%d",&N2);
        scanf(" %c",&aux);
        scanf("%d",&D2);
        if(op=='+'){
            result[i][0]=(N1*D2 + N2*D1);
            result[i][1]=(D1*D2);
        }
        else if(op=='-'){
            result[i][0]=(N1*D2 - N2*D1);
            result[i][1]=(D1*D2);
        }
        else if(op=='*'){
            result[i][0]=(N1*N2);
            result[i][1]=(D1*D2);
        }
        else{
            result[i][0]=(N1*D2);
            result[i][1]=(N2*D1);
        }
    }
    for(int i=0;i<n;i++){
        divisor=mdc(result[i][0],result[i][1]);
        printf("%d/%d = %d/%d\n",result[i][0],result[i][1],result[i][0]/divisor,result[i][1]/divisor);
    }
}
