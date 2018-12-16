#include <cstring>
#include <iostream>
using namespace std;
//特殊值 0 0.0 20.0 250.052 250/520 540%
int main()
{
    char num[22] = { 0 };
    char special = '\0';
    char part0[22] = { 0 };
    char part1[22] = { 0 };
    cin >> num;
    char* p = num + strlen(num) - 1;
    char* target = part0;
    while (p >= num) {
        if (*p >= '0' && *p <= '9') {
            *target++ = *p--;
        } else {
            target = part1;
            special = *p--;
        }
    }
    if (*part0 == 0)
        *part0 = '0';
    if (*part1 == 0)
        *part1 = '0';
    if (target >= part1 && target <= part1 + 20) {
        *target++ = special;
        if (special == '.') { //对特殊符号后面的部分做处理 添0 去0等
            p = part0 + strlen(part0) - 1;
            while (*p == '0')
                *p-- = 0;
            if (*part0 == 0)
                *part0 = '0';
            p = part0;
        } else if (special == '/') {
            p = part0;
            while (*p == '0')
                *p++ = 0;
        } else if (special == '%') {
            *part0 = 0;
            p = part0;
        }
        strcat(part1, p);
        p = part1;
        while (*p == '0' && *(p + 1) != special) //防止特殊符号前啥都没有
            p++;
        cout << p << endl;
    } else {
        p = part0;
        while (*p == '0')
            p++;
        if (*p != 0) //防止啥都没有
            cout << p << endl;
        else
            cout << '0' << endl;
    }
    system("pause");
    return 0;
}