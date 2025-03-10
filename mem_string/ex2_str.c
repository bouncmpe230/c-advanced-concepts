#include <stdio.h>
#include <string.h>

int main() {
    char str1[50] = "Hello";
    char str2[50] = " World";
    char str3[50];

    // strcpy: Copying strings
    strcpy(str3, str1);
    printf("Copied string: %s\n", str3);

    // strncpy: Copying with length limit
    strncpy(str3, str1, 3);
    str3[3] = '\0'; // Ensuring null termination
    printf("Partially copied string: %s\n", str3);

    // strcat: Concatenating strings
    strcat(str1, str2);
    printf("Concatenated string: %s\n", str1);

    // strncat: Safe concatenation
    strncat(str3, str2, 3);
    printf("Partially concatenated: %s\n", str3);

    // strcmp: Comparing strings
    printf("Comparison result: %d\n", strcmp("apple", "banana"));

    // strncmp: Comparing with length limit
    printf("Comparison result (3 chars): %d\n", strncmp("apple", "apricot", 3));

    // strstr: Finding a substring
    char *found = strstr(str1, "World");
    if (found) {
        printf("'World' found in: %s\n", found);
    }

    // strcspn: Finding first occurrence of a character from a set
    char sentence[] = "Programming in C is fun!";
    char searchChars[] = "aeiou"; // Search for first vowel
    size_t firstVowel = strcspn(sentence, searchChars);
    printf("First vowel in \"%s\" is at index: %zu\n", sentence, firstVowel);
    
    // strlen: Getting string length
    printf("Length of str1: %lu\n", strlen(str1));

    return 0;
}