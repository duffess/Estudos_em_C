#include <stdio.h>
#include <stdlib.h>

void display(int var, int *ptr);

int main() {
	int var = 15;
	int *ptr;
	ptr = &var; 
	display(var, ptr);
	*ptr = 73;
	display(var, ptr);

}

void display(int var, int *ptr)
{
	printf("\n\n");
	printf("1. Conteudo de var: %d\n", var);
	printf("2. Endereco de var: %p\n", &var); 
	printf("3. Conteudo apontado por ptr: %d\n", *ptr); 
	printf("4. Endereco apontado por ptr: %p\n", ptr); 
	printf("4. Endereco do ptr          : %p\n", &ptr);
}

// Conteúdo: O valor (dado bruto).

// Endereço: O local físico na RAM (geralmente lido em formato hexadecimal).

// &: Extrai o endereço de memória de uma variável.

// * na declaração: Informa ao compilador que aquela variável 
// específica foi alocada para armazenar um endereço de memória.

// * na execução: Instrui o processador a ir até o endereço 
// armazenado no ponteiro e acessar/sobrescrever o conteúdo que está lá.