#include<stdlib.h>
#include "list.h"



List * initialise_list()
{
    List *my_list;

    my_list = (List *)malloc(sizeof(List));

    my_list->head = my_list->tail = NULL;
    my_list->count = 0;

    return my_list;
}

Node * get_node(int data)
{
    Node *my_node;

    my_node = (Node *)malloc(sizeof(Node));
    my_node->data = data;
    my_node->ptr = NULL;

    return my_node;
}

int insert_at_beg(List *my_list, int data)
{
    Node *my_node;

    my_node = get_node(data);

    if(my_node == NULL) return MEMORY_ALLOC_FAIL;

    if(my_list->count == 0)
        my_list->head = my_list->tail = my_node;
    else
    {
        my_node->ptr = my_list->head;
        my_list->head = my_node;
    }
    my_list->count++;

    return SUCCESS;
}
int insert_at_end(List *my_list, int data)
{
    Node *my_node;

    my_node = get_node(data);

    if(my_node == NULL) return MEMORY_ALLOC_FAIL;

    if(my_list->count == 0)
        my_list->head = my_list->tail = my_node;
    else
    {
        my_list->tail->ptr = my_node;
        my_list->tail = my_node;
    }

    my_list->count++;

    return SUCCESS;
}

Node * search_list(List *my_list, int data)
{
    Node *temp;

    //for(i=0; i< size; i++)

    for(temp = my_list->head; temp != NULL; temp = temp->ptr)
    {
        if(data == temp->data)
            return temp;
    }
    return NULL;
}


int search(List *my_list, int element)
{
    Node * temp;

    temp = my_list->head;

    while(temp != NULL)
    {
        if(temp->data == element)
            return 1;
        temp = temp->ptr;
    }
    return 0;
}

// data: to store in the list; element: to search and
//store the data after element if it s found
int insert_after_element(List *my_list, int data, int element)
{
        //check if list is empty

        Node *temp, *new_node;

        if(my_list->count == 0) return LIST_EMPTY;

        if(my_list->tail->data == element)
            return insert_at_end(my_list, data);

        temp = search_list(my_list, element);

        if(temp == NULL) return FAIL; // element not found

        new_node = get_node(data);

        // insert after element with proper chaining
        new_node->ptr = temp->ptr;
        temp->ptr = new_node;

        my_list->count++;

        return SUCCESS;
 }


int insert_after_pos(List *, int data, int pos)
{

}
