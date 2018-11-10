#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

void reorderList(struct ListNode* head)
{
	struct ListNode *h = head;
	if (head == NULL || head->next == NULL || head->next->next == NULL) {
		return;
	}
	struct ListNode *p0, *p1, *temp, *pre;
	p0 = p1 = head;
	while (p1->next != NULL) {
		p1 = p1->next;
		if (p1->next == NULL) {
			break;
		}
		p1 = p1->next;
		p0 = p0->next;
	}
	temp = p0->next;
	p0->next = NULL;
	while (temp != p1) {
		pre = temp;
		temp = temp->next;
		pre->next = p0->next;
		p0->next = pre;
	}
	temp->next = p0->next;
	p0->next = temp;
	pre = p0->next;
	p0->next = NULL;
	p0 = pre->next;
	while (p0 != NULL) {
		pre->next = head->next;
		head->next = pre;
		head = pre->next;
		pre = p0;
		p0 = p0->next;
	}
	pre->next = head->next;
	head->next = pre;
	head = pre->next;
}

int main()
{
	struct ListNode n0, n1, n2, n3, n4, n5;
	n0.val = 0;
	n1.val = 1;
	n2.val = 2;
	n3.val = 3;
	n4.val = 4;
	n0.next = &n1;
	n1.next = NULL;
	n2.next = NULL;
	n3.next = &n4;
	n4.next = NULL;
	reorderList(&n0);
	getchar();
	return 0;
}