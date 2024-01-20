#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_WHITE "\e[0;37m"

int Tabuleiro2[9][9], Flag = 1, Flag2 = 1, InicioColuna = 0, InicioLinha = 0,
                      FimColuna = 2, Flag3 = 1, Flag4, Num = 1, ContaBloco,
                      Flag5 = 1, i = 0, j = -1;

int Tabuleiro[9][9] = 
  {{ 0, 6, 0, 1, 0, 4, 0, 5, 0},
   { 0, 0, 8, 3, 0, 5, 6, 0, 0},
   { 2, 0, 0, 0, 0, 0, 0, 0, 1},
   { 8, 0, 0, 4, 0, 7, 0, 0, 6},
   { 0, 0, 6, 0, 0, 0, 3, 0, 0},
   { 7, 0, 0, 9, 0, 1, 0, 0, 4},
   { 5, 0, 0, 0, 0, 0, 0, 0, 2},
   { 0, 0, 7, 2, 0, 6, 9, 0, 0},
   { 0, 4, 0, 5, 0, 8, 0, 7, 0}};

void ChamaValor() {
  if (j == 8) {
    i = i + 1;
    j = 0;
  } else {
    j = j + 1;
  }
  if (i == 9) {
    Flag5 = 0;
  }
}

void VerificaBloco() {
  if (i < 3) {
    InicioLinha = 0;
  } else if ((i < 6) && (i >= 3)) {
    InicioLinha = 3;
  } else if ((i < 9) && (i >= 6)) {
    InicioLinha = 6;
  }
  if (j < 3) {
    InicioColuna = 0;
  } else if ((j < 6) && (j >= 3)) {
    InicioColuna = 3;
  } else if ((j < 9) && (j >= 6)) {
    InicioColuna = 6;
  }
}

void Voltar() {
  do {
    if ((j == 0) && (i != 0)) {
      i = i - 1;
      j = 8;
    } else {
      j = j - 1;
    }
  } while (Tabuleiro2[i][j] != 0);
  Num = Tabuleiro[i][j] + 1;
}
void Sudoku() {
  for (int m = 0; m <= 8; m++) {
    for (int n = 0; n <= 8; n++) {
      if (Tabuleiro2[m][n] != 0) {
        printf(ANSI_COLOR_RED "%d  ", Tabuleiro[m][n]);
      } else {
        printf(ANSI_COLOR_WHITE "%d  ", Tabuleiro[m][n]);
      }
      if ((n+1) % 3 == 0){
        printf("  ");
      }
    }
    if ((m+1) % 3 == 0){
      printf("\n");
    }
    printf("\n");
  }
}
int Verifica() {
  for (int m = i; m <= i; m++) {
    for (int n = 0; n <= 8; n++) {
      if ((m != i) || (n != j)) {
        if (Tabuleiro[m][n] == Num) {
          return 0;
        }
      }
    }
  }
  for (int n = j; n <= j; n++) {
    for (int m = 0; m <= 8; m++) {
      if ((m != i) || (n != j)) {
        if (Tabuleiro[m][n] == Num) {
          return 0;
        }
      }
    }
  }
  for (int m = InicioLinha; m <= (InicioLinha + 2); m++) {
    for (int n = InicioColuna; n <= (InicioColuna + 2); n++) {
      if ((m != i) || (n != j)) {
        if (Tabuleiro[m][n] == Num) {
          return 0;
        }
      }
    }
  }
  return 1;
}
int main(void) {
  memcpy(Tabuleiro2, Tabuleiro, sizeof(int) * 9 * 9);
  while (Flag5) {
    ChamaValor();
    if (Tabuleiro[i][j] == 0) {
      Flag = 1;
      while ((Flag) && (Num <= 9)) {
        VerificaBloco();
        Flag2 = Verifica();
        if (Flag2) {
          Tabuleiro[i][j] = Num;
          Flag = 0;
          Num = 0;
          system("clear");
          Sudoku();
        }
        Num++;
      }
      if ((Flag) && (Num = 10)) {
        Voltar();
        while (Num > 9) {
          Tabuleiro[i][j] = 0;
          Voltar();
        }
        Tabuleiro[i][j] = 0;
        j = j - 1;
      }
    }
  }
}