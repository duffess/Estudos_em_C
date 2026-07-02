#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void bemvindo(){
    printf("***********************\n");
    printf(" BEM VINDO(A) AO JOGO DE ADIVINHACAO\n");
    printf("***********************\n\n");
}

void limpabuffer(){
    while(getchar() != '\n');
}

int dificuldade(){
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

int gerarnumero(){
    int numerogrande = rand();
    int numerosecreto = numerogrande % 100;
    return numerosecreto;
}

int jogarnovamente(){
    int respostajogo;
    printf("Deseja jogar novamente?\n");
    printf("1- SIM \n2- NÃO\n");
    scanf("%d", &respostajogo);
    limpabuffer();
    if (respostajogo > 2 || respostajogo < 1){
        printf("Por favor, escolha um número válido.\n");
        return jogarnovamente();
    }
    if (respostajogo == 1){
        printf("Ótimo, vamos jogar novamente!\n");
    } else {
        printf("Poxa, que pena!\n");
    }
    return respostajogo;
}

int main() {
    int chutesusuario[20];
    srand(time(0));
    bemvindo();
    int jogardenovo;
    do {
        int numerosecreto = gerarnumero();
        printf("[DEBUG] Número secreto: %d\n", numerosecreto);
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
            chutesusuario[i] = chute;
            printf("TESTANDO ARRAY. %d", chutesusuario[i]);
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
            printf("Você ganhou!\n\n");
            printf("Seus chutes, foram: ");
            for(int z = 1; z <= tentativas; z++){
                printf("[%d] ", chutesusuario[z]);
            } printf("\n\n");
            
        if(tentativas <= 5) {
            printf("Parabéns, você é ótimo!\n\n");
        }
                    
            printf("Você acertou em %d tentativas!\n\n", tentativas);
            printf("Total de pontos: %.1f\n\n", pontos);
        }
        else {
            printf("Você perdeu! O número secreto era %d.\n", numerosecreto);
            printf("Tente de novo!\n");
        }
        jogardenovo = jogarnovamente();
    } while(jogardenovo == 1);
    return 0;
}