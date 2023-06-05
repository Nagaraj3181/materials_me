#include<assert.h>
#include <stdlib.h>
#include "list.h"

int main()
{
    List *test_list;
    Node *node;

    test_list = initialise_list();

    assert(test_list->head == NULL);
    assert(test_list->tail == NULL);
    assert(test_list->count == 0);

    assert(insert_after_element(test_list, 20, 30) == LIST_EMPTY);

    assert(insert_at_beg(test_list, 10));
    assert(insert_at_beg(test_list, 20));
    assert(insert_at_beg(test_list, 30));
    assert(insert_at_beg(test_list, 40));
    assert(insert_at_beg(test_list, 50));

    assert(test_list->count == 5);
    assert(test_list->head->data == 50);
    assert(test_list->tail->data == 10);

    assert(test_list->head->ptr->ptr->data == 30);

    assert(insert_at_end(test_list, 60));
    assert(insert_at_end(test_list, 70));
    assert(insert_at_end(test_list, 80));

    assert(test_list->count == 8);
    assert(test_list->tail->data == 80);

    node = search_list(test_list, 80);
    assert(node->data == 80);


    node = search_list(test_list, 90);
    assert(node == NULL);

    //Element not found
    assert(insert_after_element(test_list, 20, 100) == FAIL);

    assert(insert_after_element(test_list,100, 80));
    assert(test_list->tail->data == 100);

    assert(insert_after_element(test_list, 130, 20));
    assert(insert_after_element(test_list, 75, 60));

    assert(test_list->count == 11);





    return 0;
}
