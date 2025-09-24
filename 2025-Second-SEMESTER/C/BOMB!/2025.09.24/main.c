#include <stdio.h>

int main() {
	char a[6];

	a[0] = 'F';
	a[1] = 'U';
	a[2] = 'X';
	a[3] = 'K';
	a[4] = 'E';
	a[5] = 'D';

	int i = 0;
	for (i = 0; i < 6; i++) {
		printf("%c", a[i]);
	}
	return 0;
}