#include<assert.h>
#include<stdlib.h>

#include "array.h"

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

    return 0;
}
