#define FULL 0
#define SUCCESS 1
#define FOUND 1
#define FAIL 0

struct _array_
{
    int *arr;
    int c_size, t_size;
};

typedef struct _array_ Array;

Array * initialize_array(int size);
int insert_data(Array *, int);
int search(Array *, int);
Array * deallocate(Array *);

Array * merge_array(Array *, Array *);

Array * split_array(Array *, int split_index);



