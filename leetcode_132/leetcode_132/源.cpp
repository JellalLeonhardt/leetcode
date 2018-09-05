#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pal_node {
	char *start, *end;
	struct pal_node *next;
}pal_node, *pal_p;

int judge(char *h, char *t)
{
	while (t - h >= 2) {
		if (*t != *h) {
			return false;
		}
		t--;
		h++;
	}
	if (h == t - 1) {
		if (*h == *t) {
			return true;
		}
		return false;
	}
	return true;
}

void insert(pal_p head, char *start, char *end)
{
	pal_p pre = head;
	head = head->next;
	while (head) {
		if (head->start <= start && end <= head->end) {
			return;
		}
		else if (start <= head->start && head->end <= end) {
			break;
		}
		else if (start <= head->start && end <= head->end) {
			if (end - start > head->end - head->start) {
				head->start = start;
				head->end = end;
			}
			return;
		}
		else if (head->start <= start && head->end <= end) {
			break;
		}
		pre = head;
		head = head->next;
	}
	if (head == NULL) {

		return;
	}
	pal_p cur = head;
	pal_p cur_pre = pre;
	while (head) {
		if (end < head->start) {
			pal_p temp = cur;
			int length = 0;
			while (temp != head) {
				length += temp->start - temp->end;
				temp = temp->next;
			}
			if (length < end - start) {
				pal_node node;
				node.start = start;
				node.end = end;
				node.next = head;
				cur_pre->next = &node;
				for (pre = cur, cur = cur->next; cur != head; pre = cur, cur = cur->next) {
					free(pre);
				}
				free(pre);
			}
			return;
		}
		else if (end < head->end) {
			pal_p temp = cur;
			int length = 0;
			while (temp != head) {
				length += temp->start - temp->end;
				temp = temp->next;
			}
			length += temp->start - temp->end;
			temp = temp->next;
			if (length < end - start) {
				pal_node node;
				node.start = start;
				node.end = end;
				node.next = temp;
				cur_pre->next = &node;
				for (pre = cur, cur = cur->next; cur != temp; pre = cur, cur = cur->next) {
					free(pre);
				}
				free(pre);
			}
			return;
		}
		else {
			pre = head;
			head = head->next;
		}
	}
	pal_p temp = cur;
	int length = 0;
	while (temp != head) {
		length += temp->start - temp->end;
		temp = temp->next;
	}
	if (length < end - start) {
		pal_node node;
		node.start = start;
		node.end = end;
		node.next = head;
		cur_pre->next = &node;
		for (pre = cur, cur = cur->next; cur != head; pre = cur, cur = cur->next) {
			free(pre);
		}
		free(pre);
	}
	return;
}

int minCut(char *s)
{
	char *tail = s, *head = s;
	int length = 0;
	while (*tail++ != '\0') length++;
	tail = tail - 2;
	char *e = tail;
	if (judge(s, e)) {
		return 0;
	}
	pal_node pal_head = {0, 0, NULL};
	for (; head <= e; head++) {
		for (tail = head; tail <= e; tail++) {
			if (judge(head, tail)) {
				insert(&pal_head, head, tail);
			}
		}
	}
	pal_p temp = &pal_head;
	for (; temp != NULL; temp = temp->next) {
		length -= temp->start - temp->end;
	}
	return length;
}

int main()
{
	//char s[] = "apjesgpsxoeiokmqmfgvjslcjukbqxpsobyhjpbgdfruqdkeiszrlmtwgfxyfostpqczidfljwfbbrflkgdvtytbgqalguewnhvvmcgxboycffopmtmhtfizxkmeftcucxpobxmelmjtuzigsxnncxpaibgpuijwhankxbplpyejxmrrjgeoevqozwdtgospohznkoyzocjlracchjqnggbfeebmuvbicbvmpuleywrpzwsihivnrwtxcukwplgtobhgxukwrdlszfaiqxwjvrgxnsveedxseeyeykarqnjrtlaliyudpacctzizcftjlunlgnfwcqqxcqikocqffsjyurzwysfjmswvhbrmshjuzsgpwyubtfbnwajuvrfhlccvfwhxfqthkcwhatktymgxostjlztwdxritygbrbibdgkezvzajizxasjnrcjwzdfvdnwwqeyumkamhzoqhnqjfzwzbixclcxqrtniznemxeahfozp";
	char s[] = "helllo";
	//printf("%d\n", judge(s, s + 1));
	printf("%d\n", minCut(s));
	getchar();
	return 0;
}