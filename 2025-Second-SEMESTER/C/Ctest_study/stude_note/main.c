/*
  students_with_comments.c
  - "학생 성적 관리 프로그램" 예제 (수정판)
  - FG_CYAN 매크로 추가 및 설명 주석 보강
  - Visual Studio (MSVC) 기준: scanf_s, fopen_s 사용
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>    // strtok_s, strcpy_s, strlen 등
#include <windows.h>   // Sleep, 콘솔 핸들 제어 (Windows 전용)
#include <conio.h>     // _getch (Windows 전용)

// -------------------------------------------------------------
// ANSI 색상 매크로 정의 (Windows 10+의 콘솔에서 동작)
//  - ESC, CSI: ANSI escape 시퀀스 기본
//  - FG_*: 전경(Foreground) 색상 코드
//  - CLR_RESET: 색상/스타일 리셋
// -------------------------------------------------------------
#define ESC         "\x1b"
#define CSI         ESC "["     // Control Sequence Introducer

// 색상/스타일 매크로: printf에 바로 붙여 쓰면 됨.
// 예: printf(FG_RED "error\n" CLR_RESET);
#define CLR_RESET   CSI "0m"
#define FG_RED      CSI "31m"
#define FG_GREEN    CSI "32m"
#define FG_YELLOW   CSI "33m"
#define FG_BLUE     CSI "34m"
#define FG_MAGENTA  CSI "35m"
#define FG_CYAN     CSI "36m"   // <-- 여기에 FG_CYAN 정의를 추가함 (없어서 에러 났음)
#define FG_WHITE    CSI "37m"
#define BOLD        CSI "1m"

// -------------------------------------------------------------
// enable_ansi: Windows 콘솔에서 ANSI 이스케이프 시퀀스 사용을 시도
//  - Windows 10 이상에서는 콘솔 모드 플래그 ENABLE_VIRTUAL_TERMINAL_PROCESSING(0x0004)
//    를 켜면 printf로 출력되는 ANSI 코드(색상 등)가 활성화됨.
//  - 실패하더라도 프로그램 로직에는 영향이 없고, 단지 색상이 보이지 않을 뿐임.
// -------------------------------------------------------------
void enable_ansi(void)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) return;

    DWORD mode = 0;
    if (!GetConsoleMode(hOut, &mode)) return;

    // ENABLE_VIRTUAL_TERMINAL_PROCESSING = 0x0004
    // 이 플래그를 켜면 콘솔이 ANSI 색상/시퀀스를 해석함.
    mode |= 0x0004;
    SetConsoleMode(hOut, mode);
}

// -------------------------------------------------------------
// 구조체: 학생 정보
// -------------------------------------------------------------
typedef struct {
    char  name[64];  // 학생 이름 (공백 없는 입력 권장; 공백 허용하려면 fgets로 변경)
    int   id;        // 학번
    int   kor;       // 국어 점수
    int   eng;       // 영어 점수
    int   math;      // 수학 점수
    double avg;      // 평균 (프로그램에서 계산)
} Student;

#define MAX_STUDENTS 100

// -------------------------------------------------------------
// flush_input: 입력 버퍼에 남아있는 개행 문자 등을 비우는 유틸
//  - scanf_s 후에는 남은 '\n'이 버퍼에 남을 수 있음. getchar/flush로 제거.
// -------------------------------------------------------------
void flush_input(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { /* 버림 */ }
}

// -------------------------------------------------------------
// write_students_to_csv:
//  - 사용자로부터 학생 정보를 받아 students.csv에 저장
//  - 각 학생마다 평균(avg)을 계산하여 파일에 기록
// -------------------------------------------------------------
int write_students_to_csv(const char* path)
{
    Student s[MAX_STUDENTS];
    int n = 0;

    // 학생 수 입력
    printf(FG_YELLOW BOLD "[입력 단계]" CLR_RESET " 학생 수 입력 (1~%d): ", MAX_STUDENTS);
    if (scanf_s("%d", &n) != 1 || n < 1 || n > MAX_STUDENTS) {
        // 입력이 정수로 읽히지 않거나 범위를 벗어나면 오류 처리
        printf(FG_RED "잘못된 입력입니다. 1~%d 범위의 값을 입력하세요.\n" CLR_RESET, MAX_STUDENTS);
        flush_input();
        return -1;
    }
    flush_input(); // 남아있는 개행 제거

    // n명의 학생 정보를 입력받음
    for (int i = 0; i < n; ++i) {
        printf(FG_WHITE "\n[%d/%d] 학생 정보 입력\n" CLR_RESET, i + 1, n);

        // 이름 입력: 공백 없는 단어 입력 전제
        printf("  이름(공백 없이): ");
        if (scanf_s("%63s", s[i].name, (rsize_t)sizeof(s[i].name)) != 1) {
            printf(FG_RED "  이름 입력 오류\n" CLR_RESET);
            flush_input();
            --i; // 재입력 유도
            continue;
        }

        // 정수 입력: 학번/점수들
        printf("  학번: ");
        if (scanf_s("%d", &s[i].id) != 1) {
            printf(FG_RED "  학번 입력 오류\n" CLR_RESET);
            flush_input();
            --i;
            continue;
        }

        printf("  국어 점수: ");
        if (scanf_s("%d", &s[i].kor) != 1) {
            printf(FG_RED "  국어 점수 입력 오류\n" CLR_RESET);
            flush_input();
            --i;
            continue;
        }

        printf("  영어 점수: ");
        if (scanf_s("%d", &s[i].eng) != 1) {
            printf(FG_RED "  영어 점수 입력 오류\n" CLR_RESET);
            flush_input();
            --i;
            continue;
        }

        printf("  수학 점수: ");
        if (scanf_s("%d", &s[i].math) != 1) {
            printf(FG_RED "  수학 점수 입력 오류\n" CLR_RESET);
            flush_input();
            --i;
            continue;
        }

        flush_input(); // 현재 학생 입력 끝난 뒤 남은 개행 제거

        // 평균 계산: 실수로 계산하여 소수점 포함 가능
        s[i].avg = (s[i].kor + s[i].eng + s[i].math) / 3.0;
    }

    // 파일 쓰기: fopen_s 사용 (MSVC secure 버전)
    FILE* fp = NULL;
    errno_t err = fopen_s(&fp, path, "w");
    if (err != 0 || fp == NULL) {
        printf(FG_RED "파일 열기 실패(쓰기): %s  (errno=%d)\n" CLR_RESET, path, err);
        return -2;
    }

    // CSV 헤더 작성: 채점/후처리용으로 고정 헤더 권장
    fprintf(fp, "name,id,kor,eng,math,avg\n");

    // 각 학생 레코드를 CSV로 기록 (avg는 소수점 2자리 고정)
    for (int i = 0; i < n; ++i) {
        fprintf(fp, "%s,%d,%d,%d,%d,%.2f\n",
            s[i].name, s[i].id, s[i].kor, s[i].eng, s[i].math, s[i].avg);
    }

    fclose(fp);

    printf(FG_GREEN "\n[저장 완료] %d명 학생 데이터 저장됨 → %s\n" CLR_RESET, n, path);
    printf("엔터를 누르면 CSV를 읽어옵니다...");
    getchar(); // 여기서는 실제 대기(위에서 flush_input 했으므로 개행 소비 후 기다림)

    return n;
}

// -------------------------------------------------------------
// read_students_from_csv:
//  - 파일에서 CSV를 읽어 Student 배열에 로드하고 표로 출력
//  - 평균에 따라 컬러(초록/노랑/빨강)로 출력
// -------------------------------------------------------------
int read_students_from_csv(const char* path)
{
    Student s[MAX_STUDENTS];
    int count = 0;

    FILE* fp = NULL;
    errno_t err = fopen_s(&fp, path, "r");
    if (err != 0 || fp == NULL) {
        printf(FG_RED "파일 열기 실패(읽기): %s  (errno=%d)\n" CLR_RESET, path, err);
        return -1;
    }

    char line[512];
    int line_no = 0;

    // 한 줄씩 읽어서 파싱
    while (fgets(line, sizeof(line), fp)) {
        ++line_no;

        // 첫 줄은 헤더이므로 건너뜀
        if (line_no == 1) continue;

        // 개행(CR/LF) 제거: CRLF 환경도 안전하게 처리
        size_t len = strlen(line);
        while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r')) {
            line[--len] = '\0';
        }

        // CSV 토크나이즈 (쉼표로 분리)
        char* ctx = NULL;
        char* tok = strtok_s(line, ",", &ctx);
        if (!tok) continue;
        // name
        strcpy_s(s[count].name, sizeof(s[count].name), tok);

        // id
        tok = strtok_s(NULL, ",", &ctx);
        if (!tok) continue;
        s[count].id = (int)strtol(tok, NULL, 10);

        // kor
        tok = strtok_s(NULL, ",", &ctx);
        if (!tok) continue;
        s[count].kor = (int)strtol(tok, NULL, 10);

        // eng
        tok = strtok_s(NULL, ",", &ctx);
        if (!tok) continue;
        s[count].eng = (int)strtol(tok, NULL, 10);

        // math
        tok = strtok_s(NULL, ",", &ctx);
        if (!tok) continue;
        s[count].math = (int)strtol(tok, NULL, 10);

        // avg
        tok = strtok_s(NULL, ",", &ctx);
        if (!tok) continue;
        s[count].avg = strtod(tok, NULL);

        // 증가
        ++count;
        if (count >= MAX_STUDENTS) break;
    }

    fclose(fp);

    // 표 출력: 헤더
    printf(FG_MAGENTA BOLD "\n[출력 단계] CSV에서 %d명 로드됨 → 표로 출력합니다.\n" CLR_RESET, count);
    printf(BOLD FG_WHITE "-------------------------------------------------------------\n" CLR_RESET);
    printf(BOLD FG_WHITE "%-12s %-6s %-6s %-6s %-6s %-6s\n" CLR_RESET, "NAME", "ID", "KOR", "ENG", "MATH", "AVG");
    printf(BOLD FG_WHITE "-------------------------------------------------------------\n" CLR_RESET);

    // 각 학생 출력: 평균별 색상 적용
    for (int i = 0; i < count; ++i) {
        Sleep(50); // 한 줄씩 출력 (시각적 효과)

        // 색상 결정: 평균 >=90 초록, <60 빨강, 나머지 노랑
        const char* color = FG_YELLOW;
        if (s[i].avg >= 90.0) color = FG_GREEN;
        else if (s[i].avg < 60.0) color = FG_RED;

        // 컬러 시작 + 데이터 출력 + 리셋
        printf("%s%-12s %-6d %-6d %-6d %-6d %-6.2f%s\n",
            color,
            s[i].name, s[i].id, s[i].kor, s[i].eng, s[i].math, s[i].avg,
            CLR_RESET);
    }

    printf(BOLD FG_WHITE "-------------------------------------------------------------\n" CLR_RESET);
    printf(FG_GREEN "\n출력 완료. 아무 키나 누르면 종료합니다..." CLR_RESET);
    _getch(); // 에코 없이 즉시 키 입력 대기

    return count;
}

// -------------------------------------------------------------
// main: 프로그램 진입점
// -------------------------------------------------------------
int main(void)
{
    enable_ansi(); // 가능하면 ANSI 색상 활성화 (없어도 동작)

    const char* CSV_PATH = "students.csv";

    printf(FG_CYAN BOLD "=== 학생 성적 관리 프로그램 ===\n" CLR_RESET);
    printf("학생 정보를 입력받아 CSV로 저장하고, 다시 읽어 표로 출력합니다.\n\n");

    int n = write_students_to_csv(CSV_PATH);
    if (n < 0) {
        // 입력/저장 단계에서 오류 발생 시 종료
        return 1;
    }

    int m = read_students_from_csv(CSV_PATH);
    if (m < 0) {
        // 읽기/출력 단계에서 오류 발생 시 종료
        return 2;
    }

    printf("\n" FG_CYAN "프로그램 종료. 수고했습니다!\n" CLR_RESET);
    return 0;
}
