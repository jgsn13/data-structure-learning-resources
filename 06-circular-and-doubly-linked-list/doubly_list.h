typedef struct doublyList DoublyList;

/* Create an empty doubly list */
DoublyList *create_doubly_list();

/* Verify if a doubly list is empty */
int empty_doubly_list(DoublyList *list);

/* Insert an element in a doubly list */
DoublyList *insert_doubly_list(DoublyList *list, int info);

/* Print a doubly list */
void print_doubly_list(DoublyList *list);

/* Search an element in a doubly list */
DoublyList *search_doubly_list(DoublyList *list, int info);

/* Remove an element from a doubly list */
DoublyList *remove_doubly_list(DoublyList *list, int info);

/* Release the allocated space of a doubly list */
void free_doubly_list(DoublyList *list);
