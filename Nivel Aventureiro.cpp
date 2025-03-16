#include <stdio.h>

#define N 10
#define NAVIO_SIZE 3

int main() {
    int tabuleiro[N][N] = {0};
    int navios[4][3] = {{2, 3, 0}, {5, 5, 1}, {0, 0, 2}, {7, 9, 3}};

    // Posicionar os navios
    for (int i = 0; i < 4; i++) {
        int linha = navios[i][0], coluna = navios[i][1], orientacao = navios[i][2];
        int valido = 1;

        for (int j = 0; j < NAVIO_SIZE; j++) {
            int x = linha + (orientacao == 1 ? j : 0) + (orientacao == 2 || orientacao == 3 ? j : 0);
            int y = coluna + (orientacao == 0 ? j : 0) + (orientacao == 2 ? j : 0) - (orientacao == 3 ? j : 0);

            // Verifica se a posição é válida
            if (x >= N || y >= N || tabuleiro[x][y] != 0) {
                valido = 0;
                break;
            }
            tabuleiro[x][y] = 3; // Marca a posição do navio
        }

        if (!valido) {
            printf("Posição inválida para o navio %d.\n", i + 1);
        }
    }

    // Exibir o tabuleiro
    printf("Tabuleiro do Jogo - Batalha Naval:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
