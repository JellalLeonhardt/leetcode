#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE {
	int index;
}Node;

void push(Node *stack, Node node, int *top, int MAX)
{
	if (*top == MAX) {
		return;
	}
	stack[*top] = node;
	*top = *top + 1;
}

Node pop(Node *stack, int *top)
{
	Node temp;
	if (*top == 0) {
		temp.index = -1;
		return temp;
	}
	*top = *top - 1;
	return stack[*top];
}

bool search4temp(int **result, int *temp, int *columnSizes, int temp_size, int returnSize)
{
	int i, j, k;
	int *tar = (int *)malloc(sizeof(int) * temp_size);
	for (i = 0; i < returnSize; i++) {
		if (columnSizes[i] != temp_size) {
			continue;
		}
		memcpy(tar, result[i], sizeof(int) * temp_size);
		for (j = 0; j < temp_size; j++) {
			for (k = 0; k < temp_size; k++) {
				if (tar[k] == temp[j]) {
					tar[k] = 0;
					break;
				}
			}
			if (k == temp_size) {
				break;
			}
		}
		if (j == temp_size) {
			free(tar);
			return true;
		}
	}
	free(tar);
	return false;
}

void temp2result(int *temp, int temp_size, int ***result, int **columnSizes, int *returnSize, int *MAX_COLUMN)
{
	if ((*returnSize) == (*MAX_COLUMN)) {
		(*MAX_COLUMN) = (*MAX_COLUMN) * 2;
		(*result) = (int **)realloc((*result), sizeof(int *) * (*MAX_COLUMN));
		(*columnSizes) = (int *)realloc((*columnSizes), sizeof(int) * (*MAX_COLUMN));
	}
	(*result)[*returnSize] = (int *)malloc(sizeof(int) * temp_size);
	memcpy((*result)[*returnSize], temp, sizeof(int) * temp_size);
	(*columnSizes)[*returnSize] = temp_size;
	(*returnSize)++;
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize)
{
	(*returnSize) = 0;
	int MAX_COLUMN = candidatesSize / 2 + 1;
	int temp_size = 0, temp_total;
	int **result = (int **)malloc(sizeof(int*) * MAX_COLUMN);
	(*columnSizes) = (int *)malloc(sizeof(int) * MAX_COLUMN);
	int *temp = (int *)malloc(sizeof(int) * candidatesSize);
	int i, j;
	int MAX = candidatesSize;
	Node *stack = (Node *)malloc(MAX * sizeof(Node));
	int top, index;
	Node node;
	for (i = 0; i < candidatesSize; i++) {
		top = 0;
		temp_total = 0;
		index = i;
		while (1) {
			temp_total += candidates[index];
			if (temp_total > target) {
				if (top == 0) {
					break;
				}
				temp_total -= candidates[index];
				index = index + 1;
				if (index >= candidatesSize) {
					if (top == 1) {
						break;
					}
					node = pop(stack, &top);
					temp_total -= candidates[node.index];
					index = node.index + 1;
					if (index >= candidatesSize) {
						if (top == 1) {
							break;
						}
						node = pop(stack, &top);
						temp_total -= candidates[node.index];
						index = node.index + 1;
					}
				}
				continue;
			}
			else if (temp_total == target) {
				node.index = index;
				push(stack, node, &top, MAX);
				temp_size = 0;
				for (j = 0; j < top; j++) {
					node = stack[j];
					temp[temp_size++] = candidates[node.index];
				}
				if (!search4temp(result, temp, *columnSizes, temp_size, *returnSize)) {
					temp2result(temp, temp_size, &result, columnSizes, returnSize, &MAX_COLUMN);
				}
				if (top == 1) {
					break;
				}
				node = pop(stack, &top);
				temp_total -= candidates[node.index];
				index = node.index + 1;
				if (index >= candidatesSize) {
					if (top == 1) {
						break;
					}
					node = pop(stack, &top);
					temp_total -= candidates[node.index];
					index = node.index + 1;
				}
				continue;
			}
			node.index = index;
			push(stack, node, &top, MAX);
			if (index == candidatesSize - 1) {
				if (top == 1) {
					break;
				}
				node = pop(stack, &top);
				temp_total -= candidates[node.index];
				index = node.index + 1;
				if (index >= candidatesSize) {
					if (top == 1) {
						break;
					}
					node = pop(stack, &top);
					temp_total -= candidates[node.index];
					index = node.index + 1;
				}
			}
			else {
				index = index + 1;
			}
		}
	}
	if ((*returnSize) < MAX_COLUMN) {
		result = (int **)realloc(result, sizeof(int *) * (*returnSize));
		(*columnSizes) = (int *)realloc((*columnSizes), sizeof(int) * (*returnSize));
	}
	return result;
}

int main()
{
	int candidates[] = { 3,1,3,5,1,1 };
	int	target = 8;
	int returnSize;
	int *columnSizes;
	int **result = combinationSum2(candidates, sizeof(candidates) / sizeof(int), target, &columnSizes, &returnSize);
	int i, j;
	for (i = 0; i < returnSize; i++) {
		for (j = 0; j < columnSizes[i]; j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
	system("pause");
}