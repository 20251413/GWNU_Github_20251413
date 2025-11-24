#include <stdio.h>
#include "jsw_20251417.h"

int jsw(int hp, char* name)
{
    if (hp <= 30) {
        printf("[%s] 체력이 낮음! 힐을 시도합니다! (현재 HP=%d)\n", name, hp);
        return Heal(hp, name);
    }
    else if (hp <= 70) {
        printf("[%s] 체력이 중간! 방어를 시도합니다! (현재 HP=%d)\n", name, hp);
        return Wait(hp, name);
    }
    else {  // 체력이 70 이상일 때는 방어
        printf("[%s] 체력이 높음! 방어를 시도합니다! (현재 HP=%d)\n", name, hp);
        return Wait(hp, name);
    }
}

//학생의 Action의 return 값은 
//return Wait(hp, name);
//return Heal(hp, name);
//둘중 하나여야함

/*int SW_20251417(int hp, char* name)
{
    int r = rand() % 2;
    if (r == 0) {
        return Wait(hp, name);
    }
    else {
        return Heal(hp, name);

    }*/