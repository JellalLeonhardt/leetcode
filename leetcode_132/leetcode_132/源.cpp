#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int judge(char *h, char *t, char **pal_table, char *s)
{
	if (*t != *h) {
		return false;
	}
	char *head = h, *tail = t;
	if (pal_table[h - s] == t) {
		return true;
	}
	while (t - h >= 2) {
		if (*t != *h) {
			return false;
		}
		t--;
		h++;
	}
	if (h == t - 1) {
		if (*h == *t) {
			if(tail - pal_table[head - s] > 0) pal_table[head - s] = tail;
			return true;
		}
		return false;
	}
	if(tail - pal_table[head - s] > 0) pal_table[head - s] = tail;
	return true;
}

int find(char *head, char *tail, char *s, char **pal_table)
{
	if (judge(head, tail, pal_table, s)) {
		return 0;
	}
	int cur = 0;
	int min = INT_MAX;
	char *e = tail;
	for (; tail - head >= 0; tail--) {
		if (judge(head, tail, pal_table, s)) {
			cur = find(tail + 1, e, s, pal_table);
 			if (cur + 1 < min) {
				min = cur + 1;
			}
		}
	}
	return min;
}

int minCut(char *s)
{
	char *tail = s;
	int length = 0;
	while(*tail++ != '\0') length++;
	char **pal_table = (char **)malloc(sizeof(char *) * length);//»ØÎÄ±í
	memset(pal_table, 0, sizeof(char *) * length);
	tail = tail - 2;
	char *e = tail;
	if (judge(s, e, pal_table, s)) {
		return 0;
	}
	int min = INT_MAX, cur;
	for (; tail - s >= 0; tail--) {
		if (judge(s, tail, pal_table, s)) {
			cur = find(tail + 1, e, s, pal_table);
			if (cur + 1 < min) {
				min = cur + 1;
			}
		}
	}
	return min;
}

int main()
{
	char s[] = "apjesgpsxoeiokmqmfgvjslcjukbqxpsobyhjpbgdfruqdkeiszrlmtwgfxyfostpqczidfljwfbbrflkgdvtytbgqalguewnhvvmcgxboycffopmtmhtfizxkmeftcucxpobxmelmjtuzigsxnncxpaibgpuijwhankxbplpyejxmrrjgeoevqozwdtgospohznkoyzocjlracchjqnggbfeebmuvbicbvmpuleywrpzwsihivnrwtxcukwplgtobhgxukwrdlszfaiqxwjvrgxnsveedxseeyeykarqnjrtlaliyudpacctzizcftjlunlgnfwcqqxcqikocqffsjyurzwysfjmswvhbrmshjuzsgpwyubtfbnwajuvrfhlccvfwhxfqthkcwhatktymgxostjlztwdxritygbrbibdgkezvzajizxasjnrcjwzdfvdnwwqeyumkamhzoqhnqjfzwzbixclcxqrtniznemxeahfozp";
	//printf("%d\n", judge(s, s + 1));
	printf("%d\n", minCut(s));
	getchar();
	return 0;
}