#include <stdio.h>
#include <Windows.h>

int main() {

	int i = 1;

	while (i < 11) {
		printf("���� %d�� ������\n", i);
		Sleep(100);
		i = i + 1;
	}

	return 0;
}