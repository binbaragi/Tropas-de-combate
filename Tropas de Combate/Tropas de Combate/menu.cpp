#include "tadFila.h"

void menu() {
    struct TROPA* pri = NULL;
    struct TROPA* ult = NULL;
    struct RELATORIO* priRel = NULL;
    struct RELATORIO* ultRel = NULL;
    int op;


    do {
        system("cls");
        printf("-=-=-=-=-=-=-=-=-=-=| MENU PRINCIPAL |=-=-=-=-=-=--=-=-=-\n\n");
        printf("[1] Adicionar tropa\n");
        printf("[2] Mostrar tropas\n");
        printf("[3] Batalhar\n");
        printf("[4] Sair\n");
        printf("Informe sua escolha: ");
        scanf_s("%d", &op);

        switch (op) {
        case 1:
            system("cls");
            enqueue(&pri, &ult, &priRel, &ultRel);
            break;
        case 2:
            system("cls");
            mostrar(&pri);
            break;
        case 3:
            system("cls");
            batalhar(&pri, &priRel);
            break;
        case 4:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("ERRO! Informe 1, 2, 3 ou 4\n");
        }
        system("pause");
    } while (op != 4);
}