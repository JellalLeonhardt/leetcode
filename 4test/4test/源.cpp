#include <stdio.h>

typedef int (*func)(char *s);
int func1(char *s);

func func0;

int func1(char *s)
{
	return 0;
}

int main()
{
	func0 = &func1;
	printf("%d\n", (*func0)("hello"));
	char test[] = "rchar: 1  2		3      4";
	char r[21];
	int int1, int2, int3, int4;
	sscanf(test, "%s%d%d%d%d", r, &int1, &int2, &int3, &int4);
	printf("%s %d %d %d %d\n", r, int1, int2, int3, int4);
	int a = 0x7fffffff;
	int b = 0xffffffff;
	printf("%d\n", a);
	printf("%d\n\n", b);
	getchar();
	return 0;
}