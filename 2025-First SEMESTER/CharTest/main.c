#include <stdio.h>
#include <Windows.h>

int main() {

    char ch = 'a';

    while (ch <= 'z') {
        printf("���� %c�� ������\n", ch);
        Sleep(100);
        ch = ch + 1;
    }

    return 0;
}