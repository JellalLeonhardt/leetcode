#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
	char board[6];
	char zero_row, zero_col;
	char step;
	struct node *next;
}Node, *pNode;
int judgeRange(int zero_row, int zero_col, int i, int j)
{
	if (zero_row + i > 1 || zero_row + i < 0 || zero_col + j > 2 || zero_col + j < 0) {
		return 0;
	}
	return 1;
}

int judge(char board[6], char target_board[6])
{
	int i, j;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 3; j++) {
			if (board[i * 3 + j] != target_board[i * 3 + j]) {
				return 0;
			}
		}
	}
	return 1;
}

void copyBoard(pNode node, char board[6], char zero_row, char zero_col, char step)
{
	int i, j;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 3; j++) {
			node->board[i * 3 + j] = board[i * 3 + j];
		}
	}
	node->zero_col = zero_col;
	node->zero_row = zero_row;
	node->step = step;
}

pNode insert(pNode head, pNode tail, pNode node)
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

int run2goal(char board[6], char target_board[6], char path_mark[6][6][6][6][6][6], int zero_row, int zero_col, int *steps, int step)
{

	int i, j;
	int cnt = 1;
	int new_row, new_col;
	char **new_board;
	Node head;
	head.next = NULL;
	pNode tail = &head, node, now;
	node = (pNode)malloc(sizeof(Node));
	copyBoard(node, board, zero_row, zero_col, step);
	tail = insert(&head, tail, node);
	while ((now = get(&head)) != NULL) {
		if (judge(now->board, target_board)) {
			*steps = now->step;
			return 1;
		}
		if (cnt > 720) {
			return 0;
		}
		new_row = now->zero_row + 0;
		new_col = now->zero_col - 1;
		if (judgeRange(now->zero_row, now->zero_col, 0, -1)) {
			node = (pNode)malloc(sizeof(Node));
			copyBoard(node, now->board, new_row, new_col, now->step + 1);
			node->board[now->zero_row * 3 + now->zero_col] = node->board[new_row * 3 + new_col];
			node->board[new_row * 3 + new_col] = 0;
			if (path_mark[node->board[0]][node->board[1]][node->board[2]][node->board[3]][node->board[4]][node->board[5]] == 0) {
				path_mark[node->board[0]][node->board[1]][node->board[2]][node->board[3]][node->board[4]][node->board[5]] = 1;
				tail = insert(&head, tail, node);
				cnt++;
			}
			else {
				free(node);
			}
		}
		new_row = now->zero_row + 0;
		new_col = now->zero_col + 1;
		if (judgeRange(now->zero_row, now->zero_col, 0, 1)) {
			node = (pNode)malloc(sizeof(Node));
			copyBoard(node, now->board, new_row, new_col, now->step + 1);
			node->board[now->zero_row * 3 + now->zero_col] = node->board[new_row * 3 + new_col];
			node->board[new_row * 3 + new_col] = 0;
			if (path_mark[node->board[0]][node->board[1]][node->board[2]][node->board[3]][node->board[4]][node->board[5]] == 0) {
				path_mark[node->board[0]][node->board[1]][node->board[2]][node->board[3]][node->board[4]][node->board[5]] = 1;
				tail = insert(&head, tail, node);
				cnt++;
			}
			else {
				free(node);
			}
		}
		new_row = now->zero_row + 1;
		new_col = now->zero_col - 0;
		if (judgeRange(now->zero_row, now->zero_col, 1, 0)) {
			node = (pNode)malloc(sizeof(Node));
			copyBoard(node, now->board, new_row, new_col, now->step + 1);
			node->board[now->zero_row * 3 + now->zero_col] = node->board[new_row * 3 + new_col];
			node->board[new_row * 3 + new_col] = 0;
			if (path_mark[node->board[0]][node->board[1]][node->board[2]][node->board[3]][node->board[4]][node->board[5]] == 0) {
				path_mark[node->board[0]][node->board[1]][node->board[2]][node->board[3]][node->board[4]][node->board[5]] = 1;
				tail = insert(&head, tail, node);
				cnt++;
			}
			else {
				free(node);
			}
		}
		new_row = now->zero_row - 1;
		new_col = now->zero_col - 0;
		if (judgeRange(now->zero_row, now->zero_col, -1, 0)) {
			node = (pNode)malloc(sizeof(Node));
			copyBoard(node, now->board, new_row, new_col, now->step + 1);
			node->board[now->zero_row * 3 + now->zero_col] = node->board[new_row * 3 + new_col];
			node->board[new_row * 3 + new_col] = 0;
			if (path_mark[node->board[0]][node->board[1]][node->board[2]][node->board[3]][node->board[4]][node->board[5]] == 0) {
				path_mark[node->board[0]][node->board[1]][node->board[2]][node->board[3]][node->board[4]][node->board[5]] = 1;
				tail = insert(&head, tail, node);
				cnt++;
			}
			else {
				free(node);
			}
		}
	}
	return 0;
}
int slidingPuzzle(int** board, int boardRowSize, int *boardColSizes) {
	char path_mark[6][6][6][6][6][6] = { 0 };
	int i, j, zero_row, zero_col;
	char new_board[6] = { 1, 2, 3,
		4, 5, 0 };
	char target_board[6];
	int steps = -1;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 3; j++) {
			target_board[i * 3 + j] = (char)board[i][j];
			if (board[i][j] == 0) {
				zero_row = i;
				zero_col = j;
			}
		}
	}
	//if (run2goal(new_board, target_board, path_mark, 1, 2, &steps, 0) == 1) printf("сп╫Б\n");
	run2goal(target_board, new_board, path_mark, zero_row, zero_col, &steps, 0);
	return steps;
}