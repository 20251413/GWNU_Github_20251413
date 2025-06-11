#include <stdio.h>
#include <conio.h>
#include <time.h>

int main() {
    int count = 0;
    time_t start;
    
    printf("10초 동안 아무 키나 눌러보세요!\n");

    start = time(NULL);

    while (time(NULL) - start < 10) {
        if (_kbhit()) {
            char ch = getch();  // getch() 반환값을 변수에 저장
            count++;
        }
    }
    printf("\n시간 종료!\n");
    printf("총 눌린 횟수: %d\n", count);

    return 0;
}
