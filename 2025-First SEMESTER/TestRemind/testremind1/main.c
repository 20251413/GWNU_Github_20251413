#include <stdio.h>
#include <conio.h>
#include <time.h>

int main() {
    int count = 0;
    time_t start;
    
    printf("10�� ���� �ƹ� Ű�� ����������!\n");

    start = time(NULL);

    while (time(NULL) - start < 10) {
        if (_kbhit()) {
            char ch = getch();  // getch() ��ȯ���� ������ ����
            count++;
        }
    }
    printf("\n�ð� ����!\n");
    printf("�� ���� Ƚ��: %d\n", count);

    return 0;
}
