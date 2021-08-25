#include <stdio.h>
typedef int element;
int size;

// 부분집합에 대해 셸 정렬을 수행하는 연산
void intervalSort(element a[], int begin, int end, int interval) {
	int i, j;
	element item;
	for (i = begin + interval; i <= end; i = i + interval) {
		item = a[i];
		for (j = i - interval; j >= begin && item<a[j]; j = j - interval)
			a[j + interval] = a[j];
		a[j + interval] = item;
	}
}

void shellSort(int a[], int size) {
	int i, t, interval;
	printf("\n정렬할 원소 : ");
	for (t = 0; t<size; t++)  printf("%d ", a[t]);
	printf("\n\n<<<<<<<<<< 셸 정렬 수행 >>>>>>>>>>\n");
	interval = size / 2;
	while (interval >= 1) {
		for (i = 0; i<interval; i++)  intervalSort(a, i, size - 1, interval);
		printf("\n interval=%d >> ", interval);
		for (t = 0; t<size; t++) printf("%d ", a[t]);
		printf("\n");
		interval = interval / 2;
	}
}

void main() {
	int list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	size = 8;

	shellSort(list, size);

	getchar();
}