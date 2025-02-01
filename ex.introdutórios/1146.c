#include<stdio.h>

int main(){
    int n=1;

    while(n!=0){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            if(i==n){
                printf("%d\n",i);
                break;
            }
            printf("%d ",i);
        }
    }
}
