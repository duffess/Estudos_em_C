#include <stdio.h>
#include <string.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define LARGURA_TELA 128
#define ALTURA_TELA 64
#define ENDERECO_OLED 0x3C

Adafruit_SSD1306 display(LARGURA_TELA, ALTURA_TELA, &Wire, -1);

#define PINO_BOTAO_A 13
#define PINO_BOTAO_B 12

struct Partida
{
	char time_a[4]; // 3 letras ( BRA, FRA, ETC + o terminador nulo do c.)
	char time_b[4];
	int gols_a;
	int gols_b;
	int status; // ex: 0 - não iniciado ; 1 - em andamento ; 2 - fim do jogo
};

void iniciarpartida(struct Partida *jogo)
{
	strcpy(jogo->time_a, "BRA");
	strcpy(jogo->time_b, "NOR");
	jogo->gols_a = 0;
	jogo->gols_b = 0;
	jogo->status = 0;
}


void goltimea(struct Partida *jogo)
{
	jogo->gols_a++;
}

void goltimeb(struct Partida *jogo)
{
	jogo->gols_b++;

}


void atualizardisplay(struct Partida *jogo)
{
	display.clearDisplay();
	display.setTextColor(SSD1306_WHITE);
	display.setTextSize(1);
	display.setCursor(0, 0);

	display.print(jogo->time_a);
	display.print(" ");
	display.print(jogo->gols_a);
	display.print(" x ");
	display.print(jogo->gols_b);
	display.print(" ");
	display.print(jogo->time_b);

	display.display();
}

	struct Partida jogocopa;

void setup()
{
	display.begin(SSD1306_SWITCHCAPVCC, ENDERECO_OLED);

	pinMode(PINO_BOTAO_A, INPUT_PULLUP);
	pinMode(PINO_BOTAO_B, INPUT_PULLUP);

	iniciarpartida(&jogocopa);

	atualizardisplay(&jogocopa);
}

void loop()
{
	if (digitalRead(PINO_BOTAO_A) == LOW) {
		goltimea(&jogocopa);
		atualizardisplay(&jogocopa);
		delay(150);
	}

	if (digitalRead(PINO_BOTAO_B) == LOW) {
		goltimeb(&jogocopa);
		atualizardisplay(&jogocopa);
		delay(150);
	}
}
