typedef struct circularList CircularList;

/* Create an empty circular list */
CircularList *create_circular_list();

/* Verify if a circular list is empty */
int empty_circular_list(CircularList *list);

/* Insert an element in a circular list */
CircularList *insert_circular_list(CircularList *list, int info);

/* Search an element in a circular list */
CircularList *search_circular_list(CircularList *list, int info);

/* Print a circular list */
void print_circular_list(CircularList *list);

/* Remove an element from a circular list */
CircularList *remove_circular_list(CircularList *list, int info);

/* Release the allocated space of a circular list */
void free_circular_list(CircularList *list);
