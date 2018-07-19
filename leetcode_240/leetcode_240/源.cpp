#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWSIZE 5
#define COLSIZE 5

typedef struct point_t {
	int x, y, value;
	struct point_t *next;
}point_t, *point;

point newPoint(int x, int y, int value)
{
	point temp = (point)malloc(sizeof(point_t));
	temp->x = x;
	temp->y = y;
	temp->value = value;
	temp->next = NULL;
	return temp;
}

void insert(point *tail, point node)
{
	(*tail)->next = node;
	(*tail) = node;
}

point get(point head, point *tail)
{
	point temp = head->next;
	if (temp == NULL) {
		return NULL;
	}
	head->next = head->next->next;
	if (temp == *tail) {
		*tail = head;
	}
	return temp;
}

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
	if (matrixRowSize == 0 || matrixColSize == 0) {
		return false;
	}
	if (target == matrix[0][0] || target == matrix[matrixRowSize - 1][matrixColSize - 1]) {
		return true;
	}
	int x, y;
	x = matrixRowSize / 2;
	y = matrixColSize / 2;
	point_t head;
	head.next = newPoint(x, y, matrix[x][y]);
	point tail = head.next;
	point now;
	while ((now = get(&head, &tail)) != NULL) {
		if (target == now->value) {
			return true;
		}
		else if (target > now->value) {
			if (now->x + 1 < matrixRowSize && matrix[now->x + 1][now->y] != INT_MAX) {
				insert(&tail, newPoint(now->x + 1, now->y, matrix[now->x + 1][now->y]));
				matrix[now->x + 1][now->y] = INT_MAX;
			}
			if (now->y + 1 < matrixColSize && matrix[now->x][now->y + 1] != INT_MAX) {
				insert(&tail, newPoint(now->x, now->y + 1, matrix[now->x][now->y + 1]));
				matrix[now->x][now->y + 1] = INT_MAX;
			}
		}
		else {
			if (now->x >= 1 && matrix[now->x - 1][now->y] != INT_MAX) {
				insert(&tail, newPoint(now->x - 1, now->y, matrix[now->x - 1][now->y]));
				matrix[now->x - 1][now->y] = INT_MAX;
			}
			if (now->y >= 1 && matrix[now->x][now->y - 1] != INT_MAX) {
				insert(&tail, newPoint(now->x, now->y - 1, matrix[now->x][now->y - 1]));
				matrix[now->x][now->y - 1] = INT_MAX;
			}
		}
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