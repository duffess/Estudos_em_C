#include <stdio.h>

struct pessoa
{
	char nome[50];
	int idade;
	float altura;
};

int main()
{
	struct pessoa parray[5];
	for ( int i = 0; i < 5; i++)
	{
		printf("Digite o nome: ");
		setbuf(stdin,NULL);
		gets(parray[1].nome);
		printf("Digite a idade: ");
		setbuf(stdin,NULL);
		scanf(" %d", &parray[1].idade);
		printf("Digite a altura: ");
		setbuf(stdin,NULL);
		scanf("%f", &parray[1].altura);
	}

	for
}