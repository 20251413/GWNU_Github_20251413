#include <stdio.h>

void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

int main() {
    
    gotoxy(0, 0);
    printf("");

    gotoxy(10, 0);
    printf("o     o\n");

    gotoxy(10, 2);
    printf("|     |\n");

    gotoxy(4, 3);
    printf("-------------------\n");

    gotoxy(4, 4);
    printf("|\\/\\/\\/\\/\\/\\/\\/\\/\\|\n");

    gotoxy(4, 5);
    printf("|                 |\n");

    gotoxy(4, 6);
    printf("-------------------\n");

    gotoxy(0, 7);
    printf("-------------------------\n");

    gotoxy(0, 8);
    printf("|\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\|\n");

    gotoxy(0, 9);
    printf("|                       |\n");

    gotoxy(0, 10);
    printf("-------------------------\n");

    return 0;
}