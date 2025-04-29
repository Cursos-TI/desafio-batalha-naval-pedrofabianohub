#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
int meio = TAM_HABILIDADE / 2;

void imprimirTabuleiro() {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void inicializarTabuleiro() {
    for (int i = 0; i < TAM_TABULEIRO; i++)
        for (int j = 0; j < TAM_TABULEIRO; j++)
            tabuleiro[i][j] = 0;

    tabuleiro[2][2] = 3;
    tabuleiro[4][4] = 3;
    tabuleiro[6][6] = 3;
}

void gerarCone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (j >= meio - i && j <= meio + i && i <= meio)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

void gerarCruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

void gerarOctaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if ( i - meio + j - meio <= meio)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

void aplicarHabilidade(int matriz[TAM_HABILIDADE][TAM_HABILIDADE], int origemLinha, int origemColuna) {
    int offset = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (matriz[i][j] == 1) {
                int linha = origemLinha - offset + i;
                int coluna = origemColuna - offset + j;
                if (linha >= 0 && linha < TAM_TABULEIRO && coluna >= 0 && coluna < TAM_TABULEIRO) {
                    if (tabuleiro[linha][coluna] != 3)
                        tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }
}

int main() {
    inicializarTabuleiro();

    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    gerarCone(cone);
    aplicarHabilidade(cone, 2, 2);
    printf("\n");


    gerarCruz(cruz);
    aplicarHabilidade(cruz, 5, 5);
    printf("\n");


    gerarOctaedro(octaedro);
    aplicarHabilidade(octaedro, 7, 7);
    printf("\n");

    imprimirTabuleiro();

    return 0;
}
