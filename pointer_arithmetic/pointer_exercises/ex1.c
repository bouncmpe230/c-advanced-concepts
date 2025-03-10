#include <stdio.h>
// https://www.geeksforgeeks.org/pointer-arithmetics-in-c-with-examples/
int main(){
	int x;
	// Integer variable
	int N = 4;
	// Pointer to an integer
	int *ptr1, *ptr2;
	// Pointer stores the address of N
	ptr1 = &N;
	ptr2 = &N;
	// Incrementing ptr2 by 3
	ptr2 = ptr2 + 3;
	// Subtraction of ptr2 and ptr1
	x = ptr2 - ptr1;
	// Print x to get the Increment
	// between ptr1 and ptr2
	printf("Subtraction of ptr1 & ptr2 is %d\n", x);
	char *ptr3, *ptr4;
	ptr3 = (char *) ptr1;
	ptr4 = (char *) ptr2;
	printf("Subtraction of ptr4 & ptr3 is %d\n", ptr4 - ptr3);
	return 0;
}