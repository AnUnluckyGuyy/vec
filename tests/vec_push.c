#include <stdio.h>

#include "vec.h"

int main() {
    vec_t *vec = vec_create();
    if (!vec) {
        return 1;
    }

    vec_size_t limit = 1000;
    for (vec_size_t i=0; i<limit; i++) {
        if (!vec_push(vec, i)) {
            printf("Cannot push\n");
            break;
        }
    }

    for (vec_size_t i=0; i<vec_size(vec); i++) {
        int x;
        if (vec_get(vec, &x, i)) {
            printf("vec[%zu]: %d\n", i, x);
        } else {
            fprintf(stderr, "Error getting element at index %zu\n", i);
            break;
        }
    }

    vec_destroy(&vec);
    return 0;
}