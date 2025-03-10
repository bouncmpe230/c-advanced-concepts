#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
   char str[100], new_str[100];
   char original[100];
   int i;
   
   printf("Enter a string: ");
   fgets(str, sizeof(str), stdin);
   strcpy(original, str);
   strcpy(new_str, "");
   
   char* token = strtok(str, " ");
   while(token != NULL) {
      token[0] = toupper(token[0]);
      strcat(new_str, token);
      strcat(new_str, " ");
      token = strtok(NULL, " ");
   }

   printf("Original string: %s", original);
   printf("String in title case: %s", new_str);

   return 0;
}
