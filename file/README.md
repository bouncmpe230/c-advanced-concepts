# File Input / Output in C

C provides a standard library of functions for handling file input and output.  
File I/O can be done in **text mode** or **binary mode** depending on the file's content.

---

## Open / Close Files

### `FILE *fopen(const char *filename, const char *mode);`

**Parameters:**
- `filename`: Name/path of the file to open.
- `mode`: String representing the file access mode (`"r"`, `"w"`, `"a"`, `"rb"`, etc.).

**Example:**
```c
FILE *fp = fopen("example.txt", "w");  // Open for writing
if (fp == NULL) {
    perror("File opening failed");
}
```

---

### `int fclose(FILE *stream);`

**Parameters:**
- `stream`: Pointer to the file object to be closed.

**Example:**
```c
fclose(fp);
```

---

## Character/Formatted Read/Write

### `char *fgets(char *str, int n, FILE *stream);`

**Parameters:**
- `str`: Buffer to store the read string.
- `n`: Maximum number of characters to read (including `\0`).
- `stream`: File pointer to read from.

**Example:**
```c
char line[100];
FILE *fp = fopen("example.txt", "r");
fgets(line, sizeof(line), fp);  // Reads a line
printf("Line: %s", line);
fclose(fp);
```

---

### `int fputs(const char *str, FILE *stream);`

**Parameters:**
- `str`: The string to write.
- `stream`: File pointer to write to.

**Example:**
```c
FILE *fp = fopen("example.txt", "w");
fputs("Hello, file!\n", fp);
fclose(fp);
```

---

### `int fscanf(FILE *stream, const char *format, ...);`

**Parameters:**
- `stream`: File pointer to read from.
- `format`: Format specifiers (like in `scanf`).
- `...`: Pointers to variables to store the read values.

**Example:**
```c
int age;
char name[50];
FILE *fp = fopen("example.txt", "r");
fscanf(fp, "%s %d", name, &age);
fclose(fp);
```

---

### `int fprintf(FILE *stream, const char *format, ...);`

**Parameters:**
- `stream`: File pointer to write to.
- `format`: Format string (like in `printf`).
- `...`: Values to write.

**Example:**
```c
FILE *fp = fopen("example.txt", "w");
fprintf(fp, "Name: %s, Age: %d\n", "Alice", 25);
fclose(fp);
```

---

### `char *gets(char *str);` *(Deprecated – use `fgets()` instead!)*

**Parameters:**
- `str`: Buffer to store input.

⚠️ Dangerous — does not check buffer length.

---

### `int puts(const char *str);`

**Parameters:**
- `str`: String to be written to stdout.

**Example:**
```c
puts("Hello, world!");
```

---

## Binary Read/Write

### `size_t fread(void *ptr, size_t size, size_t count, FILE *stream);`

**Parameters:**
- `ptr`: Pointer to the memory block to store read data.
- `size`: Size (in bytes) of each element.
- `count`: Number of elements to read.
- `stream`: File pointer.

**Example:**
```c
Record r;
fread(&r, sizeof(Record), 1, fp);
```

---

### `size_t fwrite(const void *ptr, size_t size, size_t count, FILE *stream);`

**Parameters:**
- `ptr`: Pointer to the data to be written.
- `size`: Size of each element.
- `count`: Number of elements to write.
- `stream`: File pointer.

**Example:**
```c
fwrite(&r, sizeof(Record), 1, fp);
```

---

### `int fseek(FILE *stream, long offset, int origin);`

**Parameters:**
- `stream`: File pointer.
- `offset`: Number of bytes to move the pointer.
- `origin`: Position to offset from (`SEEK_SET`, `SEEK_CUR`, `SEEK_END`).


`SEEK_SET` – It moves file pointer position to the beginning of the file.

`SEEK_CUR` – It moves file pointer position to given location.

`SEEK_END` – It moves file pointer position to the end of file.

**Example:**
```c
fseek(fp, 5, SEEK_SET);  // Go to 6th byte
```

---

### `void rewind(FILE *stream);`

**Parameters:**
- `stream`: File pointer.

**Example:**
```c
rewind(fp);  // Move to beginning of file
```

---

## Example Project: Text + Binary File Operations

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

---

## Final Notes
- Always check file pointers (`if (fp == NULL)`) to prevent crashes.
- Avoid using `gets()` — prefer `fgets()` for safety.
- Add `"b"` in mode strings for binary files (`"rb"`, `"wb"`).
- Use `fseek()`/`rewind()` to control read/write position.
