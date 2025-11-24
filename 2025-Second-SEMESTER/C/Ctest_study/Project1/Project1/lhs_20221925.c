#include <stdio.h>
#include "lhs_20221925.h"  // 헤더 파일 포함
#include "action.h"  // 공통 함수 포함


int lhs(int hp, char* name)
{

    if (hp <= 40) {
        printf(">>> [경고] %s 시야가 흐려집니다... 긴급 치료 필요! (HP=%d) <<<\n", name, hp);
        return Heal(hp, name);
    }

    else if (hp <= 60) {
        printf("[%s] 상처가 깊지만 아직 싸울 수 있습니다! 방어에 집중합니다. (HP=%d)\n", name, hp);
        return Wait(hp, name);
    }

    else {
        printf("[%s] 컨디션 최상! 전황을 살핍니다. (HP=%d)\n", name, hp);
        return Wait(hp, name);
    }
}
