#include <stdio.h>
#include <stdbool.h>

int main(){
	float pressao_interna = 120.5;
	bool porta_travada = false;

	if ( pressao_interna > 100 && !porta_travada ){
		printf("ERRO CRITICO: Risco de explosao. Trave a porta!");
	} else {
		printf("Operacao Segura");
	}
}