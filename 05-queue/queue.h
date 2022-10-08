typedef struct queue Queue;

/* Creates a new queue */
Queue *create_queue();

/* Checks if a queue is empty */
int empty_queue(Queue *queue);

/* Adds an element in a queue */
void insert_queue(Queue *queue, int value);

/* Removes an element from a queue */
int remove_queue(Queue *queue);

/* Print all elements of a queue */
void print_queue(Queue *queue);

/* Releases the allocated memory of a queue */
void free_queue(Queue *queue);
