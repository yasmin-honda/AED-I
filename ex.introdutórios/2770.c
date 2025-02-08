#include<stdio.h>

int main(){
    int x=1,y=1,n=1,l,c;
    
    while(scanf("%d %d %d",&x,&y,&n)!=EOF){
        if(x==0 && y==0)break;
        for(int i=0;i<n;i++){
            scanf("%d %d",&l,&c);
            if(l<=x && c<=y || l<=y && c<=x)printf("Sim\n");
            else printf("Nao\n");
        }   
    }
}
