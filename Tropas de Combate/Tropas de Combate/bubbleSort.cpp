#include "tadFila.h"


void bubbleSort(struct TROPA** pri) {

	if (*pri == NULL || (*pri)->proxNo == NULL) {
		return;
	}

	bool trocado = false;
	struct TROPA* atual;
	struct TROPA* aux = NULL;

	do {
		trocado = false;
		atual = *pri;
		struct TROPA* prox = atual->proxNo;

		while (atual->proxNo != aux) { //da primeira vez roda ate o final, nas proximas vai ate o penultimo pra evitar processamento desnecessario

			if (prox != NULL) {
				bool troca = false;

				if (atual->ataque < prox->ataque) {
					troca = true;
				}
				else if (atual->ataque == prox->ataque) {
					if (atual->defesa > prox->defesa) {
						troca = true;
					}
					else if (atual->defesa == prox->defesa) {
						if (atual->ordemChegada > prox->ordemChegada) {
							troca = true;
						}
					}
				}

				if (troca) {
					char tempNome[51];
					int tempAtaque, tempDefesa, tempOrdemChegada;

					//troca de nome
					strcpy_s(tempNome, atual->nome);
					strcpy_s(atual->nome, prox->nome);
					strcpy_s(prox->nome, tempNome);

					//troca de ataque
					tempAtaque = atual->ataque;
					atual->ataque = prox->ataque;
					prox->ataque = tempAtaque;

					//troca de defesa
					tempDefesa = atual->defesa;
					atual->defesa = prox->defesa;
					prox->defesa = tempDefesa;

					//troca de n de ordem de chegada
					tempOrdemChegada = atual->ordemChegada;
					atual->ordemChegada = prox->ordemChegada;
					prox->ordemChegada = tempOrdemChegada;

					trocado = true;

				}
			}

			atual = atual->proxNo;
			prox = atual->proxNo;
		}
		aux = atual;
	} while (trocado); //vai rodar ate que nao tenha sido feita nenhuma troca (ou seja ta organizado)
}
