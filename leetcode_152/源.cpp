#include <stdio.h>
#include <limits.h>

void getMax(int *nums, int numsSize, int *max)
{
	int i, j, temp, zero_flag = 0;
	for (i = 0; i < numsSize - 1; i++) {
		if (nums[i] == 0) {
			zero_flag = 1;
			getMax(nums + i + 1, numsSize - (i + 1), max);
			numsSize = i;
			break;
		}
		nums[i + 1] = nums[i] * nums[i + 1];
	}
	for (i = 0; i < numsSize; i++) {
		if (nums[i] > *max) *max = nums[i];
		for (j = i + 1; j < numsSize; j++) {
			temp = nums[j] / nums[i];
			if (temp > *max) *max = temp;
		}
	}
	if (zero_flag) {
		if (*max < 0) {
			*max = 0;
		}
	}
}

int maxProduct(int* nums, int numsSize)
{
	int max = -INT_MAX;
	getMax(nums, numsSize, &max);
	return max;
}