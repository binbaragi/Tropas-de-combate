#include "tadFila.h"

void mostrar(struct TROPA** pri) {
    struct TROPA* aux = *pri;
    if (aux == NULL) {
        printf("\n\n\n----------------------------------------\n");
        printf("     Voce nao tem nenhuma tropa :(\n");
        printf("----------------------------------------\n\n\n");
    }
    else {
           printf("-=-=-=-=-=-=-=-=-=-=-=-=| Tropas |=-=-=-=-=-=-=-=-=-=-=-=\n");
        while (aux != NULL) {
            
            printf("nome: %s\n", aux->nome);
            printf("ataque: %d\n", aux->ataque);
            printf("defesa: %d\n", aux->defesa);
            printf("ordem de chegada: %d\n", aux->ordemChegada);
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            aux = aux->proxNo;
        }
        printf("\n");
    }
}