#include<stdio.h>
#define MAX 100000000

int main(){
    int n,j,menor,maior;
    
    while(1){
        scanf("%d",&n);  
        if(n==0)break;
        int vetor[2*n],soma[n];
        j=(2*n)-1;
        for(int i=0;i<2*n;i++){
            scanf("%d",&vetor[i]);
        }
        for(int i=0;i<n;i++){
            soma[i]=vetor[i]+vetor[j];
            j--;
            if(i==0){
                menor=soma[i];
                maior=soma[i];
            }
            else if(soma[i]<menor)menor=soma[i];
            else if(soma[i]>maior)maior=soma[i];
            
        }
        printf("%d %d\n",maior,menor);
    }
}
