#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>

int main() {
	printf("10�� ���� �ƹ� Ű�� ����������!\n");
	time_t start = time(10000);

	while (time(10000) - start < 10) {
		if (_kbhit()) {
			
		}
		break;
	}

	time_t end;

	Sleep(100);

	printf("�ð� ����!\n");
	printf("�� ���� Ƚ��: %d");

	return 0;
}