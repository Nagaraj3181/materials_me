#define MEMORY_ALLOC_FAIL -1
#define SUCCESS 1
#define LIST_EMPTY -1
#define FAIL 0

struct _node_
{
    int data;
    struct _node_ *ptr;
};
typedef struct _node_ Node;

struct _linked_list_
{
    Node *head, *tail;
    int count;
};

typedef struct _linked_list_ List;

List * initialise_list();
int insert_at_beg(List *, int data);
int insert_at_end(List *, int data);
int insert_after_element(List *, int data, int element);int insert_at_end(List *, int data);
int insert_after_element(List *, int data, int element);
int insert_after_pos(List *, int data, int pos);


Node * search_list(List *, int);
