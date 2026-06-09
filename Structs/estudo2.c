#include <stdio.h>
#include <string.h>

struct pessoa
{
	char nome[50];
	int idade;
	float altura;
};

struct predio
{
	float metragem;
	int numerodeandares;
	int numerodepessoascomportadas;
};

int main() {

	// primeira maneira de atribuir valor a uma struct
	struct pessoa g, m;
	strcpy(p.nome, "GUILHERME");
	p.idade = 25;
	p.altura = 1.84;

	strcpy(m.nome, "MARIA");
	m.idade = 22;
	m.altura = 1.64;

	// segunda maneira de atribuir valor a uma struct
	struct pessoa p = {"GUILHERME", 25, 1.84}

	// ERROS COMUNS
	if(m > j){
		printf("Maria é maior do que joão")
	}
	//correto
	if(m.altura > j.altura
		){
		printf("Maria é maior do que joão")
	}

}