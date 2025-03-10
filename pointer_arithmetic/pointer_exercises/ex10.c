#include <stdio.h>
void modify_2d_array(int (*p)[2]){ // pointer to array[2] of int
	p[0][1] = 5;
}

// void modify_2d_array(int *p[2]){ // array[2] of pointer to int
// 	p[0][1] = 5;
// }

int main(){
	int A[4][2] = {{1, 1}, {2, 2}, {3, 3}, {4, 4}};
	modify_2d_array(A);
	// printf("%d", A[0][1]);
	int i, j;
	for(i = 0; i < 4; i++){
		for(j = 0; j <2; j++){
		printf("%d\n", A[i][j]);
		}
	}
	return 0;
}