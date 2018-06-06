#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define print_red(format, param) \
	HANDLE _hdl = GetStdHandle(STD_OUTPUT_HANDLE); \
	SetConsoleTextAttribute(_hdl, FOREGROUND_RED | FOREGROUND_INTENSITY); \
	printf(format, param); \
	SetConsoleTextAttribute(_hdl, FOREGROUND_INTENSITY - 1);

typedef struct NODE {
	int x, y;
	unsigned char flag;
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
		temp.x = -1;
		temp.y = -1;
		return temp;
	}
	*top = *top - 1;
	return stack[*top];
}

bool reachingPoints(int sx, int sy, int tx, int ty)
{
	int MAX = ((tx > ty) ? tx : ty) / ((sx > sy) ? sy : sx);
	Node *stack = (Node *)malloc(MAX * sizeof(Node));
	int top = 0;
	Node node;
	node.x = sx;
	node.y = sy;
	node.flag = 1;
	push(stack, node, &top, MAX);
	while (1) {
		while (1) {
			if (node.x == tx && node.y == ty) {
				return true;
			}
			if (node.flag) {
				if (node.x <= tx - node.y) {
					node.x = node.x + node.y;
					node.flag = 0;
					push(stack, node, &top, MAX);
				}
				else {
					break;
				}
			}
			else {
				if (node.y <= ty - node.x) {
					node.y = node.x + node.y;
					node.flag = 1;
					push(stack, node, &top, MAX);
				}
				else {
					break;
				}
			}
		}
		while (1) {
			node = pop(stack, &top);
			if (node.x == -1) {
				return false;
			}
			if (node.flag) {
				if (node.y <= ty - node.x) {
					node.y = node.x + node.y;
					push(stack, node, &top, MAX);
					break;
				}
			}
			else {
				if (node.x <= tx - node.y) {
					node.x = node.x + node.y;
					push(stack, node, &top, MAX);
					break;
				}
			}
		}
	}
	return false;
}

int main()
{
	printf("%d\n", reachingPoints(31, 13, 323423, 524313));
	printf("%d\n", reachingPoints(1, 1, 3, 5));
	system("pause");
	return 0;
}