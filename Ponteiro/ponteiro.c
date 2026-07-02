#include <stdio.h>

int main() {
	int leituras[5] = {15, 22, 30, 41, 55};
	int *ptr = leituras;

	ptr++;

	printf("%d e %d", *ptr, *(ptr+3));
}