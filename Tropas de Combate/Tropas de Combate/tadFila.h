#include "bibliotecas.h"
#include <string.h>

typedef struct TROPA {
	char nome[51];
	int ataque;
	int defesa;
	int ordemChegada;
	struct TROPA* proxNo;
};

typedef struct RELATORIO {
	char nome[51];
	int vitorias;
	struct RELATORIO* proxNo;
};

void bubbleSort(struct TROPA** pri);
void enqueue(struct TROPA** pri, struct TROPA** ult, struct RELATORIO** priRel, struct RELATORIO** ultRel);
void mostrar(struct TROPA** pri);
void batalhar(struct TROPA** pri, struct RELATORIO** priRel);
void menu();