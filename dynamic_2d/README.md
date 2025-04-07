# Dynamic 2D Array Allocation in C using `malloc`

When working with 2D arrays in C, dynamic memory allocation is often needed, especially when the dimensions of the array are not known at compile time. 

Here are three common approaches to allocate a square matrix `A[n][n]` using `malloc`.


## Approach 1: Rows Not Necessarily Contiguous (`n + 1 malloc` calls)

### Idea:
- Allocate an array of `n` pointers to rows.
- For each row, allocate `n` integers.
- Total of `n + 1` `malloc` calls.
- Rows may not be contiguous in memory.

Memory Layout:
```


A      --->   +---------+     A[0] ---> +---+---+---+---+---+
              | A[0] *  |               | 0 | 1 | 2 |...|   |
              +---------+     A[1] ---> +---+---+---+---+---+
              | A[1] *  |
              +---------+     A[2] ---> +---+---+---+---+---+
              | A[2] *  |
              +---------+
              |   ...   |
              +---------+     A[n-1] -->+---+---+---+---+---+
              | A[n-1]* |
              +---------+
```
Each row is independently allocated. No guarantee they are contiguous in memory.


```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n, k = 0;
    int **A;

    if (argc != 2) {
        printf("Error: run it as: ./a.out n where n is an integer\n");
        exit(1);
    }

    n = atoi(argv[1]);

    A = (int **) malloc(n * sizeof(int *));
    if (A == NULL) {
        printf("Error: memory alloc error\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        A[i] = (int *) malloc(n * sizeof(int));
        if (A[i] == NULL) {
            printf("Error: memory alloc error\n");
            exit(1);
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = k++;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%2d ", A[i][j]);
        printf("\n");
    }
}
```


## Approach 2: Rows Contiguous (`2 malloc` calls)

###  Idea:
- Allocate an array of pointers to rows.
- Allocate a contiguous block of `n*n` integers.
- Point each row to the appropriate start location in the block.

Memory Layout:
```

A      --->   +---------+     A[0] ---> t + 0
              | A[0] *  |               +---+---+---+---+---+---+---+---+---+---+
              +---------+     A[1] ---> t + n     Entire matrix in one block!
              | A[1] *  |               | 0 | 1 | 2 |...|...|...|...|...|...|...|
              +---------+     A[2] ---> t + 2n
              | A[2] *  |
              +---------+
              |   ...   |
              +---------+
              | A[n-1]* |
              +---------+

t --------> +---+---+---+---+---+---+---+---+---+---+
            | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |...|
            +---+---+---+---+---+---+---+---+---+---+
```

Only one block of data, and A[i] points to the start of each row.


```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n, k = 0;
    int **A, *t;

    if (argc != 2) {
        printf("Error: run it as: ./a.out n where n is an integer\n");
        exit(1);
    }

    n = atoi(argv[1]);

    A = (int **) malloc(n * sizeof(int *));
    t = (int *) malloc(n * n * sizeof(int));

    if (A == NULL || t == NULL) {
        printf("Error: memory alloc error\n");
        exit(1);
    }

    for (int i = 0; i < n; i++)
        A[i] = &t[i * n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = k++;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%2d ", A[i][j]);
        printf("\n");
    }
}
```


## Approach 3: Fully Contiguous (`1 malloc` call)

### Idea:
- Treat the 2D array as a 1D array of size `n*n`.
- Access element at `[i][j]` using index arithmetic: `A[i*n + j]`.


Memory Layout:
```

A --------> +---+---+---+---+---+---+---+---+---+---+
            | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |...|
            +---+---+---+---+---+---+---+---+---+---+
```
Access A[i * n + j] for row i and column j.
No row pointers – this is just a flat array treated as 2D using index math.


```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n, k = 0;
    int *A;

    if (argc != 2) {
        printf("Error: run it as: ./a.out n where n is an integer\n");
        exit(1);
    }

    n = atoi(argv[1]);

    A = (int *) malloc(n * n * sizeof(int));
    if (A == NULL) {
        printf("Error: memory alloc error\n");
        exit(1);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i * n + j] = k++;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%2d ", A[i * n + j]);
        printf("\n");
    }
}
```

---

## Summary 

| Approach   | Memory Layout        | malloc Calls | Pros                            | Cons                          |
|------------|----------------------|--------------|----------------------------------|-------------------------------|
| Approach 1 | Not contiguous rows  | `n + 1`      | Easy to read and understand     | Memory may be fragmented      |
| Approach 2 | Contiguous rows      | `2`          | Faster access, cache friendly   | Slightly more complex         |
| Approach 3 | Fully contiguous     | `1`          | Most efficient in memory layout | Row access less intuitive     |
