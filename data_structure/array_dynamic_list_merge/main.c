#include<assert.h>
#include<stdlib.h>

#include "array.h"

void test_merge_array();

int main()
{
    Array *test_ptr, *arr_one, *arr_two;

    test_ptr = initialize_array(5);
    arr_one = initialize_array(10);
    arr_two = initialize_array(15);

    assert(test_ptr != NULL);
    assert(test_ptr->c_size == 0 && test_ptr->t_size == 5);
    assert(test_ptr->arr != NULL);

    assert(insert_data(test_ptr, 10) == SUCCESS);
    assert(insert_data(test_ptr, 30) == SUCCESS);
    assert(insert_data(test_ptr, 40) == SUCCESS);
    assert(insert_data(test_ptr, 20) == SUCCESS);
    assert(insert_data(test_ptr, 60) == SUCCESS);

    assert(test_ptr->c_size == 5);
    assert(insert_data(test_ptr, 100) == FULL);

    assert(search(test_ptr, 60) == FOUND);
    assert(search(test_ptr, 20) == FOUND);
    assert(search(test_ptr, 40) == FOUND);

    assert(search(test_ptr, 100) == FAIL);

    test_ptr = deallocate(test_ptr);
    assert(test_ptr == NULL);


    //testing for merge array
    test_merge_array();

    return 0;
}


void test_merge_array()
{
    Array *arr_one, *arr_two;

    arr_one = initialize_array(10);
    arr_two = initialize_array(15);

    assert(insert_data(arr_one, 10));
    assert(insert_data(arr_one, 30));
    assert(insert_data(arr_one, 20));
    assert(insert_data(arr_one, 50));
    assert(insert_data(arr_one, 20));
    assert(insert_data(arr_one, 60));
    assert(insert_data(arr_one, 10));

    assert(arr_one->c_size == 7);


    assert(insert_data(arr_two, 90));
    assert(insert_data(arr_two, 90));
    assert(insert_data(arr_two, 90));
    assert(insert_data(arr_two, 90));
    assert(insert_data(arr_two, 30));
    assert(insert_data(arr_two, 90));
    assert(insert_data(arr_two, 50));
    assert(insert_data(arr_two, 90));
    assert(insert_data(arr_two, 10));
    assert(insert_data(arr_two, 80));

    assert(arr_two->c_size == 10);

    arr_two = merge_array(arr_one, arr_two);

    assert(arr_one->c_size == 17);
    assert(arr_one->t_size == 17);
    assert(arr_two == NULL);

    deallocate(arr_one);


}
