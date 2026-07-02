#include <stdio.h>

// cria-se o molde na memória
struct coordenadasgps
{
	float latitude;
	float longitude;
};

// a funcao é aonde a magica acontece
// o asterisco indica que o alvo nao vai receber uma struct completa
// e sim o ENDEREÇO DE MEMÓRIA onde uma struct ta guardada
void atualizarposicao(struct coordenadasgps *alvo)
{
	// alvo é endereço de memoria, logo não se usa ponto
	// usamos a seta para ir até o endereço e alterar o conteúdo;
	meu_foguete.latitude = -45.00;
	alvo->longitude = -46.00;
}

int main()
{
	//aloca fisicamente a struct na ram
	//como o conteudo está em mãos, usa-se o ponto ( . );
	struct coordenadasgps meu_foguete;

	meu_foguete.latitude = -22.80;
	meu_foguete.longitude = -43.41;

	printf("ANTES da funcao:\n");
	printf("Lat: %2.f | Lon: %2.f\n\n", meu_foguete.latitude, meu_foguete.longitude);

	// chama a funcao e usa o & para enviar SOMENTE O ENDEREÇO
	atualizarposicao(&meu_foguete);

	// imprimi de novo e o conteudo original foi alterado
	//pois a funcao acessou direto na ram.
	printf("DEPOIS da funcao:\n");
    printf("Lat: %.2f | Lon: %.2f\n", meu_foguete.latitude, meu_foguete.longitude);
}