#include <stdio.h>

#define N 10 // Tamanho do tabuleiro

int main() {
    // Inicializa o tabuleiro com 0 (água)
    int tabuleiro[N][N] = {0};

    // Definir as coordenadas e a orientação dos navios
    // Navio 1 (horizontal)
    int linhaNavio1 = 2, colunaNavio1 = 3; // Coordenadas iniciais
    // Posicionando o navio horizontalmente (3 posições)
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaNavio1][colunaNavio1 + i] = 3; // Marcando posição do navio
    }

    // Navio 2 (vertical)
    int linhaNavio2 = 5, colunaNavio2 = 6; // Coordenadas iniciais
    // Posicionando o navio verticalmente (3 posições)
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaNavio2 + i][colunaNavio2] = 3; // Marcando posição do navio
    }

    // Exibir o tabuleiro com os navios usando printf
    printf("Tabuleiro do Jogo - Batalha Naval:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
