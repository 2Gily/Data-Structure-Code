#include <stdio.h>

void main() {
	char c, c_array[100];
	int i, i_array[100];
	short s, s_array[100];
	float f, f_array[100];
	long l, l_array[100];

	printf("\n char c 크기 = %d \t: char c_array 크기 = %4d", sizeof(c), sizeof(c_array));
	printf("\n int i 크기 = %d \t: int i_array 크기 = %4d", sizeof(i), sizeof(i_array));
	printf("\n short s 크기 = %d \t: short s_array 크기 = %4d", sizeof(s), sizeof(s_array));
	printf("\n float f 크기 = %d \t: float f_array 크기 = %4d", sizeof(f), sizeof(f_array));
	printf("\n long l 크기 = %d \t: long l_array 크기 = %4d", sizeof(l), sizeof(l_array));

	getchar();  // 실행 창이 닫히지 않게 하기 위해 편의상 추가한 입력 대기 명령
}