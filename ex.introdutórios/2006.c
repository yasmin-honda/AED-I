#include<stdio.h>

int main(){
    int c[5]={},t,qtd;

    scanf("%d\n",&t);
    for(int i=0;i<5;i++){
        scanf("%d\n",&c[i]);
        if(c[i]==t) qtd++;
    }
    printf("%d\n",qtd);
}
