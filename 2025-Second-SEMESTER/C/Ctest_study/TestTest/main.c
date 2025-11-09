/*
 * C언어 시험 문제 풀이 (Microsoft _s 함수 사용 버전)
 * [수정] scanf_s, fopen_s, fscanf_s의 올바른 사용법 적용
 */

#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <conio.h>  

typedef struct {
    char name[50];
    int attack;
    int defense;
    int hp;
} Student;

// 이름 충돌을 피하기 위해 'custom_max' 사용
int custom_max(int a, int b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}

int main() {

    // ------------------------------------------------------------------
    // (1) 학번과 이름 입력 받기 (scanf_s 사용)
    // ------------------------------------------------------------------
    char student_id[20];
    char student_name[50];

    printf("학번을 입력하세요: ");
    // [수정] scanf_s는 문자열(%s)을 받을 때 버퍼의 크기를 인자로 넘겨야 함
    scanf_s("%s", student_id, sizeof(student_id));

    printf("이름을 입력하세요: ");
    // [수정] 버퍼 크기 추가
    scanf_s("%s", student_name, sizeof(student_name));

    // ------------------------------------------------------------------
    // 출력 파일 (Test.txt) 열기 (fopen_s 사용)
    // ------------------------------------------------------------------
    FILE* output_file;
    // [수정] fopen_s는 파일 포인터의 주소(&output_file)를 첫 인자로 받음
    //       성공 시 0을 반환하므로, 0이 아닌지(!= 0) 검사
    if (fopen_s(&output_file, "Test.txt", "w") != 0) {
        printf("오류: 'Test.txt' 파일을 열 수 없습니다.\n");
        return 1;
    }

    // (1) 학번과 이름 파일에 출력
    fprintf(output_file, "%s : %s\n", student_id, student_name);

    // ------------------------------------------------------------------
    // 입력 파일 (students.csv) 읽기 (fopen_s 사용)
    // ------------------------------------------------------------------
    Student students[10];
    FILE* input_file;
    // [수정] fopen_s 사용법 수정
    if (fopen_s(&input_file, "students.csv", "r") != 0) {
        printf("오류: 'students.csv' 파일을 찾을 수 없습니다.\n");
        fprintf(output_file, "오류: 'students.csv' 파일을 찾을 수 없습니다.\n");
        fclose(output_file);
        return 1;
    }

    // CSV 헤더 한 줄 읽고 버리기
    char header_buffer[1024];
    fgets(header_buffer, sizeof(header_buffer), input_file);

    int read_count = 0;
    while (read_count < 10)
    {
        // [수정] fscanf_s는 문자열(%[^,])을 받을 때 버퍼의 크기를 인자로 넘겨야 함
        int result = fscanf_s(input_file, "%[^,],%d,%d,%d\n",
            students[read_count].name,
            sizeof(students[read_count].name), // name 버퍼의 크기 추가
            &students[read_count].attack,
            &students[read_count].defense,
            &students[read_count].hp);

        if (result == 4) // _s 함수도 성공 시 4를 반환
        {
            read_count++;
        }
        else
        {
            break; // 파일 끝(EOF)이거나 형식이 안 맞으면 중단
        }
    }

    fclose(input_file);

    if (read_count != 10) {
        printf("오류: 'students.csv'에서 10명의 데이터를 읽는 데 실패했습니다. (읽은 수: %d)\n", read_count);
        fprintf(output_file, "오류: 'students.csv' 파일 형식 오류 또는 데이터 부족\n");
        fclose(output_file);
        return 1;
    }

    // ------------------------------------------------------------------
    // (2) 가장 공격력이 높은 사람 찾기
    // ------------------------------------------------------------------
    int max_atk_index = 0;
    for (int i = 1; i < 10; i++) {
        if (students[i].attack > students[max_atk_index].attack) {
            max_atk_index = i;
        }
    }
    fprintf(output_file, "가장 공격력이 높은 사람: %s (ATK=%d)\n",
        students[max_atk_index].name, students[max_atk_index].attack);

    // ------------------------------------------------------------------
    // (3) 3번째 사람 정보 출력
    // ------------------------------------------------------------------
    fprintf(output_file, "3번째: %s HP=%d\n", students[2].name, students[2].hp);

    // ------------------------------------------------------------------
    // (4) 8번째 사람 정보 출력
    // ------------------------------------------------------------------
    fprintf(output_file, "8번째: %s HP=%d\n", students[7].name, students[7].hp);

    // ------------------------------------------------------------------
    // (5) 3번째 vs 8번째 전투 시뮬레이션
    // ------------------------------------------------------------------

    int hp_player3 = students[2].hp;
    int hp_player8 = students[7].hp;

    int damage_to_3 = custom_max(0, students[7].attack - students[2].defense);
    int damage_to_8 = custom_max(0, students[2].attack - students[7].defense);

    if (damage_to_3 == 0 && damage_to_8 == 0) {
        fprintf(output_file, "3번째 vs 8번째: 무승부\n");
    }
    else {
        while (hp_player3 > 0 && hp_player8 > 0) {
            hp_player3 = hp_player3 - damage_to_3;
            hp_player8 = hp_player8 - damage_to_8;
        }

        if (hp_player3 <= 0 && hp_player8 <= 0) {
            fprintf(output_file, "3번째 vs 8번째: 무승부\n");
        }
        else if (hp_player3 <= 0) {
            fprintf(output_file, "3번째 vs 8번째 승자: %s\n", students[7].name);
        }
        else {
            fprintf(output_file, "3번째 vs 8번째 승자: %s\n", students[2].name);
        }
    }

    // ------------------------------------------------------------------
    // (6) 마지막 줄
    // ------------------------------------------------------------------
    fprintf(output_file, "교수님 시험문제 너무 쉽습니다. 담주에 더 어렵게 내주세요\n");

    // ------------------------------------------------------------------
    // 마무리
    // ------------------------------------------------------------------
    fclose(output_file);
    printf("성공: 'Test.txt' 파일이 정상적으로 생성되었습니다.\n");

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------------------


/*
 * C언어 시험 문제 풀이 (Microsoft _s 함수 사용 버전)           // 이 파일이 무엇을 하는지, 그리고 MS 보안 계열 함수를 쓴다는 설명.
 * [수정] scanf_s, fopen_s, fscanf_s의 올바른 사용법 적용         // _s 계열은 추가 인자(버퍼 크기 등)가 필요하므로 "올바른 사용"을 강조.
 */

#include <stdio.h>                                                // 표준 입출력: printf, fprintf, scanf_s, fopen_s 등 사용을 위해 포함.
#include <stdlib.h>                                               // 일반 유틸/종료 코드에 대한 상징적 포함(필수는 아니지만 관용적으로 넣음).
#include <string.h>                                               // 문자열 함수(여기서는 직접 호출은 없지만, 문자열 처리 맥락상 포함해도 무방).
#include <conio.h>                                                // 과제 허용 헤더. 실제 사용은 없지만, "허용 헤더" 목록 준수 차 포함(삭제해도 기능 동일).

typedef struct {                                                  // 학생 정보를 하나의 '레코드'로 묶어 관리하기 위해 구조체 선언.
    char name[50];                                                // 이름 저장 버퍼(최대 49글자 + 널 종료 '\0'). 고정배열로 오버런 위험을 제어.
    int attack;                                                   // 공격력: CSV에서 %d로 읽어올 정수 필드.
    int defense;                                                  // 방어력: CSV에서 %d로 읽어올 정수 필드.
    int hp;                                                       // 체력(HP): 전투 시뮬레이션에서 감소시키는 대상이므로 정수형.
} Student;

// 이름 충돌을 피하기 위해 'custom_max' 사용                      // 일부 환경에서 max 매크로나 함수와 충돌 가능성 회피(안전한 고유 이름).
int custom_max(int a, int b) {                                    // 두 정수 중 큰 값을 반환하는 순수 함수(부작용 없음).
    if (a > b) {                                                  // 비교는 분기 한 번으로 단순·명확.
        return a;                                                 // a가 더 크면 a 반환.
    }
    else {                                                        // 그렇지 않다면(= b가 크거나 같다면)
        return b;                                                 // b 반환. 동률에서도 b를 반환하지만, 여기서는 max 용도이므로 무해.
    }
}

int main() {                                                      // 프로그램 진입점. 반환값은 OS에 종료 상태(0=성공, 비0=실패) 전달.

    // ------------------------------------------------------------------
    // (1) 학번과 이름 입력 받기 (scanf_s 사용)
    // ------------------------------------------------------------------
    char student_id[20];                                          // 학번 입력 버퍼(문자열). 19자 + '\0' 여유로 안전성 확보.
    char student_name[50];                                        // 이름 입력 버퍼. 콘솔에서 공백 기준으로 끊어지므로 '홍 길 동' 형태는 불가.

    printf("학번을 입력하세요: ");                                 // 사용자에게 학번 입력을 요청(개행 없이 띄워 입력 커서 유도).
    // [핵심] scanf_s의 문자열 계열(%s, %[...)은 '반드시' 버퍼 크기(문자 개수)를 추가 인자로 넘겨야 함.
    // 미제공 시 MSVC의 Invalid Parameter Handler가 트리거되어 프로그램이 비정상 종료될 수 있음.
    scanf_s("%s", student_id, sizeof(student_id));                // %s는 공백 전까지 읽음. sizeof로 '문자수'를 그대로 전달(ANSI 가정하 바이트=문자).

    printf("이름을 입력하세요: ");                                 // 사용자에게 이름 입력 요청.
    // 동일하게 문자열 변환자이므로, 버퍼 크기를 반드시 제공해야 안전/정상 동작.
    scanf_s("%s", student_name, sizeof(student_name));            // 이름 입력. 공백이 나오면 끊김(문제에서 이름에 공백 없다고 가정).

    // ------------------------------------------------------------------
    // 출력 파일 (Test.txt) 열기 (fopen_s 사용)
    // ------------------------------------------------------------------
    FILE* output_file;                                            // 결과물을 쓸 파일 포인터.
    // fopen_s 프로토타입: errno_t fopen_s(FILE** ppFile, const char* filename, const char* mode)
    // 성공 시 0, 실패 시 0이 아닌 값을 반환하므로, '!= 0'로 실패를 감지.
    if (fopen_s(&output_file, "Test.txt", "w") != 0) {            // 쓰기 모드("w"): 없으면 생성, 있으면 내용 비움(트렁케이트).
        printf("오류: 'Test.txt' 파일을 열 수 없습니다.\n");        // 사용자에게 에러상황을 알려 디버깅 용이.
        return 1;                                                 // 출력 불가능하므로 즉시 실패 종료.
    }

    // (1) 학번과 이름 파일에 출력
    // 요구 포맷 100% 일치 필요: "학번 : 이름" + 줄바꿈. 공백/콜론 위치까지 채점 포인트.
    fprintf(output_file, "%s : %s\n", student_id, student_name);  // 형식 문자와 데이터 개수 일치. 유효 문자열이므로 %s 사용 적절.

    // ------------------------------------------------------------------
    // 입력 파일 (students.csv) 읽기 (fopen_s 사용)
    // ------------------------------------------------------------------
    Student students[10];                                         // 문제 조건: 총 10명 고정. 배열로 충분(동적 할당 불필요).
    FILE* input_file;                                             // CSV를 읽을 파일 포인터.
    // ANSI 인코딩 가정. BOM 없는 일반 텍스트. fscanf_s는 바이트 기반 읽기라 ANSI 환경에서 문제 없음.
    if (fopen_s(&input_file, "students.csv", "r") != 0) {         // 읽기 모드로 열기 실패 시, 이후 로직 진행 불가능.
        printf("오류: 'students.csv' 파일을 찾을 수 없습니다.\n");  // 콘솔로 즉시 원인 안내(파일 미존재, 권한 등).
        fprintf(output_file, "오류: 'students.csv' 파일을 찾을 수 없습니다.\n"); // 결과 파일에도 원인 기록(채점자 가독성↑).
        fclose(output_file);                                      // 이미 연 출력 파일은 반드시 닫아 리소스/버퍼 누수 방지.
        return 1;                                                 // 실패 종료.
    }

    // CSV 헤더 한 줄 읽고 버리기
    // [가정] 첫 줄이 "이름,공격력,방어력,HP" 같은 헤더라고 가정. 만약 헤더가 없다면 이 줄은 삭제해야 첫 데이터가 유실되지 않음.
    char header_buffer[1024];                                     // 헤더를 임시로 담을 충분히 큰 버퍼(1KB).
    fgets(header_buffer, sizeof(header_buffer), input_file);      // 개행까지 한 줄 읽고 버림. 실패해도致命은 아니지만 "헤더 없음"일 때는 문제.

    int read_count = 0;                                           // 정상적으로 읽은 학생 수 카운터.
    while (read_count < 10)                                       // 정확히 10명까지 읽을 때까지 반복. EOF/형식 오류 시 중단.
    {
        // fscanf_s의 포맷 해설:
        //  - "%[^,]"  : 콤마(,)가 나오기 전까지의 모든 문자를 '문자열'로 읽는 스캔셋(이름에 콤마가 없다는 가정 전제).
        //  - 뒤의 "%d,%d,%d" : 공격력/방어력/HP 정수 읽기.
        //  - 문자열 변환자(%[^,])에는 반드시 '버퍼 크기' 추가 인자를 제공해야 함(여기서는 name의 크기).
        //  - 마지막 "\n"은 '리터럴 개행'이어서, 레코드 끝에 개행이 있어야 매칭에 성공함(Windows의 \r\n도 공백 처리 규칙으로 대체 가능).
        int result = fscanf_s(input_file, "%[^,],%d,%d,%d\n",     // 한 줄 전체 포맷을 명시(이름,정수,정수,정수 + 개행).
            students[read_count].name,                            // 이름을 저장할 버퍼의 시작 주소.
            sizeof(students[read_count].name),                    // [중요] name 버퍼의 '문자 수' 크기 전달(오버런 방지).
            &students[read_count].attack,                         // 정수 필드(공격력) 주소.
            &students[read_count].defense,                        // 정수 필드(방어력) 주소.
            &students[read_count].hp);                            // 정수 필드(HP) 주소.

        if (result == 4)                                          // 변환 성공 항목 수가 4개면(이름+3정수) 그 줄은 정상 레코드.
        {
            read_count++;                                         // 학생 수 증가.
        }
        else                                                       // 4가 아니면: EOF, 빈 줄, 잘못된 형식(콤마 수/개행 없음) 등.
        {
            break;                                                // 더 이상 읽기 시도하지 않고 루프 종료 → 아래에서 read_count 검증.
        }
    }

    fclose(input_file);                                           // 입력 스트림 닫기. OS 리소스 반환 및 파일 핸들 누수 방지.

    if (read_count != 10) {                                       // 문제 요구는 '정확히 10명'. 하나라도 모자라면 채점 불합격 조건.
        printf("오류: 'students.csv'에서 10명의 데이터를 읽는 데 실패했습니다. (읽은 수: %d)\n", read_count); // 콘솔로 개수 보고.
        fprintf(output_file, "오류: 'students.csv' 파일 형식 오류 또는 데이터 부족\n"); // 결과 파일에도 원인 명시.
        fclose(output_file);                                      // 출력 파일 닫기(버퍼 flush 겸).
        return 1;                                                 // 실패 종료.
    }

    // ------------------------------------------------------------------
    // (2) 가장 공격력이 높은 사람 찾기
    // ------------------------------------------------------------------
    int max_atk_index = 0;                                        // 최댓값 후보를 0번째로 초기화(동률 시 "먼저 나온 사람"이 유지됨).
    for (int i = 1; i < 10; i++) {                                // 1~9 인덱스 순회(총 10명, 선형 탐색 O(10)=상수).
        if (students[i].attack > students[max_atk_index].attack) {// 더 큰 공격력을 만나면 인덱스 갱신. 동률이면 >가 false라 그대로 유지.
            max_atk_index = i;                                    // 현재까지의 최댓값 인덱스를 i로 업데이트.
        }
    }
    // 정확한 출력 형식 요구: "가장 공격력이 높은 사람: 이름 (ATK=정수)"
    fprintf(output_file, "가장 공격력이 높은 사람: %s (ATK=%d)\n",
        students[max_atk_index].name,                             // 최댓값 보유자 이름 출력.
        students[max_atk_index].attack);                          // 최댓값 보유자 공격력 출력.

    // ------------------------------------------------------------------
    // (3) 3번째 사람 정보 출력
    // ------------------------------------------------------------------
    // '3번째'는 사람 기준 카운트(1부터). 배열은 0부터이므로 인덱스 2가 맞음.
    fprintf(output_file, "3번째: %s HP=%d\n",
        students[2].name,                                     // 3번째(인덱스 2)의 이름.
        students[2].hp);                                      // 3번째의 HP.

    // ------------------------------------------------------------------
    // (4) 8번째 사람 정보 출력
    // ------------------------------------------------------------------
    // 동일하게 '8번째' → 인덱스 7.
    fprintf(output_file, "8번째: %s HP=%d\n",
        students[7].name,                                     // 8번째(인덱스 7)의 이름.
        students[7].hp);                                      // 8번째의 HP.

    // ------------------------------------------------------------------
    // (5) 3번째 vs 8번째 전투 시뮬레이션
    // ------------------------------------------------------------------

    int hp_player3 = students[2].hp;                              // 원본 데이터(students[])는 보존하고, 시뮬레이션은 복사본으로 수행.
    int hp_player8 = students[7].hp;                              // 8번째도 동일하게 복사본을 사용.

    // 피해 공식: 받는 피해 = max(0, 상대 ATK - 내 DEF)
    // '동시에 피해' → 같은 턴 내에 두 HP를 모두 감소시켜야 하므로, 루프 안에서 같은 틱에 각각 빼는 형태로 구현.
    int damage_to_3 = custom_max(0, students[7].attack - students[2].defense); // 3번째가 매 턴 받을 피해(음수가 되면 0으로 클램프).
    int damage_to_8 = custom_max(0, students[2].attack - students[7].defense); // 8번째가 매 턴 받을 피해.

    if (damage_to_3 == 0 && damage_to_8 == 0) {                   // 양쪽 피해가 모두 0이면 HP가 절대 줄지 않아 무한루프 위험.
        fprintf(output_file, "3번째 vs 8번째: 무승부\n");          // 규칙상 '즉시 무승부'로 처리(명시된 요구사항 충족).
    }
    else {                                                        // 최소 한 쪽은 피해 > 0인 정상 전투 상황.
        while (hp_player3 > 0 && hp_player8 > 0) {                // 두 플레이어 모두 생존(HP>0)일 때만 턴 진행.
            hp_player3 = hp_player3 - damage_to_3;                // 같은 턴에 3번째 HP를 감소.
            hp_player8 = hp_player8 - damage_to_8;                // 같은 턴에 8번째 HP를 감소.
            // 같은 반복에서 두 HP를 모두 깎으므로, 동일 턴에 동시에 0 이하가 될 수 있음(아래 판정에서 무승부로 처리).
        }

        if (hp_player3 <= 0 && hp_player8 <= 0) {                 // 같은 턴에 둘 다 0 이하 → 무승부(규칙에 명시).
            fprintf(output_file, "3번째 vs 8번째: 무승부\n");
        }
        else if (hp_player3 <= 0) {                               // 3번째만 0 이하 → 8번째 승리.
            fprintf(output_file, "3번째 vs 8번째 승자: %s\n", students[7].name);
        }
        else {                                                    // 반대의 경우(8번째만 0 이하) → 3번째 승리.
            fprintf(output_file, "3번째 vs 8번째 승자: %s\n", students[2].name);
        }
    }

    // ------------------------------------------------------------------
    // (6) 마지막 줄
    // ------------------------------------------------------------------
    fprintf(output_file, "교수님 시험문제 너무 쉽습니다. 담주에 더 어렵게 내주세요\n"); // 요구된 문장을 '띄어쓰기/맞춤/개행'까지 정확히 출력.

    // ------------------------------------------------------------------
    // 마무리
    // ------------------------------------------------------------------
    fclose(output_file);                                          // 출력 스트림 닫기: 내부 버퍼 flush + 핸들 반환. 누락 시 데이터 유실 위험.
    printf("성공: 'Test.txt' 파일이 정상적으로 생성되었습니다.\n");  // 사용자에게 정상 완료 피드백(과제 실행 확인 용이).

    return 0;                                                     // 정상 종료 코드(관례적 0). 채점 스크립트가 이 값을 이용할 수 있음.
}
