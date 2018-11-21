#include <Windows.h>
#include <stdio.h>

int main()
{
    long long a = 1, b = 1;
    char A[8], B[8];
    int i;
    scanf("%s", A);
    scanf("%s", B);
    for (i = 0; i < 6; i++) {
        if (A[i] >= 'A' && A[i] <= 'Z')
            a *= (A[i] - 'A' + 1);
        if (B[i] >= 'A' && B[i] <= 'Z')
            b *= (B[i] - 'A' + 1);
    }
    if (a % 47 == b % 47) {
        printf("GO");
    } else {
        printf("STAY");
    }
    system("pause");
    return 0;
}