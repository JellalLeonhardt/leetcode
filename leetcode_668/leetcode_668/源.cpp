#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

int getNumUnder(int min, int max, int num)
{
	int i, MAX, temp_result, result = 0;
	if (num <= max) {
		MAX = num;
	}
	else {
		MAX = max;
	}
	for (i = 1; i <= MAX; i++) {
		temp_result = num / i;
		result += (temp_result > min) ? min : temp_result;
	}
	return result;
}

int findKthNumber(int m, int n, int k)
{
	int min = (m > n) ? n : m, max = (m > n) ? m : n;
	int i, j;
	int MAX = m * n;
	int current_result = -1;
	int low = 1, high = MAX;
	while (current_result != k || (high - low) >= 1) {
		current_result = getNumUnder(min, max, (low + high) / 2);
		if (current_result < k) {
			low = (low + high) / 2 + 1;
		}
		else if (current_result >= k) {
			high = (low + high) / 2;
		}
		if (low == high && current_result != k) {
			current_result = getNumUnder(min, max, low);
			if (current_result >= k && k > getNumUnder(min, max, low - 1)) {
				return low;
			}
			else {
				return low + 1;
			}
			return low;
		}
	}
	return (low + high) / 2;
}

void print_table(int m, int n, int num, ...)
{
	int i, j, k;
	HANDLE hdl = GetStdHandle(STD_OUTPUT_HANDLE);
	va_list valist;
	va_start(valist, num);
	int *result = (int *)malloc(num * sizeof(int));
	int *target = (int *)malloc(num * sizeof(int));
	for (i = 0; i < num; i++) {
		target[i] = va_arg(valist, int);
		result[i] = findKthNumber(m, n, target[i]);
	}
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			for (k = 0; k < num; k++) {
				if (i * j == result[k]) {
					SetConsoleTextAttribute(hdl, FOREGROUND_RED | FOREGROUND_INTENSITY);
					printf("%d\t", i * j);
					SetConsoleTextAttribute(hdl, FOREGROUND_INTENSITY - 1);
					k = num;
					continue;
				}
				if (k == num - 1) {
					printf("%d\t", i * j);
				}
			}
		}
		printf("\n");
	}
	printf("\n\n\n");
}
int main()
{
	print_table(3, 3, 1, 5);
	print_table(42, 34, 1, 401);
	system("pause");
	return 0;
}