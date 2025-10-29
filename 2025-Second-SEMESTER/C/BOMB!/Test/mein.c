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
        {"���", "SPACEX�� ���Ͽ����� Raptor�� ����ϴ� �� �����?\n1) RP-1/LOX  2) LCH4/LOX  3) LH2/LOX  4) N2O4/UDMH\n> ", 2, "�����̴ٺ��!", "Ʋ�ȴٺ��..."},
        {"�ޱ�", "KTX û���� �����ְ�ӵ���?\n1) 300km/h  2) 310km/h  3) 320km/h  4) 352km/h\n> ", 3, "������ �ȶ��ѱ�?", "�ƴѾ�"},
        {"�ϸ�", "���(Lift)�� �߻���Ű�� �ֵ� ������ ���� ������ ����?\n1) ������ �� 1��Ģ(������ ��Ģ)  2) �Ƹ�Ű�޵����� ����  3) �Ľ�Į�� ����  4) ���������� ����\n> ", 4, "�����̴ϸ�!", "Ʋ�ȴϸ�..."},
        {"����", "�λ�����(Impressionism) ȭ���� ��ǥ���� ȭ���� �ƴ� �ι���?\n1) �ĺ�� ��ī��  2) ���尡 �尡  3) ���ͽ�Ʈ �����Ƹ�  4) Ŭ�ε� ���\n> ", 1, "�����Դϰ���", "�����̰���"},
        {"��", "��Ÿũ����Ʈ���� �ƸӸ�(Armory)���� �����Ҽ� �ִ� '�׶� ���� �尩 (Terran Vehicle Plating) 1�ܰ� ���׷��̵��� ��Ȯ�� �ڿ� ����� ���ΰ��� ?\n1) 100�̳׶� / 100����  2) 150�̳׶� / 100����  3) 150�̳׶� / 100����  4) 100�̳׶� / 0����\n> ", 1, "����������", "Ʋ������"}
    };

    FILE* fp = fopen("log.txt", "a+");
    if (fp == NULL) {
        printf("���� ����!\n");
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

    printf("%d��° �����Դϴ�!\n", total + 1);
    if (total > 0)
        printf("����� %d/%d\n\n", correct, total);
    else
        printf("����� 0/0\n\n");

    printf("� ������ (Y/N) > ");
    char yn;
    while (1) {
        yn = _getch();
        if (yn == 'y' || yn == 'Y' || yn == 'n' || yn == 'N') {
            printf("%c\n", yn);
            break;
        }
    }
    if (yn == 'n' || yn == 'N') {
        printf("������ �����մϴ�.\n");
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
    printf("������ �Դ�!!!!\n\n");
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

    printf("\n(����� log.txt�� ����Ǿ����ϴ�)\n");

    return 0;
}