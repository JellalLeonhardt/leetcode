#include <stdio.h>
#include <Windows.h>

int main()
{
    double a, b = 0, c = 2;
	int cnt = 0;
	scanf("%lf", &a);
	while(b < a){
		b += c;
		c *= 0.98;
		cnt++;
	}
	printf("%d", cnt);
	system("pause");
}