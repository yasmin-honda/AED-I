#include<stdio.h> //pq da problema no 0?

int qtd(int n){
    if(n==0)return 1;
    else return n+qtd(n-1);
}

void sequencia(int n){
    if(n==0)printf("0\n");
    if(n==1)printf("0 1");
    else{
        sequencia(n-1);
        for(int i=0;i<n;i++){
            printf(" %d",n);
        }
    }
}

int main(){
    int n=1,caso=1;

    while(n!=-2){
        scanf("%d",&n);
        if(n==-1)break;
        if(qtd(n)==1)printf("Caso %d: %d numero\n",caso,qtd(n));
        else printf("Caso %d: %d numeros\n",caso,qtd(n));
        caso++;
        sequencia(n);
        if(n!=0)printf("\n");
    }

}
