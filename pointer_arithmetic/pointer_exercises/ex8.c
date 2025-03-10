#include <stdio.h>
void modify_array(int arr[5]){
	int i;
	for(i = 0; i < 5; i++){
	arr[i] *= 2;
	}
}
int main(){
	int A[5] = {1, 2, 3, 4, 5};
	int i;
	modify_array(A);
	for(i = 0; i < 5; i++){
	printf("%d\n", *(A+i));
	}
	return 0;
}