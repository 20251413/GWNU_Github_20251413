#include <stdio.h>
#include <Windows.h>
#include <time.h>

int main() {
	clock_t start, end;
	double cpu_time_used;
	
	start = clock();

	int i = 1;

	while (i < 11) {
		printf("���� %d�� ������\n", i);
		Sleep(100);
		i = i + 1;
	}
	end = clock();
	
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

	printf("\n 10�� ���꿡 �� %.3f�� �ɷȽ��ϴ�.\n", cpu_time_used);

	return 0;
}