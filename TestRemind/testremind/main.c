#include <stdio.h>
#include <conio.h>
#include <string.h>

// �־��� �Լ���
void gotoXY(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

void setTextColor(int color) {
    printf("\033[%dm", color);
}

void resetTextColor() {
    printf("\033[0m");
}

void startUnderline() {
    printf("\033[4m");
}

void endUnderline() {
    printf("\033[24m");
}

int main() {
    const char* target = "Love!!";
    char input[100] = { 0 };
    int i = 0;
    int len = strlen(target);

    // 1. ���� ���� ���
    gotoXY(1, 1);
    setTextColor(37); // ���
    printf("%s", target);
    resetTextColor();

    // 2. ����� �Է�
    while (1) {
        char ch = getch();

        if (ch == 13) break;  // Enter = ����
        if (i >= len) continue; // �ʰ� �Է� ����

        input[i] = ch;

        // 3. Ŀ�� �̵�: 2��° ��, �ش� ��ġ
        gotoXY(i + 1, 2);

        if (ch == target[i]) {
            setTextColor(37); // ���
            printf("%c", ch);
        }
        else {
            setTextColor(31); // ������
            startUnderline();
            printf("%c", ch);
            endUnderline();
        }

        resetTextColor();
        i++;
    }

    // 4. ��� ���
    int correct = 0;
    for (int j = 0; j < len; j++) {
        if (input[j] == target[j]) correct++;
    }

    gotoXY(1, 4);
    setTextColor(33); // �����
    printf("�Է� ����! ���� ���� ��: %d, Ʋ�� ���� ��: %d\n", correct, len - correct);
    resetTextColor();

    return 0;
}

