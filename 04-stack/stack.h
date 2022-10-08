typedef struct stack Stack;

/* Creates a new stack */
Stack *create_stack();

/* Checks if a stack is empty */
int empty_stack(Stack *stack);

/* Adds an element on top of a stack */
void push_stack(Stack *stack, int value);

/* Removes an element from the top of a stack */
int pop_stack(Stack *stack);

/* Prints all elements of a stack */
void print_stack(Stack *stack);

/* Releades the allocated memory of a stack */
void free_stack(Stack *stack);
