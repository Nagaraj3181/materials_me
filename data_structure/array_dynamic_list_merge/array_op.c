
#include<stdlib.h>
#include<assert.h>
#include "array.h"


Array * initialize_array(int size)
{
    Array *my_arr;

    my_arr = (Array *)malloc(sizeof(Array));

    if(NULL == my_arr) return NULL; // memory allocation FAILED

    my_arr->c_size = 0;
    my_arr->t_size = size;
    my_arr->arr = (int *)malloc(sizeof(int) * size);

    return my_arr;
}


int insert_data(Array *my_arr, int data)
{
    if(my_arr->c_size == my_arr->t_size) return FULL;

    *(my_arr->arr + my_arr->c_size) = data;
    my_arr->c_size++;

    return SUCCESS;


}

Array * deallocate(Array *my_arr)
{
    free(my_arr->arr);
    free(my_arr);

    return NULL;
}


int search(Array *my_arr, int element)
{
    int i;

    if(my_arr == NULL) return FAIL;
    if(my_arr->arr == NULL) return FAIL;

    for(i=0; i<my_arr->c_size; i++)
    {
        if(*(my_arr->arr + i) == element) return FOUND;
    }

    return FAIL;
}

//Assumption : Both array A and B have elements
Array * merge_array(Array *arr_a, Array *arr_b)
{
    int updated_c_size_a, i, j;

    if(arr_a == NULL) return arr_b; // arrays does not exist

    if(arr_b == NULL) return arr_b;

    updated_c_size_a = arr_a->c_size + arr_b->c_size;

    if(updated_c_size_a > arr_a->t_size) {
        arr_a->arr = realloc(arr_a->arr, (updated_c_size_a) * sizeof(int));
        arr_a->t_size = updated_c_size_a;
    }

    for(i=0; i < arr_b->c_size; i++)
        assert(insert_data(arr_a, *(arr_b->arr + i)) == SUCCESS);

    arr_b = deallocate(arr_b);


    return arr_b;
}
