#include <stdio.h>

#include "vec.h"

int main() {
    vec_t *vec = vec_create();
    if (!vec) {
        return 1;
    }

    vec_size_t limit = 20;
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

    vec_size_t n = vec_size(vec);
    for (vec_size_t i=0; i<n; i++) {
        int val;
        if (vec_pop(vec, &val)) {
            printf("popped value: %d\n", val);
        } else {
            fprintf(stderr, "Error popping element from vector\n");
            break;
        }
    }

    int x;
    if (vec_pop(vec, &x)) {
        printf("One last pop.\n");
    } else {
        fprintf(stderr, "One last pop failed! Empty vector.\n");
    }

    vec_destroy(&vec);
    return 0;
}