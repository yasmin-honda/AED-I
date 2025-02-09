/*Programa que recebe dois inteiros n e m, calcula seus fatoriais e soma
obs: tive que substituir a recursão do fatorial pois nn estava funcionando para números muito grandes (sobrecarregava a pilha de recursão)
*/
#include <stdio.h>

long long int fatorial(int num) {
    long long int resultado = 1;
    for (int i = 2; i <= num; i++) {
        resultado *= i;
    }
    return resultado;
}

int main() {
    int n, m;
    long long int fat;
    
    while (scanf("%d %d", &n, &m) != EOF) {
        fat = fatorial(n) + fatorial(m);
        printf("%lld\n", fat);  
    }

    return 0;
}
