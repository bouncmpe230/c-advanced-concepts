#include <stdio.h>
int main()
{
	int (*p)[5]; // pointer to an array[5] of int
	int B[2][2];
	p = B;
	//p = (int (*)[5]) B;
	return 0;
}