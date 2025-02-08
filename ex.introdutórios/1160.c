#include<stdio.h>

int main(){
    int t,pa,pb,tempo=0;
    float g1,g2;
    
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        tempo=0;
        scanf("%d %d %f %f",&pa,&pb,&g1,&g2);
        while(pa<=pb){
            if(tempo>100){
                break;
            }
            pa=pa+pa*(g1/100);
            pb=pb+pb*(g2/100);
            tempo++;
        }
        if(tempo>100)printf("Mais de 1 seculo.\n");
        else printf("%d anos.\n",tempo);
    }
}
