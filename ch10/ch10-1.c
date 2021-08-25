#include <stdio.h>
typedef int element;

void sequentialSearch1(element a[], int n, int key) {
	int i = 0;
	printf("\n %d를 검색하라! ->> ", key);
	while (i<n && a[i] != key) i++;
	if (i<n) printf("%d 번째에 검색 성공! \n\n", i + 1);
	else   printf("%d번째에 검색 실패! \n\n", i + 1);
}

void main() {
	element a[] = { 8, 30, 1, 9, 11, 19, 2 };
	int n = 7;

	sequentialSearch1(a, n, 9);  // 배열 a의 n개 원소 중에서 탐색키가 9인 원소 검색
	sequentialSearch1(a, n, 6);  // 배열 a의 n개 원소 중에서 탐색키가 6인 원소 검색

	getchar();
}