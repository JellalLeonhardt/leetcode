#include <Windows.h>
#include <stdio.h>

int main()
{
    char word[51], word0[51];
    char *p, *p0;
    int offset = 'a' - 'A';
    int cnt = 0, num = 0;
    int position = -1;
    scanf("%[^\n\x20]%[^A-Za-z]", word, word0);
    p0 = word0;
    int cnt0;
    while (*p0 != 0) {
        if (*p0++ == ' ')
            cnt++;
    }
    while (scanf("%[^\x20\n]%*[\x20]", word0) > 0) { // %s -> %[^\040\n]%*[\040] 否则会出现理由不明的阻塞，感觉是剩了一个\n没有读取到，而那个\n导致了再次读取%s时被阻塞或者异常
        p = word;
        p0 = word0;
        cnt0 = cnt;
        while ((*p != 0) && (*p0 != 0)) {
            cnt++;
            if (!(*p == *p0 || (*p0 <= 'Z' && *p == (*p0) + offset) || (*p0 >= 'a' && (*p) + offset == *p0))) {
                while (*p0 != 0) {
                    p0++;
                    cnt++;
                }
                break;
            }
            p++;
            p0++;
        }
        if (*p == 0 && *p0 == 0) {
            num++;
            if (position == -1)
                position = cnt0;
        }
    }
    if (position == -1)
        printf("-1");
    else
        printf("%d %d", num, position);
    system("pause");
    return 0;
}