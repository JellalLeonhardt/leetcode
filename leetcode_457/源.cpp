#include <stdio.h>
int add(int pnum, int *add, int numsSize, int circle_mark) {
	int res = (pnum + *add) % numsSize;
	res += (res >= 0) ? 0 : numsSize;
	*add = circle_mark;
	return res;
}

int findSafe(int *nums, int numsSize, int start, int circle_mark) {
	int i;
	for (i = 0; i < numsSize; i++) {
		if (*(nums + start) >= (numsSize + 100) && *(nums + start) <= circle_mark) {
			start = (start + 1) % numsSize;
		}
		else {
			return start;
		}
	}
	return -1;
}
bool circularArrayLoop(int* nums, int numsSize) {
	int i, *temp;
	int dir = 1, flags = 1, cnt = 0;
	int num0, num1;
	int pnum = 0;
	int circle_mark = numsSize + 100;
	if (*(nums + pnum) < 0) {
		dir = 0;
	}
	for (i = 0; i < numsSize; i++) {
		pnum = add(pnum, nums + pnum, numsSize, circle_mark);
		if ((*(nums + pnum) < 0 && dir == 1) || (*(nums + pnum) > 0 && dir == 0)) {
			flags = 0;
		}
		cnt++;
		if (*(nums + pnum) == circle_mark) {
			if (flags == 1 && cnt >= 2) {
				return true;
			}
			if ((pnum = findSafe(nums, numsSize, pnum, circle_mark)) == -1) {
				break;
			}
			if (*(nums + pnum) < 0) {
				dir = 0;
			}
			else {
				dir = 1;
			}
			circle_mark++;
			cnt = 0;
			flags = 1;
		}
		if (*(nums + pnum) >= (numsSize + 100) && *(nums + pnum) < circle_mark) {
			if ((pnum = findSafe(nums, numsSize, pnum, circle_mark)) == -1) {
				break;
			}
			if (*(nums + pnum) < 0) {
				dir = 0;
			}
			else {
				dir = 1;
			}
			circle_mark++;
			cnt = 0;
			flags = 0;
		}
	}
	return false;
}