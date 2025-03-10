#include <stdio.h>
#include <ctype.h>

// Grouping integral constants
typedef enum {
    TOKEN_TYPE_NUMBER,
    TOKEN_TYPE_OPERATOR,
    TOKEN_TYPE_FUNCTION
} TokenType;

// Grouping variables
typedef struct {
    TokenType type;
    char value[64];
} Token;

Token get_first_integer(char *input){ 
 	Token token;
    int i = 0;
    while (isspace(input[i])) {
        i++;
    }
    if (isdigit(input[i])) {
        token.type = TOKEN_TYPE_NUMBER;
        int j = 0;
        while (isdigit(input[i])) {
            token.value[j] = input[i];
            i++;
            j++;
        }
        token.value[j] = '\0';
    }
    return token; 
}

int main()
{
	char line[100] = "100 200";

	Token x = get_first_integer(line);
	printf("%s", x.value);
	
	return 0;
}