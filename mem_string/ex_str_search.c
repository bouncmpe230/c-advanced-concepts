#include <stdio.h>
#include <string.h>

int main() {
    char text[] = "Hello, world! Welcome to C programming.";
    char *word = "world";
    
    char *found = strstr(text, word);  // Find "world"
    
    if (found) {
        size_t pos = strcspn(found, ".,!?");  // Find first punctuation
        printf("Word \"%s\" found at: %ld, first punctuation at: %zu\n", word, found - text, pos);
    } else {
        printf("Word not found.\n");
    }
    
    return 0;
}
