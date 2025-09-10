#include <stdio.h>

int main() {
    int Sero = 0;
    while (Sero < 5) {
        int Garo = 0;
        while (Garo < 6) {
            if (Sero == 0 || Sero == 4 || Garo == 0 || Garo == 5) {
                printf("\x1B[%d;%dH#", Sero + 1, Garo + 1);
            }
            Garo = Garo + 1;
        }
        Sero = Sero + 1;
    }
    printf("\x1B[7;1H");
    return 0;
}