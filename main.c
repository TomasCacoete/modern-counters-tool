#include <stdio.h>

#include "header/vector.h"

#include "header/card.h"
#include "header/shoe.h"

int main(/*int argc, char *argv[]*/){

    vector* arr = init_vector(sizeof(int), 2);

    int aux1 = 3;
    int aux2 = 4;
    int aux3 = 5;
    int aux4 = 6;

    insert_element(arr, &aux1);
    insert_element(arr, &aux2);
    insert_element(arr, &aux3);
    insert_element(arr, &aux4);

    remove_element(arr, 9);


    for(size_t i=0; i<arr->size; i++){
        printf("%d\n", *(int*)get(arr, i));
    }

    free_vector(arr);

    return 0;
}