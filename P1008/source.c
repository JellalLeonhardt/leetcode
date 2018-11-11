#include <stdio.h>
#include <string.h>

int main()
{
    int i, j;
    char num[10];
    for(i = 100; i < 1000; i++){
        memset(num, 0, 10);
        num[0] = 1;
        if(i * 2 < 1000 && i * 3 < 1000){
            j = i;
            if(num[j % 10]){
                continue;
            }
            else{
                num[j % 10] = 1;
            }
            j = j / 10;
            if(num[j % 10]){
                continue;
            }
            else{
                num[j % 10] = 1;
            }
            j = j / 10;
            if(num[j % 10]){
                continue;
            }
            j = i * 2;
            if(num[j % 10]){
                continue;
            }
            else{
                num[j % 10] = 1;
            }
            j = j / 10;
            if(num[j % 10]){
                continue;
            }
            else{
                num[j % 10] = 1;
            }
            j = j / 10;
            if(num[j % 10]){
                continue;
            }
            else{
                num[j % 10] = 1;
            }
            j = i * 3;
            if(num[j % 10]){
                continue;
            }
            else{
                num[j % 10] = 1;
            }
            j = j / 10;
            if(num[j % 10]){
                continue;
            }
            else{
                num[j % 10] = 1;
            }
            j = j / 10;
            if(num[j % 10]){
                continue;
            }
            else{
                num[j % 10] = 1;
            }
            printf("%d %d %d\n", i, i * 2, i * 3);
        }
    }
    return 0;
}