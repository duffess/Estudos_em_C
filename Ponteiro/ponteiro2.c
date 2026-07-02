#include <stdio.h>

void tomar_dano(int *v) {
    *v = *v - 20; // Ele viaja até a casa original e altera para 80.
}

int main() {
    int vida = 100;
    tomar_dano(&vida); // Passa o endereço original
    // Agora a vida no main é 80! O jogo funciona.
    printf("%d\n", vida);

}