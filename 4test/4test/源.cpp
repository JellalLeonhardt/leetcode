#include <stdio.h>
#include <Windows.h>

int main()
{
	char element[] = "ABCDE";
	int i0, i1, i2, i3, i4, i5;
	i0 = 0;
		for (i1 = 0; i1 < 5; i1++) {
			for (i2 = 0; i2 < 5; i2++) {
				for (i3 = 0; i3 < 5; i3++) {
					for (i4 = 0; i4 < 5; i4++) {
						i5 = 0;
						printf("%c%c%c%c%c%c\n", element[i0], element[i1], element[i2], element[i3], element[i4], element[i5]);
					}
				}
			}
		}
	system("pause");
	return 0;
}