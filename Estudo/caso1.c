#include <stdio.h>

int main(){
	int idsensor = 3;
	float umidadedosensor = 85.5;

	printf("O Sensor ID[%d] registrou uma [%.1f]%%UMIDADE", idsensor, umidadedosensor);

	return 0;
}