#include <stdio.h>
#include <Windows.h>

int main() {

    char ch = 'a';

    while (ch <= 'z') {
        printf("»§ÀÌ %c°³ »ý¼ºµÊ\n", ch);
        Sleep(100);
        ch = ch + 1;
    }

    return 0;
}