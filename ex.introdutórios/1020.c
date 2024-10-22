#include<stdio.h>

int main(){
    int i,a=0,m=0,d=0;

    scanf("%d",&i);
    if(i>=365){
        a=i/365;
        d=i%365;
        if(d>=30){
            m=d/30;
            d=d%30;
        }
    }
    else{
        if(i>=30){
            m=i/30;
            d=i%30;
        }
        else d=i;
    }
    printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n",a,m,d);

}
