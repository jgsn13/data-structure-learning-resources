typedef struct linked_list LinkedList;

/* Creates an empty linked list */
LinkedList *create_linked_list();

/* Verify if an linked list is empty */
int empty_linked_list(LinkedList *list);

/* Insert an element at the beginnig of a linked list */
LinkedList *insert_linked_list(LinkedList *list, int value);

/* Insert an element by sorting the existing elements */
LinkedList *insert_sorted_linked_list(LinkedList *list, int value);

/* Search for an element in a linked list */
LinkedList *search_linked_list(LinkedList *list, int value);

/* Prints a linked list */
void print_linked_list(LinkedList *list);

/* Prints a linked list recursively */
void print_linked_list_recursively(LinkedList *list);

/* Removes an element from a linked list */
LinkedList *remove_linked_list(LinkedList *list, int value);

/* Removes an element from a linked list recursively */
LinkedList *remove_linked_list_recursively(LinkedList *list, int value);

/* Releases the memory allocated by a linked list */
void free_linked_list(LinkedList *list);
