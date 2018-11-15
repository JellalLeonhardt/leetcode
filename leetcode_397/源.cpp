#include <stdio.h>
#include <limits.h>
#include <Windows.h>

int integerReplacement(int n) {
	int cnt = 0;
	if (n == INT_MAX) { //防溢出 也有人转换成long做
		return 32;
	}
	while (n > 1) {
		if (n == 3) { // 3的时候最好的策略不是变成4右移 直接减后右移比较快 原因是没有更高位
			return cnt + 2;
		}
		if ((n & 1) == 1) {
			if ((n & 2) == 2) {
				n++;	//这个地方更快是因为还有更高位 加了之后右移能有效
				cnt++;
				continue;
			}
			else {
				cnt++;
			}
		}
		cnt++;
		n >>= 1;
	}
	return cnt;
}

int main()
{
	printf("%d\n", integerReplacement(2147483647));
	system("pause");
	return 0;
}