/*
#include <stdio.h>
#include <math.h>
#include <Windows.h>

#define PI 3.14159226535897

void moveCursor(int x, int y)
{
    printf("\x1b[%d;%dH", y, x);
}

//�Ű����� isExploded
//0: ������ ��ź
//1: ������
void printBomb(int isExploded)
{
    //��ź�� �׻� 7ĭ
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
    // ������� �ڵ带 �ۼ��ϼ���----------------------   
    int path_x[100], path_y[100];
    int x = 14, y = 9; // '*'�� ���� ��ġ
    int count = 0;
    int length = 2;

    // 2. ��û�� ��Ģ�� ���� ���� ��� ���
    path_x[count] = x;
    path_y[count] = y;
    count++;

    while (length <= 12) {
        // �Ʒ��� �̵�
        for (int i = 0; i < length; i++) { y++; path_x[count] = x; path_y[count] = y; count++; }
        // ���������� �̵�
        for (int i = 0; i < length; i++) { x++; path_x[count] = x; path_y[count] = y; count++; }
        length += 2;
        // ���� �̵�
        for (int i = 0; i < length; i++) { y--; path_x[count] = x; path_y[count] = y; count++; }
        // �������� �̵�
        for (int i = 0; i < length; i++) { x--; path_x[count] = x; path_y[count] = y; count++; }
        length += 2;
    }

    // 3. �ʱ� ������ ��ź �׸���
    int fuse_end_x = path_x[count - 1];
    int fuse_end_y = path_y[count - 1];

    // �ڡڡ� ���� ����: ��ź ��ġ�� �������� 3ĭ �߰� �̵� �ڡڡ�
    int bomb_x = fuse_end_x - 7;
    int bomb_y = fuse_end_y;

    // ����('#') ��ü�� ���� �׸��ϴ�.
    for (int i = 1; i < count; i++) {
        moveCursor(path_x[i], path_y[i]);
        printf("#");
    }

    // ������ �� �׷��� ��, �� ���� �и��� ��ġ�� ��ź�� �׸��ϴ�.
    moveCursor(bomb_x, bomb_y);
    printBomb(0); // ( b ) ���

    // 4. �Ҳ��� ������ �¿�� �ִϸ��̼�
    for (int i = 0; i < count; i++) {
        if (i > 0) {
            moveCursor(path_x[i - 1], path_y[i - 1]);
            printf(" ");
        }
        moveCursor(path_x[i], path_y[i]);
        printf("*");
        Sleep(200);
    }

    // 5. ��ź ����
    moveCursor(fuse_end_x, fuse_end_y);
    printf(" ");
    Sleep(200);
    moveCursor(bomb_x, bomb_y);
    printBomb(1);
    // ������� �ڵ带 �ۼ��ϼ���----------------------   
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

//�Ű����� isExploded
//0: ������ ��ź
//1: ������
void printBomb(int isExploded)
{
    //��ź�� �׻� 7ĭ
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
    int x = 14;     // �Ҳ��� ���۵� x ��ġ
    int y = 9;      // �Ҳ��� ���۵� y ��ġ
    int bomb_x = 0; // ���߿� ��ź�� ���� x ��ġ
    int bomb_y = 0; // ���߿� ��ź�� ���� y ��ġ

    system("cls"); // ȭ���� �����ϰ� ����ϴ�.

    // --- 2�ܰ�: ����(#) �׸��� ---
    // for �ݺ����� ������� ���󰡸� ������ �׸��ϴ�.

    // �Ʒ��� 2ĭ �׸���
    for (int i = 0; i < 2; i++) { y++; moveCursor(x, y); printf("#"); }
    // ���������� 2ĭ �׸���
    for (int i = 0; i < 2; i++) { x++; moveCursor(x, y); printf("#"); }
    // ���� 4ĭ �׸���
    for (int i = 0; i < 4; i++) { y--; moveCursor(x, y); printf("#"); }
    // �������� 4ĭ �׸���
    for (int i = 0; i < 4; i++) { x--; moveCursor(x, y); printf("#"); }
    // �Ʒ��� 6ĭ �׸���
    for (int i = 0; i < 6; i++) { y++; moveCursor(x, y); printf("#"); }
    // ���������� 6ĭ �׸���
    for (int i = 0; i < 6; i++) { x++; moveCursor(x, y); printf("#"); }
    // ���� 8ĭ �׸���
    for (int i = 0; i < 8; i++) { y--; moveCursor(x, y); printf("#"); }
    // �������� 8ĭ �׸���
    for (int i = 0; i < 8; i++) { x--; moveCursor(x, y); printf("#"); }
    // �Ʒ��� 10ĭ �׸���
    for (int i = 0; i < 10; i++) { y++; moveCursor(x, y); printf("#"); }
    // ���������� 10ĭ �׸���
    for (int i = 0; i < 10; i++) { x++; moveCursor(x, y); printf("#"); }
    // ���� 12ĭ �׸���
    for (int i = 0; i < 12; i++) { y--; moveCursor(x, y); printf("#"); }
    // �������� 12ĭ �׸���
    for (int i = 0; i < 12; i++) { x--; moveCursor(x, y); printf("#"); }

    // ������ �� �׷��� ������ ��ġ�� ��ź ��ġ�� ���մϴ�.
    bomb_x = x;
    bomb_y = y;

    // �� ��ġ�� ��ź�� �׸��ϴ�.
    moveCursor(bomb_x, bomb_y);
    printBomb(0); // ( b ) ���

    // --- 3�ܰ�: �Ҳ�(*) �����̱� ---

    // �Ҳ��� �����̱� ���� x, y ��ġ�� ó������ �ǵ����ϴ�.
    x = 14;
    y = 9;

    // ������ �׷ȴ� ������ �Ȱ��� ���󰡸� �Ҳ��� '��Ÿ���� �������' �մϴ�.
    // �Ʒ��� 2ĭ �̵�
    for (int i = 0; i < 2; i++) {
        y++; moveCursor(x, y); printf("*"); Sleep(200); moveCursor(x, y); printf(" ");
    }
    // ���������� 2ĭ �̵�
    for (int i = 0; i < 2; i++) {
        x++; moveCursor(x, y); printf("*"); Sleep(200); moveCursor(x, y); printf(" ");
    }
    // ���� 4ĭ �̵�
    for (int i = 0; i < 4; i++) {
        y--; moveCursor(x, y); printf("*"); Sleep(200); moveCursor(x, y); printf(" ");
    }
    // �������� 4ĭ �̵�
    for (int i = 0; i < 4; i++) {
        x--; moveCursor(x, y); printf("*"); Sleep(200); moveCursor(x, y); printf(" ");
    }
    // ... ������ ��ε� ���� ������� �ݺ� ...
    for (int i = 0; i < 6; i++) { y++; moveCursor(x, y); printf("*"); Sleep(200); moveCursor(x, y); printf(" "); }
    for (int i = 0; i < 6; i++) { x++; moveCursor(x, y); printf("*"); Sleep(200); moveCursor(x, y); printf(" "); }
    for (int i = 0; i < 8; i++) { y--; moveCursor(x, y); printf("*"); Sleep(200); moveCursor(x, y); printf(" "); }
    for (int i = 0; i < 8; i++) { x--; moveCursor(x, y); printf("*"); Sleep(200); moveCursor(x, y); printf(" "); }
    for (int i = 0; i < 10; i++) { y++; moveCursor(x, y); printf("*"); Sleep(200); moveCursor(x, y); printf(" "); }
    for (int i = 0; i < 10; i++) { x++; moveCursor(x, y); printf("*"); Sleep(200); moveCursor(x, y); printf(" "); }
    for (int i = 0; i < 12; i++) { y--; moveCursor(x, y); printf("*"); Sleep(200); moveCursor(x, y); printf(" "); }
    for (int i = 0; i < 12; i++) { x--; moveCursor(x, y); printf("*"); Sleep(200); moveCursor(x, y); printf(" "); }


    // --- 4�ܰ�: ��ź �Ͷ߸��� ---
    moveCursor(bomb_x, bomb_y);
    printBomb(1);

    moveCursor(1, 25);
    return 0;
}