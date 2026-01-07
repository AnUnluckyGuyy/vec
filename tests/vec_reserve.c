#include <stdio.h>
#include <assert.h>

#include "vec.h"

int main() {
    vec_t *vec = vec_create();
    if (!vec) {
        return 1;
    }
    vec_reserve(vec, 1000);
    assert(vec->capacity == 1000);
    printf("success\n");
    return 0;
}