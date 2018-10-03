#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <Windows.h>

//int minMutation(char* start, char* end, char** bank, int bankSize) {
//	char change_to[8];
//	char change_from[8];
//	memset(change_to, 0, 8);
//	memset(change_from, 0, 8);
//	int i;
//	for (i = 0; i < 8; i++) {
//		if (start[i] != end[i]) {
//			change_to[i] = end[i];
//			change_from[i] = start[i];
//		}
//	}
//	
//}

typedef struct NODE {
	char *str;
	int cnt;
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

pNode NewNode(char *str, int cnt, pNode next)
{
	pNode node = (pNode)malloc(sizeof(Node));
	node->str = str;
	node->cnt = cnt;
	node->next = next;
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
	int *mark = (int *)malloc(sizeof(int) * bankSize);
	memset(mark, 0, sizeof(int) * bankSize);
	int i, min = INT_MAX, target;
	Node head;
	head.next = NewNode(start, 0, NULL);
	pNode tail = head.next;
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
			if (mark[i] == 0) {
				if (compare(node->str, bank[i]) == 1) {
					if (i == target) {
						if (node->cnt + 1 < min) {
							min = node->cnt + 1;
						}
					}
					else {
						node = NewNode(bank[i], node->cnt + 1, NULL);
						tail = insert(&head, tail, node);
					}
				}
			}
		}
	}
	if (min < INT_MAX) {
		return min;
	}
	return -1;
}

#define BANKSIZE 3

int main()
{
	char start[100] = "AACCGGTT";
	char end[100] = "AAACGGTA";
	char bank[BANKSIZE][100] = { "AACCGGTA", "AACCGCTA", "AAACGGTA" };
	char **BANK = (char **)malloc(sizeof(char *) * BANKSIZE);
	int i;
	for (i = 0; i < BANKSIZE; i++) {
		BANK[i] = (char *)malloc(sizeof(char) * 100);
		memcpy(BANK[i], bank[i], 100);
	}
	printf("%d\n", minMutation(start, end, BANK, BANKSIZE));
	system("pause");
}