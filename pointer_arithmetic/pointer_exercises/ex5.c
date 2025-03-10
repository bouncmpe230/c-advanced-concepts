#include <stdio.h>
int main()
{
	int (*p)[5]; // pointer to an array[5] of int
	int A[3][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};
	p = A;


	printf("%d\n", (*(p+1))[1]);
	printf("%p\n", p[0]);
	printf("%p\n", p+1);
	printf("%d\n", *(p[0]));
	printf("%d\n", *(p[0]+1));
	printf("%d\n", p[2][1]);
	//printf("%d\n", *(*(p+2)+1));
	return 0;
}