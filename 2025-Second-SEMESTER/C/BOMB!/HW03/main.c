/*
#include <stdio.h>
#include <math.h>
#include <Windows.h>

#define PI 3.14159226535897

void moveCursor(int x, int y)
{
    printf("\x1b[%d;%dH", y, x);
}

//매개변수 isExploded
//0: 폭발전 폭탄
//1: 폭발함
void printBomb(int isExploded)
{
    //폭탄은 항상 7칸
    if (isExploded)
    {
        printf("\x1b[A^^^^^^^");
        printf("\x1b[B\x1b[7D!!BAM!!");
        printf("\x1b[B\x1b[7D^^^^^^^");
    }
    else
        printf("(  b  )"); 
}

int main()
{
    // 여기부터 코드를 작성하세요----------------------   
    int path_x[100], path_y[100];
    int x = 14, y = 9; // '*'의 시작 위치
    int count = 0;
    int length = 2;

    // 2. 요청된 규칙에 따라 심지 경로 계산
    path_x[count] = x;
    path_y[count] = y;
    count++;

    while (length <= 12) {
        // 아래로 이동
        for (int i = 0; i < length; i++) { y++; path_x[count] = x; path_y[count] = y; count++; }
        // 오른쪽으로 이동
        for (int i = 0; i < length; i++) { x++; path_x[count] = x; path_y[count] = y; count++; }
        length += 2;
        // 위로 이동
        for (int i = 0; i < length; i++) { y--; path_x[count] = x; path_y[count] = y; count++; }
        // 왼쪽으로 이동
        for (int i = 0; i < length; i++) { x--; path_x[count] = x; path_y[count] = y; count++; }
        length += 2;
    }

    // 3. 초기 심지와 폭탄 그리기
    int fuse_end_x = path_x[count - 1];
    int fuse_end_y = path_y[count - 1];

    // ★★★ 최종 수정: 폭탄 위치를 왼쪽으로 3칸 추가 이동 ★★★
    int bomb_x = fuse_end_x - 7;
    int bomb_y = fuse_end_y;

    // 심지('#') 전체를 먼저 그립니다.
    for (int i = 1; i < count; i++) {
        moveCursor(path_x[i], path_y[i]);
        printf("#");
    }

    // 심지가 다 그려진 후, 그 옆의 분리된 위치에 폭탄을 그립니다.
    moveCursor(bomb_x, bomb_y);
    printBomb(0); // ( b ) 출력

    // 4. 불꽃이 심지를 태우는 애니메이션
    for (int i = 0; i < count; i++) {
        if (i > 0) {
            moveCursor(path_x[i - 1], path_y[i - 1]);
            printf(" ");
        }
        moveCursor(path_x[i], path_y[i]);
        printf("*");
        Sleep(200);
    }

    // 5. 폭탄 폭파
    moveCursor(fuse_end_x, fuse_end_y);
    printf(" ");
    Sleep(200);
    moveCursor(bomb_x, bomb_y);
    printBomb(1);
    // 여기까지 코드를 작성하세요----------------------   
    moveCursor(10, 20);
    return 0;
}
*/


#include <stdio.h>
#include <math.h>
#include <Windows.h>

#define PI 3.14159226535897

void moveCursor(int x, int y)
{
    printf("\x1b[%d;%dH", y, x);
}

//매개변수 isExploded
//0: 폭발전 폭탄
//1: 폭발함
void printBomb(int isExploded)
{
    //폭탄은 항상 7칸
    if (isExploded)
    {
        printf("\x1b[A^^^^^^^");
        printf("\x1b[B\x1b[7D!!BAM!!");
        printf("\x1b[B\x1b[7D^^^^^^^");
    }
    else
        printf("(  b  )");
}

int main()
{
    int x = 14;     // 불꽃이 시작될 x 위치
    int y = 9;      // 불꽃이 시작될 y 위치
    int bomb_x = 0; // 나중에 폭탄이 놓일 x 위치
    int bomb_y = 0; // 나중에 폭탄이 놓일 y 위치

    system("cls"); // 화면을 깨끗하게 지웁니다.

    // --- 2단계: 심지(#) 그리기 ---
    // for 반복문을 순서대로 따라가며 심지를 그립니다.

    // 아래로 2칸 그리기
    for (int i = 0; i < 2; i++) { y++; moveCursor(x, y); printf("#"); }
    // 오른쪽으로 2칸 그리기
    for (int i = 0; i < 2; i++) { x++; moveCursor(x, y); printf("#"); }
    // 위로 4칸 그리기
    for (int i = 0; i < 4; i++) { y--; moveCursor(x, y); printf("#"); }
    // 왼쪽으로 4칸 그리기
    for (int i = 0; i < 4; i++) { x--; moveCursor(x, y); printf("#"); }
    // 아래로 6칸 그리기
    for (int i = 0; i < 6; i++) { y++; moveCursor(x, y); printf("#"); }
    // 오른쪽으로 6칸 그리기
    for (int i = 0; i < 6; i++) { x++; moveCursor(x, y); printf("#"); }
    // 위로 8칸 그리기
    for (int i = 0; i < 8; i++) { y--; moveCursor(x, y); printf("#"); }
    // 왼쪽으로 8칸 그리기
    for (int i = 0; i < 8; i++) { x--; moveCursor(x, y); printf("#"); }
    // 아래로 10칸 그리기
    for (int i = 0; i < 10; i++) { y++; moveCursor(x, y); printf("#"); }
    // 오른쪽으로 10칸 그리기
    for (int i = 0; i < 10; i++) { x++; moveCursor(x, y); printf("#"); }
    // 위로 12칸 그리기
    for (int i = 0; i < 12; i++) { y--; moveCursor(x, y); printf("#"); }
    // 왼쪽으로 12칸 그리기
    for (int i = 0; i < 12; i++) { x--; moveCursor(x, y); printf("#"); }

    // 심지가 다 그려진 마지막 위치를 폭탄 위치로 정합니다.
    bomb_x = x;
    bomb_y = y;

    // 그 위치에 폭탄을 그립니다.
    moveCursor(bomb_x, bomb_y);
    printBomb(0); // ( b ) 출력

    // --- 3단계: 불꽃(*) 움직이기 ---

    // 불꽃을 움직이기 위해 x, y 위치를 처음으로 되돌립니다.
    x = 14;
    y = 9;

    // 심지를 그렸던 순서와 똑같이 따라가며 불꽃을 '나타났다 사라지게' 합니다.
    // 아래로 2칸 이동
    for (int i = 0; i < 2; i++) {
        y++; moveCursor(x, y); printf("*"); Sleep(200); moveCursor(x, y); printf(" ");
    }
    // 오른쪽으로 2칸 이동
    for (int i = 0; i < 2; i++) {
        x++; moveCursor(x, y); printf("*"); Sleep(200); moveCursor(x, y); printf(" ");
    }
    // 위로 4칸 이동
    for (int i = 0; i < 4; i++) {
        y--; moveCursor(x, y); printf("*"); Sleep(200); moveCursor(x, y); printf(" ");
    }
    // 왼쪽으로 4칸 이동
    for (int i = 0; i < 4; i++) {
        x--; moveCursor(x, y); printf("*"); Sleep(200); moveCursor(x, y); printf(" ");
    }
    // ... 나머지 경로도 같은 방식으로 반복 ...
    for (int i = 0; i < 6; i++) { y++; moveCursor(x, y); printf("*"); Sleep(200); moveCursor(x, y); printf(" "); }
    for (int i = 0; i < 6; i++) { x++; moveCursor(x, y); printf("*"); Sleep(200); moveCursor(x, y); printf(" "); }
    for (int i = 0; i < 8; i++) { y--; moveCursor(x, y); printf("*"); Sleep(200); moveCursor(x, y); printf(" "); }
    for (int i = 0; i < 8; i++) { x--; moveCursor(x, y); printf("*"); Sleep(200); moveCursor(x, y); printf(" "); }
    for (int i = 0; i < 10; i++) { y++; moveCursor(x, y); printf("*"); Sleep(200); moveCursor(x, y); printf(" "); }
    for (int i = 0; i < 10; i++) { x++; moveCursor(x, y); printf("*"); Sleep(200); moveCursor(x, y); printf(" "); }
    for (int i = 0; i < 12; i++) { y--; moveCursor(x, y); printf("*"); Sleep(200); moveCursor(x, y); printf(" "); }
    for (int i = 0; i < 12; i++) { x--; moveCursor(x, y); printf("*"); Sleep(200); moveCursor(x, y); printf(" "); }


    // --- 4단계: 폭탄 터뜨리기 ---
    moveCursor(bomb_x, bomb_y);
    printBomb(1);

    moveCursor(1, 25);
    return 0;
}