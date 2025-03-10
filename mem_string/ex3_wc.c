#include <stdio.h>
#include <string.h>

int main() {
    char input[500];
    printf("Enter a sentence (type 'exit' to quit):\n");
    
    while (1) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove newline
        
        if (strcmp(input, "exit") == 0) {
            printf("Exiting program.\n");
            break;
        }
        
        int wordCount = 0;
        char *token = strtok(input, " ");
        while (token != NULL) {
            wordCount++;
            token = strtok(NULL, " ");
        }
        
        printf("Word count: %d\n", wordCount);
    }
    return 0;
}