#include <stdlib.h>
#include <stdio.h>

int judge(int A, int B, int C, int D)
{
	if (A <= C) {
		if (B <= D) {
			return 0;
		}
		else {
			return 1;
		}
	}
	else {
		if (B <= D) {
			return 2;
		}
		else {
			return 3;
		}
	}
}
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
	int stat;
	int a, b, c, d;
	switch (judge(C, D, E, F)) {
	case 0:
	case 1:
	case 2:
		return (C - A) * (D - B) + (G - E) * (H - F);
	case 3:
		stat = judge(A, B, G, H);
		if (stat == 3 || stat == 2 || stat == 1) {
			return (C - A) * (D - B) + (G - E) * (H - F);
		}
		else {
			switch (judge(A, B, E, F)) {
			case 0:
				a = E;
				b = F;
				break;
			case 1:
				a = E;
				b = B;
				break;
			case 2:
				a = A;
				b = F;
				break;
			case 3:
				a = A;
				b = B;
				break;
			default:
				return 0;
			}
			switch (judge(C, D, G, H)) {
			case 0:
				c = C;
				d = D;
				break;
			case 3:
				c = G;
				d = H;
				break;
			case 1:
				c = C;
				d = H;
				break;
			case 2:
				c = G;
				d = D;
				break;
			default:
				return 0;
			}
			return (C - A) * (D - B) + (G - E) * (H - F) - (c - a) * (d - b);
		}
	default:
		return 0;
	}
}

int main()
{
	//printf("%d\n", computeArea(-3, 0, 3, 4, 0, -1, 9, 2));
	//printf("%d\n", computeArea(-3, 0, 74, 12, 43, 11, 93, 72));
	printf("%d\n", computeArea(-2, -2, 2, 2, 1, -3, 3, -1));
	system("pause");
	return 0;
}