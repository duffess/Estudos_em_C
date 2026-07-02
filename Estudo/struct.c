#include <stdio.h>

// Função que tenta alterar a temperatura
void alterarTemperatura(int temp) {
    temp = 99;
}

int main() {
    int minhaTemperatura = 20;
    
    alterarTemperatura(minhaTemperatura);
    
    printf("%d", minhaTemperatura);
    
    return 0;
}


#include <stdio.h>

// Agora a função recebe um PONTEIRO (o bloco de notas com o endereço)
void alterarTemperatura(int *temp) {
    *temp = 99; // O carteiro vai até o endereço original e troca o valor lá dentro!
}

int main() {
    int minhaTemperatura = 20;
    
    // Enviamos o ENDEREÇO da variável usando o '&'
    alterarTemperatura(&minhaTemperatura); 
    
    printf("%d", minhaTemperatura); // Agora sim, imprime 99!
    return 0;
}