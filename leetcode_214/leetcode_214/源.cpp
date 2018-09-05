#include <stdio.h>

char* shortestPalindrome(char* s) {
	char *max_position = s;
	char *p = s;
	char *tmp0, *tmp1;
	while (*(p++) != '\0') {
		if (*p == *s) {
			tmp0 = s;
			tmp1 = p;
			while (*(tmp0++) == *(tmp1--)) {
				if (tmp0 > tmp1) {
					max_position = p;
				}
			}
		}
	}
	p = p - 2;
	int len = p - max_position + p - s + 2;
	int cnt = 0;
	char *result = (char *)malloc(sizeof(char) * len);
	for (tmp1 = p; tmp1 > max_position; tmp1--) {
		result[cnt++] = *tmp1;
	}
	for (tmp0 = s; tmp0 <= p; tmp0++) {
		result[cnt++] = *tmp0;
	}
	result[cnt++] = 0;//foolish me
	return result;
}