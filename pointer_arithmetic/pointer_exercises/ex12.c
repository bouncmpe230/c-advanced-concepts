#include <stdio.h>
int main(){
	int A[4][2] = {{1, 1}, {2, 2}, {3, 3}, {4, 4}};
	int *p[2];
	p[0] = A[0];
	p[1] = A[2];
	printf("%d", *(*(p+1)));
	return 0;
}