#include <stdio.h>

int main()
{
    int a, i, cnt = 1;
    long long up = 1, down = 1;
    scanf("%d", &a);
    up = a - 1;
    while(up >= 0){
        cnt++;
        if(up == 0){
            break;
        }
        up = up * cnt - down;
        down = down * cnt;
        if(!down % up){
            up =  1;
            down = down / up;
        }
        printf("%lld/%lld\n", up, down);
    }
    printf("%d", cnt);
}