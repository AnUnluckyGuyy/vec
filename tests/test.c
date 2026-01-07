#include <stdio.h>
#include <assert.h>

#include "vec.h"

int main() {
    printf("Hello from Vec lib!\n");

    vec_t *vec = vec_create();
    if (!vec) {
        return 1;
    }
    vec_push(vec, 5);
    assert(vec->size == 1);
    assert(vec->data[0] == 5);

    int x;
    vec_pop(vec, &x);
    assert(x == 5);
    assert(vec->size == 0);

    vec_push(vec, 10);
    if (vec_get(vec, &x, 0)) {
        assert(x == 10);
    }
    if (vec_set(vec, 0, 5)) {
        assert(vec->data[0] == 5);
    }

    if (vec_pop(vec, &x)) printf("true\n");
    if (vec_pop(vec, &x)) printf("true\n");
    if (vec_pop(vec, &x)) printf("true\n");

    for (int i=0; i<100; i++) {
        vec_push(vec, i);
    }

    vec_size_t n = vec_size(vec);
    for (vec_size_t i = 0; i < n; i++) {
        int v;
        if (!vec_get(vec, &v, i)) {
            fprintf(stderr, "Error reading element %zu\n", i);
        } else {
            printf("vec[%zu]: %d\n", i, v);
        }
    }

    vec_clear(vec);
    printf("size after clear: %zu\n", vec_size(vec));

    vec_t *vec2 = vec_create();
    if (!vec2) {
        vec_destroy(&vec);
        return 1;
    }

    vec_reserve(vec2, 200);
    printf("capacity of vec2: %zu\n", vec2->capacity);
    vec_reserve(vec2, 100);
    
    vec_destroy(&vec2);
    vec_destroy(&vec);
    return 0;
}