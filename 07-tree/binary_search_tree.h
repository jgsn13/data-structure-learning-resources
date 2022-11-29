typedef struct bbTree BBTree;

/* Create an empty binary search tree */
BBTree *create_empty_bbtree(void);

/* Verify if a binary tree is empty */
int empty_bbtree(BBTree *tree);

/* Searche the subtree that contains an integer */
BBTree *search_bbtree(BBTree *tree, int c);

/* Print the elements of a tree */
void print_bbtree(BBTree *tree);

/* Insert an integer in a tree */
BBTree *insert_bbtree(BBTree *tree, int c);

/* Remove an integer from a tree */
BBTree *remove_bbtree(BBTree *tree, int c);

/* Release the allocated memory of a tree */
void free_bbtree(BBTree *tree);
