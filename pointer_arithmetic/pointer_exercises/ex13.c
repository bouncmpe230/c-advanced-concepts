#include <stdio.h>
int main(){
	int A[4][2] = {{1, 1}, {2, 2}, {3, 3}, {4, 4}};
	int (*p)[2] = A;
	printf("%d", *(p+1));
	printf("%d", *(*(p+1)));
	return 0;
}