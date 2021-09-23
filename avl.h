#pragma once


#include "generic_vector.h"
#include "my_string.h"

typedef void* HANG_TREE;
typedef struct node Node;
struct node {
	G_VECTOR hVector;
	MY_STRING hKey;
	Node* left;
	Node* right;
	int height;
};


struct hang_tree {
	Node* head;
};
typedef struct hang_tree Hang_tree;

HANG_TREE my_tree_init_default(void);

G_VECTOR get_largest_word_vector(HANG_TREE root);
G_VECTOR find_largest_vector(Node* root);


int getBalance(Node* N);
Node* leftRotate(Node* x);
Node* rightRotate(Node* y);
void insert_new_node(HANG_TREE pRoot, MY_STRING hKey, MY_STRING hWord);
void traversal_in_order(Node* root);
void check_balance(Node** pRoot);
void rotate_left_right(Node** pRoot);
