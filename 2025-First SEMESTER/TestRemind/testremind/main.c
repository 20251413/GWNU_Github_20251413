#include <stdio.h>
#include <conio.h>
#include <string.h>

// 주어진 함수들
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

    // 1. 예시 문장 출력
    gotoXY(1, 1);
    setTextColor(37); // 흰색
    printf("%s", target);
    resetTextColor();

    // 2. 사용자 입력
    while (1) {
        char ch = getch();

        if (ch == 13) break;  // Enter = 종료
        if (i >= len) continue; // 초과 입력 방지

        input[i] = ch;

        // 3. 커서 이동: 2번째 줄, 해당 위치
        gotoXY(i + 1, 2);

        if (ch == target[i]) {
            setTextColor(37); // 흰색
            printf("%c", ch);
        }
        else {
            setTextColor(31); // 빨간색
            startUnderline();
            printf("%c", ch);
            endUnderline();
        }

        resetTextColor();
        i++;
    }

    // 4. 결과 출력
    int correct = 0;
    for (int j = 0; j < len; j++) {
        if (input[j] == target[j]) correct++;
    }

    gotoXY(1, 4);
    setTextColor(33); // 노란색
    printf("입력 종료! 맞은 글자 수: %d, 틀린 글자 수: %d\n", correct, len - correct);
    resetTextColor();

    return 0;
}

