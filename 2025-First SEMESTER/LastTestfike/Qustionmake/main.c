#include <stdio.h>
#include <conio.h>    // _kbhit, _getch
#include <windows.h>  // Sleep
#include <time.h>     // clock

int main() {
    char letters[5] = { 'a', 'b', 'c', 'd', 'e' }; // 5개의 고정 알파벳
    int correct = 0, wrong = 0;

    for (int i = 0; i < 5; i++) {
        printf("문자 등장: %c\n", letters[i]);  // 1번째 줄

        clock_t start = clock();
        char input = '\0';

        while ((clock() - start) < CLOCKS_PER_SEC) {
            if (_kbhit()) {
                input = _getch();
                printf("%c\n", input);  // 2번째 줄

                if (input == letters[i]) {
                    printf("\033[32m완벽!!!\033[0m\n");  // 초록
                    correct++;
                }
                else {
                    printf("\033[31m에러!!!\033[0m\n");  // 빨강
                    wrong++;
                }
                break;
            }
        }

        if (input == '\0') {
            printf("\n\033[31m에러!!!\033[0m\n");  // 시간 초과 시 에러 처리
            wrong++;
        }

        printf("\n");  // 4번째 줄 - 공백
        Sleep(1000);   // 1초 대기
    }

    // 결과 출력
    printf("\033[33m=== 결과 ===\033[0m\n");
    printf("\033[33m정답 수: %d\033[0m\n", correct);
    printf("\033[33m오답 수: %d\033[0m\n", wrong);

    return 0;
}