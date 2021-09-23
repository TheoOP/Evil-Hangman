#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

//typedef struct hangmanTree
//{
//	Node* head;
//} HangmanTree;


HANG_TREE my_tree_init_default(void) {
	Hang_tree* pMy_tree = (Hang_tree*)malloc(sizeof(Hang_tree));
	if (pMy_tree == NULL) {
		return NULL;
	}
	pMy_tree->head = NULL;
	return pMy_tree;
}


G_VECTOR get_largest_word_vector(HANG_TREE root) {
	Hang_tree* pTree = (Hang_tree*)root;
	G_VECTOR largestVector = NULL;
	G_VECTOR tmpVector = NULL;
	int i;
	tmpVector = find_largest_vector(pTree->head);
	largestVector = g_vector_init_default(my_string_assignment, my_string_destroy);
	for (i = 0; i < g_vector_get_size(tmpVector); i++) {
		g_vector_push_back(largestVector, g_vector_at(tmpVector, i));
	}
	return largestVector;
}
//
//G_VECTOR find_largest_vector(Node* root) {
//	G_VECTOR tmpLargestVector = NULL;
//	tmpLargestVector = g_vector_init_default(my_string_assignment, my_string_destroy);
//	int size;
//	if (root != NULL) {
//	size = g_vector_get_size(root->hVector);
//	/*printf("value = %c\tbalance_factor = %d\n", root->hKey, root->height);*/
//		tmpLargestVector = find_largest_vector(root->left);
//		if (tmpLargestVector == NULL || g_vector_get_size(tmpLargestVector) < g_vector_get_size(root->hVector))
//			tmpLargestVector = root->hVector;
//
//		tmpLargestVector = find_largest_vector(root->right);
//		if (tmpLargestVector == NULL || g_vector_get_size(tmpLargestVector) < g_vector_get_size(root->hVector))
//			tmpLargestVector = root->hVector;
//		my_string_insertion(root->hKey, stdout);
//		printf("SIZE OF VECTOR IS %d\n", g_vector_get_size(root->hVector));
//		return tmpLargestVector;
//	}
//	return tmpLargestVector;
//}

G_VECTOR find_largest_vector(Node* root) {
	G_VECTOR tmpLargestVector = NULL;
	tmpLargestVector = g_vector_init_default(my_string_assignment, my_string_destroy);
	int size;
	if (root != NULL) {
		size = g_vector_get_size(root->hVector);
		/*printf("value = %c\tbalance_factor = %d\n", root->hKey, root->height);*/
		if (root->left != NULL) {
			tmpLargestVector = find_largest_vector(root->left);
			if (tmpLargestVector == NULL || g_vector_get_size(tmpLargestVector) < g_vector_get_size(root->hVector))
				tmpLargestVector = root->hVector;
		}
		if (root->right != NULL) {
			tmpLargestVector = find_largest_vector(root->right);
			if (tmpLargestVector == NULL || g_vector_get_size(tmpLargestVector) < g_vector_get_size(root->hVector))
				tmpLargestVector = root->hVector;
		}
		my_string_insertion(root->hKey, stdout);
		printf("SIZE OF VECTOR IS %d\n", g_vector_get_size(root->hVector));
		return tmpLargestVector;
	}
}
void insert_new_node(HANG_TREE pRoot, MY_STRING hKey, MY_STRING hWord) {
	//if pRoot = NULL
	// create a new node -> root
	// insert node on left or right
	Hang_tree* hMy_Tree = (Hang_tree*)pRoot;

	if (hMy_Tree->head == NULL) {
		hMy_Tree->head = (Node*)malloc(sizeof(Node));

		if (hMy_Tree->head == NULL) {
			printf("New node could not be made\n");
			exit(1);
		}
		hMy_Tree->head->hVector = g_vector_init_default(my_string_assignment, my_string_destroy);
		if (hMy_Tree->head->hVector == NULL)
			exit(1);
		if (g_vector_push_back(hMy_Tree->head->hVector, hWord) == FAILURE) {
			printf("Word could not be pushed into vector\n");
			exit(1);

		}
		hMy_Tree->head->hKey = my_string_init_default();
		if (hMy_Tree->head->hKey == NULL) {
			exit(1);
		}
		my_string_assignment(&(hMy_Tree->head->hKey), hKey);
		hMy_Tree->head->left = NULL;
		hMy_Tree->head->right = NULL;
		hMy_Tree->head->height = 1;


	}
	else {

		if (my_string_compare(hKey, hMy_Tree->head->hKey) == -1)
			insert_new_node(&(hMy_Tree->head->left), hKey, hWord);

		if (my_string_compare(hKey, hMy_Tree->head->hKey) == 1)
			insert_new_node(&(hMy_Tree->head->right), hKey, hWord);

		if (my_string_compare(hKey, hMy_Tree->head->hKey) == 0) {
			g_vector_push_back(hMy_Tree->head->hVector, hWord);

		}
		if (hMy_Tree->head->left != NULL && hMy_Tree->head->right != NULL) {
			hMy_Tree->head->height = 1 + max(hMy_Tree->head->left->height, hMy_Tree->head->right->height);
			int balance = getBalance(hMy_Tree->head);

			// Left Left Case 
			if (balance > 1 && hKey < hMy_Tree->head->left->hKey) {
				hMy_Tree->head = rightRotate(hMy_Tree->head);
				hMy_Tree = hMy_Tree->head;
				return;
			}
			// Right Right Case 
			if (balance < -1 && hKey > hMy_Tree->head->right->hKey) {
				hMy_Tree->head = leftRotate(hMy_Tree->head);
				hMy_Tree = hMy_Tree->head;
				return;
			}
			// Left Right Case 
			if (balance > 1 && hKey > hMy_Tree->head->left->hKey)
			{
				hMy_Tree->head->left = leftRotate(hMy_Tree->head->left);
				hMy_Tree->head = rightRotate(hMy_Tree->head);
				hMy_Tree = hMy_Tree->head;
				return;
			}

			// Right Left Case 
			if (balance < -1 && hKey < hMy_Tree->head->right->hKey)
			{
				hMy_Tree->head->right = rightRotate(hMy_Tree->head->right);
				hMy_Tree->head = leftRotate(hMy_Tree->head);

				return;
			}
		}
	}
	return;
}
Node* leftRotate(Node* x)
{
	Node* y = x->right;
	Node* T2 = y->left;

	// Perform rotation 
	y->left = x;
	x->right = T2;

	//  Update heights 
	x->height = max(x->left->height, x->right->height) + 1;
	y->height = max(y->left->height, y->right->height) + 1;

	// Return new root 
	return y;
}
Node* rightRotate(Node* y)
{
	Node* x = y->left;
	Node* T2 = x->right;

	// Perform rotation 
	x->right = y;
	y->left = T2;

	// Update heights 
	y->height = max(y->left->height, y->right->height) + 1;
	x->height = max(x->left->height, x->right->height) + 1;

	// Return new root 
	return x;
}


int getBalance(Node* N)
{
	if (N == NULL)
		return 0;
	return N->left->height - N->right->height;
}

void traversal_in_order(Node* root) {
	if (root != NULL) {
		traversal_in_order(root->left);
		printf("value = %c\tbalance_factor = %d\n", root->hKey, root->height);
		traversal_in_order(root->right);
	}
}
void check_balance(Node** pRoot) {
	if ((*pRoot)->height == 2) { //parent is left-heavy
		if (((*pRoot)->left)->height == 1) {
			//do something here
		}
		else
			rotate_left_right(&(*pRoot));
	}
	//return NULL;
}
void rotate_left_right(Node** pRoot) {
	Node* tmp_root = *pRoot;
	Node* tmp_left = (*pRoot)->left;
	Node* tmp_right = ((*pRoot)->left)->right;
	//rotate child left
	tmp_root->left = tmp_right;  //left child is 33
	tmp_left->right = NULL;
	tmp_right->left = tmp_left;   //take 21 as a child
	tmp_left->height++;   //balance factor of 33 is 1
	//rotate parent right
	*pRoot = tmp_right;   //root is 33 now
	tmp_right->right = tmp_root; //making 33 right child of 33
	(tmp_right->right)->left = NULL;
	(tmp_right->right)->height = 0;
	//	return NULL;
}