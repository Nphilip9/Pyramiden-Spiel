#include <stdio.h>
#include <windows.h>

char pyramid[5][14] = {
        {' ', ' ', ' ', ' ', ' ', '0'},
        {' ', ' ', ' ', ' ', '0', ' ', '0'},
        {' ', ' ', ' ', '0', ' ', '0', ' ', '0'},
        {' ', ' ', '0', ' ', '0', ' ', '0', ' ', '0'},
        {'0', ' ', '0', ' ', '0', ' ', '0', ' ', '0', ' ', '0'}
};

void game();
void drawPyramid();
void setConsoleColor(int);
void resetConsoleColor();

int main() {
    drawPyramid();
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
        int row, colStart, colCounter;

        drawPyramid();
        if (currentPlayer == 1) {
            setConsoleColor(FOREGROUND_RED);
            printf("%s ist an der Reihe\n", playerName1);
            resetConsoleColor();
        } else {
            setConsoleColor(FOREGROUND_GREEN);
            printf("%s ist an der Reihe\n", playerName2);
            resetConsoleColor();
        }

        printf("Welche Reihe wählst du? ");
        scanf("%d", &row);
        printf("\nBei welchen Strich möchtest du Starten und wie viele? ");
        scanf("%d %d", &colStart, &colCounter);
        

        currentPlayer = currentPlayer == 1 ? 2 : 1;
    }
}

void drawPyramid() {
    printf("\t");
    for (int k = 0; k < 5; k++) {
        printf("%d ", k);
    }
    printf("\n");
    for (int i = 0; i < 5; i++) {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < 14; j++) {
            if (pyramid[i][j] == '0') {
                printf("|");
            } else if (pyramid[i][j] == '1') {
                setConsoleColor(FOREGROUND_RED);
                printf("\\");
                resetConsoleColor();
            } else if (pyramid[i][j] == '2') {
                setConsoleColor(FOREGROUND_BLUE);
                printf("\\");
                resetConsoleColor();
            } else {
                printf("%c", pyramid[i][j]);
            }
        }
        printf("\n");
    }
}

void setConsoleColor(int colorCode) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorCode);
}

void resetConsoleColor() {
    setConsoleColor(RESETDEV);
}