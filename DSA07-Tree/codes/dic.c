#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 100
#define MAX_MEANING_SIZE 200


typedef struct {
	char word[MAX_WORD_SIZE];
	char meaning[MAX_MEANING_SIZE];
} element;

typedef struct BinaryTree{
	element key;
	struct BinaryTree* left;
	struct BinaryTree* right;
} TreeNode;

void display(TreeNode *node){
	if (node != NULL){
		display(node->left);
		printf("%s", node->key.word);
		display(node->right);
	}
}

int compare(element e1, element e2){
	return strcmp(e1.word, e2.word);
}

void help(){
	printf("******************\n");
	printf("i: input\n");
	printf("d: delete\n");
	printf("s: search\n");
	printf("p: print\n");
	printf("q: quit\n");
	printf("******************\n");
}

TreeNode *search(TreeNode *root, element key){
	TreeNode *parent = root;
	while (parent != NULL){
		switch(compare(key, parent->key)){
			case -1:
				parent = parent->left;
				break;
			case 0:
				return parent;
			case 1:
				parent = parent->right;
				break;
		}
	}
	return parent;
}

void bintree_insert(TreeNode **root, element key){
	TreeNode *parent, *current; // parent and current node
	TreeNode *new;              // new node

	current = *root;
	parent = NULL;

	// search for the place to insert
	// if it is already in the tree, skip
	while (current != NULL){
		if (compare(key, current->key) == 0) 
			return;
		parent = current;

		if (compare(key, current->key) < 0)
			current = current->left;
		else 
			current = current->right;
	}

	// create a node for the key
	new = (TreeNode *)malloc(sizeof(TreeNode));
	if (new == NULL) 
		return ; // error checking

	// data and links of the new node
	new->key = key;
	new->left = new->right = NULL;

	// insert the key in the tree
	if (parent !=NULL)
		if (compare(key, parent->key) < 0)
			parent->left = new;  // insert in the left child
		else 
			parent->right = new; // insert in the right child
	else
		*root = new;             // tree is empty, the new is the root 
}


void bintree_delete(TreeNode **root, element key){
	TreeNode *parent, *child;
    TreeNode *successor, *successor_parent;
	TreeNode *current;

	parent = NULL;
	current = *root;

	// find the node with the key
	while (current != NULL && compare(current->key, key) != 0){
		parent = current;

		// current = (key < current->key) ? current->left : current->right;
		if (compare(key, current->key) < 0)
			current = current->left;
		else
			current = current->right;
	}

	// if the key is not in the tree
	if (current == NULL){
		printf("The key is not in the tree\n");
		return;
	}

	// if the key is the terminal node
	if ((current->left == NULL) && (current->right==NULL)){
		if (parent != NULL){
			// delete the found terminal node NULL
			if (parent->left == current)
				parent->left = NULL;
			else
				parent->right = NULL;
		}
		else // if there is no child and the found node is NULL
			 // then it is the root node
			*root = NULL;
	} 
	// if the target node has one child
	else if ((current->left == NULL) || (current->right == NULL)){
		if (compare(key, current->key) < 0)
			child = current->left;
		else
			child = current->right;

		if (parent != NULL){
			// link the target's child with the target's parent 
			if (parent->left == current)
				parent->left = child;
			else
				parent->right = child;
		} else { // if it is not found then the target node is root
			*root = child;
		}
	}
	// if the target node has two child
	else {
		// search successor from the right subtree
		successor_parent = current;
		successor = current->right;
		// find the successor and make it the left child
		while (successor->left != NULL){
			successor_parent = successor;
			successor = successor->left;
		}

		// link the successor's parent with the child
		if (successor_parent->left == successor)
			successor_parent->left = successor->right;
		else
			successor_parent->right = successor->right;

		// copy the key value of successor
		current->key = successor->key;
		// delete the successor
		current = successor;
	}
	free(current);
}

int main(){
	char cmd;
	element e;
	TreeNode *root = NULL;
	TreeNode *tmp;

	do{
		help();
		cmd = getchar();
		fflush(stdin);
		switch(cmd){
		case 'i':
			printf("word: ");
			fgets(e.word, sizeof(e.word), stdin);
			printf("meaning: ");
			fgets(e.meaning, sizeof(e.meaning), stdin);
			bintree_insert(&root, e);
			break;
		case 'd':
			printf("word: ");
			fgets(e.word, sizeof(e.word), stdin);
			bintree_delete(&root, e);
			break;
		case 'p':
			display(root);
			printf("\n");
			break;
		case 's':
			printf("word: ");
			fgets(e.word, sizeof(e.word), stdin);
			tmp = search(root, e);
			if (tmp != NULL)
				printf("meaning: %s\n", e.meaning); 
			break;
		}
	} while (cmd != 'q');
}