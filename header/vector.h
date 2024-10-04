#include <stdio.h>

typedef struct {

    void* elements;
    size_t element_size;
    size_t size;            //current size
    size_t capacity;        //max size

} vector;

vector* init_vector(size_t element_size, size_t initial_capacity);
void insert_element(vector* v, void* element);
void* get(vector* v, size_t index);
void remove_element(vector* v, size_t index);
void free_vector(vector* v);