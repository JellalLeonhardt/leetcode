#include <stdio.h>

int main()
{
    int a, b, c = 0, d;
    int i;
    for(i = 0; i < 7; i++){
        scanf("%d %d", &a, &b);
        if(a + b > c){
            c = a + b;
            d = i + 1;
        }
    }
    printf("%d", c >= 8 ? d : 0);
    return 0;
}