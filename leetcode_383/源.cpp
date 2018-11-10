#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool canConstruct(char* ransomNote, char* magazine) {
	int p = 0;
	int m;
	int length = strlen(magazine) + 1;
	char *marks = (char *)malloc(length * sizeof(char));
	memset(marks, 0, length);
	while (*(ransomNote + p) != '\0') {
		m = 0;
		while (*(magazine + m) != '\0') {
			if (*(magazine + m) == *(ransomNote + p) && marks[m] == 0) {
				p++;
				marks[m] = 1;
				break;
			}
			m++;
		}
		if (*(magazine + m) == '\0') {
			return false;
		}
	}
	return true;
}

int main()
{
	printf("%d\n", canConstruct("aa", "acb"));
	return 0;
}