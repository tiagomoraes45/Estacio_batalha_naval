#include <stdio.h>

#define TAMANHO_TABULEIRO 10

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};  // Inicializa o tabuleiro com 0 (água)

    // Posicionamento dos navios (representados por 3)
    tabuleiro[4][4] = 3;
    tabuleiro[4][5] = 3;
    tabuleiro[4][6] = 3;

    // Aplicar área de efeito Cone (em (0, 0))
    for (int i = 0; i < 5; i++) {
        for (int j = i; j < 10 - i; j++) {
            if (i + 0 < TAMANHO_TABULEIRO && j + 0 < TAMANHO_TABULEIRO) {
                tabuleiro[i][j] = 5;  // Marca a área afetada
            }
        }
    }

    // Aplicar área de efeito Cruz (em (5, 5))
    for (int i = 0; i < 10; i++) {
        tabuleiro[5][i] = 5; // Linha central
        tabuleiro[i][5] = 5; // Coluna central
    }

    // Aplicar área de efeito Octaedro (em (7, 7))
    tabuleiro[7][7] = 5;
    tabuleiro[8][7] = 5;
    tabuleiro[9][7] = 5;
    tabuleiro[8][6] = 5;
    tabuleiro[8][8] = 5;

    // Exibe o tabuleiro
    printf("Tabuleiro com áreas de efeito:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
