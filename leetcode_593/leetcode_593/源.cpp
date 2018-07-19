#include <stdio.h>
#include <Windows.h>
#include <math.h>

/*bool validSquare(int* p1, int p1Size, int* p2, int p2Size, int* p3, int p3Size, int* p4, int p4Size)
{
	int *P0, *P1, *P2, *P3, *temp;
	if (abs(p1[0] - p2[0]) == abs(p3[0] - p4[0]) && abs(p1[1] - p2[1]) == abs(p3[1] - p4[1])) {
		P0 = p1;
		P3 = p2;
		P1 = p3;
		P2 = p4;
	}
	else if (abs(p1[0] - p3[0]) == abs(p2[0] - p4[0]) && abs(p1[1] - p3[1]) == abs(p2[1] - p4[1])) {
		P0 = p1;
		P3 = p3;
		P1 = p2;
		P2 = p4;
	}
	else if (abs(p1[0] - p4[0]) == abs(p2[0] - p3[0]) && abs(p1[1] - p4[1]) == abs(p2[1] - p3[1])) {
		P0 = p1;
		P3 = p4;
		P1 = p2;
		P2 = p3;
	}
	else {
		return false;
	}
	if ((P0[0] - P1[0]) * (P0[0] - P1[0]) + (P0[1] - P1[1]) * (P0[1] - P1[1]) > (P0[0] - P2[0]) * (P0[0] - P2[0]) + (P0[1] - P2[1]) * (P0[1] - P2[1])) {
		temp = P1;
		P1 = P2;
		P2 = temp;
	}
	int angle_size = (P0[0] - P2[0]) * (P0[0] - P2[0]) + (P0[1] - P2[1]) * (P0[1] - P2[1]);
	int size1 = (P0[0] - P1[0]) * (P0[0] - P1[0]) + (P0[1] - P1[1]) * (P0[1] - P1[1]);
	int size2 = (P0[0] - P3[0]) * (P0[0] - P3[0]) + (P0[1] - P3[1]) * (P0[1] - P3[1]);
	if (angle_size - size1 == size2) {
		return true;
	}
	else {
		return false;
	}
}*/

bool validSquare(int* p1, int p1Size, int* p2, int p2Size, int* p3, int p3Size, int* p4, int p4Size)
{
	if ((p1[0] == p3[0]) && (p1[0] == p2[0]) && (p1[0] == p4[0])) {
		return false;
	}
	if ((p1[1] == p3[1]) && (p1[1] == p2[1]) && (p1[1] == p4[1])) {
		return false;
	}
	int n0 = (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
	int n1 = (p4[0] - p3[0]) * (p4[0] - p3[0]) + (p4[1] - p3[1]) * (p4[1] - p3[1]);
	int m0 = (p1[0] - p3[0]) * (p1[0] - p3[0]) + (p1[1] - p3[1]) * (p1[1] - p3[1]);
	int m1 = (p4[0] - p2[0]) * (p4[0] - p2[0]) + (p4[1] - p2[1]) * (p4[1] - p2[1]);
	int l0 = (p1[0] - p4[0]) * (p1[0] - p4[0]) + (p1[1] - p4[1]) * (p1[1] - p4[1]);
	int l1 = (p3[0] - p2[0]) * (p3[0] - p2[0]) + (p3[1] - p2[1]) * (p3[1] - p2[1]);
	if (n0 == n1 && m0 == m1 && l0 == l1 && (n0 == m0 || n0 == l0 || m0 == l0)) {
		return true;
	}
	return false;
}

int main()
{
	int p1[] = {0, 0};
	int p2[] = {5, 0};
	int p3[] = {5, 4};
	int p4[] = {0, 4};
	printf("%s\n", validSquare(p1, 2, p2, 2, p3, 2, p4, 2) ? "true" : "false");
	system("pause");
}