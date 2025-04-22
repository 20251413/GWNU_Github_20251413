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

    return 0;
}