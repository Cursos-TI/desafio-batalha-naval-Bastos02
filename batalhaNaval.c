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
    if(colunah + i < 10 && tabuleiro[linhah][colunah + i] == 0)
    tabuleiro[linhah][colunah + i] = 3;
}
//NAVIO VERTICAL
int linhav = 5, colunav =7;
for (int i = 0; i < 3; i++)
{
    if(linhav + i < 10 && tabuleiro[linhav + i][colunav] == 0)
    tabuleiro[linhav + i][colunav] = 3;
}

//NAVIOS DIAGONAL 1
// -> ESQUERDA SUPERIOR PARA DIREITA INFERIOR
int linhaDiag1 = 0, colDiag1 = 0;
for (int i = 0; i < 3; i++)
{
    if(linhaDiag1 + i < 10 && colDiag1 + i < 10 && tabuleiro[linhaDiag1 + i][colDiag1 + i] == 0)
    tabuleiro[linhaDiag1 + i][colDiag1 + i] = 3;
}

//NAVIOS DIAGONAL 2 
// -> DIREITA SUPERIOR PARA ESQUERDA INFERIOR
int linhaDiag2 = 0, colDiag2 = 9;
for (int i = 0; i < 3; i++)
{
    if(linhaDiag2 + i < 10 && colDiag2 - i >= 0 && tabuleiro[linhaDiag2 + i][colDiag2 - i] == 0)
    {
         tabuleiro[linhaDiag2 + i][colDiag2 - i] = 3;
    }
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

  
    return 0;
}
