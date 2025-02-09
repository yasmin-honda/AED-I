//Programa que, dada uma expressão qualquer, indica se o número de parênteses está correto ou não 
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool verificaBalancoParenteses (char *);

int main (){
	char expressao[1100];

	while (scanf(" %s", expressao) != EOF){
	  if(verificaBalancoParenteses(expressao)) printf("correct\n");
		else printf("incorrect\n");
  }
}

bool verificaBalancoParenteses(char *str){
	short qtsP = 0;
  
  //se a expressão começar com uma parêntese que fecha já não esta balanceada;
	if (*str == ')') return false;

	//enquanto a string não acabar ou o balanço for irrecuperável
	while ((*str) && (qtsP >= 0)){
		//se achar um parentese que abre, incrementa variável;
		if (*str == '(') qtsP++;

		//se achar um parentese que fecha, decrementa;
		if (*str == ')') qtsP --;
    
		str++;
	}

	if (qtsP == 0)	return true;
	else return false;

}
