#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTree{
	int data;
	struct BinaryTree* left;
	struct BinaryTree* right;
} TreeNode;

void inorder( TreeNode *ptr ){
	if (ptr){
		inorder(ptr->left); // traverse left tree
		printf("%d\n", ptr->data); // visit the node
		inorder(ptr->right); // traverse to right tree
	}
}

void preorder( TreeNode *ptr ){
	if (ptr){
		printf("%d\n", ptr->data); // visit the node
		preorder(ptr->left); // traverse left tree
		preorder(ptr->right); // traverse to right tree
	}
}

void postorder( TreeNode *ptr ){
	if (ptr){
		postorder(ptr->left); // traverse left tree
		postorder(ptr->right); // traverse to right tree
		printf("%d\n", ptr->data); // visit the node
	}
}

int main(){
	TreeNode N1 = {1, NULL, NULL};
	TreeNode N2 = {4, &N1, NULL};
	TreeNode N3 = {16, NULL, NULL};
	TreeNode N4 = {25, NULL, NULL};
	TreeNode N5 = {20, &N3, &N4};
	TreeNode N6 = {15, &N2, &N5};

	TreeNode *ptr = &N6; // root of the tree

	printf("Start of Preoder traverse\n");
	preorder(ptr);
	printf("Start of Inoder traverse\n");
	inorder(ptr);
	printf("Start of Postoder traverse\n");
	postorder(ptr);

	
}