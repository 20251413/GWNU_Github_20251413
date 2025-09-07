#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>

int main() {
	printf("10초 동안 아무 키나 눌러보세요!\n");
	time_t start = time(10000);

	while (time(10000) - start < 10) {
		if (_kbhit()) {
			
		}
		break;
	}

	time_t end;

	Sleep(100);

	printf("시간 종료!\n");
	printf("총 눌린 횟수: %d");

	return 0;
}