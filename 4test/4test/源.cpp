#include <stdio.h>

int main()
{
	char test[] = "rchar: 1  2		3      4";
	char r[21];
	int int1, int2, int3, int4;
	sscanf(test, "%s%d%d%d%d", r, &int1, &int2, &int3, &int4);
	printf("%s %d %d %d %d\n", r, int1, int2, int3, int4);
	getchar();
	return 0;
}