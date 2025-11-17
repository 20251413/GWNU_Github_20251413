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

int custom_max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

int main() {
	char student_id[20];
	char student_name[50];

	printf("학번을 입력하세요: ");
	scanf_s("%s", student_id, sizeof(student_id));

	printf("이름을 입력하세요: ");
	scanf_s("%s", student_name, sizeof(student_name));

	FILE* output_file;
	if (fopen_s(&output_file, "Test.txt", "w") != 0) {
		printf("오류: 'Test.txt' 파일을 열 수 없습니다.\n");
		return 1;
	}

	fprintf(output_file, "%s : %s\n", student_id, student_name);

	Student students[10];
	FILE* input_file;
	if (fopen_s(&input_file, "student.csv", "r") != 0) {
		printf("오류: 'student.csv' 파일을 찾을 수 없습니다.\n");
		fprintf(output_file, "오류: 'student.csv' 파일을 찾을 수 없습니다.\n");
		fclose(output_file);
		return 1;
	}

	char header_buffer[1024];
	fgets(header_buffer, sizeof(header_buffer), input_file);

	int read_count = 0;
	while (read_count < 10) {
		int result = fscanf_s(input_file, "%s[^,],%d,%d,%d\n",
		students[read_count].name,
		sizeof(students[read_count].name),
		&students[read_count].attack,
		&students[read_count].defense,
		&students[read_count].hp);

		if (result == 4)
		{
			read_count++;
		}
		else
		{
			break;
		}
	}

	fclose(input_file);

	if (read_count != 10) {
		printf("오류: 'students.csv'에서 10명의 데이터를 읽는 데 실패했습니다. (읽은 수: %d)/n", read_count);
		fprintf(output_file, "오류: 'students.csv' 파일 형식 오류 또는 데이터 부족.\n");
		fclose(output_file);
		return 1;
	}

	int max_atk_index = 0;
	for (int i = 1; i < 10; i++) {
		if (students[i].attack > students[max_atk_index].attack) {
			max_atk_index = i;
		}
	}

	fprintf(output_file, "가장 공격력이 높은 사람: %s (ATK=%d)\n",
		students[max_atk_index].name,
		students[max_atk_index].attack);

	fprintf(output_file, "세번째: %s HP=%d\n",
		students[2].name,
		students[2].hp);
	fprintf(output_file, "여덟번째: %s HP=%d\n",
		students[7].name,
		students[7].hp);

	int hp_player3 = students[2].hp;
	int hp_player3 = students[2].hp;

	int damege_3 = custom_max(0, students[7].attack - students[2].defence);
	int damege_8 = custom_max(0, students[2].attack - students[7].defence);

	if (damege_3 == 0 && damege_8 == 0) {
		fprintf(output_file, "3번째 vs 8번째: 무승부\n");
	}
	else if (hp_player3 <= 0) {
		fprintf(output_file, "3번째 vs 8번째 승자: %s\n", students[7].name);
	}
	else {
		fprintf(output_file, "3번째 vs 8번째 승자: %s\n", students[2].name);
	}

	fprintf(output_file, "교수님 시험문제 너무 쉽습니다. 담주에 더 어렵게 내주세요\n");

	fclose(output_file);
	printf("성공: 'Test.txt' 파일이 정상적으로 생성되었습니다.\n");

	return 0;
}