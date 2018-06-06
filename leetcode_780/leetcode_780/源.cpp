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
	if (sx > tx || sy > ty) {
		return false;
	}
	Node head;
	head.next = NULL;
	pNode tail = &head, node, current;
	node = NewNode(tx, ty, NULL);
	tail = insert(&head, tail, node);
	while (head.next != NULL) {
		current = get(&head);
		if (current->y == sy && current->x == sx) {
			freeNodes(&head);
			return true;
		}
		if (current->x == sx) {
			if ((current->y - sy) % current->x == 0 && (current->y - sy) >= current->x) {
				freeNodes(&head);
				return true;
			}
			else {
				return false;
			}
		}
		if (current->y == sy) {
			if ((current->x - sx) % current->y == 0 && (current->x - sx) >= current->y) {
				freeNodes(&head);
				return true;
			}
			else {
				return false;
			}
		}
		if (current->x - current->y >= sx) {
			node = NewNode(current->x - current->y, current->y, NULL);
			tail = insert(&head, tail, node);
		}
		if (current->y - current->x >= sy) {
			current->y = current->y - current->x;
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
	printf("%d\n", reachingPoints(3, 3, 12, 9));
	printf("%d\n", reachingPoints(4, 2, 2, 4));
	printf("%d\n", reachingPoints(1, 5, 19, 5));
	printf("%d\n", reachingPoints(31, 11, 3234231, 5323423));
	system("pause");
	return 0;
}