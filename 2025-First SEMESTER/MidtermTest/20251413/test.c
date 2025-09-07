#include <stdio.h>
#include <conio.h>
#include <Windows.h>

void gotoxy(int x, int y)
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main()
{
    printf("                                            (\033[47mT\033[47mT\033[47mT\033[47mT\033[0m)                    T\n");
    printf("                                           (\033[47mT\033[47mT\033[47mT\033[0m)                      T\n");
    printf("                                          (\033[47mT\033[47mT\033[47mT\033[0m)                       T\n");
    printf("                                          (\033[47mT\033[47mT\033[0m(                        T\n");
    printf("                 _________________________|  |__                      T\n");
    printf("                /\\                              \\                     T\n");
    printf("               //_\\                              \\                    T\n");
    printf("TEST\n");
    printf("TEST\n");
    printf("TEST\n");
    printf("TEST\n");
    printf("TEST\n");
    printf("TEST\n");
    printf("TEST\n");
    printf("TEST\n");
    printf("TEST\n");

    return 0;
}