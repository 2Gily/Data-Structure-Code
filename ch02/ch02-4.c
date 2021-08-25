#include <stdio.h>

void main() {
	char str[20] = "Data Structure!";
	int i;
	printf("\n문자 배열 str[] : ");
	for (i = 0; str[i]; i++) {
		printf("%c", str[i]);
	}
	getchar();
}