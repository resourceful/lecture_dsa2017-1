#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTree{
	int data;
	struct BinaryTree* left;
	struct BinaryTree* right;
} TreeNode;

int calc( TreeNode *node){
	if (node == NULL)
		return 0;

	if (node->left == NULL && node-> right == NULL)
		return node->data;
	else {                                // postorder style
		int operand1 = calc(node->left);  // traverse left tree
		int operand2 = calc(node->right); // traverse to right tree

		switch (node->data){ 
			case '+':                     // add
				return operand1 + operand2;
			case '-':                     // subtract 
				return operand1 - operand2;
			case '*':                     // multiply 
				return operand1 * operand2;
			case '/':                     // divide 
				return operand1 / operand2;
		}
	}
	return 0;
}

int main(){
	TreeNode N1 = {2, NULL, NULL};
	TreeNode N2 = {4, NULL, NULL};
	TreeNode N3 = {'*', &N1 , &N2};
	TreeNode N4 = {25, NULL, NULL};
	TreeNode N5 = {15, NULL, NULL};
	TreeNode N6 = {'-', &N4, &N5};
	TreeNode N7 = {'+', &N3, &N6};

	TreeNode *root= &N7; // root of the tree

	printf("%d\n", calc(root));
	
}