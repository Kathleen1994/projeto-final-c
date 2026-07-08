#include <stdio.h>
#include "jogo.h"

int main() {

    int opcao;

    do {

        menu();

        printf("\nOpcao: ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1:
                novoJogo();
                break;

            case 2:
                regras();
                break;

            case 3:
                pontuacoes();
                break;

            case 0:
                printf("\nObrigado por jogar!\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}
