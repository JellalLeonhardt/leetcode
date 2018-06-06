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
	struct NODE *next;
}Node, *pNode;

pNode insert(pNode head, pNode tail, pNode node)	//¸³Öµ¸øtail
{
	if (head->next == NULL) {
		head->next = node;
		node->next = NULL;
		return node;
	}
	tail->next = node;
	node->next = NULL;
	return node;
}

pNode get(pNode head) {
	pNode temp;
	if (head->next != NULL) temp = head->next;
	else return NULL;
	head->next = head->next->next;
	return temp;
}

void freeNodes(pNode head) {
	pNode realese, temp;
	temp = head->next;
	while (temp != NULL) {
		realese = temp;
		temp = temp->next;
		free(realese);
	}
}

pNode NewNode(int x, int y, pNode next)
{
	pNode node = (pNode)malloc(sizeof(Node));
	node->x = x;
	node->y = y;
	node->next = next;
	return node;
}
bool reachingPoints(int sx, int sy, int tx, int ty) {
	Node head;
	head.next = NULL;
	pNode tail = &head, node, current;
	node = NewNode(sx, sy, NULL);
	tail = insert(&head, tail, node);
	while (head.next != NULL) {
		current = get(&head);
		if (current->x == tx && current->y == ty) {
			freeNodes(&head);
			return true;
		}
		if (current->x <= tx - current->y) {
			node = NewNode(current->x + current->y, current->y, NULL);
			tail = insert(&head, tail, node);
		}
		if (current->x <= ty - current->y) {
			current->y = current->x + current->y;
			current->next = NULL;
			tail = insert(&head, tail, current);
		}
		else {
			free(current);
		}
	}
	freeNodes(&head);
	return false;
}

int main()
{
	printf("%d\n", reachingPoints(1, 1, 3, 5));
	system("pause");
	return 0;
}