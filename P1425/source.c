#include <stdio.h>

int main()
{
    int a, b, c, d, e, f;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    f = ((c * 60) + d) - ((a * 60) + b);
    e = f / 60;
    f = f % 60;
    printf("%d %d", e, f);
    return 0;
}