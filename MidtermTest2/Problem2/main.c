#include <stdio.h>

int SS(int mp, int range) {

    if (mp >= 50 && range > 10) {
        printf("주인공 : 너는 점수를 획득했나?\n");
    }
    return 0;
}

int main() {
    int mp = 150;
    int range = 20;

    SS(mp, range);

    return 0;
}