#include <stdio.h>

int main() {
    for( int i = 1; i <= 4; i++){
        switch(i){
            case 1:
                printf("Ligando rotores.\n\n");
                break;
            case 2:
                printf("Decolando.\n\n");
                break;
            case 3:
                printf("Estabilizando altitude.\n\n");
                break;
            case 4:
                printf("Comando nao reconhecido. Pousando.\n\n");
                break;
        }
    }
}