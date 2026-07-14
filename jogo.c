#include <stdio.h>
#include "jogo.h"

char mapa[10][10] = {
    "#########",
    "#.......#",
    "#...T...#",
    "#..X....#",
    "#...K...#",
    "#.......#",
    "#....X..#",
    "#.......#",
    "#P......#",
    "#########"
};

int jogadorLinha = 8;
int jogadorColuna = 1;
int pontos = 0;
int temChave = 0;
int vidas = 3;
int jogoTerminado = 0;

char casaAtual;
char nomeJogador[50];

void menu() {

    printf("\n==============================\n");
    printf("      CAÇA AO TESOURO\n");
    printf("==============================\n");
    printf("1 - Novo Jogo\n");
    printf("2 - Regras\n");
    printf("3 - Pontuações\n");
    printf("0 - Sair\n");
    printf("==============================\n");

}


void novoJogo() {

    char movimento;

    printf("Nome do jogador: ");
scanf("%49s", nomeJogador);

    do {

        mostrarMapa();

        printf("\nMover (W/A/S/D) ou X para sair: ");
        scanf(" %c", &movimento);

        moverJogador(movimento);
        verificarObjetivo();

    } while (movimento != 'x' &&
             movimento != 'X' &&
             vidas > 0 &&
             !jogoTerminado);

}
void regras() {

    printf("\n========== REGRAS ==========\n");
    printf("-> Usa W A S D para mover o jogador.\n");
    printf("-> Encontra a chave (K).\n");
    printf("-> Depois encontra o tesouro (T).\n");
    printf("-> Evita as armadilhas (X).\n");
    printf("-> Cada armadilha retira 1 vida.\n");
    printf("-> Tens 3 vidas.\n");
    printf("-> O jogo termina quando encontras o tesouro\n");
    printf("   ou quando perdes todas as vidas.\n");

}


void pontuacoes() {

    FILE *ficheiro;
    char linha[100];

    ficheiro = fopen("pontuacoes.txt", "r");

    if(ficheiro == NULL) {

        printf("\nAinda não existem pontuações.\n");
        return;
    }

    printf("\n===== PONTUAÇÕES =====\n");

    while(fgets(linha, sizeof(linha), ficheiro) != NULL) {

        printf("%s", linha);

    }

    fclose(ficheiro);
}


void moverJogador(char movimento)
{
    int novaLinha = jogadorLinha;
    int novaColuna = jogadorColuna;

    if (movimento == 'w' || movimento == 'W')
        novaLinha--;

    else if (movimento == 's' || movimento == 'S')
        novaLinha++;

    else if (movimento == 'a' || movimento == 'A')
        novaColuna--;

    else if (movimento == 'd' || movimento == 'D')
        novaColuna++;

    if(mapa[novaLinha][novaColuna] != '#') {

    casaAtual = mapa[novaLinha][novaColuna];

    mapa[jogadorLinha][jogadorColuna] = '.';

    jogadorLinha = novaLinha;
    jogadorColuna = novaColuna;

    mapa[jogadorLinha][jogadorColuna] = 'P';
    }

}
void verificarObjetivo() {

    if(casaAtual == 'X') {

        vidas--;
        pontos -= 20;

        if(pontos < 0)
            pontos = 0;

        printf("\nCaíste numa armadilha!\n");
        printf("Perdeste uma vida.\n");

        if(vidas == 0) {

            printf("\n==============================\n");
            printf("        GAME OVER\n");
            printf("==============================\n");
            printf("Pontuação final: %d\n", pontos);
jogoTerminado = 1;

        }

    }

    if(casaAtual == 'K') {

        temChave = 1;
        pontos += 50;

        printf("\nEncontraste a chave! +50 pontos\n");

    }

    if(casaAtual == 'T') {

        if(temChave) {

            pontos += 100;

            printf("\n==============================\n");
            printf("      PARABÉNS!\n");
            printf("==============================\n");
            printf("Encontraste o tesouro!\n");
            printf("Pontuação final: %d\n", pontos);

            guardarPontuacao();

jogoTerminado = 1;

        } else {

            printf("\nPrecisas da chave primeiro!\n");

        }

    }
}
void guardarPontuacao() {

    FILE *ficheiro;

    ficheiro = fopen("pontuacoes.txt", "a");

    if(ficheiro == NULL) {

        printf("\nErro ao guardar pontuacao.\n");
        return;
    }

    fprintf(ficheiro, "%s - %d pontos\n", nomeJogador, pontos);

    fclose(ficheiro);

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
