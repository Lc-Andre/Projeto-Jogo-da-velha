#include <stdio.h>

//Funcoes
void mostrar_mensagem(void) {
    printf("******************************\n");
    printf("* Bem-Vindo ao Jogo da Velha *\n");
    printf("******************************\n");
    printf("\n");
}

void mostrar_tabuleiro(char tabuleiro[3][3]) {
    for (int linha = 0; linha < 3; linha++) {
        for (int coluna = 0; coluna < 3; coluna++) {
            printf("%c\t", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }
}

void verifica_posicao(char tabuleiro[3][3], int* posX, int* posY, char jogador, int* minJogadas) {
    while (tabuleiro[*posX][*posY] != '-') {
        printf("Posição inválida! Tente novamente.\n");
        printf("\nJogador %c, digite a linha da posição que deseja jogar: ", jogador);
        scanf("%d", posX);
        printf("Agora digite a coluna da posição que deseja jogar: ");
        scanf("%d", posY);
    }
    tabuleiro[*posX][*posY] = jogador;
    (*minJogadas)++;
}

int verifica_vitoria(char tabuleiro[3][3], char jogador, int* minJogadas, int* ganhou) {
    if (*minJogadas >= 3) {
        for (int linha = 0; linha < 3; linha++) {
            if (tabuleiro[linha][0] == jogador &&
                tabuleiro[linha][1] == jogador &&                    //verifica as linhas
                tabuleiro[linha][2] == jogador) {
                *ganhou = 1;
            }
        }

        for (int coluna = 0; coluna < 3; coluna++) {
            if (tabuleiro[0][coluna] == jogador &&
                tabuleiro[1][coluna] == jogador &&                  //verifica as colunas
                tabuleiro[2][coluna] == jogador) {
                *ganhou = 1;
            }
        }

        if (tabuleiro[0][0] == jogador &&
            tabuleiro[1][1] == jogador &&                        //verifica a diagonal principal
            tabuleiro[2][2] == jogador) {
            *ganhou = 1;
        }

        if (tabuleiro[0][2] == jogador &&
            tabuleiro[1][1] == jogador &&                        //verifica a diagonal secundaria
            tabuleiro[2][0] == jogador) {
            *ganhou = 1;
        }
    }

    return *ganhou;
}

int verifica_empate(char tabuleiro[3][3]) {
    for (int linha = 0; linha < 3; linha++) {
        for (int coluna = 0; coluna < 3; coluna++) {
            if (tabuleiro[linha][coluna] == '-') {
                return 0; 
            }
        }
    }
    return 1; 
}

// Bloco principal
int main() {
    char jogador1;
    char jogador2;
    int posX;
    int posY;
    int ganhou = 0; // 0 indica falso
    int minJogadasJogador1 = 0;
    int minJogadasJogador2 = 0;
    char tabuleiro[3][3] = {
        {'-','-','-'},
        {'-','-','-'},
        {'-','-','-'}
    };

    mostrar_mensagem();
    mostrar_tabuleiro(tabuleiro);

    printf("Jogador 1, escolha um dos simbolos para jogar (x/o): ");
    scanf(" %c", &jogador1);
    if (jogador1 == 'x') {
        jogador2 = 'o';
    }
    else {
        jogador2 = 'x';
    }

    while (ganhou == 0) {
        // Jogador 1 faz a jogada
        printf("\nJogador 1, digite a linha da posicao que deseja jogar: ");
        scanf("%d", &posX);
        printf("Agora digite a coluna da posicao que deseja jogar: ");
        scanf("%d", &posY);

        verifica_posicao(tabuleiro, &posX, &posY, jogador1, &minJogadasJogador1);
        mostrar_tabuleiro(tabuleiro);

        if (verifica_vitoria(tabuleiro, jogador1, &minJogadasJogador1, &ganhou) == 1) {
            printf("Jogador 1 venceu!!\n");
            break;
        }
        if (verifica_empate(tabuleiro)) {
            printf("O jogo empatou!\n");
            break;
        }

        // Jogador 2 faz a jogada
        printf("\nJogador 2, digite a linha da posicao que deseja jogar: ");
        scanf("%d", &posX);
        printf("Agora digite a coluna da posicao que deseja jogar: ");
        scanf("%d", &posY);

        verifica_posicao(tabuleiro, &posX, &posY, jogador2, &minJogadasJogador2);
        mostrar_tabuleiro(tabuleiro);

        if (verifica_vitoria(tabuleiro, jogador2, &minJogadasJogador2, &ganhou) == 1) {
            printf("Jogador 2 venceu!!\n");
            break;
        }

        if (verifica_empate(tabuleiro)) {
            printf("O jogo empatou!\n");
            break;
        }
    }

    return 0;
}