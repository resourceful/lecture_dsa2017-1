#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTree{
	int data;
	struct BinaryTree* left;
	struct BinaryTree* right;
} TreeNode;

void inorder( TreeNode *root ){
	if (root){
		inorder(root->left); // traverse left tree
		printf("%d\n", root->data); // visit the node
		inorder(root->right); // traverse to right tree
	}
}

void preorder( TreeNode *root ){
	if (root){
		printf("%d\n", root->data); // visit the node
		preorder(root->left); // traverse left tree
		preorder(root->right); // traverse to right tree
	}
}

void postorder( TreeNode *root ){
	if (root){
		postorder(root->left); // traverse left tree
		postorder(root->right); // traverse to right tree
		printf("%d\n", root->data); // visit the node
	}
}

int main(){
	TreeNode N1 = {1, NULL, NULL};
	TreeNode N2 = {4, &N1, NULL};
	TreeNode N3 = {16, NULL, NULL};
	TreeNode N4 = {25, NULL, NULL};
	TreeNode N5 = {20, &N3, &N4};
	TreeNode N6 = {15, &N2, &N5};

	TreeNode *root = &N6;

	printf("Start of Preoder traverse\n");
	preorder(root);
	printf("Start of Inoder traverse\n");
	inorder(root);
	printf("Start of Postoder traverse\n");
	postorder(root);

	
}