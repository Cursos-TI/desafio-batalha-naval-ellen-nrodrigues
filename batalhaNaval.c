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

    int tamanhoNavio = 3;  // Cada navio tem 3 posições
    int podeColocar = 1;   // Flag para verificar se é possível posicionar

    // Verifica se o navio horizontal cabe no tabuleiro
    if (colunaHorizontal + tamanhoNavio > 10) {
        printf("Erro: navio horizontal fora do tabuleiro.\n");
        podeColocar = 0;
    }

    // Verifica se o navio vertical cabe no tabuleiro
    if (linhaVertical + tamanhoNavio > 10) {
        printf("Erro: navio vertical fora do tabuleiro.\n");
        podeColocar = 0;
    }

    // Verifica se as posições do navio vertical estão livres (para evitar sobreposição)
    if (podeColocar) {
        for (i = 0; i < tamanhoNavio; i++) {
            int linha = linhaVertical + i;
            int coluna = colunaVertical;
            if (tabuleiro[linha][coluna] == 3) {
                printf("Erro: sobreposição de navios.\n");
                podeColocar = 0;
                break;
            }
        }
    }

    // Posiciona os navios se tudo estiver certo
    if (podeColocar) {
        // Coloca navio horizontal
        for (i = 0; i < tamanhoNavio; i++) {
            tabuleiro[linhaHorizontal][colunaHorizontal + i] = 3;
        }

        // Coloca navio vertical
        for (i = 0; i < tamanhoNavio; i++) {
            tabuleiro[linhaVertical + i][colunaVertical] = 3;
        }

        // Exibe o tabuleiro
        printf("Tabuleiro final:\n\n");
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 10; j++) {
                printf("%d ", tabuleiro[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
