#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    void* elements;
    size_t element_size;
    size_t size;            //current size
    size_t capacity;        //max size

} vector;

vector* init_vector(size_t element_size, size_t initial_capacity){

    vector* v = (vector*)malloc(sizeof(vector));
    if(v == NULL){
        fprintf(stderr, "ERROR: Failed to allocate memory for vector\n");
        exit(EXIT_FAILURE);
    }

    v->element_size = element_size;
    v->elements = malloc(element_size * initial_capacity);
    if(v->elements == NULL){
        fprintf(stderr, "ERROR: Failed to allocate memory for vector's elements\n");
        exit(EXIT_FAILURE);
    }
    v->size = 0;
    v->capacity = initial_capacity;

    return v;
}

void insert_element(vector* v, void* element){
    if(v->size == v->capacity){
        v->capacity *= 2;
        v->elements = realloc(v->elements, v->capacity*v->element_size);
        if(v->elements == NULL){
            fprintf(stderr, "ERROR: Failed to reallocate memory for vector\n");
            exit(EXIT_FAILURE);
        }
    }

    void* new_element = v->elements + v->size*v->element_size;
    memcpy(new_element, element, v->element_size);
    v->size++;
}

void* get(vector* v, size_t index){
    if(index >= v->size){
        fprintf(stderr, "ERROR: Index %lu exceeds vector's capacity %lu\n", index, v->capacity);
        exit(EXIT_FAILURE);
    }

    return v->elements + index*v->element_size;
}

void remove_element(vector* v, size_t index){
    if(index >= v->size){
        fprintf(stderr, "ERROR: Index %lu exceeds vector's capacity %lu\n", index, v->capacity);
        exit(EXIT_FAILURE);
    }

    for(size_t i=index; i<v->size-1; i++){
        void* current_element = get(v, i);
        void* next_element = get(v, i+1);
        memcpy(current_element, next_element, v->element_size);
    }

    v->size--;
}

void free_vector(vector* v){
    free(v->elements);
    free(v);
}