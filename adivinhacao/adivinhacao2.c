#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct estadodepartida
{
	int numerosecreto;
	int tentativas;
	int numerodetentativas;
	double pontos;
	int acertou;
	int chutesusuario[20];
	int chute;
};

int dificuldade()
{
    int nivel;
    printf("Qual o nível de dificuldade?\n");
    printf("(1) Fácil (2) Médio (3) Difícil\n");
    printf("Escolha: ");
    scanf("%d", &nivel);
    limpabuffer();
    if (nivel > 3 || nivel < 1){
        printf("Por favor, escolha um número válido.\n");
        return dificuldade();
    }
    return nivel;
}

int gerarnumero()
{
    int numerogrande = rand();
    int numerosecreto = numerogrande % 100;
    return numerosecreto;
}

void configuracaopartida (struct estadodepartida *jogo)
{
	dificuldade();
	gerarnumero();
	switch(nivel) {
            case 1:
                numerodetentativas = 20;
                break;
            case 2:
                numerodetentativas = 15;
                break;
            default:
                numerodetentativas = 6;
                break;
        }
    meujogo->pontos = 1000;
    meujogo->
}

int main(){
	struct estadodepartida meujogo;
}