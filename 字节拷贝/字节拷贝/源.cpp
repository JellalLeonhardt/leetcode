#include <stdio.h>

#define START 0
#define END 254

unsigned char buf[END - START + 1];

int main(int args, char **argv)
{
	if (args != 3) {
		return 0;
	}
	FILE *fa = fopen(argv[1], "wb+");
	FILE *fb = fopen(argv[2], "wb+");
	fseek(fa, START, SEEK_SET);
	fseek(fb, START, SEEK_SET);

	int size = fread(buf, 1, END - START + 1, fa);
	fwrite(buf, 1, size, fb);
	fclose(fa);
	fclose(fb);
	printf("copy over");
	return 1;
}