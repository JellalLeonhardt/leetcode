#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWSIZE 5
#define COLSIZE 5

bool searchMatrix(int** arr, int rows, int cols, int target) {
	int r = rows - 1;
	int c = 0;

	while (r >= 0 && c < cols)
	{
		if (arr[r][c] == target)
			return true;
		if (target > arr[r][c])
			c++;
		else
			r--;
	}
	return false;
}

int main()
{
	int MATRIX[ROWSIZE][COLSIZE]=
	{
		1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25
	};
	int **matrix, i, target = 5;
	matrix = (int **)malloc(sizeof(int *) * ROWSIZE);
	for (i = 0; i < ROWSIZE; i++) {
		matrix[i] = &MATRIX[i][0];
	}
	printf("%s\n", searchMatrix(matrix, ROWSIZE, COLSIZE, 21) ? "true" : "false");
	getchar();
	return 0;
}