#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void bemvindo(){
    printf("***********************\n");
    printf(" BEM VINDO(A) AO JOGO DE ADIVINHACAO\n");
    printf("***********************\n\n");
}

int dificuldade(){
    int nivel;
    printf("Qual o nível de dificuldade?\n");
    printf("(1) Fácil (2) Médio (3) Difícil\n");
    printf("Escolha: ");
    scanf("%d", &nivel);
    if (nivel > 3 || nivel < 1){
        printf("Por favor, escolha um número válido.\n");
        return dificuldade();
    }
    return nivel;
}

int gerarnumero(){
    int numerogrande = rand();
    int numerosecreto = numerogrande % 100;
    return numerosecreto;
}

int main() {
    // funcao
    srand(time(0));
    bemvindo();
    int numerosecreto = gerarnumero();
    int chute;
    int tentativas = 0;                    
    double pontos = 1000.0;
    int acertou = 0;
    int nivel = dificuldade();

    int numerodetentativas;
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

    for(int i = 1; i <= numerodetentativas; i++) {
        
        tentativas++;                             
        printf("Tentativa %d de %d\n", tentativas, numerodetentativas);
        printf("Qual é o seu número? ");

        scanf("%d", &chute);
        printf("Seu chute foi: %d\n", chute);

        if(chute < 0) {
            printf("Você não pode chutar números negativos!\n");
            tentativas--;
            continue;
        }

        acertou = (chute == numerosecreto);

        if(acertou) {
            break;
        } 
        else if(chute > numerosecreto) {
            printf("Seu chute foi maior que o número secreto\n");
        } 
        else {
            printf("Seu chute foi menor que o número secreto\n");
        }

        double pontosperdidos = abs(chute - numerosecreto) / 2.0;
        pontos = pontos - pontosperdidos;
    }

    printf("\nFim de jogo!\n\n");

    if(acertou) {
        printf("Você ganhou!\n");
        
    if(tentativas <= 5) {
        printf("Parabéns, você é ótimo!\n");
    }
    else if(tentativas <= 10) {
        printf("Eh... foi quase..\n\n");
    }
    else if(tentativas <= 19) {
        printf("Péssimo, melhore.\n");
    }
        
        printf("Você acertou em %d tentativas!\n", tentativas);
        printf("Total de pontos: %.1f\n", pontos);
    }
    else {
        printf("Você perdeu! O número secreto era %d.\n", numerosecreto);
        printf("Tente de novo!\n");
    }

    return 0;
}