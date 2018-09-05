#include <stdio.h>
#include <string.h>
#include <Windows.h>

char s[1000];
char s_new[2000];
int p[2000];

int Init()
{
	int len = strlen(s);
	s_new[0] = '$';
	s_new[1] = '#';
	int j = 2;

	for (int i = 0; i < len; i++)
	{
		s_new[j++] = s[i];
		s_new[j++] = '#';
	}

	s_new[j] = '\0';  // ������Ŷ

	return j;  // ���� s_new �ĳ���
}

int Manacher()
{
	int len = Init();  // ȡ�����ַ������Ȳ������ s_new ��ת��
	int max_len = -1;  // ����ĳ���

	int id;
	int mx = 0;

	for (int i = 1; i < len; i++)
	{
		if (i < mx) {
			if (p[2 * id - i] > mx - i)
				p[i] = mx - i;
			else
				p[i] = p[2 * id - i];
		}
		else
			p[i] = 1;

		while (s_new[i - p[i]] == s_new[i + p[i]])  // ����߽��жϣ���Ϊ����'$',����'\0'
			p[i]++;

		if (mx < i + p[i])
		{
			id = i;
			mx = i + p[i];
		}
		if (max_len < p[i] - 1) {
			max_len = p[i] - 1;
		}
	}

	return max_len;
}

int main() {
	sprintf(s, "abbcbbade");
	printf("%d\n", Manacher());
	system("pause");
	return 0;
}