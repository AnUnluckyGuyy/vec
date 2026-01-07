#include <stdio.h>
#include <stdlib.h>


#include "vec.h"


vec_t *vec_create() {
    vec_t *vector = malloc(sizeof(vec_t));
    if (vector == NULL) {
        return NULL;
    }
    vec_size_t capacity = 4;
    vector->data = malloc(sizeof(int)*capacity);
    if (vector->data) {
        vector->size = 0;
        vector->capacity = capacity;
    } else {
        free(vector);
        return NULL;
    }
    return vector;
} 


bool vec_grow(vec_t *vector, vec_size_t new_capacity) {
    if (!vector) return false; 
    if (new_capacity <= vector->capacity) {
        return false;
    }
    int *temp = realloc(vector->data, new_capacity * sizeof(int));
    if (temp == NULL) {
        return false;
    }
    vector->data = temp;
    vector->capacity = new_capacity;
    return true;
}


bool vec_push(vec_t *vector, int value) {
    if (!vector) return false;
    if (vector->size == vector->capacity) {
        if (!vec_grow(vector, vector->capacity*2)) {
            return false;
        }
    }
    vector->data[vector->size] = value;
    vector->size++;
    return true;
}


bool vec_pop(vec_t *vector, int *out) {
    if (!vector || !out) return false;
    if (vector->size < 1) {
        return false;
    }
    *out = vector->data[vector->size-1];
    vector->size--;
    return true;
}


bool vec_get(vec_t *vector, int *out, vec_size_t index) {
    if (!vector || !out) return false;
    if (index >= vector->size) {
        return false;
    }
    *out = vector->data[index];
    return true;
}


bool vec_set(vec_t *vector, vec_size_t index, int value) {
    if (!vector) return false;
    if (index >= vector->size) {
        return false;
    }
    vector->data[index] = value;
    return true;
}


bool vec_reserve(vec_t *vector, vec_size_t capacity) {
    if (!vector) return false;
    if (capacity <= vector->capacity) return true;
    
    return vec_grow(vector, capacity);
}


bool vec_clear(vec_t * vector) {
    if (!vector) return false;
    vector->size = 0;
    return true;
}


vec_size_t vec_size(vec_t *vector) {
    return vector->size;
}


void vec_destroy(vec_t **vector) {
    if (vector && *vector) {
        free((*vector)->data);
        free(*vector);
        *vector = NULL;
    } 
}