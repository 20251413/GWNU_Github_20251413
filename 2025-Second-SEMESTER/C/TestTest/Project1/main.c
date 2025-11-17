#define _CRT_SECURE_NO_WARNINGS 1 // Visual Studio의 C4996 경고를 비활성화합니다.

/*
 * C 언어 시험 문제 솔루션
 * - students.csv 파일을 읽어 Test.txt 파일에 결과를 출력합니다.
 * - C99 표준을 준수합니다.
 * - 사용된 헤더: <stdio.h>, <stdlib.h>, <string.h>
 */

#include <stdio.h>
#include <stdlib.h> // exit() 함수 사용을 위해
#include <string.h> // strcpy(), strcmp() 함수 사용을 위해

 // 학생 정보를 저장하기 위한 구조체 정의
struct Student {
    char name[100]; // 학생 이름
    int attack;     // 공격력
    int defense;    // 방어력
    int hp;         // HP
};

// C99 표준에는 max 매크로가 없으므로 간단히 정의
// (참고: battle 로직에서만 사용)
int getMax(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    // 0. 변수 선언
    FILE* fp_in;
    FILE* fp_out;
    struct Student students[10]; // 10명의 학생 데이터 저장 배열
    char studentID[20];          // 사용자 입력 학번
    char studentName[100];       // 사용자 입력 이름
    int i;

    // 1. 사용자로부터 학번과 이름 입력 (요구사항 (1) 준비)
    printf("학번을 입력하세요: ");
    scanf("%s", studentID);
    printf("이름을 입력하세요: ");
    scanf("%s", studentName); // 공백 없는 이름만 받는다고 가정

    // 2. students.csv 파일 열기 (읽기 모드)
    fp_in = fopen("students.csv", "r");
    if (fp_in == NULL) {
        perror("오류: students.csv 파일을 열 수 없습니다.");
        return 1; // 오류 발생 시 프로그램 종료
    }

    // 3. Test.txt 파일 열기 (쓰기 모드)
    fp_out = fopen("Test.txt", "w");
    if (fp_out == NULL) {
        perror("오류: Test.txt 파일을 생성할 수 없습니다.");
        fclose(fp_in); // 이미 연 입력 파일은 닫아줌
        return 1;
    }

    // 4. CSV 파일 읽기
    // 총 10명의 고정된 데이터 읽기
    for (i = 0; i < 10; i++) {
        // fscanf를 사용하여 쉼표로 구분된 데이터 읽기
        // %[^,] : 쉼표(,)가 나오기 전까지의 모든 문자를 읽음 (이름)
        int scan_result = fscanf(fp_in, "%[^,],%d,%d,%d\n",
            students[i].name,
            &students[i].attack,
            &students[i].defense,
            &students[i].hp);

        if (scan_result != 4) {
            // 10줄이 아니거나 형식이 맞지 않는 경우 대비
            fprintf(stderr, "경고: %d번째 줄 데이터 형식 오류\n", i + 1);
        }
    }

    // 입력 파일 닫기
    fclose(fp_in);

    // 5. Test.txt 파일에 요구사항대로 출력

    // (1) 학번과 이름 출력
    fprintf(fp_out, "%s : %s\n", studentID, studentName);

    // (2) 가장 공격력이 높은 사람 찾기
    int max_atk_index = 0; // 가장 높은 공격력을 가진 학생의 인덱스
    int max_atk = students[0].attack;
    for (i = 1; i < 10; i++) {
        // 공격력이 같다면 먼저 등장한 사람(더 낮은 인덱스)이 유지됨 (>)
        if (students[i].attack > max_atk) {
            max_atk = students[i].attack;
            max_atk_index = i;
        }
    }
    fprintf(fp_out, "가장 공격력이 높은 사람: %s (ATK=%d)\n",
        students[max_atk_index].name, students[max_atk_index].attack);

    // (3) 3번째 사람 (인덱스 2) 정보 출력
    fprintf(fp_out, "3번째: %s HP=%d\n",
        students[2].name, students[2].hp);

    // (4) 8번째 사람 (인덱스 7) 정보 출력
    fprintf(fp_out, "8번째: %s HP=%d\n",
        students[7].name, students[7].hp);

    // (5) 3번째 vs 8번째 전투 시뮬레이션
    { // 변수 범위(scope)를 제한하기 위해 블록 사용
        struct Student p3 = students[2]; // 3번째 (인덱스 2)
        struct Student p8 = students[7]; // 8번째 (인덱스 7)

        // 각자 받는 피해 계산
        int dmg_to_p3 = getMax(0, p8.attack - p3.defense);
        int dmg_to_p8 = getMax(0, p3.attack - p8.defense);

        // 규칙: 양쪽 피해가 0이면 즉시 무승부
        if (dmg_to_p3 == 0 && dmg_to_p8 == 0) {
            fprintf(fp_out, "3번째 vs 8번째: 무승부\n");
        }
        else {
            // 시뮬레이션을 위해 HP 복사
            int hp3 = p3.hp;
            int hp8 = p8.hp;

            // HP가 0 이하가 될 때까지 턴 진행
            while (1) {
                // 동시에 피해를 입음
                hp3 -= dmg_to_p3;
                hp8 -= dmg_to_p8;

                int p3_dead = (hp3 <= 0);
                int p8_dead = (hp8 <= 0);

                // 규칙: 같은 턴에 둘 다 0 이하가 되면 무승부
                if (p3_dead && p8_dead) {
                    fprintf(fp_out, "3번째 vs 8번째: 무승부\n");
                    break;
                }
                else if (p8_dead) { // 8번째만 패배
                    fprintf(fp_out, "3번째 vs 8번째 승자: %s\n", p3.name);
                    break;
                }
                else if (p3_dead) { // 3번째만 패배
                    fprintf(fp_out, "3번째 vs 8번째 승자: %s\n", p8.name);
                    break;
                }
                // 둘 다 살아있으면 다음 턴 진행
            }
        }
    } // 전투 시뮬레이션 블록 끝

    // (6) 고정 문자열 출력
    fprintf(fp_out, "교수님 시험문제 너무 쉽습니다. 담주에 더 어렵게 내주세요\n");

    // 6. 출력 파일 닫기
    fclose(fp_out);

    printf("Test.txt 파일 생성이 완료되었습니다.\n");

    return 0; // 프로그램 정상 종료
}