#include <stdio.h>
#include <Windows.h>

int main()
{
    int a, cnt = 1;
	int array[16] = {0, 2, 4, 11, 31, 83, 227, 616, 1674, 4550, 12367, 33617, 91380, 248397, 675214, 1835421};
    scanf("%d", &a);
    printf("%d", array[a]);
	system("pause");
}