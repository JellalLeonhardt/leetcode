#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

//简单粗暴版本

int main()
{
    int a, b, c[100], d[100], cnt = 0, i;
	char e[10001];
	scanf("%d", &a);
	memset(e, 0xff, a + 1);
	scanf("%d", &b);
	for(i = 0; i < b; i++){
		scanf("%d%d", &c[i], &d[i]);
	}
	for(i = 0; i < b; i++){
		memset(e + c[i], 0, d[i] - c[i] + 1);//不包括当前位置
	}
	for(i = 0; i <= a; i++){
		if(e[i] != 0){
			cnt++;
		}
	}
	printf("%d", cnt);
	system("pause");
}