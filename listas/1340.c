//Programa que tenta identificar se a estrutura de dados é do tipo fila, pilha, fila de prioridade, mais de um caso ou nenhum
#include<stdio.h> 
#define MAX 1000

int fila(int matriz[MAX][2],int linha){ //analisar se o primeiro elemento que entra é o primeiro elemento que sai
    int i=0,retorno=1;

    for(int j=0;j<linha;j++){
        while(matriz[j][0]==2){
            if(matriz[i][1]!=matriz[j][1]){
                retorno=0;
                break;
            }
            i++;
            j++;
        }
    }
    return retorno;

}

int pilha (int matriz[MAX][2],int fim){ //verifica se o ultimo a sair foi o primeiro a entrar
    int saida,retorno;

    //busca toda a matriz de tras pra frente para encontrar a ultima inserção, compara se foi a primeira saída dps dela
    for(int z=fim-1;z>=0;z--){
        if(matriz[z][0]==2) {
            while(matriz[z][0]!=1){
                saida=matriz[z][1];
                z--;
            }
            if(matriz[z][1]!=saida) retorno=retorno*0;
            else retorno*=1;
        }
        else{
            while(matriz[z][0]!=2)z--;
            saida=matriz[z][1];
            while(matriz[z][0]!=1)z--;
            if(matriz[z][1]!=saida) retorno*=0;
            else retorno*=1;
        }
    }
    return retorno;
}

int filap(int matriz[MAX][2],int tam){ //analisa se o primeiro elemento a sair é o de maior valor
    int aux[tam],i=1,cont=0,retorno=1,aux2=0;

    if(matriz[0][0]==1){
        aux[0]=matriz[0][1];
    }
    else return 0;
    while(i<tam){
        while(matriz[i][0]==1){
            //deixa sempre o maior elemento na primeira posição do vetor
            cont++;
            aux2=0;
            while(aux[aux2]==0) aux2++;
            if(matriz[i][1]>aux[aux2]){
                for(int j=cont;j>=0;j--){
                    if(j==0) aux[j]=matriz[i][1];
                    else aux[j]=aux[j-1];
                }
            }
            else{
                while(matriz[i][1]<aux[aux2+1])aux2++;
                aux[aux2+2]=aux[aux2+1];
                aux[aux2+1]=matriz[i][1];
            }
            i++;
        }
        while(matriz[i][0]==2){
            //remove os valores que aparecerem
            //compara se esta saindo na ordem desejada
            aux2=0;
            while(aux[aux2]==0) aux2++;
            if(aux[aux2]==matriz[i][1]){
                aux[aux2]=0;
            }
            else retorno=0;
            i++;
        }
    }
    return retorno;
}

int impossivel(int matriz[MAX][2], int tam){
    int aux[tam],i=0,p=0,j=0,cont=0;

    if(matriz[0][0]==2) return 1;
    while(i<tam){
         while(matriz[i][0]!=2){
            aux[i]=matriz[i][1];
            i++;
            cont++;
        }
        i++;
    }
    for(int i=1;i<tam;i++){
        while(j<tam){
            if(matriz[i][0]==2){
                while(matriz[i][1]!=aux[j]){
                    j++;
                    p++;
                    if(p==cont){
                        return 1;
                        break;
                    }
                }
            }
            j++;
        }
    }
    return 0;
}

int main(){
    int n,aux=0;

    scanf("%d",&n);
    int lista[n][2];

    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            scanf("%d",&lista[i][j]);
        }
    }
    if(impossivel(lista,n)==1) printf("impossible\n");
    else{
        if(fila(lista,n)==1 && pilha(lista,n)==1 || pilha(lista,n)==1 && filap(lista,n)==1 || fila(lista,n)==1 && filap(lista,n)==1) printf("not sure\n");
        else{
            if(fila(lista,n)==1) printf("queue\n");
            if(pilha(lista,n)==1) printf("stack\n");
            if(filap(lista,n)==1) printf("priority queue\n");
        }
    }
}
