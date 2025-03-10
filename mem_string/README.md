# Problem Session: Dynamic Memory Allocation, String Handling & Terminal Input in C

## Overview
This problem session covers:
- **Dynamic memory allocation (`malloc`, `calloc`, `realloc`, `free`)**
- **String handling (`strcpy`, `strncpy`, `strcmp`, `strncmp`, `strtok`, `strcat`, `strncat`, `strstr`, `strlen`)**
- **Reading from the terminal (`scanf`, `fgets`)**
- **Applying these concepts to a playlist manager (Spotify-like system)**

## 1. Dynamic Memory Allocation in C
### **1.1 Why Dynamic Memory?**
- Allows managing memory efficiently during runtime.
- Prevents memory waste compared to static arrays.
- Enables resizable data structures like linked lists and dynamic arrays.

### **1.2 Functions for Dynamic Memory**

Function prototypes: 
```c
void *malloc(size_t size);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void free(void *ptr);
``

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int size = 5;
    
    // Allocating memory using malloc
    arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Assigning values
    for (int i = 0; i < size; i++) {
        arr[i] = i * 10;
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    // Freeing memory
    free(arr);
    return 0;
}
```

### **1.3 `calloc` vs `malloc`**
```c
// calloc initializes allocated memory to 0
int *ptr = (int *)calloc(5, sizeof(int));
```
- `malloc` leaves memory uninitialized.
- `calloc` initializes memory to zero.

### **1.4 Resizing Memory with `realloc`**
```c
int *ptr = (int *)malloc(3 * sizeof(int));
ptr = (int *)realloc(ptr, 6 * sizeof(int));
```
- `realloc` resizes a previously allocated memory block.
- Ensure to check if `realloc` returns `NULL`.


## 2. String Handling in C
### **2.1 String Function Prototypes**
```c
// strcpy: Copying strings
char *strcpy(char *destination, const char *source);
// strncpy: Copying strings with length limits
char *strncpy(char *destination, const char *source, size_t num);
// strcmp: Comparing strings
int strcmp(const char *str1, const char *str2);
int strncmp(const char *str1, const char *str2, size_t num);
// strtok: Tokenizing strings
char *strtok(char *str, const char *delim);
// strcat: Concatenating strings
char *strcat(char *destination, const char *source);
char *strncat(char *destination, const char *source, size_t num);
// strstr: Searching a substring
char *strstr(const char *haystack, const char *needle);
// strcspn: Finding first occurrence of a character from a set
size_t strcspn(const char *str, const char *search);
size_t strlen(const char *str);
```

The `const` keyword in C is used to declare variables whose values cannot be changed after initialization. It helps enforce immutability, improve code safety, and prevent accidental modifications.

When a variable is declared with const, its value cannot be modified after initialization.


### **2.2 Understanding the Null Terminator (`\0`)**
- In C, strings are null-terminated, meaning the last character is always `\0`.
- This marks the end of a string and helps functions like `strlen` work correctly.

### **2.3 Common String Functions with Examples**
```c
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
```

### **2.4 Splitting a String with `strtok`**
```c
char input[] = "Coldplay - Yellow";
char *artist = strtok(input, "-");
char *title = strtok(NULL, "-");
```


## 3. Reading from Terminal
### **3.1 Using `fgets` Safely**
```c
char name[50];
printf("Enter your name: ");
fgets(name, sizeof(name), stdin);
name[strcspn(name, "\n")] = '\0';
```

### **3.1 Word Counter Using `strtok` and Terminal Input**
```c
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
```

### **3.2 Problems with `gets()` and Non-Safe String Functions**

#### **Buffer Overflow and Buffer Overrun**
- **Buffer Overflow:** Occurs when data exceeds the allocated buffer, potentially overwriting adjacent memory.
- **Buffer Overrun:** A specific type of overflow where a program writes data past the allocated memory boundary, leading to crashes or vulnerabilities.
- **Security Risks:** Attackers can exploit buffer overflows to inject malicious code or manipulate program behavior.

#### **Why `gets()` is Dangerous?**
- **`gets()` does not check for input size, leading to buffer overflows.**
- It keeps reading until a newline (`\n`) or EOF, which may overwrite critical memory.
- **Use `fgets()` instead**, which allows specifying a buffer limit to prevent overflow.

#### **Unsafe String Functions (`strcpy`, `strcat`)**
- **`strcpy(dest, src)` copies `src` into `dest`, but does not check bounds.**
- **`strcat(dest, src)` appends `src` to `dest` without checking buffer limits.**
- **Better alternatives:** Use `strncpy()` and `strncat()` to specify maximum lengths and avoid buffer overruns.

## 4. **Applying Concepts to a Playlist Manager**
### **4.1 Defining Structs**
```c
typedef struct {
    char title[100];
    char artist[100];
    int duration; // in seconds
} Song;

typedef struct {
    Song *songs;
    int count;
    int capacity;
} Playlist;
```

### **4.2 Initializing Playlist**
```c
void initPlaylist(Playlist *pl) {
    pl->count = 0;
    pl->capacity = 2;
    pl->songs = (Song *)malloc(pl->capacity * sizeof(Song));
}
```

### **4.3 Adding Songs Dynamically**
```c
void addSong(Playlist *pl, const char *title, const char *artist, int duration) {
    if (pl->count >= pl->capacity) {
        pl->capacity *= 2;
        pl->songs = (Song *)realloc(pl->songs, pl->capacity * sizeof(Song));
    }
    strcpy(pl->songs[pl->count].title, title);
    strcpy(pl->songs[pl->count].artist, artist);
    pl->songs[pl->count].duration = duration;
    pl->count++;
}
```

### **4.4 Viewing Playlist**
```c
void printPlaylist(const Playlist *pl) {
    for (int i = 0; i < pl->count; i++) {
        printf("%d. %s - %s [%d sec]\n", i + 1, pl->songs[i].title, pl->songs[i].artist, pl->songs[i].duration);
    }
}
```

### **4.5 Interactive Menu System**
```c
int main() {
    Playlist myPlaylist;
    initPlaylist(&myPlaylist);
    int choice;
    do {
        printf("\n1. Add Song\n2. View Playlist\n3. Exit\n");
        scanf("%d", &choice);
        getchar(); // Consume the newline character left in the buffer
        
        if (choice == 1) {
            char title[100], artist[100];
            int duration;
            printf("Enter song title: ");
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = '\0';
            printf("Enter artist name: ");
            fgets(artist, sizeof(artist), stdin);
            artist[strcspn(artist, "\n")] = '\0';
            printf("Enter song duration (sec): ");
            scanf("%d", &duration);
            getchar();
            addSong(&myPlaylist, title, artist, duration);
        } else if (choice == 2) {
            printPlaylist(&myPlaylist);
        }
    } while (choice != 3);
    
    free(myPlaylist.songs);
    return 0;
}
```

