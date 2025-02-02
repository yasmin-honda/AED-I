#include<stdio.h>

int chamadas=0;

int fibonacci(int n){
    chamadas++;
    if(n==0)return 0;
    if(n==1)return 1;
    else{
        return fibonacci(n-1)+fibonacci(n-2);
    }
}

int main(){
    int n,x;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        printf("fib(%d) = %d calls = %d\n",x,chamadas-1,fibonacci(x));
        chamadas=0;
    }
}
