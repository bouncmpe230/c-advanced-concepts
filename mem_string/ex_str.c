#include <stdio.h>
#include <string.h>

int main() {
    char str1[50] = "Hello";
    char str2[50] = "World";
    char str3[100];

    // Compare two strings
    if (strcmp(str1, str2) == 0) {
        printf("The strings are equal.\n");
    } else {
        printf("The strings are not equal.\n");
    }

    // Copy one string to another
    strcpy(str3, str1);
    printf("String 1: %s\n", str1);
    printf("String 3: %s\n", str3);

    // Concatenate two strings
    strcat(str3, str2);
    printf("String 3 after concatenation: %s\n", str3);

    return 0;
}