#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

char* shortestPalindrome(char* s) {
	if (s == NULL) return NULL;
	int len = strlen(s);
	char *result = (char *)malloc(sizeof(char) * (len * 2 + 1));
	char *p = s + len - 1;
	int cnt = 1;
	result[0] = *p;
	while (p-- > s) {
		result[cnt++] = *p;
	}
	result[cnt] = 0;
	int i;
	for (i = 0; result[i] != 0; i++) {
		if (strncmp(&result[i], s, cnt - i) == 0) {
			break;
		}
	}
	p = s + cnt - i;
	strcpy(&result[cnt], p);
	result[len + i] = 0;
	return result;
}

int main() {
	printf("%s\n", shortestPalindrome("abacde"));
	system("pause");
	return 0;
}