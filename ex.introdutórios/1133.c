#include<stdio.h>

int main(){
    int x,y,aux;
    
    scanf("%d %d",&x,&y);
    if(x<y){
        aux=x+1;
        while(aux<y){
            if(aux%5==2 || aux%5==3) printf("%d\n",aux);
            aux++;
        }   
    }
    else{
        aux=y+1;
        while(aux<x){
            if(aux%5==2 || aux%5==3) printf("%d\n",aux);
            aux++;
        } 
    }
}
