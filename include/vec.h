#ifndef VEC_H
#define VEC_H

#include "stdbool.h"

/*
 * vec.h - Dynamic integer vector library
 *
 * Mini Cheat Sheet:
 *
 * vec_t *v = vec_create();          // create
 * vec_push(v, 42);                  // append
 * int x; vec_get(v, &x, 0);         // read
 * vec_set(v, 0, 99);                // write
 * int y; vec_pop(v, &y);            // remove last
 * vec_size_t n = vec_size(v);           // current size
 * vec_clear(v);                      // clear
 * vec_destroy(&v);                  // free memory
 */

typedef size_t vec_size_t;


typedef struct Vector {
    vec_size_t size;
    vec_size_t capacity;
    int *data;
} vec_t;


vec_t *vec_create();
bool vec_grow(vec_t *vector, vec_size_t new_capacity);
bool vec_push(vec_t *vector, int value);
bool vec_pop(vec_t *vector, int *out);
bool vec_get(vec_t *vector, int *out, vec_size_t index);
bool vec_set(vec_t *vector, vec_size_t index, int value);
bool vec_reserve(vec_t *vector, vec_size_t capacity);
bool vec_clear(vec_t *vector);
vec_size_t vec_size(vec_t *vector);
void vec_destroy(vec_t **vector);

#endif