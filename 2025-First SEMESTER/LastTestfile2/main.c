#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

void gotoXY(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

int main() {
    printf("LOVE!!\n");
    return 0;
}