#include <stdio.h>

int main()
{
    int a, b0, c0, b1, c1, b2, c2, d = -1, e = 0;
    scanf("%d", &a);
    scanf("%d%d", &b0, &c0);
    scanf("%d%d", &b1, &c1);
    scanf("%d%d", &b2, &c2);
    d = !(a % b0) ? a / b0 : a / b0 + 1;
    e = d * c0;
    d = !(a % b1) ? a / b1 : a / b1 + 1;
    if(d * c1 < e) e = d * c1;
    d = !(a % b2) ? a / b2 : a / b2 + 1;
    if(d * c2 < e) e = d * c2;
    printf("%d", e);
    return 0;
}