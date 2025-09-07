#include <stdio.h>
#include <conio.h>    // _kbhit, _getch
#include <windows.h>  // Sleep
#include <time.h>     // clock

int main() {
    char letters[5] = { 'a', 'b', 'c', 'd', 'e' }; // 5���� ���� ���ĺ�
    int correct = 0, wrong = 0;

    for (int i = 0; i < 5; i++) {
        printf("���� ����: %c\n", letters[i]);  // 1��° ��

        clock_t start = clock();
        char input = '\0';

        while ((clock() - start) < CLOCKS_PER_SEC) {
            if (_kbhit()) {
                input = _getch();
                printf("%c\n", input);  // 2��° ��

                if (input == letters[i]) {
                    printf("\033[32m�Ϻ�!!!\033[0m\n");  // �ʷ�
                    correct++;
                }
                else {
                    printf("\033[31m����!!!\033[0m\n");  // ����
                    wrong++;
                }
                break;
            }
        }

        if (input == '\0') {
            printf("\n\033[31m����!!!\033[0m\n");  // �ð� �ʰ� �� ���� ó��
            wrong++;
        }

        printf("\n");  // 4��° �� - ����
        Sleep(1000);   // 1�� ���
    }

    // ��� ���
    printf("\033[33m=== ��� ===\033[0m\n");
    printf("\033[33m���� ��: %d\033[0m\n", correct);
    printf("\033[33m���� ��: %d\033[0m\n", wrong);

    return 0;
}