#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

//差分数组
//差分数组的这种思想，有点类似与以前处理括号运算时的方法
//以前处理括号匹配时，是将左括号入栈，每有一个右括号则出栈表示匹配成功
//这里的差分数组则是用两种标记来标记首尾
//从左往右扫一遍，记录遇到的首标记的和，和大于1时表示还没有匹配完所有尾标记（即还首尾之间，也可理解为还在括号内），每遇到尾标记则将首标记和减1（就像遇到右括号后左括号出栈一样）
//首标记为0时则表示不在首位之间（不在括号内）

int main()
{
    int a, b, c, d, cnt = 0, i, mark_cnt = 0;;
	char e[10001];
	scanf("%d", &a);
	memset(e, 0, a + 1);
	scanf("%d", &b);
	for(i = 0; i < b; i++){
		scanf("%d%d", &c, &d);
		e[c]++; //加1减1是为了防止重复标记，如首部是同一个位置重复标记，而尾部是不同位置的话，则永远无法匹配
		e[d + 1]--; //d + 1是了下面写得方便
	}
	for(i = 0; i <= a; i++){
		mark_cnt += e[i];
		if(!mark_cnt){
			printf("%d\n", i);
			cnt++;
		}
	}
	printf("%d", cnt);
	system("pause");
}