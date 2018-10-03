#include <stdio.h>
#include <Windows.h>

char* pushDominoes(char* dominoes) {
	char *start, *end, *temp;
	int tmp;
	end = start = dominoes;
	while (*end != '\0') {
		while (*end == *start) {
			end++;
			if (*end == '\0') {
				return dominoes;
			}
		}
		if (*start == '.' && *end == 'L') {
			for (; start < end; start++) {
				*start = *end;
			}
			start++;
			end++;
		}
		else if (*start == '.' && *end == 'R') {
			start = end;
			end++;
		}
		else if (*start == 'R' && *end == '.') {
			start = end - 1;
			while (*end == '.') {
				if (*end == '\0') {
					for (; start < end; start++) {
						*start = 'R';
					}
					return dominoes;
				}
				end++;
			}
			if (*end == 'L') {
				tmp = end - start - 1;
				temp = start + tmp / 2;
				for (; start <= temp; start++) {
					*start = 'R';
				}
				if (tmp % 2) {
					temp += 2;
				}
				else {
					temp += 1;
				}
				for (start = temp; start < end; start++) {
					*start = 'L';
				}
				start++;
				end++;
			}
			else {
				for (; start < end; start++) {
					*start = 'R';
				}
				start = end;
				end++;
			}
		}
		else {
			//nothing to do
			start = end;
			end++;
		}
	}
	return dominoes;
}

int main()
{
	char s[100] = "R.";
	printf("%s\n", pushDominoes(s));
	system("pause");
	return 0;
}