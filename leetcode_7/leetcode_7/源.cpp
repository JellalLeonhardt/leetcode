#include <stdio.h>
#include <stdlib.h>
#include <limits>

int reverse(int x) {
	int result = 0;
	while (x > 0) {
		if ((INT_MAX - (x % 10)) / 10 < result) {	//�ص��Ǵ˴�������жϣ�������� result * 10 + x % 10 < result ֮����ж���ʽ���ͻᱻ����main�е����ֿ�
			return 0;								//�ʶ���������̸��Ҫ����������֣���������һ�ߣ���һ��Ӧ��������ٽ�ֵ�Ĳ���
		}
		result = result * 10 + x % 10;
		x = x / 10;
	}
	while (x < 0) {
		if ((-INT_MAX - (x % 10)) / 10 > result) {
			return 0;
		}
		result = result * 10 + x % 10;
		x = x / 10;
	}
	return result;
}

int main()
{
	int result = reverse(1534236469);
	printf("%d\n", result);
	system("pause");
	return 0;
}