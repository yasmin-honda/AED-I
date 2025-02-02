/* Cria um programa que recebe um inteiro n indicando o numero de conjuntos a serem testados
Identifica a formação de um par '<>' e o substitui por x para que seja contado corretamente
*/
#include <stdio.h>
#include <string.h>

typedef unsigned short us;

us diamonds(char *);

us diamonds(char *string){

	short x = 0;
	us qtsDiamonds = 0;

	us i, j;
	for (i = 0; string[i]; ++i){
		if (string[i] != '<')continue;
    
		for (j = i + 1; string[j]; ++j){
			if (string[j] == '>'){
				++qtsDiamonds;
				string[i] = 'x';
				string[j] = 'x';
				break;
			}
		}
	}
	return qtsDiamonds;
}

int main (){
	us n;
	int lixo;
	char string[1005];

	scanf("%hu", &n);
	scanf("%d", &lixo);

	while (n--){
		fgets(string, 1005, stdin);
		string[strlen(string) - 1] = '\0';
		printf("%hu\n", diamonds(string));
		memset(string, 0, sizeof(string));
 	}
}
