#include <stdio.h>
struct ListNode {	//�˽ṹ��Ϊԭ�ж��壬�˴���Ϊ���ֳ������
	int val;
	struct ListNode *next;
};
struct ListNode* oddEvenList(struct ListNode* head)
{
	struct ListNode even_head;
	even_head.next = NULL;
	struct ListNode *even = &even_head;
	struct ListNode *pre = head;
	if (head == NULL) return NULL;
	struct ListNode *node = head->next;
	int i = 0;
	while (node != NULL) {
		if (i % 2 == 0) {
			even->next = node;
			even = even->next;
			pre->next = node->next;
			node = node->next;
		}
		else {
			pre = node;
			node = node->next;
		}
		i++;
	}
	pre->next = even_head.next;
	even->next = NULL;
	return head;
}