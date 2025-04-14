#include "tadFila.h"
#include <time.h>

int ordemChegada = 1;

void lbtec() {
	int c = 0;
	while ((c = getchar()) != '\n' && c != EOF) {
		return;
	}
}

void enqueue(struct TROPA** pri, struct TROPA** ult, struct RELATORIO** priRel, struct RELATORIO** ultRel) {
	struct TROPA* novoNo;
	struct RELATORIO* novoRel;

	if ((novoNo = (struct TROPA*)malloc(sizeof(struct TROPA))) == NULL || (novoRel = (struct RELATORIO*)malloc(sizeof(struct RELATORIO))) == NULL) {
		printf("Erro!! Memoria nao alocada\n");
	}
	else {
		lbtec();
		printf("=-=-=-=-=-=-=-=-=-=| Adicionar Tropa |=-=-=-=-=-=-=-=-=-=\n");
		printf("---------------------------------------------------------\n");
		printf("| poderes de ataque e defesa sao gerados randomicamente |\n");
		printf("---------------------------------------------------------\n");
		printf("Digite o nome da tropa: ");
		scanf_s("%s", &(*novoNo).nome, (unsigned)_countof(novoNo->nome));
		srand(time(NULL));
		novoNo->ataque = (rand() % 100);
		novoNo->defesa = (rand() % 100);

		strcpy_s(novoRel->nome, novoNo->nome);
		novoRel->vitorias = 0;

		(novoNo)->proxNo = NULL;
		(novoRel)->proxNo = NULL;

		if (*ult == NULL) {
			*pri = novoNo;
			*priRel = novoRel;
		}
		else {
			(*ult)->proxNo = novoNo;
			(*ultRel)->proxNo = novoRel;
		}
		*ult = novoNo;
		*ultRel = novoRel;
		(novoNo)->ordemChegada = ordemChegada++;
		bubbleSort(pri);
	}
}
