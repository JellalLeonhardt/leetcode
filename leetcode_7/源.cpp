#include <stdio.h>
#include <stdlib.h>
#include <limits>

int reverse(int x) {
	int result = 0;
	while (x > 0) {
		if ((INT_MAX - (x % 10)) / 10 < result) {	//重点是此处的溢出判断，如果采用 result * 10 + x % 10 < result 之类的判定方式，就会被类似main中的数字坑
			return 0;								//故而，老生常谈，要判溢出的数字，单独放在一边，另一边应该是针对临界值的操作
		}
		result = result * 10 + x % 10;
		x = x / 10;
	}
	while (x < 0) {
		if ((-INT_MAX - (x % 10)) / 10 > result) {
			return 0;
		}
		result = result * 10 + x % 10;
		x = x / 10;
	}
	return result;
}

int main()
{
	int result = reverse(1534236469);
	printf("%d\n", result);
	system("pause");
	return 0;
}