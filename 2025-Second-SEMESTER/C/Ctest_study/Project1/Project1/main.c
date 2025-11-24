#include <stdlib.h>  // rand, srand
#include <time.h>    // time (난수 시드 설정)
#include <Windows.h>
#include "action.h"
#include "yunjun_1101.h"
#include "js_20251409.h"
#include "lhs_20221925.h"
#include "jsw_20251417.h"

typedef int (*ActionFunc)(int hp, char* name);

typedef struct {
    int isDead;
    char* name;
    int hp;
    ActionFunc act;   // 행동을 가리키는 함수포인터
} Player;

int main()
{
    Player p[4];

    int i = 0;
    for (i = 0; i < 4; i++)
    {
        p[i].isDead = 0;

        p[i].hp = 100;


    }
    //함수 각각 플레이어에 연결하는 부분
    p[3].name = "yunjun";
    p[3].act = yunjun;
    p[1].name = "js";
    p[1].act = js;
    p[2].name = "lhs";
    p[2].act = lhs;
    p[0].name = "jsw";
    p[0].act = jsw;


    while (1)
    {
        for (i = 0; i < 4; i++)
        {
            if (p[i].hp > 0 && !p[i].isDead)
            {
                int point = p[i].act(p[i].hp, p[i].name);
                p[i].hp += point;
                //Sleep(1000);
            }

            if (!p[i].isDead && p[i].hp <= 0)
            {
                printf("\n*************\n쥬금 : %s\n**************\n\n", p[i].name);
                p[i].isDead = 1;
                //Sleep(1000);
            }

        }
        Sleep(100);

        int count = 0;

        for (i = 0; i < 4; i++)
        {
            if (p[i].isDead)
                count++;
        }

        //4명 다 죽으면
        if (count == 4)
            break;

    }

    return 0;
}