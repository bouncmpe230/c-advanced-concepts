# File Input / Output in C

C provides a standard library of functions for handling file input and output. 

File I/O can be done in **text mode** or **binary mode** depending on the file's content.


## Open / Close Files

### `fopen()`
Opens a file with a specified mode (`"r"`, `"w"`, `"a"`, `"rb"`, etc.).

```c
FILE *fp = fopen("example.txt", "w");  // Open for writing
if (fp == NULL) {
    perror("File opening failed");
}
```

### `fclose()`
Closes the file.

```c
fclose(fp);
```

---

## Character/Formatted Read/Write

---

### `fgets()`
Reads a string (line) from a file, including newline.

```c
char line[100];
FILE *fp = fopen("example.txt", "r");
fgets(line, sizeof(line), fp);  // Reads a line
printf("Line: %s", line);
fclose(fp);
```

---

### `fputs()`
Writes a string to a file (without adding newline).

```c
FILE *fp = fopen("example.txt", "w");
fputs("Hello, file!\n", fp);  // Writes string
fclose(fp);
```

---

### `fscanf()`
Reads formatted input from a file, similar to `scanf`.

```c
int age;
char name[50];
FILE *fp = fopen("example.txt", "r");
fscanf(fp, "%s %d", name, &age);  // e.g., "Alice 25"
printf("Name: %s, Age: %d\n", name, age);
fclose(fp);
```

---

### `fprintf()`
Writes formatted output to a file, similar to `printf`.

```c
FILE *fp = fopen("example.txt", "w");
fprintf(fp, "Name: %s, Age: %d\n", "Alice", 25);
fclose(fp);
```

---

### `gets()` *(Deprecated – use `fgets()` instead!)*
Reads a string from stdin, but it's **unsafe**. Shown here just for completeness.

```c
char name[50];
gets(name);  // ⚠️ Unsafe: may cause buffer overflow
printf("You entered: %s\n", name);
```

---

### `puts()`
Writes a string to stdout with a newline.

```c
puts("Hello, world!");  // Equivalent to printf("Hello, world!\n");
```

---

## Binary Read/Write

---

### `fread()`
Reads binary data into memory.

```c
typedef struct {
    int id;
    float score;
} Record;

FILE *fp = fopen("data.bin", "rb");
Record r;
fread(&r, sizeof(Record), 1, fp);  // Read one record
printf("ID: %d, Score: %.2f\n", r.id, r.score);
fclose(fp);
```

---

### `fwrite()`
Writes binary data from memory to a file.

```c
Record r = {1, 98.5};
FILE *fp = fopen("data.bin", "wb");
fwrite(&r, sizeof(Record), 1, fp);  // Write one record
fclose(fp);
```

---

### `fseek()`
Moves the file pointer to a specific byte.

```c
FILE *fp = fopen("example.txt", "r");
fseek(fp, 5, SEEK_SET);  // Move to the 6th byte
char ch = fgetc(fp);
printf("Char at position 6: %c\n", ch);
fclose(fp);
```

---

### `rewind()`
Moves the file pointer back to the beginning.

```c
FILE *fp = fopen("example.txt", "r");
fseek(fp, 10, SEEK_SET);  // Move forward
rewind(fp);               // Go back to start
char ch = fgetc(fp);
printf("First char: %c\n", ch);
fclose(fp);
```

---

## Example

Here's a combined mini project demonstrating both **text** and **binary** file operations:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
} Person;

int main() {
    // --- TEXT FILE ---
    FILE *textFile = fopen("people.txt", "w");
    fprintf(textFile, "Alice 30\nBob 25\n");
    fclose(textFile);

    textFile = fopen("people.txt", "r");
    char name[50];
    int age;
    printf("Text file contents:\n");
    while (fscanf(textFile, "%s %d", name, &age) != EOF) {
        printf("Name: %s, Age: %d\n", name, age);
    }
    fclose(textFile);

    // --- BINARY FILE ---
    Person p1 = {"Charlie", 28}, p2 = {"Diana", 32};
    FILE *binFile = fopen("people.bin", "wb");
    fwrite(&p1, sizeof(Person), 1, binFile);
    fwrite(&p2, sizeof(Person), 1, binFile);
    fclose(binFile);

    binFile = fopen("people.bin", "rb");
    Person buffer;
    printf("\nBinary file contents:\n");
    while (fread(&buffer, sizeof(Person), 1, binFile)) {
        printf("Name: %s, Age: %d\n", buffer.name, buffer.age);
    }
    fclose(binFile);

    return 0;
}
```

## Final Notes:
- Always check file pointers for `NULL` to handle errors.
- Prefer `fgets()` over `gets()`.
- Use `"b"` in mode strings (`"rb"`, `"wb"`) for binary files.

