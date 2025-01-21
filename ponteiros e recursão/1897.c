//dado um numero n e um numero m, devolve a quantidade minima de operações que convertem n em m
#include<stdio.h>

int operacoes(int n, int m) {
    int minimo=1,op[6],menor;

    if(n*2 == m || n*3 == m || n/2 == m || n/3 == m || n+7 == m || n-7 == m) return minimo;
    else{
        op[0]=operacoes(n*2,m);
        op[1]=operacoes(n*3,m);
        op[2]=operacoes(n/2,m);
        op[3]=operacoes(n/3,m);
        op[4]=operacoes(n+7,m);
        op[5]=operacoes(n-7,m);
        menor=op[0];
        for(int i=1;i<6;i++){
            if(op[i]<menor) menor=op[i];
        }
        return menor;
    }
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);
    printf("%d\n", operacoes(n, m));
}
