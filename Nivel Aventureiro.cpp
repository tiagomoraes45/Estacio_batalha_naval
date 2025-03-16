#include <stdio.h>

#define N 10 // Tamanho do tabuleiro
#define NAVIO_SIZE 3 // Tamanho dos navios

// Função para validar e posicionar o navio
int validar_e_posicionar_navio(int tabuleiro[N][N], int linha, int coluna, int orientacao) {
    for (int i = 0; i < NAVIO_SIZE; i++) {
        int x = linha, y = coluna;
        if (orientacao == 0) y += i; // Horizontal
        if (orientacao == 1) x += i; // Vertical
        if (orientacao == 2) { x += i; y += i; } // Diagonal crescente
        if (orientacao == 3) { x += i; y -= i; } // Diagonal decrescente
        
        // Verifica se a posição é válida
        if (x >= N || y >= N || tabuleiro[x][y] != 0) return 0;
        
        // Marca a posição do navio
        tabuleiro[x][y] = 3;
    }
    return 1; // Navio posicionado corretamente
}

// Função para exibir o tabuleiro
int exibir_tabuleiro(int tabuleiro[N][N]) {
    printf("Tabuleiro do Jogo - Batalha Naval:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    return 1;
}

int main() {
    int tabuleiro[N][N] = {0}; // Inicializa o tabuleiro com 0 (água)

    // Coordenadas e orientações dos navios (linha, coluna, orientacao)
    int navios[4][3] = {
        {2, 3, 0}, // Navio 1 (Horizontal)
        {5, 5, 1}, // Navio 2 (Vertical)
        {0, 0, 2}, // Navio 3 (Diagonal crescente)
        {7, 9, 3}  // Navio 4 (Diagonal decrescente)
    };

    // Posiciona os navios no tabuleiro
    for (int i = 0; i < 4; i++) {
        int linha = navios[i][0], coluna = navios[i][1], orientacao = navios[i][2];
        if (!validar_e_posicionar_navio(tabuleiro, linha, coluna, orientacao)) {
            printf("Posição inválida para o navio %d.\n", i + 1);
        }
    }

    // Exibe o tabuleiro
    exibir_tabuleiro(tabuleiro);

    return 0;
}
