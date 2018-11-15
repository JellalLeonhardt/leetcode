#include <stdio.h>

int main()
{
    int array[100];
    int i, j;
    for(i = 0; i < 100; i++){
        scanf("%d", &array[i]);
        if(array[i] == 0){
            break;
        }
    }
    i--;
    while(i > -1){
        printf("%d ", array[i--]);
    }
    return 0;
}