#include <stdio.h>
int main() {
    // Tamanho fixo do tabuleiro e dos navios
    int tabuleiro[10][10];  // Matriz 10x10
    int i, j;

    // Inicializa todas as posições com 0 (água)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Coordenadas do navio horizontal (linha, coluna)
    int linhaHorizontal = 6;
    int colunaHorizontal = 2;

    // Coordenadas do navio vertical (linha, coluna)
    int linhaVertical = 0;
    int colunaVertical = 9;

    //Cordenadas do navio diagonal (linha, coluna)
    // Navio diagonal principal 
    int linhaDiagonal1 = 1;
    int colunaDiagonal1 = 1;

    // Navio diagonal secundária 
    int linhaDiagonal2 = 2;
    int colunaDiagonal2 = 7;

    
    int tamanhoNavio = 3;  // Cada navio tem 3 posições
    

   
        // Coloca navio horizontal
        for (i = 0; i < tamanhoNavio; i++) {
            tabuleiro[linhaHorizontal][colunaHorizontal + i] = 3;
        }

        // Coloca navio vertical
        for (i = 0; i < tamanhoNavio; i++) {
            tabuleiro[linhaVertical + i][colunaVertical] = 3;
        }

        // Coloca navio diagonal principal
        for (i = 0; i < tamanhoNavio; i++) {
            tabuleiro[linhaDiagonal1 + i][colunaDiagonal1 + i] = 3;
        }

        // Coloca navio diagonal secundária
        for (i = 0; i < tamanhoNavio; i++) {
            tabuleiro[linhaDiagonal2 + i][colunaDiagonal2 - i] = 3;
        }

        // Exibe o tabuleiro
        printf("Tabuleiro final:\n\n");
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 10; j++) {
                printf("%d ", tabuleiro[i][j]);
            }
            printf("\n");
        }
    

    return 0;
}
