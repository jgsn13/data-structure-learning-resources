#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

struct tree {
    char info;
    Tree *left;
    Tree *right;
};

Tree *create_empty_tree() { return NULL; }

Tree *create_tree_node(char c, Tree *left, Tree *right) {
    Tree *t = (Tree *)malloc(sizeof(Tree));
    t->info = c;
    t->left = left;
    t->right = right;
    return t;
}

int empty_tree(Tree *tree) { return tree == NULL; }

void print_tree(Tree *tree) {
    if (!empty_tree(tree)) {
        printf("%c ", tree->info);
        print_tree(tree->left);
        print_tree(tree->right);
    }
}

int include_tree(Tree *tree, char c) {
    if (empty_tree(tree)) {
        return 0;
    } else {
        return tree->info == c || include_tree(tree->left, c) ||
               include_tree(tree->right, c);
    }
}

int tree_height(Tree *tree) {
    if (empty_tree(tree)) {
        return -1;
    } else {
        int hLeft = tree_height(tree->left);
        int hRight = tree_height(tree->right);
        if (hLeft > hRight) {
            return 1 + hLeft;
        } else {
            return 1 + hRight;
        }
    }
}

void free_tree(Tree *tree) {
    if (!empty_tree(tree)) {
        free_tree(tree->left);
        free_tree(tree->right);
        free(tree);
    }
}

int main() {
    Tree t1;
    t1.info = '2';
    t1.left = NULL;
    t1.right = NULL;
    Tree t2;
    t2.info = '3';
    t2.left = NULL;
    t2.right = NULL;
    Tree t3;
    t2.info = '+';
    t2.left = &t1;
    t2.right = &t2;

    return 0;
}
