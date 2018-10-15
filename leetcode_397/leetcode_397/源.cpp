#include <stdio.h>
#include <limits.h>
#include <Windows.h>

int integerReplacement(int n) {
	int cnt = 0;
	if (n == INT_MAX) { //����� Ҳ����ת����long��
		return 32;
	}
	while (n > 1) {
		if (n == 3) { // 3��ʱ����õĲ��Բ��Ǳ��4���� ֱ�Ӽ������ƱȽϿ� ԭ����û�и���λ
			return cnt + 2;
		}
		if ((n & 1) == 1) {
			if ((n & 2) == 2) {
				n++;	//����ط���������Ϊ���и���λ ����֮����������Ч
				cnt++;
				continue;
			}
			else {
				cnt++;
			}
		}
		cnt++;
		n >>= 1;
	}
	return cnt;
}

int main()
{
	printf("%d\n", integerReplacement(2147483647));
	system("pause");
	return 0;
}