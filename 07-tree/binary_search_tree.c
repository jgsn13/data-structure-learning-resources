#include "binary_search_tree.h"
#include <stdio.h>
#include <stdlib.h>

struct bbTree {
    int info;
    BBTree *left;
    BBTree *right;
};

BBTree *search_bbtree(BBTree *tree, int c) {
    if (empty_bbtree(tree)) {
        return NULL;
    } else if (tree->info < c) {
        return search_bbtree(tree->right, c);
    } else if (tree->info > c) {
        return search_bbtree(tree->left, c);
    } else {
        return tree;
    }
}

void print_bbtree(BBTree *tree) {
    if (!empty_bbtree(tree)) {
        print_bbtree(tree->left);
        printf("%d ", tree->info);
        print_bbtree(tree->right);
    }
}

BBTree *insert_bbtree(BBTree *tree, int c) {
    if (empty_bbtree(tree)) {
        tree = (BBTree *)malloc(sizeof(BBTree));
        tree->info = c;
        tree->left = NULL;
        tree->right = NULL;
    } else if (tree->info > c) {
        tree->left = insert_bbtree(tree->left, c);
    } else if (tree->info < c) {
        tree->left = insert_bbtree(tree->right, c);
    } else {
        printf("Elemento já pertence à árvore\n");
    }
    return tree;
}

BBTree *remove_bbtree(BBTree *tree, int c) {
    if (!empty_bbtree(tree)) {
        if (tree->info > c) {
            tree->left = remove_bbtree(tree->left, c);
        } else if (tree->info < c) {
            tree->right = remove_bbtree(tree->right, c);
        } else {
            BBTree *t;
            if (tree->left == NULL) {
                t = tree;
                tree = tree->right;
                free(t);
            } else if (tree->right == NULL) {
                t = tree;
                tree = tree->left;
                free(t);
            } else {
                t = tree->left;
                while (t->right != NULL) {
                    t = t->right;
                }
                tree->info = t->info;
                t->info = c;
                tree->left = remove_bbtree(tree->left, c);
            }
        }
    }
    return tree;
}
