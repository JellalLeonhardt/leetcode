#include <stdio.h>
#include <stdlib.h>

int judge(int A, int L, int R)
{
	if (A < L) {
		return 0;
	}
	if (A >= L && R >= A) {
		return 1;
	}
	return 2;
}

int combinationNum(int number)
{
	return ((1 + number) * number / 2);
}
int numSubarrayBoundedMax(int* A, int ASize, int L, int R)
{
	int i;
	int total = 0, invalid = 0, invalid_cnt = 0, cnt = 0;
	for (i = 0; i < ASize; i++) {
		switch (judge(A[i], L, R)) {
		case 0:
			invalid_cnt++;
			cnt++;
			break;
		case 1:
			invalid += combinationNum(invalid_cnt);
			invalid_cnt = 0;
			cnt++;
			break;
		case 2:
			invalid += combinationNum(invalid_cnt);
			total += (combinationNum(cnt) - invalid);
			invalid = invalid_cnt = cnt = 0;
			break;
		default:
			return -1;
		}
	}
	invalid += combinationNum(invalid_cnt);
	total += (combinationNum(cnt) - invalid);
	return total;
}

int main()
{
	//int A[] = { 2, 1, 4, 3 };
	int A[] = { 6,4,6,3,2,1,5,6,8,9,6,4,3,5,6,4,6,7,11,2,4,23,21 };
	int ASize = sizeof(A) / sizeof(A[0]);
	printf("%d\n", numSubarrayBoundedMax(A, ASize, 4, 8));
	system("pause");
	return 0;
}