#include <stdio.h>
#include <conio.h>

void gotoxy(int x, int y)
}
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}