#include "tadFila.h"
#include <Windows.h>

void relatorio(struct RELATORIO** priRel, const char* vencedor) {
	struct RELATORIO* aux = *priRel;

	while (aux != NULL) {
		if (strcmp(aux->nome, vencedor) == 0) { //no strcmp 0 = encontrou e 1 = n encontrou
			aux->vitorias++;
			break;
		}
		aux = aux->proxNo;
	}

	aux = *priRel;

	printf("-=-=-=-=-=-=-=-=| RELATORIO DE VITORIAS |=-=-=-=-=-=-=-=-\n");
	while (aux != NULL) {
		printf("%s: %d\n", aux->nome, aux->vitorias);
		printf("--------------------------\n");
		aux = aux->proxNo;
	}

}

void batalhar(struct TROPA** pri, struct RELATORIO** priRel) {
	struct TROPA* atual = *pri;
	
	if (*pri == NULL || (*pri)->proxNo == NULL) {
		printf("\n\n\n----------------------------------------\n");
		printf("   Voce nao tem tropas suficientes :/ \n");
		printf("----------------------------------------\n\n\n");
		return;
	}

	struct TROPA* prox = atual->proxNo;

	printf("=-=-=-=-=-=-=-=-=-=-=-=| COMBATE |=-=-=-=-=-=-=-=-=-=-=-=\n");
	printf("\n\n--------| %s VS %s |--------\n\n", atual->nome, prox->nome);
	printf("tropa: %s\n", atual->nome);
	printf("ataque: %d\n", atual->ataque);
	printf("defesa: %d\n", atual->defesa);
	printf("--------------------------\n");
	printf("tropa: %s\n", prox->nome);
	printf("ataque: %d\n", prox->ataque);
	printf("defesa: %d\n", prox->defesa);
	printf("\n\nBatalhando");

	const char* m = ".....";
	for (int i = 0; m[i] != '\0'; i++) {
		printf("%c", m[i]);
		fflush(stdout); //garante que o caractere seja exibido imediatamente
		Sleep(1000);
	}
	printf("\n\n\n");

	int danoAtual, danoProx;
	danoAtual = atual->ataque - prox->defesa;
	danoProx = prox->ataque - atual->defesa;
	char vencedor[51];

	if (danoAtual > danoProx) {

		printf("--------------------------\n");
		printf("|    Tropa vencedora:    |\n");
		printf("|           %s            |\n", atual->nome);
		printf("--------------------------\n");
		printf("\nDano causado por %s: %d\n", atual->nome, danoAtual);
		printf("Dano causado por %s: %d\n\n", prox->nome, danoProx);
		strcpy_s(vencedor, atual->nome);

		if (danoProx > 0) {
		atual->defesa = atual->defesa - danoProx;
		}
		
		atual->proxNo = prox->proxNo;
		free(prox);
	}
	else {
		printf("--------------------------\n");
		printf("|    Tropa vencedora:    |\n");
		printf("|           %s            |\n", prox->nome);
		printf("--------------------------\n");
		printf("\n\n\nDano causado por %s: %d\n", atual->nome, danoAtual);
		printf("Dano causado por %s: %d\n\n\n\n\n", prox->nome, danoProx);
		strcpy_s(vencedor, prox->nome);

		if (danoAtual > 0) {
			prox->defesa = prox->defesa - danoAtual;
		}
		
		*pri = prox;
		free(atual);
	}
	bubbleSort(pri);
	relatorio(priRel, vencedor);
}