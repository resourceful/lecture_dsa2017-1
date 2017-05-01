#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTree{
	int data;
	struct BinaryTree* left;
	struct BinaryTree* right;
} TreeNode;

int main(){
	TreeNode *N1, *N2, *N3;

	N1 = (TreeNode *)malloc(sizeof(TreeNode));
	N2 = (TreeNode *)malloc(sizeof(TreeNode));
	N3 = (TreeNode *)malloc(sizeof(TreeNode));

	N1->data = 10;
	N1->left = N2;
	N1->right= N3;

	N2->data = 20;
	N2->left = NULL;
	N2->right= NULL;

	N3->data = 30;
	N3->left = NULL;
	N3->right= NULL;

	printf("N2 data = %d, N3 data = %d\n", N1->left->data, N1->right->data);

	free(N1);
	free(N2);
	free(N3);

	TreeNode M1;
	M1.data = 10;
	M1.left = NULL; 
	M1.right = NULL; 

	printf("M1 data = %d", M1.data);

}