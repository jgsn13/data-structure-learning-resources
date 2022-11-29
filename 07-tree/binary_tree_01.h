typedef struct tree Tree;

/* Create and empty tree */
Tree *create_empty_tree(void);

/* Create a node in a binary tree */
Tree *create_tree_node(char c, Tree *left, Tree *right);

/* Verify if a tree is empty */
int empty_tree(Tree *tree);

/* Print the elements of a binary tree */
void print_tree(Tree *tree);

/* Verify if an element is included in a tree */
int include_tree(Tree *tree, char c);

/* Return the height of a tree */
int tree_height(Tree *tree);

/* Release the space allocated for a binary tree */
void free_tree(Tree *tree);
