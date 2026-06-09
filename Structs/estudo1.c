#include <stdio.h>

struct pessoa {
	char nome[50];
	int idade;
	float altura;
};

int main() {
	struct pessoa p;
	printf("Digite seu nome: ");
	gets(p.nome);
	printf("Digite sua idade: ");
	scanf(" %d", &p.idade);
	printf("Digite sua altura: ");
	scanf(" %f", &p.altura);

	printf("\nNome: %s \nIdade: %i \nAltura: %f", p.nome, p.idade, p.altura);
}