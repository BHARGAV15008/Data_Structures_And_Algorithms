// This code all about binary tree which is not like avl tree, but simple binary tree.
#include <stdio.h>
#include <stdlib.h>

struct Tree
{
	int data;
	struct Tree *left;
	struct Tree *right;
};

void inOrderTraversal(struct Tree* head){
	if(head == NULL) return;
	inOrderTraversal(head->left);
	printf("--> %d ",head->data);
	inOrderTraversal(head->right);
}

void preOrderTraversal(struct Tree* head){
	if(head == NULL) return;
	printf("--> %d ",head->data);
	preOrderTraversal(head->left);
	preOrderTraversal(head->right);
}

void postOrderTraversal(struct Tree* head){
	if(head == NULL) return;
	postOrderTraversal(head->left);
	postOrderTraversal(head->right);
	printf("--> %d ",head->data);
}

struct Tree* createNode(int val){
	struct Tree* cNode = (struct Tree *)malloc(sizeof(struct Tree));
	cNode->data = val;
	cNode->left = NULL;
	cNode->right = NULL;
	return cNode;
}

struct Tree* createTree(int val[]){
	printf("%d\n",val[0]);
	struct Tree* cNode = createNode(val[0]);
	cNode->left = createNode(val[1]);
	cNode->right = createNode(val[2]);
	cNode->left->left = createNode(val[3]);
	cNode->left->right = createNode(val[4]);
	cNode->right->left = createNode(val[5]);
	cNode->right->right = createNode(val[6]);

	return cNode;
}


int main(){
	struct Tree* cRoot;
	int choice, ext, value[8];
	char ch = 'y';
	printf("-------- Tree Data Structure --------\n");
	printf("\n1. Create Tree once only...");

	do{
		printf("\n2. Traverse element in Inorder.");
		printf("\n3. Traverse element in Preorder.");
		printf("\n4. Traverse element in Postorder.");
		printf("\n5. Exit...\n");
		printf("Which operation you want to perform :- ");
		scanf("%d", &choice);

		switch(choice){
			case 1: 
				printf("Enter number of element to be insert: \n");
				scanf("%d", &ext);
				printf("Enter the value to be inserted : ");
				for(int i = 0; i < ext; i++) scanf("%d", &value[i]);
				cRoot = createTree(value);
				break;
			case 2:
				printf("Inorder Traversal is : ");
				inOrderTraversal(cRoot);
				break;
			case 3:
				printf("Preorder Traversal is : ");
				preOrderTraversal(cRoot);
				break;
			case 4:
				printf("Postorder Traversal is : ");
				postOrderTraversal(cRoot);
				break;
			case 5: 
				printf("Exit...\n");
		}

	}while(choice != 5);

	return 0;
}