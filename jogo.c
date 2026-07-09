#include <stdio.h>
#include "jogo.h"

char mapa[10][10] = {
    "#########",
    "#.......#",
    "#...T...#",
    "#.......#",
    "#...K...#",
    "#.......#",
    "#.......#",
    "#.......#",
    "#P......#",
    "#########"
};

int jogadorLinha = 8;
int jogadorColuna = 1;
int pontos = 0;
int temChave = 0;


void menu() {
    printf("\n==============================\n");
    printf("      CACA AO TESOURO\n");
    printf("==============================\n");
    printf("1 - Novo Jogo\n");
    printf("2 - Regras\n");
    printf("3 - Pontuacoes\n");
    printf("0 - Sair\n");
}


void novoJogo() {

    char movimento;

    do {

        mostrarMapa();

        printf("\nMover (W/A/S/D) ou X para sair: ");
        scanf(" %c", &movimento);

        moverJogador(movimento);
verificarObjetivo();


    } while(movimento != 'x' && movimento != 'X');

}


void regras() {

    printf("\nObjetivo: encontrar o tesouro T.\n");
    printf("Usa W A S D para movimentar o jogador.\n");

}


void pontuacoes() {

    printf("\nAinda nao existem pontuacoes.\n");

}


void mostrarMapa() {

    int i, j;

    for(i = 0; i < 10; i++) {

        for(j = 0; j < 10; j++) {

            printf("%c ", mapa[i][j]);

        }

        printf("\n");
    }
}


void moverJogador(char movimento) {

    int novaLinha = jogadorLinha;
    int novaColuna = jogadorColuna;


    if(movimento == 'w' || movimento == 'W')
        novaLinha--;

    else if(movimento == 's' || movimento == 'S')
        novaLinha++;

    else if(movimento == 'a' || movimento == 'A')
        novaColuna--;

    else if(movimento == 'd' || movimento == 'D')
        novaColuna++;


    if(mapa[novaLinha][novaColuna] != '#') {

        mapa[jogadorLinha][jogadorColuna] = '.';

        jogadorLinha = novaLinha;
        jogadorColuna = novaColuna;

        mapa[jogadorLinha][jogadorColuna] = 'P';
    }

}
void verificarObjetivo() {

    if(mapa[jogadorLinha][jogadorColuna] == 'K') {

        temChave = 1;
        pontos += 50;

        printf("\nEncontraste a chave! +50 pontos\n");

    }


    if(mapa[jogadorLinha][jogadorColuna] == 'T') {

        if(temChave) {

            pontos += 100;

            printf("\nPARABENS! Encontraste o tesouro!\n");
            printf("Pontuacao final: %d\n", pontos);

        } else {

            printf("\nPrecisas da chave primeiro!\n");

        }

    }

}
