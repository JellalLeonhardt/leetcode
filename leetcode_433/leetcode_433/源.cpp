#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <Windows.h>

typedef struct NODE {
	char *str;
	int cnt;
	int *mark;
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
		free(realese->mark);
		free(realese);
	}
}

pNode NewNode(char *str, int cnt, pNode next, int size)
{
	pNode node = (pNode)malloc(sizeof(Node));
	node->str = str;
	node->cnt = cnt;
	node->next = next;
	node->mark = (int *)malloc(size);
	memset(node->mark, 0, size);
	return node;
}

int compare(char *from, char* to) {
	int i, cnt = 0;
	for (i = 0; i < 8; i++) {
		if (from[i] != to[i]) {
			cnt++;
			if (cnt > 1) {
				return 0;
			}
		}
	}
	if (cnt == 0) {
		return 0;
	}
	return 1;
}

int minMutation(char* start, char* end, char** bank, int bankSize)
{
	int size = sizeof(int) * bankSize;
	int i, min = INT_MAX, target;
	Node head;
	head.next = NewNode(start, 0, NULL, size);
	pNode tail = head.next, temp;
	for (i = 0; i < bankSize; i++) {
		if (strcmp(end, bank[i]) == 0) {
			target = i;
			break;
		}
	}
	while (head.next != NULL) {
		pNode node = get(&head);
		if (node == NULL) {
			break;
		}
		for (i = 0; i < bankSize; i++) {
			if (node->mark[i] == 0) {
				if (compare(node->str, bank[i]) == 1) {
					if (i == target) {
						if (node->cnt + 1 < min) {
							min = node->cnt + 1;
						}
					}
					else {
						temp = NewNode(bank[i], node->cnt + 1, NULL, size);
						tail = insert(&head, tail, temp);
						memcpy(temp->mark, node->mark, size);
						temp->mark[i] = 1;
					}
				}
			}
		}
		free(node->mark);
		free(node);
	}
	if (min < INT_MAX) {
		return min;
	}
	return -1;
}

#define BANKSIZE 8

int main()
{
	char start[9] = "AAAACCCC";
	char end[9] = "CCCCCCCC";
	char bank[BANKSIZE][9] = { "AAAACCCA","AAACCCCA","AACCCCCA","AACCCCCC","ACCCCCCC","CCCCCCCC","AAACCCCC","AACCCCCC" };
	char **BANK = (char **)malloc(sizeof(char *) * BANKSIZE);
	int i;
	for (i = 0; i < BANKSIZE; i++) {
		BANK[i] = (char *)malloc(sizeof(char) * 9);
		memcpy(BANK[i], bank[i], 9);
	}
	printf("%d\n", minMutation(start, end, BANK, BANKSIZE));
	system("pause");
}