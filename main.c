#include <stdio.h>
#include <windows.h>

char pyramid[5][14] = {
        {' ', ' ', ' ', ' ', ' ', '|'},
        {' ', ' ', ' ', ' ', '|', ' ', '|'},
        {' ', ' ', ' ', '|', ' ', '|', ' ', '|'},
        {' ', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
        {'|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'}
};

void game();
void drawPyramid();
void setConsoleColor(int);
void resetConsoleColor();

int main() {
    game();
    return 0;
}

void game() {
    int gameMode, currentPlayer = 1;
    char playerName1[20] = {'\0'}, playerName2[20] = {'\0'};

    printf("Spielmodi:\n");
    printf("1. Spiel gegen Freund\n");
    printf("2. Spiel gegen Computer\n");
    scanf("%d", &gameMode);

    if (gameMode == 1) {
        printf("Name des ersten Spielers: ");
        scanf("%s", playerName1);
        printf("Name des zweiten Spielers: ");
        scanf("%s", playerName2);
    } else if (gameMode == 1) {
        printf("Gib deinen Benutzernamen ein: ");
        scanf("%s", playerName1);
    } else {
        printf("Dieser Spielmodi existiert nicht\n");
    }

    printf("Spiel beginnt!\n");

    while (1) {
        if (currentPlayer == 1) {
            setConsoleColor(FOREGROUND_RED);
            printf("%s ist an der Reihe", playerName1);
            resetConsoleColor();
        } else {
            setConsoleColor(FOREGROUND_GREEN);
            printf("%s ist an der Reihe", playerName2);
            resetConsoleColor();
        }

        currentPlayer = currentPlayer == 1 ? 2 : 1;
    }
}

void drawPyramid() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 14; j++) {
            printf("%c", pyramid[i][j]);
        }
        printf("\n");
    }
}

void setConsoleColor(int colorCode) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorCode);
}

void resetConsoleColor() {
    setConsoleColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
}