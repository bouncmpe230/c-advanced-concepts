#include <stdio.h>

void printMessage(const char *msg) {
    // *msg = 'H'; //  ERROR: Cannot modify a const parameter
    printf("%s\n", msg);
}

int main() {
    const int x = 10;  // x is a constant
    printf("Value of x: %d\n", x);
    
    //x = 20;  //  ERROR: Assignment of read-only variable 'x'


    int a = 5, b = 10;
    int *const ptr = &a; // ptr always points to 'a'
    
    *ptr = 20;  //  Allowed: modifying value of 'a'
    // ptr = &b; //  ERROR: Changing pointer address is not allowed
    
    printf("a: %d\n", a);

    const int *ptr2 = &a; // ptr points to a constant value
    
    // *ptr2 = 20; // ERROR: Cannot modify the value at ptr
    ptr2 = &b;   //  Allowed: Changing pointer address
    
    printf("b: %d\n", *ptr2);

    char message[] = "Hello, World!";
    printMessage(message);

    return 0;
}
