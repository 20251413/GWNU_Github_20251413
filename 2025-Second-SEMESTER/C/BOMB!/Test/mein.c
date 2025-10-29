#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

struct Fish
{
    char* name;
    char* talk;
    int answer;
    char* talk_O;
    char* talk_X;
};

void set_color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main()
{
    struct Fish fishes[5] = {
        {"블롭", "SPACEX의 로켓엔진인 Raptor가 사용하는 주 연료는?\n1) RP-1/LOX  2) LCH4/LOX  3) LH2/LOX  4) N2O4/UDMH\n> ", 2, "정답이다블룹!", "틀렸다블룹..."},
        {"앵귈", "KTX 청룡의 영업최고속도는?\n1) 300km/h  2) 310km/h  3) 320km/h  4) 352km/h\n> ", 3, "오ㅋㅋ 똑똑한궐?", "아닌앵"},
        {"니모", "양력(Lift)을 발생시키는 주된 원리와 가장 밀접한 것은?\n1) 뉴턴의 제 1법칙(관성의 법칙)  2) 아르키메데스의 원리  3) 파스칼의 원리  4) 베르누이의 원리\n> ", 4, "정답이니모!", "틀렸니모..."},
        {"가프", "인상주의(Impressionism) 화파의 대표적인 화가가 아닌 인물은?\n1) 파블로 피카소  2) 에드가 드가  3) 오귀스트 르누아르  4) 클로드 모네\n> ", 1, "정답입니가프", "오답이가프"},
        {"롱", "스타크래프트에서 아머리(Armory)에서 연구할수 있는 '테란 차량 장갑 (Terran Vehicle Plating) 1단계 업그레이드의 정확한 자원 비용은 얼마인가요 ?\n1) 100미네랄 / 100가스  2) 150미네랄 / 100가스  3) 150미네랄 / 100가스  4) 100미네랄 / 0가스\n> ", 1, "정답이지롱", "틀렸지롱"}
    };

    FILE* fp = fopen("log.txt", "a+");
    if (fp == NULL) {
        printf("파일 오류!\n");
        return 1;
    }

    rewind(fp);
    int total = 0, correct = 0;
    char line[128];

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (fgets(line, sizeof(line), fp) == NULL) break;
        if (line[0] == 'O') correct++;
        total++;
    }

    printf("%d번째 게임입니다!\n", total + 1);
    if (total > 0)
        printf("정답률 %d/%d\n\n", correct, total);
    else
        printf("정답률 0/0\n\n");

    printf("찌를 던진다 (Y/N) > ");
    char yn;
    while (1) {
        yn = _getch();
        if (yn == 'y' || yn == 'Y' || yn == 'n' || yn == 'N') {
            printf("%c\n", yn);
            break;
        }
    }
    if (yn == 'n' || yn == 'N') {
        printf("게임을 종료합니다.\n");
        fclose(fp);
        return 0;
    }

    for (int i = 0; i < 5; i++) {
        Sleep(500);
        printf(".");
        fflush(stdout);
    }
    printf("\n");

    set_color(10);
    printf("입질이 왔다!!!!\n\n");
    set_color(7);

    srand((unsigned int)time(NULL));
    int fish_index = rand() % 5;
    struct Fish f = fishes[fish_index];

    printf("%s : %s", f.name, f.talk);

    char ans = _getch();
    printf("%c\n", ans);
    int isCorrect = 0;
    if (ans - '0' == f.answer) {
        printf("%s\n", f.talk_O);
        isCorrect = 1;
    }
    else {
        printf("%s\n", f.talk_X);
    }

    fprintf(fp, "%s\n", f.name);
    fprintf(fp, "%s\n", isCorrect ? "O" : "X");
    fclose(fp);

    printf("\n(결과가 log.txt에 저장되었습니다)\n");

    return 0;
}