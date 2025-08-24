#include <stdio.h>

#define T 10 //tamanho do tabuleiro
#define H 5 //tamanho das habilidades

//função para imprimir o tabuleiro
void imprimetabuleiro(int tabuleiro[T][T])
{
    for(int i = 0; i < T; i++)
    {
        for(int j = 0; j < T; j++)
        {
            if(tabuleiro[i][j] == 0){   //AGUA
                printf("0 ");
            }
            else if (tabuleiro[i][j] == 3){   //NAVIO
                printf("3 ");
            }
            else if(tabuleiro[i][j] == 5){   //HABILIDADE cone
                printf("5 ");
            } else if(tabuleiro[i][j] == 6){   //HABILIDADE cruz
                printf("6 ");
            }else if(tabuleiro[i][j] == 7){   //HABILIDADE octaedro 
                printf("7 ");    
            }    
        }
        printf("\n");
    }
     printf("\n");
}

//função para aplicar habilidae
void aplicarhabilidade(int tabuleiro[T][T], int habilidade[5][5], int origemlinha, int origemcoluna, int valor)
{
    int centro = 2; // centro matriz 5x5
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(habilidade[i][j] == 1) 
            {
                int linha = origemlinha + (i - centro);
                int coluna = origemcoluna + (j - centro);
                
                // verificação se esta no tabuleiro
                if(linha >= 0 && linha < T && coluna >= 0 && coluna < T)
                {
                    if(tabuleiro[linha][coluna] == 0) //so marca se for agua
                        tabuleiro[linha][coluna] = valor;
                }
            }
        }
    }
}



int main() {
    
// Criar tabuleiro vazio
int tabuleiro[T][T] = {0};

// Navios (valor 3)

tabuleiro[0][2] = 3;
tabuleiro[1][2] = 3;
tabuleiro[2][0] = 3;
tabuleiro[2][1] = 3;
tabuleiro[2][2] = 3;

printf("--- TABULEIRO INICIAL ---\n");
imprimetabuleiro(tabuleiro);


//Habilidades

//cone
int cone[5][5] = {0};
for(int i =0; i < 5; i++)
{
    for(int j = 2 - i; j <= 2 + i; j++)
    {
        if(j >= 0 && j < 5)
        cone[i][j] = 1;
    }
}

//cruz
int cruz[5][5] = {0};
for(int i = 0; i < 5; i++)
{
    cruz[2][i] = 1;
    cruz[i][2] = 1;
}

//octaedro
int octaedro[5][5] = {0};
for(int i = 0; i < 5; i++)
{
    for(int j = 0; j < 5; j++)
    {
        if( ((i == 2) && (j >= 0 && j <= 4)) ||  // linha central
            ((i == 1 || i == 3 ) && (j >= 1 && j <= 3)) || //linhas acima e abaixo
            ((i == 0 || i == 4) && (j == 2)) ) // linhas extremas
        {
            octaedro[i][j] = 1;
        }
    }
}
// aplicar habilidades no tabuleiro
aplicarhabilidade(tabuleiro, cone, 1, 2, 5);
aplicarhabilidade(tabuleiro, cruz, 4, 4, 6);
aplicarhabilidade(tabuleiro, octaedro, 7, 7, 7);

// resltado final
printf("--- TABULEIRO COM HABILIDADES ---\n");
imprimetabuleiro(tabuleiro);

return 0;
}
