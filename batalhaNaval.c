#include <stdio.h>
int main() {
    
//TAMANHO DO TABULEIRO

int tabuleiro[10][10];

//INICIALIZAR TUDO COM - 0 

for (int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            tabuleiro [i][j] = 0;
        }
    }

//NAVIOS

int navio1[3] = {3,3,3};//NAVIO HORIZONTAL
int navio2[3] = {3,3,3};//NAVIO VERTICAL

//NAVIO HORIZONTAL
int linhah = 2, colunah =2;
for (int i = 0; i < 3; i++)
{
    if(colunah + i < 10)
    tabuleiro[linhah][colunah + i] = 3;
}
//NAVIO VERTICAL
int linhav = 5, colunav =7;
for (int i = 0; i < 3; i++)
{
    if(linhav + i < 10)
    tabuleiro[linhav + i][colunav] = 3;
}

//NAVIOS DIAGONAL
// -> ESQUERDA SUPERIOR PARA DIREITA INFERIOR
int linhaDiag1 = 0, colDiag1 = 0;
for (int i = 0; i < 3; i++)
{
    if(linhaDiag1 + i < 10 && colDiag1 + i < 10)
    tabuleiro[linhaDiag1 + i][colDiag1 + i] = 3;
}

//NAVIOS DIAGONAL
// -> DIREITA SUPERIOR PARA ESQUERDA INFERIOR
int linhaDiag2 = 0, colDiag2 = 9;
for (int i = 0; i < 3; i++)
{
    if(linhaDiag2 + i < 10 && colDiag2 - i >= 0)
    tabuleiro[linhaDiag2 + i][colDiag2 - i] = 3;
}

//EXIBIÇAO
printf("\n--- TABULEIRO BATALHA NAVAL ---\n");
for(int i = 0; i < 10; i++)
{
    for(int j = 0; j < 10; j++)
    {
        printf("%d ", tabuleiro[i] [j]);
    }
    printf("\n");
}

  

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
