#include <stdio.h>

int main()
{
    int a, b = 0, c = 0;
    int i;
    for(i = 0; i < 12; i++){
        scanf("%d", &a);
        b = b + 300 - a;
        if(b < 0){
            printf("%d", -(i + 1));
            return 0;
        }
        if(b / 100 > 0){
            c += b / 100;
            b = b % 100;
        }
    }
    printf("%d", b + c * 120);
    return 0;
}