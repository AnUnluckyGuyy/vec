# COMPILING THE LIBRARY:
1. Compile object files:
`gcc -Iinclude -c src/vec.c -o build/vec.o`

2. Create static library:
`ar rcs build/libvec.a build/vec.o`

# COMPILING A PROGRAM: 
Use with the following command:
`gcc -I~/vec/include main.c -L~/vec/build -lvec -o main`

# DOCUMENTATION:

## Vec Library – Dynamic Integer Vector

`vec` is a small C library for dynamic arrays of integers, similar to `std::vector<int>` in C++. It allows automatic resizing, push/pop operations, and random access.
It was made as a learning project by me.

---

## Creating and Destroying Vectors

* **Create a new vector**:

```c
vec_t *v = vec_create();
```

* **Destroy a vector and free memory:**

```c
vec_destroy(&v);
```

---

## Adding and Removing Elements

* **Append a value:**

```c
vec_push(v, 42);
```

* **Remove the last value (returns false if empty):**

```c
int x;
vec_pop(v, &x);
```

---

## Accessing and Modifying Elements

* **Read a value at a specific index:**

```c
int x;
vec_get(v, &x, 0);  // index 0
```

* **Set a value at a specific index:**

```c
vec_set(v, 0, 99);
```

---

## Capacity and Size Management

* Get the number of elements:

```c
size_t n = vec_size(v);
```

* Ensure capacity (pre-allocate memory):

```c
vec_reserve(v, 100);
```

* Clear all elements (size becomes 0):

```c
vec_clear(v);
```

---

## Usage Notes

1. Indexes are **0-based**.
2. Always **check return values** of `vec_get`, `vec_set`, and `vec_pop`.
3. `vec_push` **automatically grows** the vector when capacity is reached.
4. Always call `vec_destroy` to **avoid memory leaks**.

---

## Example

```c
#include <stdio.h>
#include "vec.h"

int main() {
    vec_t *v = vec_create();

    vec_push(v, 10);
    vec_push(v, 20);

    int x;
    vec_get(v, &x, 1); // x = 20
    printf("Second element: %d\n", x);

    vec_set(v, 0, 100);
    printf("First element after set: %d\n", v->data[0]);

    vec_destroy(&v);
    return 0;
}
```
