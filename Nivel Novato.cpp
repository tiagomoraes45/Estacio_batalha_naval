#include <stdio.h>

#define N 10 // Tamanho do tabuleiro

int main() {
    int tabuleiro[N][N] = {0};

    // Posicionar os navios diretamente
    for (int i = 0; i < 3; i++) tabuleiro[2][3 + i] = 3; // Navio 1 (horizontal)
    for (int i = 0; i < 3; i++) tabuleiro[5 + i][6] = 3; // Navio 2 (vertical)

    // Exibir o tabuleiro
    printf("Tabuleiro do Jogo - Batalha Naval:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
