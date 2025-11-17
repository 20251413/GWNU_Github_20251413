// C99 / MSVC 안전 함수(_s) 사용 버전
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX_LINE 256
#define MAX_NAME 64
#define MAX_N    128

typedef struct {
    char name[MAX_NAME];
    int total_keys;   // 총키입력수
    int typos;        // 오타수
    int ms;           // 소요시간(ms)
    int words;        // 단어수
    int cpm;          // 계산: 총키 * 60000 / ms (버림)
    int wpm;          // 계산: 단어 * 60000 / ms (버림)
    int acc;          // 계산: max(0, (총키-오타)*100/총키)
} Typer;

// 안전한 정수 파싱(없으면 0)
static int to_int(const char* s) {
    if (!s || !*s) return 0;
    return (int)strtol(s, NULL, 10);
}

// 줄 끝 개행 제거
static void rstrip(char* s) {
    if (!s) return;
    size_t n = strlen(s);
    while (n > 0 && (s[n - 1] == '\n' || s[n - 1] == '\r')) {
        s[--n] = '\0';
    }
}

// CSV 한 줄 파싱 -> Typer 채우기 (필드 부족 시 0으로)
// strtok_s / strcpy_s 사용
static int parse_line(const char* line_in, Typer* out) {
    char buf[MAX_LINE];
    char* ctx = NULL;

    strcpy_s(buf, sizeof(buf), line_in);

    char* tok = strtok_s(buf, ",", &ctx);
    int col = 0;
    while (tok && col < 5) {
        switch (col) {
        case 0: // 이름
            strcpy_s(out->name, sizeof(out->name), tok);
            break;
        case 1: out->total_keys = to_int(tok); break;
        case 2: out->typos = to_int(tok); break;
        case 3: out->ms = to_int(tok); break;
        case 4: out->words = to_int(tok); break;
        }
        tok = strtok_s(NULL, ",", &ctx);
        col++;
    }
    return (col >= 5);
}

// 지표 계산
static void compute_metrics(Typer* t) {
    if (t->ms <= 0) {
        t->cpm = 0;
        t->wpm = 0;
    }
    else {
        t->cpm = (int)((long long)t->total_keys * 60000LL / t->ms);
        t->wpm = (int)((long long)t->words * 60000LL / t->ms);
    }
    if (t->total_keys <= 0) {
        t->acc = 0;
    }
    else {
        int correct = t->total_keys - t->typos;
        if (correct < 0) correct = 0;
        t->acc = (correct * 100) / t->total_keys; // 버림
    }
}

// 최대값 인덱스(동률이면 앞선 인덱스 유지)
typedef int (*metric_fn)(const Typer*);
static int max_index(const Typer arr[], int n, metric_fn f) {
    int mi = 0;
    int maxv = f(&arr[0]);
    for (int i = 1; i < n; ++i) {
        int v = f(&arr[i]);
        if (v > maxv) { // 동률이면 유지
            maxv = v;
            mi = i;
        }
    }
    return mi;
}
static int get_cpm(const Typer* t) { return t->cpm; }
static int get_wpm(const Typer* t) { return t->wpm; }
static int get_acc(const Typer* t) { return t->acc; }

int main(void) {
    // (1) 학번/이름 입력 (_s: 문자열은 버퍼 크기 인자 필요)
    char sid[32], sname[64];
    printf("학번을 입력하세요: ");
    if (scanf_s("%31s", sid, (unsigned)sizeof(sid)) != 1) return 0;
    printf("이름을 입력하세요: ");
    if (scanf_s("%63s", sname, (unsigned)sizeof(sname)) != 1) return 0;

    // (2) CSV 읽기 (fopen_s 사용)
    FILE* fp = NULL;
    if (fopen_s(&fp, "keystrokes.csv", "r") != 0 || !fp) {
        return 0;
    }

    Typer v[MAX_N];
    int n = 0;
    char line[MAX_LINE];

    while (n < MAX_N && fgets(line, sizeof(line), fp)) {
        rstrip(line);
        if (line[0] == '\0') continue; // 빈 줄 skip
        if (parse_line(line, &v[n])) {
            compute_metrics(&v[n]);
            n++;
        }
        // 형식 불일치 줄은 무시
    }
    fclose(fp);

    if (n <= 0) {
        FILE* out = NULL;
        if (fopen_s(&out, "Test.txt", "w") != 0 || !out) return 0;
        fprintf(out, "%s : %s\n", sid, sname);
        fprintf(out, "최고 CPM: NONE (CPM=0)\n");
        fprintf(out, "최고 WPM: NONE (WPM=0)\n");
        fprintf(out, "최고 정확도: NONE (ACC=%%0)\n");
        fprintf(out, "3번째 vs 8번째: 무승부\n");
        fprintf(out, "교수님 시험문제 너무 쉽습니다. 담주에 더 어렵게 내주세요\n");
        fclose(out);
        return 0;
    }

    // (3) 요구 출력 계산
    int idx_cpm = max_index(v, n, get_cpm);
    int idx_wpm = max_index(v, n, get_wpm);
    int idx_acc = max_index(v, n, get_acc);

    // (4) 3번째/8번째 승자(WPM 비교). 인덱스 범위 확인.
    int has3 = (n >= 3);
    int has8 = (n >= 8);
    char duel_buf[256];

    if (has3 && has8) {
        int i3 = 2, i8 = 7; // 0-based
        if (v[i3].wpm > v[i8].wpm) {
            sprintf_s(duel_buf, sizeof(duel_buf),
                "3번째 vs 8번째 승자: %s", v[i3].name);
        }
        else if (v[i3].wpm < v[i8].wpm) {
            sprintf_s(duel_buf, sizeof(duel_buf),
                "3번째 vs 8번째 승자: %s", v[i8].name);
        }
        else {
            sprintf_s(duel_buf, sizeof(duel_buf),
                "3번째 vs 8번째: 무승부");
        }
    }
    else {
        sprintf_s(duel_buf, sizeof(duel_buf), "3번째 vs 8번째: 무승부");
    }

    // (5) Test.txt로 정확 포맷 출력(6줄)
    FILE* out = NULL;
    if (fopen_s(&out, "Test.txt", "w") != 0 || !out) return 0;

    fprintf(out, "%s : %s\n", sid, sname);
    fprintf(out, "최고 CPM: %s (CPM=%d)\n", v[idx_cpm].name, v[idx_cpm].cpm);
    fprintf(out, "최고 WPM: %s (WPM=%d)\n", v[idx_wpm].name, v[idx_wpm].wpm);
    fprintf(out, "최고 정확도: %s (ACC=%%%d)\n", v[idx_acc].name, v[idx_acc].acc);
    fprintf(out, "%s\n", duel_buf);
    fprintf(out, "교수님 시험문제 너무 쉽습니다. 담주에 더 어렵게 내주세요\n");

    fclose(out);
    return 0;
}
