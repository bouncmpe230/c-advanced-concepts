#include <stdio.h>
void modify_2d_array(int arr[3][2]){
	// this is also valid: void modify_2d_array(int arr[][2]);
	// this is invalid: void modify_2d_array(int arr[][]);
	arr[0][1] = 5;
}
int main(){
	int A[4][2] = {{1, 1}, {2, 2}, {3, 3}, {4, 4}};
	modify_2d_array(A);
	printf("%d", A[0][1]);
	return 0;
}