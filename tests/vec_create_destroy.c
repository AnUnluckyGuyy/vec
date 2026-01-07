#include "vec.h"

int main() {
    vec_t *vec = vec_create();
    if (!vec) {
        return 1;
    }

    vec_destroy(&vec);
    return 0;
}