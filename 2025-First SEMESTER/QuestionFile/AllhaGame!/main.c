#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

// 20251413 이종석

void showIntro();

void showIntro() {
    system("cls");
    Sleep(500);
    printf("\033[31m\033[41m\033[1m=====================================================================================\033[0m\n");
    printf("\033[41m\033[1m _____    _    _   ___   _   _  _____    _____  _____    _   _  _____ ___  ___ _____ \n");
    printf("|_   _|  | |  | | / _ \\ | \\ | ||_   _|  |  __ \\|  _  |  | | | ||  _  ||  \\/  ||  ___|\n");
    printf("  | |    | |  | |/ /_\\ \\|  \\| |  | |    | |  \\/| | | |  | |_| || | | || .  . || |__  \n");
    printf("  | |    | |/\\| ||  _  || . ` |  | |    | | __ | | | |  |  _  || | | || |\\/| ||  __| \n");
    printf(" _| |_   \\  /\\  /| | | || |\\  |  | |    | |_\\ \\\\ \\_/ /  | | | |\\ \\_/ /| |  | || |___ \n");
    printf(" \\___/    \\/  \\/ \\_| |_/\\_| \\_/  \\_/     \\____/ \\___/   \\_| |_/ \\___/ \\_|  |_/\\____/ \033[0m\n");
    printf("\033[31m\033[41m\033[1m=====================================================================================\033[0m\n\n");
    Sleep(2000);

    printf("\033[1m[아 몰라 집에 가고싶다.]\033[0m\n");
    printf("1. 집으로 가자!\n");
    printf("2. 에이씨 몰라 포기\n");
    printf("입력하세요: ");

    char choice = getchar(); getchar(); // Enter 처리

    //-------------------------------------------------------------------- 1차 선택 --------------------------------------------------------------------
    if (choice == '1') {
        system("cls");
        printf("수업을 듣고 있지만 집에 가고싶다.\n\n");
        Sleep(2000);
        printf("대충 25분 정도 남았는데.\n\n");
        Sleep(1500);
        printf("나는 정말로 집에 가고싶다.\n\n");
        Sleep(2000);
        printf("젠장 수업 하나도 못알아먹겠네!\n\n");
        Sleep(1500);
        printf("\033[1m[어떻게 눈치를 좀 봐?]\033[0m\n");
        printf("1. 튀자!\n");
        printf("2. 에매한데...\n");
        printf("입력하세요 : ");

        char innerChoice = getchar(); getchar(); // Enter 처리

        if (innerChoice == '1') {
            system("cls");
            printf("25분이나 더 기다릴 생각은 없다!\n\n");
            Sleep(1000);
            printf("금요일을 이렇게 낭비할수는 없지!\n\n");
            Sleep(1000);
            printf("바로 탈주 달립니다.\n\n");
            Sleep(3000);
            printf(".\n");
            Sleep(1000);
            printf(".\n");
            Sleep(1000);
            printf(".\n\n");
            Sleep(2000);
            printf("아 무조건 나갈거임ㅋㅋ\n");
            Sleep(2000);
            system("cls");
            printf("\033[1m=====[25분 후]=====\033[0m\n\n");
            Sleep(1500);
            printf("교수 : 강의 듣느라 고생했어요.\n\n");
            Sleep(2000);
            printf("\033[31m\033[1m아 젠장.\033[0m\n");
            Sleep(2000);
            system("cls");
            printf("----------------------\n");
            printf(" _____  _   _ ______ \n");
            printf("|  ___|| \\ | ||  _  \\\n");
            printf("| |__  |  \\| || | | |\n");
            printf("|  __| | . ` || | | |\n");
            printf("| |___ | |\\  || |/ / \n");
            printf("\\____/ \\_| \\_/|___/  \n");
            printf("----------------------\n\n");
            printf("\033[1m망상 엔딩\033[0m\n");
            printf("[그러게 좀 할거면 빨리 하던가.]");
            printf("");
            Sleep(5000);
            system("cls");
            exit(0);
        }
        else if (innerChoice == '2') {
            system("cls");
            printf("으..... 졸려어...........\n\n");
            Sleep(2000);
            printf("아 근데 진짜 이건 아닌거 같음 ㅇㅇ\n\n");
            Sleep(1000);
            printf("난 도망을 가야겠어!\n\n");
            Sleep(1000);
            printf("\033[1m[어떻게 나가볼까?]\033[0m\n");
            printf("1. 아 근데 타이밍이 좀...\n");
            printf("2. 전화를 받는 척 나간다.\n");
            printf("3. 당당하게 나간다!\n");
            printf("입력하세요 : ");

            char secondChoice = getchar(); getchar(); // Enter 처리=
            //-------------------------------------------------------------------- 2차 선택 --------------------------------------------------------------------
            if (secondChoice == '1') {
                system("cls");
                printf("그래, 자리 위치도 그렇고 나가기가 조금 에매해.\n\n");
                Sleep(2000);
                system("cls");
                printf("아씨 나가고 싶은데 언제 나가냐...\n\n");
                Sleep(2000);
                system("cls");
                printf("이거 이러다가 수업 그냥 다 듣겠는데?\n\n");
                Sleep(3000);
                printf("뭐 25분 그냥 마저 듣지 뭐.\n\n");
                Sleep(2000);
                system("cls");
                printf("----------------------\n");
                printf(" _____  _   _ ______ \n");
                printf("|  ___|| \\ | ||  _  \\\n");
                printf("| |__  |  \\| || | | |\n");
                printf("|  __| | . ` || | | |\n");
                printf("| |___ | |\\  || |/ / \n");
                printf("\\____/ \\_| \\_/|___/  \n");
                printf("----------------------\n\n");
                printf("\033[1m해피? 엔딩\033[0m\n");
                printf("[빠지면 강의를 놓치니 들은게 더 좋은 엔딩 아닐까요?]");
                printf("");
                Sleep(5000);
                system("cls");
                exit(0);
            }
            else if (secondChoice == '2') {
                system("cls");
                printf("후우! 아무 문제도 없이 나왔다!\n\n");
                Sleep(1000);
                printf("내 연기실력은 세계 일류지!\n\n");
                Sleep(1000);
                printf("으하하핳 배우나 해야겠다ㅋ\n\n");
                Sleep(2000);
                printf("...\n\n");
                Sleep(2000);
                printf("아, 가방을 두고 왔군!\n\n");
                Sleep(1000);
                printf("\033[31m\033[1m이런 시-\033[0m\n\n");
                Sleep(500);
                system("cls");
                printf("----------------------\n");
                printf(" _____  _   _ ______ \n");
                printf("|  ___|| \\ | ||  _  \\\n");
                printf("| |__  |  \\| || | | |\n");
                printf("|  __| | . ` || | | |\n");
                printf("| |___ | |\\  || |/ / \n");
                printf("\\____/ \\_| \\_/|___/  \n");
                printf("----------------------\n\n");
                printf("\033[1m멍청이 엔딩\033[0m\n");
                printf("[ㅋ]");
                printf("");
                Sleep(5000);
                system("cls");
                exit(0);
            }
            else if (secondChoice == '3') {
                system("cls");
                printf("역시 나야ㅋ\n\n");
                Sleep(1000);
                printf("하아~ 집가서 게임이나 해야지 ㅋㅋ\n\n");
                Sleep(1000);
                printf("\033[1m[근데 집을 가려면 어떻게 가야하지?]\033[0m\n");
                printf("1. 무난하게 버스를 타고 집에 가자.\n");
                printf("2. 귀찮은데 택시 ㄱ.\n");
                printf("3. 운동도 할겸 걸어가자.\n");
                printf("입력하세요 : ");

                char thirdChoice = getchar(); getchar(); // Enter 처리=
                //-------------------------------------------------------------------- 3차 선택 --------------------------------------------------------------------
                if (thirdChoice == '1') {
                    system("cls");
                    printf("후후훟ㅎ 집을 갈 생각만 하고 있으니 너무 기쁘구만 기래！\n\n");
                    Sleep(1500);
                    printf("이제 버스가 오기만을 기다리면 된다!\n\n");
                    Sleep(3000);
                    printf("근데 버스가 언제오지?\n\n");
                    Sleep(2000);
                    printf("뭐?? 20분???\n\n");
                    Sleep(1000);
                    printf("망했네 망했어!\n\n");
                    Sleep(1000);
                    for (int i = 0; i < 100; i++) {
                        printf("\033[31m\033[1m으아아아아앙아아아아아아아악아아아아아아ㅏ아아아아아아아아아아아아아아아아아아악ㄱ!!\033[0m\n");
                        Sleep(10);
                    }
                    system("cls");
                    printf("=====================\n");
                    printf(" _____  _   _ ______ \n");
                    printf("|  ___|| \\ | ||  _  \\\n");
                    printf("| |__  |  \\| || | | |\n");
                    printf("|  __| | . ` || | | |\n");
                    printf("| |___ | |\\  || |/ / \n");
                    printf("\\____/ \\_| \\_/|___/  \n");
                    printf("=====================\n\n");
                    printf("\033[1m시간낭비 엔딩\033[0m\n");
                    printf("[왜 항상 내가 타려는 버스는 이렇게 늦게 오는걸까?]");
                    printf("");
                    Sleep(5000);
                    system("cls");
                    exit(0);
                }
                else if (thirdChoice == '2') {
                    system("cls");
                    printf("X카오 택시를 잡아 탔다.\n\n");
                    Sleep(1000);
                    printf("우히히 빠르고 좋구만!\n\n");
                    Sleep(3000);
                    printf("어 왜 돌아서 가지?\n\n");
                    Sleep(2000);
                    printf("어어어??? 이거 일부러 돌아가는거 같은데???\n\n");
                    Sleep(1500);
                    printf("아이씨 젠장! 잘못 걸렸다!!!\n\n");
                    Sleep(2000);
                    system("cls");
                    for (int i = 0; i < 100; i++) {
                        printf("\033[31m\033[1m으아아아아앙아아아아아아아악아아아아아아ㅏ아아아아아아아아아아아아아아아아아아악ㄱ!!\033[0m\n");
                        Sleep(10);
                    }
                    system("cls");
                    printf("=====================\n");
                    printf(" _____  _   _ ______ \n");
                    printf("|  ___|| \\ | ||  _  \\\n");
                    printf("| |__  |  \\| || | | |\n");
                    printf("|  __| | . ` || | | |\n");
                    printf("| |___ | |\\  || |/ / \n");
                    printf("\\____/ \\_| \\_/|___/  \n");
                    printf("=====================\n\n");
                    printf("\033[1m돈폭탄 엔딩\033[0m\n");
                    printf("[운이 나빴어요! 하필 오늘같은 날에!]");
                    printf("");
                    Sleep(5000);
                    system("cls");
                    exit(0);
                }
                else if (thirdChoice == '3') {
                    system("cls");
                    printf("아이고 힘들긴 한데 뭐 좀 걸어가면 어때.\n\n");
                    Sleep(1500);
                    printf("교통비 아끼고 좋잖아?\n\n");
                    Sleep(1500);
                    printf("이제 집으로 가자!\n\n");
                    Sleep(1500);
                    printf("\033[1m[나는 어디로 가야하는가?]\033[0m\n");
                    printf("1. 당연히 본가로 가야죠. 금요일인데.\n");
                    printf("2. \033[33m굳이 집으로 가야할까?.\033[0m\n");
                    printf("입력하세요 : ");

                    char LastChoice = getchar(); getchar(); // Enter 처리=
                    //-------------------------------------------------------------------- 4차 선택 --------------------------------------------------------------------
                    
                    if (LastChoice == '1') {
                        system("cls");
                        printf("[나는 집으로 굳이 '걸어서'갔고.]\n");
                        Sleep(2000);
                        system("cls");
                        printf("[굳이굳이 손해를 보면서 본가에 도착했다.]\n");
                        Sleep(2000);
                        system("cls");
                        printf("[당연히 그냥 택시나 버스타고 갈걸 후회했고.]\n");
                        Sleep(2000);
                        system("cls");
                        printf("[그냥 집에 왔다는것에 만족하게 되었다.]\n");
                        Sleep(3000);
                        system("cls");
                        printf("=====================\n");
                        printf(" _____  _   _ ______ \n");
                        printf("|  ___|| \\ | ||  _  \\\n");
                        printf("| |__  |  \\| || | | |\n");
                        printf("|  __| | . ` || | | |\n");
                        printf("| |___ | |\\  || |/ / \n");
                        printf("\\____/ \\_| \\_/|___/  \n");
                        printf("=====================\n\n");
                        printf("\033[1m보통 엔딩\033[0m\n");
                        printf("[정말 평범해요. 그쵸?]");
                        printf("");
                        Sleep(5000);
                        system("cls");
                        exit(0);
                    }
                    else if (LastChoice == '2') {
                        system("cls");
                        printf("[굳이 집으로 가야할까?]\n");
                        Sleep(2000);
                        system("cls");
                        printf("[아니 왜, 굳이 '집'일 필요는 없는거잖아?]\n");
                        Sleep(2000);
                        system("cls");
                        printf("[그럼 어디로 갈거냐고?]\n");
                        Sleep(4000);
                        system("cls");
                        printf("=====================\n");
                        printf(" _____  _   _ ______ \n");
                        printf("|  ___|| \\ | ||  _  \\\n");
                        printf("| |__  |  \\| || | | |\n");
                        printf("|  __| | . ` || | | |\n");
                        printf("| |___ | |\\  || |/ / \n");
                        printf("\\____/ \\_| \\_/|___/  \n");
                        printf("=====================\n\n");
                        printf("\033[1m??? 엔딩\033[0m\n");
                        printf("[무언가 잘못되었습니다. 삶의 뱡향은 어디로 튈지 모릅니다.]");
                        printf("");
                        Sleep(5000);
                        system("cls");
                        exit(0);
                    }
                    else {
                        system("cls");
                        printf("주어진 숫자를 입력하라구 이 바부야!");
                        Sleep(500);
                    }
                }
                else {
                    system("cls");
                    printf("주어진 숫자를 입력하라구 이 바부야!");
                    Sleep(500);
                }
            }
            else {
                system("cls");
                printf("주어진 숫자를 입력하라구 이 바부야!");
                Sleep(500);
            }
        }
        else {
            system("cls");
            printf("주어진 숫자를 입력하라구 이 바부야!");
            Sleep(500);
        }
    }
    else {
        system("cls");
        printf("주어진 숫자를 입력하라구 이 바부야!");
        Sleep(500);
    }
}

int main() {
    system("color 0f");
    showIntro();
    return 0;
}
